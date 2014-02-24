<?php

/*
 +--------------------------------------------------------------------------+
 | Zephir Language                                                          |
 +--------------------------------------------------------------------------+
 | Copyright (c) 2013-2014 Zephir Team and contributors                     |
 +--------------------------------------------------------------------------+
 | This source file is subject the MIT license, that is bundled with        |
 | this package in the file LICENSE, and is available through the           |
 | world-wide-web at the following url:                                     |
 | http://zephir-lang.com/license.html                                      |
 |                                                                          |
 | If you did not receive a copy of the MIT license and are unable          |
 | to obtain it through the world-wide-web, please send a note to           |
 | license@zephir-lang.com so we can mail you a copy immediately.           |
 +--------------------------------------------------------------------------+
*/

namespace Zephir;

use Zephir\Detectors\ReadDetector;

/**
 * Call
 *
 * Base class for common functionality in functions/calls
 */
class Call
{
    /**
     * Call expression
	 * @var Expression
     */
    protected $_expression;

    protected $_mustInit;

    protected $_symbolVariable;

    protected $_isExpecting = false;

    protected $_resolvedParams;

    protected $_reflection;

    protected $_resolvedTypes = array();

    protected $_resolvedDynamicTypes = array();

    protected $_temporalVariables = array();

    protected $_mustCheckForCopy = array();

    /**
     * Processes the symbol variable that will be used to return
     * the result of the symbol call
     *
     * @param CompilationContext $compilationContext
     */
    public function processExpectedReturn(CompilationContext $compilationContext)
    {
        $expr = $this->_expression;
        $expression = $expr->getExpression();

        /**
         * Create temporary variable if needed
         */
        $mustInit = false;
        $symbolVariable = null;
        $isExpecting = $expr->isExpectingReturn();
        if ($isExpecting) {
            $symbolVariable = $expr->getExpectingVariable();
            if (is_object($symbolVariable)) {
                $readDetector = new ReadDetector($expression);
                if ($readDetector->detect($symbolVariable->getName(), $expression)) {
                    $symbolVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
                } else {
                    $mustInit = true;
                }
            } else {
                $symbolVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
            }
        }

        $this->_mustInit = $mustInit;
        $this->_symbolVariable = $symbolVariable;
        $this->_isExpecting = $isExpecting;
    }

    /**
     * Processes the symbol variable that will be used to return
     * the result of the symbol call
     *
     * @param CompilationContext $compilationContext
     */
    public function processExpectedObservedReturn(CompilationContext $compilationContext)
    {
        $expr = $this->_expression;
        $expression = $expr->getExpression();

        /**
         * Create temporary variable if needed
         */
        $mustInit = false;
        $symbolVariable = null;
        $isExpecting = $expr->isExpectingReturn();
        if ($isExpecting) {
            $symbolVariable = $expr->getExpectingVariable();
            if (is_object($symbolVariable)) {
                $readDetector = new ReadDetector($expression);
                if ($readDetector->detect($symbolVariable->getName(), $expression)) {
                    $symbolVariable = $compilationContext->symbolTable->getTempVariableForObserveOrNullify('variable', $compilationContext, $expression);
                } else {
                    $mustInit = true;
                }
            } else {
                $symbolVariable = $compilationContext->symbolTable->getTempVariableForObserveOrNullify('variable', $compilationContext, $expression);
            }
        }

        $this->_mustInit = $mustInit;
        $this->_symbolVariable = $symbolVariable;
        $this->_isExpecting = $isExpecting;
    }

    /**
     * Processes the symbol variable that will be used to return
     * the result of the symbol call. If a temporal variable is used
     * as returned value only the body is freed between calls
     *
     * @param CompilationContext $compilationContext
     */
    public function processExpectedComplexLiteralReturn(CompilationContext $compilationContext)
    {

        $expr = $this->_expression;
        $expression = $expr->getExpression();

        /**
         * Create temporary variable if needed
         */
        $mustInit = false;
        $isExpecting = $expr->isExpectingReturn();
        if ($isExpecting) {
            $symbolVariable = $expr->getExpectingVariable();
            if (is_object($symbolVariable)) {
                $readDetector = new ReadDetector($expression);
                if ($readDetector->detect($symbolVariable->getName(), $expression)) {
                    $symbolVariable = $compilationContext->symbolTable->getTempComplexLiteralVariableForWrite('variable', $compilationContext, $expression);
                } else {
                    $mustInit = true;
                }
            } else {
                $symbolVariable = $compilationContext->symbolTable->getTempComplexLiteralVariableForWrite('variable', $compilationContext, $expression);
            }
        }

        $this->_mustInit = $mustInit;
        $this->_symbolVariable = $symbolVariable;
        $this->_isExpecting = $isExpecting;
    }

