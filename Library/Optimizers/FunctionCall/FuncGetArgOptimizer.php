<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Optimizers\FunctionCall;

use Zephir\Call;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Exception;
use Zephir\Exception\CompilerException;
use Zephir\Optimizers\OptimizerAbstract;

/**
 * Zephir\Optimizers\FunctionCall\FuncGetArgOptimizer
 *
 * Optimizes calls to 'func_get_arg' using internal function.
 *
 * @package Zephir\Optimizers\FunctionCall
 */
class FuncGetArgOptimizer extends OptimizerAbstract
{
    /**
     * {@inheritdoc}
     *
     * @param  array              $expression
     * @param  Call               $call
     * @param  CompilationContext $context
     * @return CompiledExpression
     *
     * @throws CompilerException
     */
    public function optimize(array $expression, Call $call, CompilationContext $context)
    {
        if (!isset($expression['parameters']) || count($expression['parameters']) != 1) {
            throw new CompilerException(
                sprintf(
                    'func_get_arg() expects at exactly 1 parameter, %d given',
                    isset($expression['parameters']) ? count($expression['parameters']) : 0
                ),
                $expression
            );
        }

        /**
         * Process the expected symbol to be returned
         */
        $call->processExpectedReturn($context);

        $symbolVariable = $call->getSymbolVariable(true, $context);
        if ($symbolVariable->isNotVariableAndString()) {
            throw new CompilerException(
                'Returned values by functions can only be assigned to variant variables.',
                $expression
            );
        }

        if ($call->mustInitSymbolVariable()) {
            $symbolVariable->initVariant($context);
        }

        $symbol = $context->backend->getVariableCode($symbolVariable);

        try {
            $resolvedParams = $call->getReadOnlyResolvedParams($expression['parameters'], $context, $expression);

            // zephir_get_intval
            $context->headersManager->add('kernel/operators');

            // zephir_get_arg
            $context->headersManager->add('kernel/main');

            if ($context->backend->isZE3()) {
                $template = 'zephir_get_arg(%s, zephir_get_intval(%s));';
            } else {
                $template = 'zephir_get_arg(%s, zephir_get_intval(%s) TSRMLS_CC);';
            }

            $context->codePrinter->output(sprintf($template, $symbol, $resolvedParams[0]));

            return new CompiledExpression('variable', $symbolVariable->getRealName(), $expression);
        } catch (Exception $e) {
            throw new CompilerException($e->getMessage(), $expression, $e->getCode(), $e);
        }
    }
}
