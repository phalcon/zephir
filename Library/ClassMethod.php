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
 * ClassMethod
 *
 * Represents a class method
 */
class ClassMethod
{

	protected $_visibility;

	protected $_name;

	protected $_parameters;

	protected $_statements;

	protected $_docblock;

	/**
	 * ClassMethod constructor
	 *
	 * @param string $visibility
	 * @param string $name
	 */
	public function __construct($visibility, $name, $parameters, StatementsBlock $statements=null, $docblock=null)
	{
		$this->_visibility = $visibility;
		$this->_name = $name;
		$this->_parameters = $parameters;
		$this->_statements = $statements;
		$this->_docblock = $docblock;
	}

	public function getName()
	{
		return $this->_name;
	}

	public function getDocBlock()
	{
		return $this->_docblock;
	}

	public function getParameters()
	{
		return $this->_parameters;
	}

	public function getVisibilityAccesor()
	{
		return 'ZEND_ACC_PROTECTED';
	}

	public function removeMemoryStackReferences(SymbolTable $symbolTable, $containerCode)
	{
		if (!$symbolTable->getMustGrownStack()) {
			$containerCode = str_replace('ZEPHIR_THROW_EXCEPTION_STR', 'ZEPHIR_THROW_EXCEPTION_STRW', $containerCode);
			$containerCode = str_replace('ZEPHIR_THROW_EXCEPTION_ZVAL', 'ZEPHIR_THROW_EXCEPTION_ZVALW', $containerCode);
			$containerCode = str_replace('RETURN_THIS', 'RETURN_THISW', $containerCode);
			$containerCode = str_replace('RETURN_CTOR', 'RETURN_CTORW', $containerCode);
			$containerCode = str_replace('RETURN_NCTOR', 'RETURN_NCTORW', $containerCode);
			$containerCode = str_replace('RETURN_CCTOR', 'RETURN_CCTORW', $containerCode);
			$containerCode = str_replace('RETURN_MM_NULL', 'RETURN_NULL', $containerCode);
			$containerCode = str_replace('RETURN_MM_BOOL', 'RETURN_BOOL', $containerCode);
			$containerCode = str_replace('RETURN_MM_FALSE', 'RETURN_FALSE', $containerCode);
			$containerCode = str_replace('RETURN_MM_TRUE', 'RETURN_TRUE', $containerCode);
			$containerCode = str_replace('RETURN_MM_STRING', 'RETURN_STRING', $containerCode);
			$containerCode = str_replace('RETURN_MM_LONG', 'RETURN_LONG', $containerCode);
			$containerCode = str_replace('RETURN_MM_DOUBLE', 'RETURN_DOUBLE', $containerCode);
			$containerCode = str_replace('RETURN_MM_FALSE', 'RETURN_FALSE', $containerCode);
			$containerCode = str_replace('RETURN_MM_EMPTY_STRING', 'RETURN_MM_EMPTY_STRING', $containerCode);
			$containerCode = str_replace('RETURN_MM_EMPTY_ARRAY', 'RETURN_EMPTY_ARRAY', $containerCode);
			$containerCode = str_replace('RETURN_MM()', 'return', $containerCode);
			$containerCode = preg_replace('/[ \t]+ZEPHIR_MM_RESTORE\(\);' . PHP_EOL . '/s', '', $containerCode);
		}
		return $containerCode;
	}

