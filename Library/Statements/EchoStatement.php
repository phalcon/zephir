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
 * EchoStatement
 *
 * Produce output according to the type
 */
class EchoStatement
{
	protected $_statement;

	public function __construct($statement)
	{
		$this->_statement = $statement;
	}

	public function compile(CompilationContext $compilationContext)
	{
		foreach ($this->_statement['expressions'] as $expr) {

			$expr = new Expression($expr);
			$resolvedExpr = $expr->compile($compilationContext);

			switch ($resolvedExpr->getType()) {
				case 'int':
					$compilationContext->codePrinter->output('php_printf("%d", ' . $resolvedExpr->getCode() . ');');
					break;
				case 'char':
					$compilationContext->codePrinter->output('php_printf("%c", \'' . $resolvedExpr->getCode() . '\');');
					break;
				case 'long':
					$compilationContext->codePrinter->output('php_printf("%ld", ' . $resolvedExpr->getCode() . ');');
					break;
				case 'string':
					$compilationContext->codePrinter->output('php_printf("' . Utils::addSlaches($resolvedExpr->getCode()) . '");');
					break;
				case 'variable':
					$variable = $compilationContext->symbolTable->getVariableForRead($resolvedExpr->getCode(), $compilationContext, $expr);
					switch ($variable->getType()) {
						case 'int':
							$compilationContext->codePrinter->output('php_printf("%d", ' . $variable->getName() . ');');
							break;
						case 'long':
							$compilationContext->codePrinter->output('php_printf("%ld", ' . $variable->getName() . ');');
							break;
						case 'char':
							$compilationContext->codePrinter->output('php_printf("%c", ' . $variable->getName() . ');');
							break;
						case 'string':
							$compilationContext->codePrinter->output('php_printf("%s", ' . $variable->getName() . '->str);');
							break;
						case 'variable':
							$compilationContext->codePrinter->output('zend_print_zval(' . $variable->getName() . ', 0);');
							break;
						default:
							throw new CompilerException("Unknown type: " . $variable->getType(), $expr);
					}
					break;
				default:
					throw new CompilerException("Unknown type: " . $resolvedExpr->getType(), $expr);
			}
		}
	}

}