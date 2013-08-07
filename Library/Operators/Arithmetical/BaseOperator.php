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
 * BaseOperator
 *
 * This is the base operator for commutative, associative and distributive
 * arithmetic operators
 */
class BaseOperator
{

	protected $_expecting = true;

	protected $_expectingVariable;

	/**
	 * Sets if the variable must be resolved into a direct variable symbol
	 * create a temporary value or ignore the return value
	 *
	 * @param boolean $expecting
	 * @param Variable $expectingVariable
	 */
	public function setExpectReturn($expecting, Variable $expectingVariable=null)
	{
		$this->_expecting = $expecting;
		$this->_expectingVariable = $expectingVariable;
	}

	public function getExpected(CompilationContext $compilationContext, $expression)
	{
		$isExpecting = $this->_expecting;
		if ($isExpecting) {
			$symbolVariable = $this->_expectingVariable;
			if (is_object($symbolVariable)) {
				if ($symbolVariable->getType() == 'variable') {
					$symbolVariable->initVariant($compilationContext);
				} else {
					$symbolVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
				}
			} else {
				$symbolVariable = $compilationContext->symbolTable->getTempVariableForWrite('variable', $compilationContext, $expression);
			}
		}
		return $symbolVariable;
	}

	public function compile($expression, CompilationContext $compilationContext)
	{
		if (!isset($expression['left'])) {
			throw new Exception("Missing left part of the expression");
		}

		if (!isset($expression['right'])) {
			throw new Exception("Missing right part of the expression");
		}

		$leftExpr = new Expression($expression['left']);
		$left = $leftExpr->compile($compilationContext);

		$rightExpr = new Expression($expression['right']);
		$right = $rightExpr->compile($compilationContext);

		switch ($left->getType()) {
			case 'int':
				switch ($right->getType()) {
					case 'int':
						return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getCode(), $expression);
					case 'double':
						return new CompiledExpression('double', '(double) ' . $left->getCode() . ' ' . $this->_operator . ' ' . $right->getCode(), $expression);
					case 'bool':
						return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getBooleanCode(), $expression);
					case 'variable':
						$variableRight = $compilationContext->symbolTable->getVariableForRead($expression['right']['value'], $compilationContext, $expression);
						switch ($variableRight->getType()) {
							case 'int':
								return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
							case 'bool':
								return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
							case 'double':
								return new CompiledExpression('double', ' (double) ' . $left->getCode() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
							case 'variable':
								$compilationContext->headersManager->add('kernel/operators');
								if ($variableRight->isLocalOnly()) {
									return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' zephir_get_intval(&' . $variableRight->getName() . ')', $expression);
								} else {
									return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' zephir_get_intval(' . $variableRight->getName() . ')', $expression);
								}
							default:
								throw new Exception("Cannot add variable('int') with variable('" . $variableRight->getType() . "')");
						}
					default:
						throw new Exception("Cannot add 'int' with '" . $right->getType() . "'");
				}
				break;
			case 'bool':
				switch ($right->getType()) {
					case 'int':
					case 'double':
						return new CompiledExpression('bool', $left->getBooleanCode() . ' ' . $this->_bitOperator . '((' . $right->getCode() . ') ? 1 : 0)', $expression);
					case 'bool':
						return new CompiledExpression('bool', $left->getBooleanCode() . ' ' . $this->_bitOperator . '' . $right->getBooleanCode(), $expression);
					default:
						throw new Exception("Cannot add 'bool' with '" . $right->getType() . "'");
				}
				break;
			case 'double':
				switch ($right->getType()) {
					case 'int':
						return new CompiledExpression('double', $left->getCode() . ' ' . $this->_operator . ' (double) (' . $right->getCode() . ')', $expression);
					case 'double':
						return new CompiledExpression('double', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getCode(), $expression);
					case 'bool':
						return new CompiledExpression('double', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getBooleanCode(), $expression);
					default:
						throw new CompilerException("Cannot add 'double' with '" . $right->getType() . "'", $expression);
				}
				break;
			case 'string':
				switch ($right->getType()) {
					default:
						throw new CompilerException("Add is not supported between strings", $expression);
				}
				break;
			case 'variable':

				$variableLeft = $compilationContext->symbolTable->getVariableForRead($left->resolve(null, $compilationContext), $compilationContext, $expression);

				switch ($variableLeft->getType()) {
					case 'int':
						switch ($right->getType()) {
							case 'int':
								return new CompiledExpression('int', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getCode(), $expression);
							case 'variable':
								$variableRight = $compilationContext->symbolTable->getVariableForRead($expression['right']['value'], $compilationContext, $expression['right']);
								switch ($variableRight->getType()) {
									case 'int':
										return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
									case 'bool':
										return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
									case 'double':
										return new CompiledExpression('double', ' (double) ' . $variableLeft->getName() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
									case 'variable':
										$compilationContext->headersManager->add('kernel/operators');
										if ($variableRight->isLocalOnly()) {
											return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' zephir_get_intval(&' . $variableRight->getName() . ')', $expression);
										} else {
											return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' zephir_get_intval(' . $variableRight->getName() . ')', $expression);
										}
									default:
										throw new CompilerException("Cannot add variable('int') with variable('" . $variableRight->getType() . "')", $expression);
								}
							default:
								throw new CompilerException("Cannot add variable('int') with '" . $right->getType() . "'", $expression);
						}
						break;
					case 'bool':
						switch ($right->getType()) {
							case 'int':
								return new CompiledExpression('bool', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getCode(), $expression);
							case 'bool':
								return new CompiledExpression('bool', $left->getCode() . ' ' . $this->_bitOperator . '' . $right->getBooleanCode(), $expression);
							case 'variable':
								$variableRight = $compilationContext->symbolTable->getVariableForRead($expression['right']['value'], $compilationContext, $expression['right']);
								switch ($variableRight->getType()) {
									case 'int':
										return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
									case 'bool':
										return new CompiledExpression('bool', $variableLeft->getName() . ' ' . $this->_bitOperator . '' . $variableRight->getName(), $expression);
									case 'variable':
										if ($variableRight->isLocalOnly()) {
											return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' zephir_get_intval(&' . $variableRight->getName() . ')', $expression);
										} else {
											return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' zephir_get_intval(' . $variableRight->getName() . ')', $expression);
										}
									default:
										throw new CompilerException("Cannot add variable('int') with variable('" . $variableRight->getType() . "')", $expression);
								}
							default:
								throw new CompilerException("Cannot add variable('int') with '" . $right->getType() . "'", $expression);
						}
					case 'double':
						switch ($right->getType()) {
							case 'int':
								return new CompiledExpression('double', $left->getCode() . ' ' . $this->_operator . ' (double) ' . $right->getCode(), $expression);
							case 'double':
								return new CompiledExpression('double', $left->getCode() . ' ' . $this->_operator . ' ' . $right->getCode(), $expression);
							case 'bool':
								return new CompiledExpression('bool', $left->getCode() . ' ' . $this->_bitOperator . '' . $right->getBooleanCode(), $expression);
							case 'variable':
								$variableRight = $compilationContext->symbolTable->getVariableForRead($expression['right']['value'], $compilationContext, $expression['right']);
								switch ($variableRight->getType()) {
									case 'int':
										return new CompiledExpression('double', $variableLeft->getName() . ' ' . $this->_operator . '  (double) ' . $variableRight->getName(), $expression);
									case 'double':
										return new CompiledExpression('double', $variableLeft->getName() . ' ' . $this->_operator . '  ' . $variableRight->getName(), $expression);
									case 'bool':
										return new CompiledExpression('bool', $variableLeft->getName() . ' ' . $this->_bitOperator . '' . $variableRight->getName(), $expression);
									case 'variable':
										$compilationContext->headersManager->add('kernel/operators');
										if ($variableRight->isLocalOnly()) {
											return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' zephir_get_intval(&' . $variableRight->getName() . ')', $expression);
										} else {
											return new CompiledExpression('int', $variableLeft->getName() . ' ' . $this->_operator . ' zephir_get_intval(' . $variableRight->getName() . ')', $expression);
										}
									default:
										throw new Exception("Cannot add variable('double') with variable('" . $variableRight->getType() . "')");
								}
							default:
								throw new CompilerException("Cannot add variable('int') with '" . $right->getType() . "'", $expression);
						}
					case 'string':
						throw new CompilerException("Cannot add string variables'", $expression);
					case 'variable':
						switch ($right->getType()) {
							/* a + 1 */
							case 'int':
							case 'double':
								$compilationContext->headersManager->add('kernel/operators');
								$op = $this->_operator;
								if ($variableLeft->isLocalOnly()) {
									$op1 = '&' . $variableLeft->getName();
								} else {
									$op1 = $variableLeft->getName();
								}
								$op2 = $right->getCode();
								return new CompiledExpression('double', 'zephir_get_doubleval(' . $op1 . ') ' . $op . ' ' . $op2, $expression);
							/* a(var) + a(x) */
							case 'variable':
								$variableRight = $compilationContext->symbolTable->getVariableForRead($right->resolve(null, $compilationContext), $compilationContext, $expression);
								switch ($variableRight->getType()) {
									/* a(var) + a(int) */
									case 'int':
										$compilationContext->headersManager->add('kernel/operators');
										if ($variableLeft->isLocalOnly()) {
											return new CompiledExpression('int', 'zephir_get_intval(&' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										} else {
											return new CompiledExpression('int', 'zephir_get_intval(' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										}
										break;
									/* a(var) + a(bool) */
									case 'bool':
										$compilationContext->headersManager->add('kernel/operators');
										if ($variableLeft->isLocalOnly()) {
											return new CompiledExpression('int', 'zephir_get_intval(&' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										} else {
											return new CompiledExpression('int', 'zephir_get_intval(' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										}
										break;
									/* a(var) + a(var) */
									case 'variable':

										$compilationContext->headersManager->add('kernel/operators');

										if ($variableLeft->isLocalOnly()) {
											$op1 = '&' . $variableLeft->getName();
										} else {
											$op1 = $variableLeft->getName();
										}

										if ($variableRight->isLocalOnly()) {
											$op2 = '&' . $variableRight->getName();
										} else {
											$op2 = $variableRight->getName();
										}

										$expected = $this->getExpected($compilationContext, $expression);
										if ($expected->isLocalOnly()) {
											$compilationContext->codePrinter->output('zephir_add_function(&' . $expected->getName() . ', ' . $op1 . ', ' . $op2 . ');');
										} else {
											$compilationContext->codePrinter->output('zephir_add_function(' . $expected->getName() . ', ' . $op1 . ', ' . $op2 . ');');
										}
										return new CompiledExpression('variable', $expected->getName(), $expression);

									default:
										throw new CompilerException("Cannot add 'variable' with variable ('" . $variableRight->getType() . "')", $expression);
								}
							default:
								throw new CompilerException("Cannot add 'variable' with '" . $right->getType() . "'", $expression);
						}
					case 'variable':
						switch ($right->getType()) {
							case 'int':
							case 'double':
								$compilationContext->headersManager->add('kernel/operators');
								$op = $this->_operator;
								if ($variableLeft->isLocalOnly()) {
									$op1 = '&' . $variableLeft->getName();
								} else {
									$op1 = $variableLeft->getName();
								}
								$op2 = $right->getCode();
								return new CompiledExpression('double', 'zephir_get_double(' . $op1 . ') ' . $op . ' ' . $op2, $expression);
							case 'variable':

								$variableRight = $compilationContext->symbolTable->getVariableForRead($right->resolve(null, $compilationContext), $compilationContext, $expression);

								switch ($variableRight->getType()) {
									case 'int':
										$compilationContext->headersManager->add('kernel/operators');
										if ($variableLeft->isLocalOnly()) {
											return new CompiledExpression('int', 'zephir_get_intval(&' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										} else {
											return new CompiledExpression('int', 'zephir_get_intval(' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										}
									case 'bool':
										$compilationContext->headersManager->add('kernel/operators');
										if ($variableLeft->isLocalOnly()) {
											return new CompiledExpression('int', 'zephir_get_intval(&' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										} else {
											return new CompiledExpression('int', 'zephir_get_intval(' . $variableLeft->getName() . ') ' . $this->_operator . ' ' . $variableRight->getName(), $expression);
										}
									case 'variable':
										$variableRight = $compilationContext->symbolTable->getVariableForRead($expression['right']['value'], $compilationContext, $expression);
										switch ($variableRight->getType()) {
											case 'int':
												return new CompiledExpression('double', $variableLeft->getName() . ' ' . $this->_operator . '  (double) ' . $variableRight->getName(), $expression);
											case 'double':
												return new CompiledExpression('double', $variableLeft->getName() . ' ' . $this->_operator . '  ' . $variableRight->getName(), $expression);
											case 'bool':
												return new CompiledExpression('bool', $variableLeft->getName() . ' ' . $this->_bitOperator . '' . $variableRight->getName(), $expression);
											case 'variable':
												$compilationContext->headersManager->add('kernel/operators');

												if ($variableLeft->isLocalOnly()) {
													$op1 = '&' . $variableLeft->getName();
												} else {
													$op1 = $variableLeft->getName();
												}
												if ($variableRight->isLocalOnly()) {
													$op2 = '&' . $variableRight->getName();
												} else {
													$op2 = $variableRight->getName();
												}

												$expected = $this->getExpected($compilationContext, $expression);
												$compilationContext->codePrinter->output('zephir_add_function(' . $expected->getName() . ', ' . $op1 . ', ' . $op2 . ');');
												return new CompiledExpression('variable', $expected->getName(), $expression);
											default:
												throw new CompilerException("Cannot add variable('double') with variable('" . $variableRight->getType() . "')", $expression);
										}
										break;
									default:
										throw new CompilerException("Cannot add 'variable' with variable ('" . $variableRight->getType() . "')", $expression);
								}
							default:
								throw new CompilerException("Cannot add 'variable' with '" . $right->getType() . "'", $expression);
						}
						break;
					default:
						throw new CompilerException("Unknown '" . $variableLeft->getType() . "'", $expression);
				}
				break;
			default:
				throw new CompilerException("Unsupported type: " . $left->getType(), $expression);
		}
	}
}