	/**
	 * Assigns a default value
	 *
	 * @param array $parameter
	 */
	public function assignDefaultValue($parameter, $compilationContext)
	{
		if (isset($parameter['data-type'])) {
			$dataType = $parameter['data-type'];
		} else {
			$dataType = 'variable';
		}

		$code = '';

		switch ($dataType) {
			case 'int':
				switch ($parameter['default']['type']) {
					case 'int':
						$code .= "\t\t" . $parameter['name'] . ' = ' . $parameter['default']['value'] . ';';
						break;
					case 'double':
						$code .= "\t\t" . $parameter['name'] . ' = (int) ' . $parameter['default']['value'] . ';';
						break;
					default:
						throw new CompilerException("Default parameter value type: " . $parameter['default']['type'] . " cannot be assigned to variable(int)", $parameter);
				}
				break;
			case 'bool':
				switch ($parameter['default']['type']) {
					case 'bool':
						if ($parameter['default']['value'] == 'true') {
							$code .= "\t\t" . $parameter['name'] . ' = 1;' . PHP_EOL;
						} else {
							$code .= "\t\t" . $parameter['name'] . ' = 0;' . PHP_EOL;
						}
						break;
					default:
						throw new CompilerException("Default parameter value type: " . $parameter['default']['type'] . " cannot be assigned to variable(int)", $parameter);
				}
				break;
			case 'variable':
				$compilationContext->headersManager->add('kernel/memory');
				$code .= "\t\t" . 'ZEPHIR_INIT_VAR(' . $parameter['name'] . ');' . PHP_EOL;
				switch ($parameter['default']['type']) {
					case 'int':
						$code .= "\t\t" . 'ZVAL_LONG(' . $parameter['name'] . ', ' . $parameter['default']['value'] . ');' . PHP_EOL;
						break;
					case 'double':
						$code .= "\t\t" . 'ZVAL_DOUBLE(' . $parameter['name'] . ', ' . $parameter['default']['value'] . ');' . PHP_EOL;
						break;
					case 'null':
						break;
					default:
						throw new CompilerException("Default parameter value type: " . $parameter['default']['type'] . " cannot be assigned to variable(variable)", $parameter);
				}
				break;
			default:
				throw new CompilerException("Default parameter type: " . $dataType, $parameter);
		}

		return $code;
	}

	/**
	 * Assigns zval value to static type
	 *
	 * @param array $parameter
	 */
	public function assignZvalValue($parameter, $compilationContext)
	{
		if (isset($parameter['data-type'])) {
			$dataType = $parameter['data-type'];
		} else {
			$dataType = 'variable';
		}

		switch ($dataType) {
			case 'int':
				$compilationContext->headersManager->add('kernel/operators');
				return "\t\t" . $parameter['name'] . ' = zephir_get_intval(' . $parameter['name'] . '_param);' . PHP_EOL;
			case 'bool':
				$compilationContext->headersManager->add('kernel/operators');
				return "\t\t" . $parameter['name'] . ' = zephir_get_boolval(' . $parameter['name'] . '_param);' . PHP_EOL;
			case 'double':
				$compilationContext->headersManager->add('kernel/operators');
				return "\t\t" . $parameter['name'] . ' = zephir_get_doubleval(' . $parameter['name'] . '_param);' . PHP_EOL;
			default:
				throw new CompilerException("Default parameter type: " . $dataType, $parameter);
		}
	}

