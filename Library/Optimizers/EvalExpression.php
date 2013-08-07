<?php

/*
 +----------------------------------------------------------------------+
 | Zephir Language                                                      |
 +----------------------------------------------------------------------+
 | Copyright (c) 2013 Zephir Team                                       |
 +----------------------------------------------------------------------+
 | This source file is subject to version 1.0 of the Zephir license,    |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.zephir-lang.com/license                                   |
 |                                                                      |
 | If you did not receive a copy of the Zephir license and are unable   |
 | to obtain it through the world-wide-web, please send a note to       |
 | license@zephir-lang.com so we can mail you a copy immediately.       |
 +----------------------------------------------------------------------+
*/

/**
 * EvalExpression
 *
 * Resolves evaluation expressions returning a C-int expression that can be used by 'if'/'while' statements
 */
class EvalExpression
{
	public function optimizeNot($expr, $compilationContext)
	{
		/**
		 * Compile the expression negating the evaluted expression
		 */
		if ($expr['type'] == 'not') {
			$conditions = $this->optimize($expr['left'], $compilationContext);
			if ($conditions !== false) {
				return '!(' . $conditions . ')';
			}
		}
		return false;
	}

	public function optimizeTypeOf($expr, $compilationContext)
	{

		if (!isset($expr['left'])) {
			return false;
		}

		if ($expr['left']['type'] == 'typeof' && $expr['right']['type'] == 'string') {

			if (isset($expr['type'])) {
				switch ($expr['type']) {
					case 'identical':
					case 'equals':
						$operator = '==';
						break;
					case 'not-identical':
					case 'not-equals':
						$operator = '!=';
						break;
					default:
						return false;
				}
			}

			switch ($expr['right']['value']) {
				case 'array':
					$condition = 'Z_TYPE_P(' . $expr['left']['left']['value'] . ') ' . $operator . ' IS_ARRAY';
					break;
				case 'object':
					$condition = 'Z_TYPE_P(' . $expr['left']['left']['value'] . ') ' . $operator . ' IS_OBJECT';
					break;
				case 'null':
					$condition = 'Z_TYPE_P(' . $expr['left']['left']['value'] . ') ' . $operator . ' IS_NULL';
					break;
				case 'string':
					$condition = 'Z_TYPE_P(' . $expr['left']['left']['value'] . ') ' . $operator . ' IS_STRING';
					break;
				default:
					echo $expr['right']['value'];
			}

			return $condition;
		}

		return false;
	}

	/**
	 * Replaces function calls in the PHP userland by optimized versions
	 */
	public function optimizeFunctionCall($expr, $compilationContext)
	{
		if ($expr['type'] == 'fcall') {
			switch ($expr['name']) {
				case 'count':
					/**
					 * @TODO Count the number of parameters and check types!
					 */
					return 'zephir_fast_count_ev(' . $expr['parameters'][0]['value'] . ' TSRMLS_CC)';
			}
		}
		return false;
	}

	/**
	 * Optimizes expressions
	 */
	public function optimize($exprRaw, CompilationContext $compilationContext)
	{

		$conditions = $this->optimizeNot($exprRaw, $compilationContext);
		if ($conditions !== false) {
			return $conditions;
		}

		$conditions = $this->optimizeTypeOf($exprRaw, $compilationContext);
		if ($conditions !== false) {
			return $conditions;
		}

		$conditions = $this->optimizeFunctionCall($exprRaw, $compilationContext);
		if ($conditions !== false) {
			return $conditions;
		}

		$expr = new Expression($exprRaw);
		$compiledExpression = $expr->compile($compilationContext);

		/**
		 * Generate the condition according to the value returned by the evaluted expression
		 */
		switch ($compiledExpression->getType()) {
			case 'null':
				/**
				 * @TODO This potentially would create unrecheable code
				 */
				return '0';
			case 'int':
			case 'double':
				return $compiledExpression->getCode();
			case 'bool':
				/**
				 * @TODO This potentially would create unrecheable code if is evaluated to false
				 */
				return $compiledExpression->getBooleanCode();
			case 'variable':
				$variableRight = $compilationContext->symbolTable->getVariableForRead($compiledExpression->getCode(), $exprRaw);
				switch ($variableRight->getType()) {
					case 'int':
						return $variableRight->getName();
					case 'bool':
						return $variableRight->getName();
					case 'double':
						return $variableRight->getName();
					case 'variable':
						if ($variableRight->isLocalOnly()) {
							return 'zend_is_true(&' . $variableRight->getName() . ')';
						} else {
							return 'zend_is_true(' . $variableRight->getName() . ')';
						}
					default:
						throw new CompilerException("Variable can't be evaluated " . $variableRight->getType(), $exprRaw);
				}
				break;
			default:
				throw new CompilerException("Expression can't be evaluated", $exprRaw);
		}
	}

}