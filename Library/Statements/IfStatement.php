<?php

/**
 * This file is part of the Zephir package.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Statements;

use Zephir\CompilationContext;
use Zephir\Passes\SkipVariantInit;
use Zephir\StatementsBlock;
use Zephir\Optimizers\EvalExpression;
use Zephir\Detectors\ReadDetector;
use Zephir\Branch;

/**
 * IfStatement
 *
 * 'If' statement, the same as in PHP/C
 */
class IfStatement extends StatementAbstract
{
    /**
     * @param CompilationContext $compilationContext
     */
    public function compile(CompilationContext $compilationContext)
    {
        $exprRaw = $this->_statement['expr'];

        $expr = new EvalExpression();
        $condition = $expr->optimize($exprRaw, $compilationContext);

        /**
         * This pass tries to move dynamic variable initialization out of the if/else branch
         */
        if (isset($this->_statement['statements']) && (isset($this->_statement['else_statements']) || isset($this->_statement['elseif_statements']))) {
            $readDetector = new ReadDetector();

            $skipVariantInit = new SkipVariantInit();

            $skipVariantInit->setVariablesToSkip(0, $expr->getUsedVariables());
            $skipVariantInit->pass(0, new StatementsBlock($this->_statement['statements']));

            $lastBranchId = 0;

            if (isset($this->_statement['else_statements'])) {
                ++$lastBranchId;
                $skipVariantInit->setVariablesToSkip($lastBranchId, $expr->getUsedVariables());
                $skipVariantInit->pass($lastBranchId, new StatementsBlock($this->_statement['else_statements']));
            }

            if (isset($this->_statement['elseif_statements'])) {
                foreach ($this->_statement['elseif_statements'] as $key => $statement) {
                    $this->_statement['elseif_statements'][$key]['condition'] = $expr->optimize($statement['expr'], $compilationContext);

                    $lastBranchId++;
                    $skipVariantInit->setVariablesToSkip($lastBranchId, $expr->getUsedVariables());

                    if (!isset($statement['statements'])) {
                        continue;
                    }

                    $skipVariantInit->pass($lastBranchId, new StatementsBlock($statement));
                }
            }

            $symbolTable = $compilationContext->symbolTable;
            foreach ($skipVariantInit->getVariables() as $variable) {
                if ($symbolTable->hasVariable($variable)) {
                    $symbolVariable = $symbolTable->getVariable($variable);
                    if ($symbolVariable->getType() == 'variable') {
                        if (!$readDetector->detect($variable, $exprRaw)) {
                            $symbolVariable->initVariant($compilationContext);
                            $symbolVariable->skipInitVariant(2);
                        }
                    }
                }
            }
        }

        $compilationContext->codePrinter->output('if (' . $condition . ') {');
        $this->_evalExpression = $expr;

        /**
         * Try to mark latest temporary variable used as idle
         */
        $evalVariable = $expr->getEvalVariable();
        if (is_object($evalVariable)) {
            if ($evalVariable->isTemporal()) {
                $evalVariable->setIdle(true);
            }
        }

        /**
         * Compile statements in the 'if' block
         */
        if (isset($this->_statement['statements'])) {
            $st = new StatementsBlock($this->_statement['statements']);
            $branch = $st->compile($compilationContext, $expr->isUnreachable(), Branch::TYPE_CONDITIONAL_TRUE);
            $branch->setRelatedStatement($this);
        }

        /**
         * Compile statements in the 'elseif' block
         */
        if (isset($this->_statement['elseif_statements'])) {
            foreach ($this->_statement['elseif_statements'] as $key => $statement) {
                if (!isset($statement['statements'])) {
                    continue;
                }

                $st = new StatementsBlock($statement['statements']);
                $compilationContext->codePrinter->output('} else if (' . $statement['condition'] . ') {');
                $branch = $st->compile($compilationContext, $expr->isUnreachable(), Branch::TYPE_CONDITIONAL_TRUE);
                $branch->setRelatedStatement($this);
            }
        }

        /**
         * Compile statements in the 'else' block
         */
        if (isset($this->_statement['else_statements'])) {
            $compilationContext->codePrinter->output('} else {');
            $st = new StatementsBlock($this->_statement['else_statements']);
            $branch = $st->compile($compilationContext, $expr->isUnreachableElse(), Branch::TYPE_CONDITIONAL_FALSE);
            $branch->setRelatedStatement($this);
        }

        $compilationContext->codePrinter->output('}');
    }
}