	/**
	 * Compiles the method
	 *
	 * @param CompilationContext $compilationContext
	 */
	public function compile(CompilationContext $compilationContext)
	{

		/**
		 * This pass checks for zval variables than can be potentally
		 * used without allocate memory and memory tracking
		 * these variables are stored in the heap
		 */
		if (is_object($this->_statements)) {
			$localContext = new LocalContextPass();
			$localContext->pass($this->_statements);
		} else {
			$localContext = null;
		}

		/**
		 * Every method has its own symbol table
		 */
		$symbolTable = new SymbolTable();
		if ($localContext) {
			$symbolTable->setLocalContext($localContext);
		}

		$compilationContext->symbolTable = $symbolTable;

		$oldCodePrinter = $compilationContext->codePrinter;

		/**
		 * Change the code printer to a single method instance
		 */
		$codePrinter = new CodePrinter();
		$compilationContext->codePrinter = $codePrinter;

		if (is_object($this->_parameters)) {

			/**
			 * Round 1. Create variables in parameters in the symbol table
			 */
			foreach ($this->_parameters->getParameters() as $parameter) {

				$symbolParam = null;

				if (isset($parameter['data-type'])) {
					if ($parameter['data-type'] == 'variable') {
						$symbol = $symbolTable->addVariable($parameter['data-type'], $parameter['name']);
					} else {
						$symbol = $symbolTable->addVariable($parameter['data-type'], $parameter['name']);
						$symbolParam = $symbolTable->addVariable('variable', $parameter['name'] . '_param');
					}
				} else {
					$symbol = $symbolTable->addVariable('variable', $parameter['name']);
				}

				if (is_object($symbolParam)) {

					/**
					 * Parameters are marked as 'external'
					 */
					$symbolParam->setIsExternal(true);

					/**
					 * Assuming they're initialized
					 */
					$symbolParam->setIsInitialized(true);

					/**
					 * Initialize auxiliar parameter zvals to null
					 */
					$symbolParam->setMustInitNull(true);

				} else {
					if (isset($parameter['default'])) {
						if (isset($parameter['data-type'])) {
							if ($parameter['data-type'] == 'variable') {
								$symbol->setMustInitNull(true);
							}
						} else {
							$symbol->setMustInitNull(true);
						}
					}
				}

				/**
				 * Parameters are marked as 'external'
				 */
				$symbol->setIsExternal(true);

				/**
				 * Assuming they're initialized
				 */
				$symbol->setIsInitialized(true);
			}
		}

		/**
		 * Compile the block of statements if any
		 */
		if (is_object($this->_statements)) {
			$this->_statements->compile($compilationContext);
		}

		/**
		 * Fetch parameters from vm-top
		 */
		if (is_object($this->_parameters)) {

			$code = '';

			/**
			 * Round 2. Fetch the parameters in the method
			 */
			$params = array();
			$optionalParams = array();
			$numberRequiredParams = 0;
			$numberOptionalParams = 0;
			foreach ($this->_parameters->getParameters() as $parameter) {

				if (isset($parameter['data-type'])) {
					$dataType = $parameter['data-type'];
				} else {
					$dataType = 'variable';
				}

				if ($dataType == 'variable') {
					$params[] = '&' . $parameter['name'];
				} else {
					$params[] = '&' . $parameter['name'] . '_param';
				}

				if (isset($parameter['default'])) {
					$optionalParams[] = $parameter;
					$numberOptionalParams++;
				} else {
					$numberRequiredParams++;
				}
			}

			/**
			 * Fetch the parameters to zval pointers
			 */
			$codePrinter->preOutputBlankLine();
			$compilationContext->headersManager->add('kernel/memory');
			if ($symbolTable->getMustGrownStack()) {
				$code .= "\t" . 'zephir_fetch_params(1, ' . $numberRequiredParams . ', ' . $numberOptionalParams . ', ' . join(', ', $params) . ');' . PHP_EOL;
			} else {
				$code .= "\t" . 'zephir_fetch_params(0, ' . $numberRequiredParams . ', ' . $numberOptionalParams . ', ' . join(', ', $params) . ');' . PHP_EOL;
			}
			$code .= PHP_EOL;

			/**
			 * Initialize optional parameters
			 */
			foreach ($optionalParams as $parameter) {

				if (isset($parameter['data-type'])) {
					$dataType = $parameter['data-type'];
				} else {
					$dataType = 'variable';
				}

				if ($dataType == 'variable') {
					$name = $parameter['name'];
				} else {
					$name = $parameter['name'] . '_param';
				}

				/**
				 * Assign the default value according to the variable's type
				 */
				$code .= "\t" . 'if (!' . $name . ') {' . PHP_EOL;
				$code .= $this->assignDefaultValue($parameter, $compilationContext);
				if ($dataType == 'variable') {
					$code .= "\t" . '}' . PHP_EOL;
				} else {
					$code .= "\t" . '} else {' . PHP_EOL;
					$code .= $this->assignZvalValue($parameter, $compilationContext);
					$code .= "\t" . '}' . PHP_EOL;
				}
			}

			/**
			 * Pass the write detector to the statement block to check if the parameter
			 * variable is modified so as do the proper separation
			 */
			if (is_object($this->_statements)) {
				$writeDetector = new WriteDetector();
				foreach ($this->_parameters->getParameters() as $parameter) {

					if (isset($parameter['data-type'])) {
						$dataType = $parameter['data-type'];
					} else {
						$dataType = 'variable';
					}

					if ($dataType == 'variable') {
						if ($writeDetector->detect($parameter['name'], $this->_statements->getStatements())) {
							echo $parameter['name'];
						}
					}

				}
			}

			$codePrinter->preOutput($code);
		}

		/**
		 * Grow the stack if needed
		 */
		if ($symbolTable->getMustGrownStack()) {
			$compilationContext->headersManager->add('kernel/memory');
			$codePrinter->preOutput("\t" . 'ZEPHIR_MM_GROW();');
		}

		/**
		 * Check if there are unused variables
		 */
		$usedVariables = array();
		foreach ($symbolTable->getVariables() as $variable) {

			if ($variable->getNumberUses() <= 0) {
				echo 'Warning: Variable "' . $variable->getName() . '" declared but not used in ' .
					$compilationContext->classDefinition->getName() . '::' . $this->getName(), PHP_EOL;
				if ($variable->isExternal() == false) {
					continue;
				}
			}

			if ($variable->getName() != 'this_ptr') {
				$type = $variable->getType();
				if (!isset($usedVariables[$type])) {
					$usedVariables[$type] = array();
				}
				$usedVariables[$type][] = $variable;
			}
		}

		if (count($usedVariables)) {
			$codePrinter->preOutputBlankLine();
		}

		/**
		 * Generate the variable definition for variables used
		 */
		foreach ($usedVariables as $type => $variables) {

			$pointer = null;
			switch ($type) {
				case 'int':
					$code = 'long ';
					break;
				case 'bool':
					$code = 'zend_bool ';
					break;
				case 'double':
					$code = 'double ';
					break;
				case 'string':
					$compilationContext->headersManager->add('kernel/string_type');
					$pointer = '*';
					$code = 'zephir_str ';
					break;
				case 'variable':
					$pointer = '*';
					$code = 'zval ';
					break;
				case 'HashTable':
					$pointer = '*';
					$code = 'HashTable ';
					break;
				case 'HashPosition':
					$code = 'HashPosition ';
					break;
				default:
					throw new CompilerException("Unsupported type in declare: " . $type);
			}

			$groupVariables = array();
			foreach ($variables as $variable) {
				if (($type == 'variable' || $type == 'string') && $variable->mustInitNull()) {
					if ($variable->isLocalOnly()) {
						$groupVariables[] = $variable->getName();
					} else {
						if ($variable->isDoublePointer()) {
							$groupVariables[] = $pointer . $pointer . $variable->getName() . ' = NULL';
						} else {
							$groupVariables[] = $pointer . $variable->getName() . ' = NULL';
						}
					}
				} else {
					if ($variable->isLocalOnly()) {
						$groupVariables[] = $variable->getName();
					} else {
						if ($variable->isDoublePointer()) {
							$groupVariables[] = $pointer . $pointer . $variable->getName();
						} else {
							$groupVariables[] = $pointer . $variable->getName();
						}
					}
				}
			}

			$codePrinter->preOutput("\t" . $code . join(', ', $groupVariables) . ';');
		}

		/**
		 * Compile the block of statements if any
		 */
		if (is_object($this->_statements)) {
			if ($symbolTable->getMustGrownStack()) {
				if ($this->_statements->getLastStatementType() != 'return') {
					$compilationContext->headersManager->add('kernel/memory');
					$codePrinter->output("\t" . 'ZEPHIR_MM_RESTORE();');
				}
			}
		}

		/**
		 * Remove macros that restore the memory stack if it wasn't used
		 */
		$code = $this->removeMemoryStackReferences($symbolTable, $codePrinter->getOutput());

		/**
		 * Restore the compilation context
		 */
		$oldCodePrinter->output($code);
		$compilationContext->codePrinter = $oldCodePrinter;

		return null;
	}

}
