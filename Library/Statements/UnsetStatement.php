<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Statements;

use Zephir\CompilationContext;
use Zephir\Exception\CompilerException;
use Zephir\Expression;

/**
 * Class UnsetStatement
 */
class UnsetStatement extends StatementAbstract
{
    /**
     * @param CompilationContext $compilationContext
     * @throws CompilerException
     */
    public function compile(CompilationContext $compilationContext)
    {
        $compilationContext->headersManager->add('kernel/array');
        $expression = $this->statement['expr'];

        $flags = 'PH_SEPARATE';

        if ($expression['type'] == 'list') {
            $expression = $expression['left'];
        }

        switch ($expression['type']) {
            case 'array-access':
                $expr = new Expression($expression['left']);
                $expr->setReadOnly(true);
                $exprVar = $expr->compile($compilationContext);
                $variable = $compilationContext->symbolTable->getVariableForWrite($exprVar->getCode(), $compilationContext, $this->statement);

                $expr = new Expression($expression['right']);
                $expr->setReadOnly(true);
                $exprIndex = $expr->compile($compilationContext);
                break;

            case 'property-access':
                $expr = new Expression($expression['left']);
                $expr->setReadOnly(true);
                $exprVar = $expr->compile($compilationContext);
                $variable = $compilationContext->symbolTable->getVariableForWrite($exprVar->getCode(), $compilationContext, $this->statement);
                $variableCode = $compilationContext->backend->getVariableCode($variable);

                $compilationContext->headersManager->add('kernel/object');
                $compilationContext->codePrinter->output('zephir_unset_property(' . $variableCode . ', "' . $expression['right']['value'] . '" TSRMLS_CC);');
                return true;

            case 'property-dynamic-access':
                //@todo fix it

            default:
                throw new CompilerException('Cannot use expression type: ' . $expression['type'] . ' in "unset"', $expression);
        }

        if (!in_array($variable->getType(), array('variable', 'array'))) {
            throw new CompilerException('Cannot use variable type: ' . $variable->gettype() . ' in "unset"', $expression['left']);
        }

        if ($variable->hasDifferentDynamicType(array('undefined', 'array', 'object', 'null'))) {
            $compilationContext->logger->warning('Possible attempt to use non array/object in unset operator', 'non-valid-unset', $expression['left']);
        }

        $compilationContext->backend->arrayUnset($variable, $exprIndex, $flags, $compilationContext);
    }
}