    public function isExpectingReturn()
    {
        return $this->_isExpecting;
    }

    /**
     * Returns if the symbol to be returned by the call must be initialized
     *
     * @return boolean
     */
    public function mustInitSymbolVariable()
    {
        return $this->_mustInit;
    }

    /**
     * Returns the symbol variable that must be returned by the call
     *
     * @return Variable
     */
    public function getSymbolVariable()
    {
        return $this->_symbolVariable;
    }

    /**
     * Resolves paramameters
     *
     * @param array $parameters
     * @param CompilationContext $compilationContext
     * @param array $expression
     * @param boolean $readOnly
     * @return array|null|CompiledExpression[]
     */
    public function getResolvedParamsAsExpr($parameters, CompilationContext $compilationContext, $expression, $readOnly = false)
    {
        if (!$this->_resolvedParams) {

            $hasParametersByName = false;
            foreach ($parameters as $parameter) {
                if (isset($parameter['name'])) {
                    $hasParametersByName = true;
                    break;
                }
            }

            /**
             * All parameters must be passed by name
             */
            if ($hasParametersByName) {
                foreach ($parameters as $parameter) {
                    if (!isset($parameter['name'])) {
                        throw new CompilerException('All parameters must use named', $parameter);
                    }
                }
            }

            if ($hasParametersByName) {
                if ($this->_reflection) {
                    $positionalParameters = array();
                    foreach ($this->_reflection->getParameters() as $position => $reflectionParameter) {
                        if (is_object($reflectionParameter)) {
                            $positionalParameters[$reflectionParameter->getName()] = $position;
                        } else {
                            $positionalParameters[$reflectionParameter['name']] = $position;
                        }
                    }
                    $orderedParameters = array();
                    foreach ($parameters as $parameter) {
                        if (isset($positionalParameters[$parameter['name']])) {
                            $orderedParameters[$positionalParameters[$parameter['name']]] = $parameter;
                        } else {
                            throw new CompilerException('Named parameter "' . $parameter['name'] . '" is not a valid parameter name, available: ' . join(', ', array_keys($positionalParameters)), $parameter['parameter']);
                        }
                    }
                    for ($i = 0; $i < count($parameters); $i++) {
                        if (!isset($orderedParameters[$i])) {
                            $orderedParameters[$i] = array('parameter' => array('type' => 'null'));
                        }
                    }
                    $parameters = $orderedParameters;
                }
            }

            $params = array();
            foreach ($parameters as $parameter) {

                if (is_array($parameter['parameter'])) {
                    $paramExpr = new Expression($parameter['parameter']);
                    switch ($parameter['parameter']['type']) {
                        case 'property-access':
                        case 'array-access':
                        case 'static-property-access':
                            $paramExpr->setReadOnly(true);
                            break;
                        default:
                            $paramExpr->setReadOnly($readOnly);
                            break;
                    }
                    $params[] = $paramExpr->compile($compilationContext);
                    continue;
                }

                if ($parameter['parameter'] instanceof CompiledExpression) {
                    $params[] = $parameter['parameter'];
                    continue;
                }

                throw new CompilerException("Invalid expression ", $expression);
            }
            $this->_resolvedParams = $params;
        }

        return $this->_resolvedParams;
    }

    /**
     * Resolve parameters getting aware that the target function/method could retain or change
     * the parameters
     *
     * @param array $parameters
     * @param CompilationContext $compilationContext
     * @param array $expression
     * @param array $calleeDefinition
     * @return array
     */
    public function getResolvedParams($parameters, CompilationContext $compilationContext, $expression, $calleeDefinition = null)
    {
        $codePrinter = &$compilationContext->codePrinter;
        $exprParams = $this->getResolvedParamsAsExpr($parameters, $compilationContext, $expression);

        /**
         * Static typed parameters in final methods are promotable to read only parameters
         * Recursive calls with static typed methods also also promotable
         */
        $isFinal = false;
        $readOnlyParameters = array();
        if (is_object($calleeDefinition)) {
            if ($calleeDefinition instanceof ClassMethod) {
                if ($calleeDefinition->isFinal() || $compilationContext->currentMethod == $calleeDefinition) {
                    $isFinal = true;
                    foreach ($calleeDefinition->getParameters() as $position => $parameter) {
                        if (isset($parameter['data-type'])) {
                            switch ($parameter['data-type']) {
                                case 'int':
                                case 'uint':
                                case 'double':
                                case 'long':
                                case 'char':
                                case 'uchar':
                                    $readOnlyParameters[$position] = true;
                                    break;
                            }
                        }
                    }
                }
            }
        }

        $params = array();
        $types = array();
        $dynamicTypes = array();
        $mustCheck = array();
        foreach ($exprParams as $position => $compiledExpression) {

            $expression = $compiledExpression->getOriginal();
            switch ($compiledExpression->getType()) {

                case 'null':
                    $params[] = 'ZEPHIR_GLOBAL(global_null)';
                    $types[] = $compiledExpression->getType();
                    $dynamicTypes[] = $compiledExpression->getType();
                    break;

                case 'int':
                case 'uint':
                case 'long':
                    if (isset($readOnlyParameters[$position])) {
                        $parameterVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                        $codePrinter->output('ZVAL_LONG(&' . $parameterVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                        $params[] = '&' . $parameterVariable->getName();
                    } else {
                        $parameterVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
                        $codePrinter->output('ZVAL_LONG(' . $parameterVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                        $params[] = $parameterVariable->getName();
                    }
                    $this->_temporalVariables[] = $parameterVariable;
                    $types[] = $compiledExpression->getType();
                    $dynamicTypes[] = $compiledExpression->getType();
                    break;

                case 'double':
                    if (isset($readOnlyParameters[$position])) {
                        $parameterVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                        $codePrinter->output('ZVAL_DOUBLE(&' . $parameterVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                        $params[] = '&' . $parameterVariable->getName();
                    } else {
                        $parameterVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
                        $codePrinter->output('ZVAL_DOUBLE(' . $parameterVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                        $params[] = $parameterVariable->getName();
                    }
                    $this->_temporalVariables[] = $parameterVariable;
                    $types[] = $compiledExpression->getType();
                    break;

                case 'bool':
                    if ($compiledExpression->getCode() == 'true') {
                        $params[] = 'ZEPHIR_GLOBAL(global_true)';
                    } else {
                        if ($compiledExpression->getCode() == 'false') {
                            $params[] = 'ZEPHIR_GLOBAL(global_false)';
                        } else {
                            $params[] = '(' . $compiledExpression->getBooleanCode() . ' ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false))';
                        }
                    }
                    $types[] = $compiledExpression->getType();
                    $dynamicTypes[] = $compiledExpression->getType();
                    break;

                case 'ulong':
                case 'string':
                    $parameterVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
                    $codePrinter->output('ZVAL_STRING(' . $parameterVariable->getName() . ', "' . $compiledExpression->getCode() . '", 0);');
                    $this->_temporalVariables[] = $parameterVariable;
                    $mustCheck[] = $parameterVariable->getName();
                    $params[] = $parameterVariable->getName();
                    $types[] = $compiledExpression->getType();
                    $dynamicTypes[] = $compiledExpression->getType();
                    break;

                case 'array':
                    $parameterVariable = $compilationContext->symbolTable->getVariableForRead($compiledExpression->getCode(), $compilationContext, $expression);
                    $params[] = $parameterVariable->getName();
                    $types[] = $parameterVariable->getType();
                    $dynamicTypes[] = $parameterVariable->getType();
                    break;

                case 'variable':
                    $parameterVariable = $compilationContext->symbolTable->getVariableForRead($compiledExpression->getCode(), $compilationContext, $expression);
                    switch ($parameterVariable->getType()) {

                        case 'int':
                        case 'uint':
                        case 'long':
                        case 'ulong': /* ulong must be stored in string */
                            if (isset($readOnlyParameters[$position])) {
                                $parameterTempVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                                $codePrinter->output('ZVAL_LONG(&' . $parameterTempVariable->getName() . ', ' . $parameterVariable->getName() . ');');
                                $params[] = '&' . $parameterTempVariable->getName();
                            } else {
                                $parameterTempVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
                                $codePrinter->output('ZVAL_LONG(' . $parameterTempVariable->getName() . ', ' . $parameterVariable->getName() . ');');
                                $params[] = $parameterTempVariable->getName();
                            }
                            $this->_temporalVariables[] = $parameterTempVariable;
                            $types[] = $parameterVariable->getType();
                            $dynamicTypes[] = $parameterVariable->getType();
                            break;

                        case 'double':
                            if (isset($readOnlyParameters[$position])) {
                                $parameterTempVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                                $codePrinter->output('ZVAL_DOUBLE(&' . $parameterTempVariable->getName() . ', ' . $parameterVariable->getName() . ');');
                                $params[] = '&' . $parameterTempVariable->getName();
                            } else {
                                $parameterTempVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
                                $codePrinter->output('ZVAL_DOUBLE(' . $parameterTempVariable->getName() . ', ' . $parameterVariable->getName() . ');');
                                $params[] = $parameterTempVariable->getName();
                            }
                            $this->_temporalVariables[] = $parameterTempVariable;
                            $types[] = $parameterVariable->getType();
                            $dynamicTypes[] = $parameterVariable->getType();
                            break;

                        case 'bool':
                            $params[] = '(' . $parameterVariable->getName() . ' ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false))';
                            $types[] = $parameterVariable->getType();
                            $dynamicTypes[] = $parameterVariable->getType();
                            break;

                        case 'string':
                            $params[] = $parameterVariable->getName();
                            $types[] = $parameterVariable->getType();
                            $dynamicTypes[] = $parameterVariable->getType();
                            break;

                        case 'array':
                            $params[] = $parameterVariable->getName();
                            $types[] = $parameterVariable->getType();
                            $dynamicTypes[] = $parameterVariable->getType();
                            break;

                        case 'variable':
                            $params[] = $parameterVariable->getName();
                            $types[] = $parameterVariable->getType();
                            $dynamicTypes[] = $parameterVariable->getDynamicTypes();
                            break;

                        default:
                            throw new CompilerException("Cannot use variable type: " . $parameterVariable->getType() . " as parameter", $expression);
                    }
                    break;

                default:
                    throw new CompilerException("Cannot use value type: " . $compiledExpression->getType() . " as parameter", $expression);
            }
        }

        $this->_resolvedTypes = $types;
        $this->_resolvedDynamicTypes = $dynamicTypes;
        $this->_mustCheckForCopy = $mustCheck;
        return $params;
    }

    /**
     * Resolve parameters using zvals in the stack and without allocating memory for constants
     *
     * @param array $parameters
     * @param CompilationContext $compilationContext
     * @param array $expression
     * @return array
     */
    public function getReadOnlyResolvedParams($parameters, CompilationContext $compilationContext, $expression)
    {
        $codePrinter = &$compilationContext->codePrinter;
        $exprParams = $this->getResolvedParamsAsExpr($parameters, $compilationContext, $expression, true);

        $params = array();
        foreach ($exprParams as $compiledExpression) {
            $expression = $compiledExpression->getOriginal();
            switch ($compiledExpression->getType()) {

                case 'null':
                    $params[] = 'ZEPHIR_GLOBAL(global_null)';
                    break;

                case 'int':
                case 'uint':
                case 'long':
                    $parameterVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                    $codePrinter->output('ZVAL_LONG(&' . $parameterVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                    $this->_temporalVariables[] = $parameterVariable;
                    $params[] = '&' . $parameterVariable->getName();
                    break;

                case 'char':
                case 'uchar':
                    $parameterVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                    $codePrinter->output('ZVAL_LONG(&' . $parameterVariable->getName() . ', \'' . $compiledExpression->getCode() . '\');');
                    $this->_temporalVariables[] = $parameterVariable;
                    $params[] = '&' . $parameterVariable->getName();
                    break;

                case 'double':
                    $parameterVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                    $codePrinter->output('ZVAL_DOUBLE(&' . $parameterVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                    $this->_temporalVariables[] = $parameterVariable;
                    $params[] = '&' . $parameterVariable->getName();
                    break;

                case 'bool':
                    if ($compiledExpression->getCode() == 'true') {
                        $params[] = 'ZEPHIR_GLOBAL(global_true)';
                    } else {
                        $params[] = 'ZEPHIR_GLOBAL(global_false)';
                    }
                    break;

                case 'string':
                case 'ulong':
                    $parameterVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                    $codePrinter->output('ZVAL_STRING(&' . $parameterVariable->getName() . ', "' . $compiledExpression->getCode() . '", 0);');
                    $this->_temporalVariables[] = $parameterVariable;
                    $params[] = '&' . $parameterVariable->getName();
                    break;

                case 'variable':
                    $parameterVariable = $compilationContext->symbolTable->getVariableForRead($compiledExpression->getCode(), $compilationContext, $expression);
                    switch ($parameterVariable->getType()) {

                        case 'int':
                        case 'uint':
                        case 'long':
                        case 'ulong':
                            $parameterTempVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                            $codePrinter->output('ZVAL_LONG(&' . $parameterTempVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                            $params[] = '&' . $parameterTempVariable->getName();
                            $this->_temporalVariables[] = $parameterTempVariable;
                            break;

                        case 'char':
                        case 'uchar':
                            $parameterTempVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                            $codePrinter->output('ZVAL_LONG(&' . $parameterTempVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                            $params[] = '&' . $parameterTempVariable->getName();
                            $this->_temporalVariables[] = $parameterTempVariable;
                            break;

                        case 'double':
                            $parameterTempVariable = $compilationContext->symbolTable->getTempLocalVariableForWrite('variable', $compilationContext, $expression);
                            $codePrinter->output('ZVAL_DOUBLE(&' . $parameterTempVariable->getName() . ', ' . $compiledExpression->getCode() . ');');
                            $params[] = '&' . $parameterTempVariable->getName();
                            $this->_temporalVariables[] = $parameterTempVariable;
                            break;

                        case 'bool':
                            $params[] = '(' . $parameterVariable->getName() . ' ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false))';
                            break;

                        case 'string':
                        case 'variable':
                        case 'array':
                            $params[] = $parameterVariable->getName();
                            break;

                        default:
                            throw new CompilerException("Cannot use variable type: " . $parameterVariable->getType() . " as parameter", $expression);
                    }
                    break;

                default:
                    throw new CompilerException("Cannot use value type: " . $compiledExpression->getType() . " as parameter", $expression);
            }
        }

        return $params;
    }

    /**
     * Add the last-call-status flag to the current symbol table
     *
     * @param CompilationContext $compilationContext
     */
    public function addCallStatusFlag(CompilationContext $compilationContext)
    {
        if (!$compilationContext->symbolTable->hasVariable('ZEPHIR_LAST_CALL_STATUS')) {
            $callStatus = new Variable('int', 'ZEPHIR_LAST_CALL_STATUS', $compilationContext->currentBranch);
            $callStatus->setIsInitialized(true, $compilationContext, array());
            $callStatus->increaseUses();
            $callStatus->setReadOnly(true);
            $compilationContext->symbolTable->addRawVariable($callStatus);
        }
    }

    /**
     * Checks the last call status or make a label jump to the next catch block
     *
     * @param CompilationContext $compilationContext
     */
    public function addCallStatusOrJump(CompilationContext $compilationContext)
    {
        if (!$compilationContext->insideTryCatch) {
            $compilationContext->codePrinter->output('zephir_check_call_status();');
        } else {
            $compilationContext->codePrinter->output('zephir_check_call_status_or_jump(try_end_' . $compilationContext->insideTryCatch . ');');
        }
    }

    /**
     * Return resolved parameter types
     *
     * @return array
     */
    public function getResolvedTypes()
    {
        return $this->_resolvedTypes;
    }

    /**
     * Return resolved parameter dynamic types
     *
     * @return array
     */
    public function getResolvedDynamicTypes()
    {
        return $this->_resolvedDynamicTypes;
    }

    /**
     * Returns the temporal variables generated during the parameter resolving
     *
     * @return Variable[]
     */
    public function getTemporalVariables()
    {
        return $this->_temporalVariables;
    }

    /**
     * Parameters to check if they must be copied
     *
     * @return array
     */
    public function getMustCheckForCopyVariables()
    {
        return $this->_mustCheckForCopy;
    }
}
