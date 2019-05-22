<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Backends\ZendEngine3;

use Zephir\BaseBackend;
use function Zephir\add_slashes;
use Zephir\ClassDefinition;
use Zephir\ClassMethod;
use Zephir\CodePrinter;
use Zephir\CompilationContext;
use Zephir\CompiledExpression;
use Zephir\Compiler;
use Zephir\Exception\CompilerException;
use Zephir\Fcall\FcallManagerInterface;
use Zephir\FunctionDefinition;
use Zephir\GlobalConstant;
use Zephir\Variable;

/**
 * Zephir\Backends\ZendEngine3\Backend.
 */
class Backend extends BaseBackend
{
    protected $name = 'ZendEngine3';

    /**
     * {@inheritdoc}
     *
     * @return bool
     */
    public function isZE3()
    {
        return true;
    }

    /**
     * {@inheritdoc}
     *
     * @return FcallManagerInterface
     */
    public function getFcallManager()
    {
        if (!$this->fcallManager) {
            $this->setFcallManager(new FcallManager());
        }

        return $this->fcallManager;
    }

    /**
     * {@inheritdoc}
     */
    public function getVariableCode(Variable $variable)
    {
        if ($variable->isDoublePointer() ||
            \in_array($variable->getName(), ['this_ptr', 'return_value']) ||
            \in_array($variable->getType(), ['int', 'long'])) {
            return $variable->getName();
        }

        return '&'.$variable->getName();
    }

    public function getBoolCode(Variable $variable, CompilationContext $context, $useCodePrinter = true)
    {
        $code = '(Z_TYPE_P('.$this->getVariableCode($variable).') == IS_TRUE)';
        if ($useCodePrinter) {
            $context->codePrinter->output($code);
        }

        return $code;
    }

    /**
     * {@inheritdoc}
     */
    public function getStringsManager()
    {
        return new StringsManager();
    }

    public function getTypeDefinition($type)
    {
        switch ($type) {
            case 'zend_ulong':
                return ['', 'zend_ulong'];

            case 'zend_string':
                return ['*', 'zend_string'];
        }

        $code = null;
        $pointer = null;
        switch ($type) {
            case 'int':
                $code = 'zend_long';
                break;

            case 'uint':
                $code = 'zend_ulong';
                break;

            case 'char':
                $code = 'char';
                break;

            case 'uchar':
                $code = 'unsigned char';
                break;

            case 'long':
                $code = 'long';
                break;

            case 'ulong':
                $code = 'unsigned long';
                break;

            case 'bool':
                $code = 'zend_bool';
                break;

            case 'double':
                $code = 'double';
                break;

            case 'string':
            case 'variable':
            case 'array':
            case 'null':
                $pointer = '*';
                $code = 'zval';
                break;

            case 'HashTable':
                $pointer = '*';
                $code = 'HashTable';
                break;

            case 'HashPosition':
                $code = 'HashPosition';
                break;

            case 'zend_class_entry':
                $pointer = '*';
                $code = 'zend_class_entry';
                break;

            case 'zend_function':
                $pointer = '*';
                $code = 'zend_function';
                break;

            case 'zend_object_iterator':
                $pointer = '*';
                $code = 'zend_object_iterator';
                break;

            case 'zend_property_info':
                $pointer = '*';
                $code = 'zend_property_info';
                break;

            case 'zephir_fcall_cache_entry':
                $pointer = '*';
                $code = 'zephir_fcall_cache_entry';
                break;

            case 'static_zephir_fcall_cache_entry':
                $pointer = '*';
                $code = 'zephir_fcall_cache_entry';
                break;

            case 'static_zend_class_entry':
                $pointer = '*';
                $code = 'zend_class_entry';
                break;

            case 'zephir_ce_guard':
                $code = 'zend_bool';
                break;

            default:
                throw new CompilerException('Unsupported type in declare: '.$type);
        }

        return [$pointer, $code];
    }

    /**
     * Checks the type of a variable using the ZendEngine constants.
     *
     * @param Variable           $variableVariable
     * @param string             $operator
     * @param string             $value
     * @param CompilationContext $context
     *
     * @throws CompilerException
     *
     * @return string
     */
    public function getTypeofCondition(Variable $variableVariable, $operator, $value, CompilationContext $context)
    {
        $variableName = $this->getVariableCode($variableVariable);

        switch ($value) {
            case 'array':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_ARRAY';
                break;

            case 'object':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_OBJECT';
                break;

            case 'null':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_NULL';
                break;

            case 'string':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_STRING';
                break;

            case 'int':
            case 'long':
            case 'integer':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_LONG';
                break;

            case 'double':
            case 'float':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_DOUBLE';
                break;

            case 'boolean':
            case 'bool':
                $condition = '((Z_TYPE_P('.$variableName.') == IS_TRUE || Z_TYPE_P('.$variableName.') == IS_FALSE) '.$operator.' 1)';
                break;

            case 'resource':
                $condition = 'Z_TYPE_P('.$variableName.') '.$operator.' IS_RESOURCE';
                break;

            case 'callable':
                $condition = 'zephir_is_callable('.$variableName.' TSRMLS_CC) '.$operator.' 1';
                break;

            default:
                throw new CompilerException('Unknown type: "'.$value.'" in typeof comparison', $expr['right']);
        }

        return $condition;
    }

    public function onPreInitVar(ClassMethod $method, CompilationContext $context)
    {
        if ($method instanceof FunctionDefinition) {
            return;
        }
        if (!$method->isInternal()) {
            return "zval *this_ptr = getThis();\n"; //TODO: think about a better way to solve this.
        }
    }

    public function onPreCompile(ClassMethod $method, CompilationContext $context)
    {
        $codePrinter = $context->codePrinter;
        /*
         * Initialize the properties within create_object, handler code
         */
        if (preg_match('/^zephir_init_properties/', $method->getName())) {
            $codePrinter->increaseLevel();
            $codePrinter->output('{');
            $codePrinter->increaseLevel();
            $codePrinter->output('zval local_this_ptr, *this_ptr = &local_this_ptr;');
            $codePrinter->output('ZEPHIR_CREATE_OBJECT(this_ptr, class_type);');
            $codePrinter->decreaseLevel();
        }
    }

    public function onPostCompile(ClassMethod $method, CompilationContext $context)
    {
        $codePrinter = $context->codePrinter;
        if (preg_match('/^zephir_init_properties/', $method->getName())) {
            $codePrinter->increaseLevel();
            $codePrinter->output('return Z_OBJ_P(this_ptr);');
            $codePrinter->decreaseLevel();
            $codePrinter->output('}');
            $codePrinter->decreaseLevel();
        }
    }

    public function generateInitCode(&$groupVariables, $type, $pointer, Variable $variable)
    {
        $isComplex = ('variable' == $type || 'string' == $type || 'array' == $type || 'resource' == $type || 'callable' == $type || 'object' == $type);

        if ($isComplex && !$variable->isDoublePointer()) { /* && $variable->mustInitNull() */
            $groupVariables[] = $variable->getName();
            switch ($variable->getRealname()) {
                case '__$null':
                    return "\t".'ZVAL_NULL(&'.$variable->getName().');';
                case '__$true':
                    return "\t".'ZVAL_BOOL(&'.$variable->getName().', 1);';
                case '__$false':
                    return "\t".'ZVAL_BOOL(&'.$variable->getName().', 0);';
                default:
                    return "\t".'ZVAL_UNDEF(&'.$variable->getName().');';
            }
        }

        if ($variable->isLocalOnly()) {
            $groupVariables[] = $variable->getName();

            return;
        }

        if ($variable->isSuperGlobal()) {
            $groupVariables[] = $variable->getName();

            return;
        }

        if ($variable->isDoublePointer()) {
            /* Double pointers for ZE3 are used as zval * */
            $ptr = $isComplex ? $pointer : $pointer.$pointer;
            if ($variable->mustInitNull()) {
                $groupVariables[] = $ptr.$variable->getName().' = NULL';
            } else {
                $groupVariables[] = $ptr.$variable->getName();
            }

            return;
        }

        $defaultValue = $variable->getDefaultInitValue();
        if (null !== $defaultValue) {
            switch ($type) {
                case 'variable':
                case 'string':
                case 'array':
                case 'resource':
                case 'callable':
                case 'object':
                    $groupVariables[] = $pointer.$variable->getName();
                    break;

                /* @noinspection PhpMissingBreakStatementInspection */
                case 'char':
                    if (\strlen($defaultValue) > 4) {
                        if (\strlen($defaultValue) > 10) {
                            throw new CompilerException("Invalid char literal: '".substr($defaultValue, 0, 10)."...'", $variable->getOriginal());
                        } else {
                            throw new CompilerException("Invalid char literal: '".$defaultValue."'", $variable->getOriginal());
                        }
                    }
                    /* no break */

                default:
                    $groupVariables[] = $pointer.$variable->getName().' = '.$defaultValue;
                    break;
            }

            return;
        }

        if ($variable->mustInitNull() && $pointer) {
            $groupVariables[] = $pointer.$variable->getName().' = NULL';

            return;
        }

        $groupVariables[] = $pointer.$variable->getName();
    }

    public function declareConstant($type, $name, $value, CompilationContext $context)
    {
        $ce = $context->classDefinition->getClassEntry($context);

        $dType = null;
        switch ($type) {
            case 'bool':
                $value = 'false' == $value ? '0' : 1;
                break;

            case 'long':
            case 'int':
                $dType = 'long';
                break;

            case 'double':
                break;

            case 'string':
            case 'char':
                if ('string' == $type || 'char' == $type) {
                    $value = '"'.add_slashes($value).'"';
                }
                $dType = 'string';
                break;
        }

        if (!isset($dType)) {
            $dType = $type;
        }

        if ('null' == $dType) {
            $context->codePrinter->output('zephir_declare_class_constant_null('.$ce.', SL("'.$name.'"));');
        } else {
            $context->codePrinter->output('zephir_declare_class_constant_'.$dType.'('.$ce.', SL("'.$name.'"), '.$value.');');
        }
    }

    public function declareVariables($method, $typeToVariables, CompilationContext $compilationContext)
    {
        $varInitCode = [];
        $additionalCode = ($method ? $this->onPreInitVar($method, $compilationContext) : '').PHP_EOL."\t".'ZEPHIR_MM_GROW();';

        foreach ($typeToVariables as $type => $variables) {
            list($pointer, $code) = $this->getTypeDefinition($type);
            $code .= ' ';
            $groupVariables = [];

            /*
             * @var Variable[]
             */
            foreach ($variables as $variable) {
                $nextCode = $this->generateInitCode($groupVariables, $type, $pointer, $variable);
                if ($nextCode && $additionalCode) {
                    $additionalCode .= PHP_EOL.$nextCode;
                } else {
                    $additionalCode .= $nextCode;
                }
            }

            $varInitCode[] = $code.implode(', ', $groupVariables).';';
        }
        /* Keep order consistent with previous zephir versions (BC-only) */
        $varInitCode = array_reverse($varInitCode);
        if ($additionalCode) {
            $varInitCode[] = $additionalCode;
        }

        return $varInitCode;
    }

    public function initializeVariableDefaults($variables, CompilationContext $compilationContext)
    {
        $codePrinter = new CodePrinter();
        $codePrinter->increaseLevel();
        $oldCodePrinter = $compilationContext->codePrinter;
        $compilationContext->codePrinter = $codePrinter;

        /* Initialize default values in dynamic variables */
        foreach ($variables as $variable) {
            /*
             * Initialize 'dynamic' variables with default values
             */
            if ('variable' == $variable->getType()) {
                if ($variable->getNumberUses() > 0) {
                    if ('this_ptr' != $variable->getName() && 'return_value' != $variable->getName() && 'return_value_ptr' != $variable->getName()) {
                        $defaultValue = $variable->getDefaultInitValue();
                        if (\is_array($defaultValue)) {
                            switch ($defaultValue['type']) {
                                case 'int':
                                case 'uint':
                                case 'long':
                                    $compilationContext->backend->assignLong($variable, $defaultValue['value'], $compilationContext);
                                    break;

                                case 'bool':
                                    $compilationContext->backend->assignBool($variable, $defaultValue['value'], $compilationContext);
                                    break;

                                case 'char':
                                case 'uchar':
                                    if (\strlen($defaultValue['value']) > 2) {
                                        if (\strlen($defaultValue['value']) > 10) {
                                            throw new CompilerException("Invalid char literal: '".substr($defaultValue['value'], 0, 10)."...'", $defaultValue);
                                        } else {
                                            throw new CompilerException("Invalid char literal: '".$defaultValue['value']."'", $defaultValue);
                                        }
                                    }
                                    $compilationContext->backend->assignLong($variable, '\''.$defaultValue['value'].'\'', $compilationContext);
                                    break;

                                case 'null':
                                    $compilationContext->backend->assignNull($variable, $compilationContext);
                                    break;

                                case 'double':
                                    $compilationContext->backend->assignDouble($variable, $defaultValue['value'], $compilationContext);
                                    break;

                                case 'string':
                                    $compilationContext->backend->assignString(
                                        $variable,
                                        add_slashes($defaultValue['value']),
                                        $compilationContext
                                    );
                                    break;

                                case 'array':
                                case 'empty-array':
                                    $compilationContext->backend->initArray($variable, $compilationContext, null);
                                    break;

                                default:
                                    throw new CompilerException('Invalid default type: '.$defaultValue['type'].' for data type: '.$variable->getType(), $variable->getOriginal());
                            }
                        }
                    }
                }
                continue;
            }

            /*
             * Initialize 'string' variables with default values
             */
            if ('string' == $variable->getType()) {
                if ($variable->getNumberUses() > 0) {
                    $defaultValue = $variable->getDefaultInitValue();
                    if (\is_array($defaultValue)) {
                        switch ($defaultValue['type']) {
                            case 'string':
                                $compilationContext->backend->assignString(
                                    $variable,
                                    add_slashes($defaultValue['value']),
                                    $compilationContext
                                );
                                break;

                            case 'null':
                                $compilationContext->backend->assignString($variable, null, $compilationContext);
                                break;

                            default:
                                throw new CompilerException('Invalid default type: '.$defaultValue['type'].' for data type: '.$variable->getType(), $variable->getOriginal());
                        }
                    }
                }
                continue;
            }

            /*
             * Initialize 'array' variables with default values
             */
            if ('array' == $variable->getType()) {
                if ($variable->getNumberUses() > 0) {
                    $defaultValue = $variable->getDefaultInitValue();
                    if (\is_array($defaultValue)) {
                        switch ($defaultValue['type']) {
                            case 'null':
                                $compilationContext->backend->assignNull($variable, $compilationContext);
                                break;

                            case 'array':
                            case 'empty-array':
                                $compilationContext->backend->initArray($variable, $compilationContext, null);
                                break;

                            default:
                                throw new CompilerException('Invalid default type: '.$defaultValue['type'].' for data type: '.$variable->getType(), $variable->getOriginal());
                        }
                    }
                }
            }
        }
        $compilationContext->codePrinter = $oldCodePrinter;

        return $codePrinter->getOutput();
    }

    public function initVar(Variable $variable, CompilationContext $context, $useCodePrinter = true, $second = false)
    {
        $code = 'ZEPHIR_INIT_VAR('.$this->getVariableCode($variable).');';
        if ($useCodePrinter) {
            $context->codePrinter->output($code);
        }

        return $code;
    }

    /**
     * Returns the signature of an internal method.
     */
    public function getInternalSignature(ClassMethod $method, CompilationContext $context)
    {
        if ($method->isInitializer() && !$method->isStatic()) {
            return 'zend_object *'.$method->getName().'(zend_class_entry *class_type TSRMLS_DC)';
        }

        if ($method->isInitializer() && $method->isStatic()) {
            return 'void '.$method->getName().'(TSRMLS_D)';
        }

        $signatureParameters = [];
        $parameters = $method->getParameters();
        if (\is_object($parameters)) {
            foreach ($parameters->getParameters() as $parameter) {
                switch ($parameter['data-type']) {
                    case 'int':
                    case 'uint':
                    case 'long':
                    case 'double':
                    case 'bool':
                    case 'char':
                    case 'uchar':
                    case 'string':
                    case 'array':
                        $signatureParameters[] = 'zval *'.$parameter['name'].'_param_ext';
                        break;

                    default:
                        $signatureParameters[] = 'zval *'.$parameter['name'].'_ext ';
                        break;
                }
            }
        }

        if (\count($signatureParameters)) {
            return 'void '.$method->getInternalName().'(int ht, zval *return_value, zval *this_ptr, int return_value_used, '.implode(', ', $signatureParameters).')';
        }

        return 'void '.$method->getInternalName().'(int ht, zval *return_value, zval *this_ptr, int return_value_used)';
    }

    /* Assign value to variable */
    public function assignString(Variable $variable, $value, CompilationContext $context, $useCodePrinter = true, $doCopy = null)
    {
        return $this->assignHelper('ZEPHIR_MM_ZVAL_STRING', $this->getVariableCode($variable), $value, $context, $useCodePrinter, null);
    }

    public function assignLong(Variable $variable, $value, CompilationContext $context, $useCodePrinter = true)
    {
        return $this->assignHelper('ZVAL_LONG', $this->getVariableCode($variable), $value, $context, $useCodePrinter);
    }

    public function assignDouble(Variable $variable, $value, CompilationContext $context, $useCodePrinter = true)
    {
        return $this->assignHelper('ZVAL_DOUBLE', $this->getVariableCode($variable), $value, $context, $useCodePrinter);
    }

    public function assignBool(Variable $variable, $value, CompilationContext $context, $useCodePrinter = true)
    {
        return $this->assignHelper('ZVAL_BOOL', $this->getVariableCode($variable), $value, $context, $useCodePrinter);
    }

    public function assignNull(Variable $variable, CompilationContext $context, $useCodePrinter = true)
    {
        $output = 'ZVAL_NULL('.$this->getVariableCode($variable).');';
        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $output;
    }

    /**
     * Assigns a zval to another.
     *
     * @param Variable           $variable
     * @param string             $code
     * @param CompilationContext $context
     */
    public function assignZval(Variable $variable, $code, CompilationContext $context)
    {
        $code = $this->resolveValue($code, $context);
        if (!$variable->isDoublePointer()) {
            $context->symbolTable->mustGrownStack(true);
            $symbolVariable = $this->getVariableCode($variable);
            $context->codePrinter->output('ZEPHIR_CPY_WRT('.$symbolVariable.', '.$code.');');
        } else {
            $context->codePrinter->output($variable->getName().' = '.$code.';');
        }
    }

    public function concatSelf(Variable $variable, Variable $itemVariable, CompilationContext $context)
    {
        $variable = $this->getVariableCode($variable);
        $itemVariable = $this->getVariableCode($itemVariable);
        $context->codePrinter->output('ZEPHIR_MM_CONCAT_SELF('.$variable.', '.$itemVariable.');');
    }

    public function returnString($value, CompilationContext $context, $useCodePrinter = true, $doCopy = true)
    {
        return $this->returnHelper('RETURN_MM_STRING', $value, $context, $useCodePrinter, null);
    }

    public function initArray(Variable $variable, CompilationContext $context, $size = null, $useCodePrinter = true)
    {
        if (!isset($size)) {
            $output = 'array_init('.$this->getVariableCode($variable).');';
        } else {
            $output = 'zephir_create_array('.$this->getVariableCode($variable).', '.$size.', 0);';
        }
        if ($useCodePrinter) {
            $context->codePrinter->output($output);
            $variable->addMemoryEntry($context);
        }
        if ('this_ptr' != $variable->getName() && 'return_value' != $variable->getName()) {
            $output .= PHP_EOL.'ZEPHIR_MM_ADD_ENTRY('.$this->getVariableCode($variable).');';
        }

        return $output;
    }

    public function createClosure(Variable $variable, $classDefinition, CompilationContext $context)
    {
        $symbol = $this->getVariableCode($variable);
        $context->codePrinter->output('zephir_create_closure_ex('.$symbol.', NULL, '.$classDefinition->getClassEntry().', SL("__invoke"));');
        $variable->addMemoryEntry($context);
    }

    public function addArrayEntry(Variable $variable, $key, $value, CompilationContext $context, $statement = null, $useCodePrinter = true)
    {
        $type = null;
        $keyType = 'assoc';

        if (!isset($key)) {
            $keyType = 'append';
        } elseif ($key instanceof CompiledExpression) {
            $typeKey = $key->getType();
            if ('variable' == $typeKey) {
                $var = $context->symbolTable->getVariableForRead($key->getCode(), $context);
                $typeKey = $var->getType();
            }
            if (\in_array($typeKey, ['int', 'uint', 'long', 'ulong'])) {
                $keyType = 'index';
            }
        }
        if ('null' == $value) {
            if (!isset($key)) {
                $value = $this->resolveValue('null', $context);
                $context->codePrinter->output('zephir_array_append('.$this->getVariableCode($variable).', '.$value.', 0, "'.Compiler::getShortUserPath($statement['file']).'", '.$statement['line'].');');

                return;
            }
        }

        switch ($value->getType()) {
            case 'int':
            case 'uint':
            case 'long':
            case 'ulong':
                $type = 'long';
                break;

            case 'double':
                $type = 'double';
                break;

            case 'string':
                $type = 'stringl';
                break;

            case 'variable':
            case 'array':
                $type = 'zval';
                break;
        }

        if (null === $type) {
            throw new CompilerException('Unknown type mapping: '.$value->getType());
        }

        if (isset($key)) {
            if ('variable' == $key->getType()) {
                $var = $context->symbolTable->getVariableForRead($key->getCode(), $context);
                $keyStr = 'string' == $typeKey ? 'Z_STRVAL_P('.$this->getVariableCode($var).'), Z_STRLEN_P('.$this->getVariableCode($var).')' : $this->getVariableCode($var);
            } else {
                $keyStr = 'string' == $key->getType() ? 'SL("'.$key->getCode().'")' : $key->getCode();
            }
        }

        if ('stringl' == $type) {
            if ($value instanceof Variable) {
                $valueStr = 'Z_STRVAL_P('.$this->getVariableCode($value).'), Z_STRLEN_P('.$this->getVariableCode($value).')';
            } else {
                $valueStr = 'SL("'.$value->getCode().'")';
            }
        } elseif ('zval' == $type) {
            $valueStr = $this->getVariableCode($value);
        } else {
            $valueStr = $value->getCode();
        }

        if ('assoc' == $keyType) {
            $output = 'add_assoc_'.$type.'_ex('.$this->getVariableCode($variable).', '.$keyStr.', '.$valueStr.');';
        } elseif ('append' == $keyType) {
            $output = 'zephir_array_append('.$this->getVariableCode($variable).', '.$this->resolveValue($value, $context).', PH_SEPARATE, "'.Compiler::getShortUserPath($statement['file']).'", '.$statement['line'].');';
        } else {
            $output = 'add_index_'.$type.'('.$this->getVariableCode($variable).', '.$keyStr.', '.$valueStr.');';
        }

        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $output;
    }

    public function updateArray(Variable $symbolVariable, $key, $value, CompilationContext $compilationContext, $flags = null)
    {
        $value = $this->resolveValue($value, $compilationContext, true);
        if (!isset($flags)) {
            $flags = 'PH_SEPARATE';
        }

        if ($key instanceof Variable) {
            switch ($key->getType()) {
                case 'string':
                case 'variable':
                    $compilationContext->codePrinter->output('zephir_array_update_zval('.$this->getVariableCode($symbolVariable).', '.$this->getVariableCode($key).', '.$value.', '.$flags.');');
                    break;

                case 'int':
                case 'uint':
                case 'long':
                    $compilationContext->codePrinter->output('zephir_array_update_long('.$this->getVariableCode($symbolVariable).', '.$key->getName().', '.$value.', '.$flags.' ZEPHIR_DEBUG_PARAMS_DUMMY);');
                    break;

                default:
                    throw new CompilerException('updateArray: Found a variable with unsupported type '.$key->getType());
            }
        } elseif ($key instanceof CompiledExpression) {
            switch ($key->getType()) {
                case 'string':
                    $compilationContext->codePrinter->output('zephir_array_update_string('.$this->getVariableCode($symbolVariable).', SL("'.$key->getCode().'"), '.$value.', '.$flags.');');
                    break;

                case 'int':
                    $compilationContext->codePrinter->output('zephir_array_update_long('.$this->getVariableCode($symbolVariable).', '.$key->getCode().', '.$value.', '.$flags.' ZEPHIR_DEBUG_PARAMS_DUMMY);');
                    break;

                case 'variable':
                    $this->updateArray($symbolVariable, $compilationContext->symbolTable->getVariableForRead($key->getCode()), $value, $compilationContext, $flags);
                    break;

                default:
                    throw new CompilerException('updateArray: Found an expression with unsupported type '.$key->getType());
            }
        } else {
            throw new CompilerException('?');
        }
    }

    public function initObject(Variable $variable, $ce, CompilationContext $context, $useCodePrinter = true)
    {
        $variableAccess = $this->getVariableCode($variable);
        if (!isset($ce)) {
            $output = 'object_init('.$variableAccess.');';
        } else {
            $output = 'object_init_ex('.$variableAccess.', '.$ce.');';
        }

        if ('this_ptr' != $variable->getName() && 'return_value' != $variable->getName()) {
            $output .= 'ZEPHIR_MM_ADD_ENTRY('.$variableAccess.');';
        }

        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $output;
    }

    public function arrayFetch(Variable $var, Variable $src, $index, $flags, $arrayAccess, CompilationContext $context, $useCodePrinter = true)
    {
        $context->headersManager->add('kernel/array');
        $isVariable = $index instanceof Variable;

        switch ($index->getType()) {
            case 'int':
            case 'uint':
            case 'long':
                $type = 'long';
                break;

            /* Types which map to the same */
            case 'variable':
            case 'string':
                $type = $index->getType();
                break;

            default:
                throw new CompilerException(
                    sprintf('Variable type: %s cannot be used as array index without cast', $index->getType()),
                    $arrayAccess['right']
                );
        }
        if ($isVariable && \in_array($index->getType(), ['variable', 'string'])) {
            $output = 'zephir_array_fetch('.$this->getVariableCode($var).', '.$this->getVariableCode($src).', '.$this->getVariableCode($index).', '.$flags.', "'.Compiler::getShortUserPath($arrayAccess['file']).'", '.$arrayAccess['line'].' TSRMLS_CC);';
        } else {
            if ($isVariable) {
                $indexAccess = $this->getVariableCode($index);
            } else {
                $indexAccess = $index->getCode();
                if ('string' == $type) {
                    $indexAccess = 'SL("'.$indexAccess.'")';
                }
            }
            $output = 'zephir_array_fetch_'.$type.'('.$this->getVariableCode($var).', '.$this->getVariableCode($src).', '.$indexAccess.', '.$flags.', "'.Compiler::getShortUserPath($arrayAccess['file']).'", '.$arrayAccess['line'].' TSRMLS_CC);';
        }

        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $output;
    }

    public function arrayIsset(Variable $var, $resolvedExpr, $expression, CompilationContext $context)
    {
        if (!($resolvedExpr instanceof Variable)) {
            if ('string' == $resolvedExpr->getType()) {
                return new CompiledExpression('bool', 'zephir_array_isset_string('.$this->getVariableCode($var).', SL("'.$resolvedExpr->getCode().'"))', $expression);
            } else {
                return new CompiledExpression('bool', 'zephir_array_isset_long('.$this->getVariableCode($var).', '.$resolvedExpr->getCode().')', $expression);
            }
        }

        if ('int' == $resolvedExpr->getType() || 'long' == $resolvedExpr->getType()) {
            return new CompiledExpression('bool', 'zephir_array_isset_long('.$this->getVariableCode($var).', '.$this->getVariableCode($resolvedExpr).')', $expression);
        } elseif ('variable' == $resolvedExpr->getType() || 'string' == $resolvedExpr->getType()) {
            return new CompiledExpression('bool', 'zephir_array_isset('.$this->getVariableCode($var).', '.$this->getVariableCode($resolvedExpr).')', $expression);
        }

        throw new CompilerException('['.$resolvedExpr->getType().']', $expression);
    }

    public function arrayIssetFetch(Variable $target, Variable $var, $resolvedExpr, $flags, $expression, CompilationContext $context)
    {
        $code = $this->getVariableCode($target).', '.$this->getVariableCode($var);
        if (!($resolvedExpr instanceof Variable)) {
            if ('string' == $resolvedExpr->getType()) {
                return new CompiledExpression('bool', 'zephir_array_isset_string_fetch('.$code.', SL("'.$resolvedExpr->getCode().'"), '.$flags.')', $expression);
            } elseif (\in_array($resolvedExpr->getType(), ['int', 'uint', 'long'])) {
                return new CompiledExpression('bool', 'zephir_array_isset_long_fetch('.$code.', '.$resolvedExpr->getCode().', '.$flags.')', $expression);
            } else {
                $resolvedExpr = $context->symbolTable->getVariableForRead($resolvedExpr->getCode(), $context);
            }
        }

        if ('int' == $resolvedExpr->getType() || 'long' == $resolvedExpr->getType()) {
            return new CompiledExpression('bool', 'zephir_array_isset_long_fetch('.$code.', '.$this->getVariableCode($resolvedExpr).', '.$flags.')', $expression);
        } elseif ('variable' == $resolvedExpr->getType() || 'string' == $resolvedExpr->getType()) {
            return new CompiledExpression('bool', 'zephir_array_isset_fetch('.$code.', '.$this->getVariableCode($resolvedExpr).', '.$flags.')', $expression);
        }
        throw new CompilerException('arrayIssetFetch ['.$resolvedExpr->getType().']', $expression);
    }

    public function propertyIsset(Variable $var, $key, CompilationContext $context)
    {
        return new CompiledExpression('bool', 'zephir_isset_property('.$this->getVariableCode($var).', SL("'.$key.'"))', null);
    }

    public function arrayUnset(Variable $variable, $exprIndex, $flags, CompilationContext $context)
    {
        $context->headersManager->add('kernel/array');
        $variableCode = $this->getVariableCode($variable);
        switch ($exprIndex->getType()) {
            case 'int':
            case 'uint':
            case 'long':
                $context->codePrinter->output('zephir_array_unset_long('.$variableCode.', '.$exprIndex->getCode().', '.$flags.');');
                break;

            case 'string':
                $context->codePrinter->output('zephir_array_unset_string('.$variableCode.', SL("'.$exprIndex->getCode().'"), '.$flags.');');
                break;

            case 'variable':
                $variableIndex = $context->symbolTable->getVariableForRead($exprIndex->getCode(), $context, $exprIndex->getOriginal());
                $indexCode = $this->getVariableCode($variableIndex);
                switch ($variableIndex->getType()) {
                    case 'int':
                    case 'uint':
                    case 'long':
                        $context->codePrinter->output('zephir_array_unset_long('.$variableCode.', '.$indexCode.', '.$flags.');');
                        break;

                    case 'string':
                    case 'variable':
                        $context->codePrinter->output('zephir_array_unset('.$variableCode.', '.$indexCode.', '.$flags.');');
                        break;

                    default:
                        throw new CompilerException('Variable type: '.$variableIndex->getType().' cannot be used as array index without cast', $expression['right']);
                }
                break;

            default:
                throw new CompilerException('Cannot use expression: '.$exprIndex->getType().' as array index without cast', $expression['right']);
        }
    }

    public function assignArrayMulti(Variable $variable, $symbolVariable, $offsetExprs, CompilationContext $compilationContext)
    {
        list($keys, $offsetItems, $numberParams) = $this->resolveOffsetExprs($offsetExprs, $compilationContext);

        $symbol = $this->resolveValue($symbolVariable, $compilationContext, true);
        $varCode = $this->getVariableCode($variable);
        $compilationContext->codePrinter->output('zephir_array_update_multi('.$varCode.', '.$symbol.', SL("'.$keys.'"), '.$numberParams.', '.implode(', ', $offsetItems).');');
    }

    public function assignPropertyArrayMulti(Variable $variable, $valueVariable, $propertyName, $offsetExprs, CompilationContext $compilationContext)
    {
        list($keys, $offsetItems, $numberParams) = $this->resolveOffsetExprs($offsetExprs, $compilationContext);
        $valueVariable = $this->resolveValue($valueVariable, $compilationContext, true);

        $compilationContext->codePrinter->output('zephir_update_property_array_multi('.$variable->getName().', SL("'.$propertyName.'"), '.$valueVariable.', SL("'.$keys.'"), '.$numberParams.', '.implode(', ', $offsetItems).');');
    }

    public function assignStaticPropertyArrayMulti($classEntry, $valueVariable, $propertyName, $offsetExprs, CompilationContext $compilationContext)
    {
        list($keys, $offsetItems, $numberParams) = $this->resolveOffsetExprs($offsetExprs, $compilationContext);
        $valueVariable = $this->resolveValue($valueVariable, $compilationContext, true);

        $offsetStr = $offsetItems ? ', '.implode(', ', $offsetItems) : '';
        $compilationContext->codePrinter->output('zephir_update_static_property_array_multi_ce('.$classEntry.', SL("'.$propertyName.'"), '.$valueVariable.' TSRMLS_CC, SL("'.$keys.'"), '.$numberParams.$offsetStr.');');
    }

    public function fetchGlobal(Variable $globalVar, CompilationContext $compilationContext, $useCodePrinter = true)
    {
        $name = $globalVar->getName();
        $output = strtr('zephir_get_global(&:name, SL(":name"));', [':name' => $name]);
        if ($useCodePrinter) {
            $compilationContext->codePrinter->output($output);
        }

        return $output;
    }

    public function fetchClass(Variable $zendClassEntry, $className, $guarded, CompilationContext $context)
    {
        $context->headersManager->add('kernel/object');
        if ($guarded) {
            $context->codePrinter->output('if (!'.$zendClassEntry->getName().') {');
        }
        $context->codePrinter->output($zendClassEntry->getName().' = zephir_fetch_class_str_ex('.$className.', ZEND_FETCH_CLASS_AUTO);');
        if ($guarded) {
            $context->codePrinter->output('}');
        }
    }

    public function fetchProperty(Variable $symbolVariable, Variable $variableVariable, $property, $readOnly, CompilationContext $context, $useOptimized = false)
    {
        $flags = 'PH_NOISY_CC';
        if ($readOnly) {
            $flags .= ' | PH_READONLY';
        }
        $variableCode = $this->getVariableCode($variableVariable);
        $symbol = $this->getVariableCode($symbolVariable);
        //TODO: maybe optimizations (read_nproperty/quick) for thisScope access in NG (as in ZE2 - if necessary)
        if ($property instanceof Variable) {
            $context->codePrinter->output('zephir_read_property_zval('.$symbol.', '.$variableCode.', '.$this->getVariableCode($property).', '.$flags.');');
        } else {
            $context->codePrinter->output('zephir_read_property('.$symbol.', '.$variableCode.', SL("'.$property.'"), '.$flags.');');
        }
        if (!$readOnly) {
            $symbolVariable->addMemoryEntry($context);
        }
    }

    /**
     * @param Variable        $symbolVariable
     * @param ClassDefinition $classDefinition
     * @param $property
     * @param bool               $readOnly
     * @param CompilationContext $context
     */
    public function fetchStaticProperty(Variable $symbolVariable, $classDefinition, $property, $readOnly, CompilationContext $context)
    {
        // TODO: maybe optimizations as well as above
        $context->codePrinter->output(
            sprintf(
                'zephir_read_static_property_ce(%s%s, %s, SL("%s"), PH_NOISY_CC%s);',
                $symbolVariable->isDoublePointer() ? '' : '&',
                $symbolVariable->getName(),
                $classDefinition->getClassEntry(),
                $property,
                $readOnly ? ' | PH_READONLY' : ''
            )
        );
    }

    /**
     * @param $value
     * @param CompilationContext $context
     * @param bool               $usePointer
     *
     * @throws CompilerException
     *
     * @return bool|string|Variable
     */
    public function resolveValue($value, CompilationContext $context, $usePointer = false)
    {
        if ($value instanceof GlobalConstant) {
            switch ($value->getName()) {
                case 'ZEPHIR_GLOBAL(global_null)':
                    $value = 'null';
                    break;
                case 'ZEPHIR_GLOBAL(global_true)':
                    $value = 'true';
                    break;
                case 'ZEPHIR_GLOBAL(global_false)':
                    $value = 'false';
                    break;
                default:
                    throw new CompilerException(
                        $this->name.': Unknown constant '.$value->getName()
                    );
            }
        }

        if ('null' == $value || 'true' == $value || 'false' == $value) {
            $varName = '__$'.$value;
            if (!$context->symbolTable->hasVariable($varName)) {
                $tempVariable = new Variable('variable', $varName, $context->branchManager->getCurrentBranch());
                $context->symbolTable->addRawVariable($tempVariable);
            }
            $tempVariable = $context->symbolTable->getVariableForWrite($varName, $context);
            $tempVariable->increaseUses();
            $tempVariable->setUsed(true, null);
            if ('null' == $value) {
                $tempVariable->setDynamicTypes('null');
            } else {
                $tempVariable->setDynamicTypes('bool');
            }
            $value = $this->getVariableCode($tempVariable);
        } else {
            if ($value instanceof CompiledExpression) {
                if ('array' == $value->getType()) {
                    $value = $context->symbolTable->getVariableForWrite($value->getCode(), $context, null);
                } elseif ('variable' == $value->getType()) {
                    $value = $context->symbolTable->getVariableForWrite($value->getCode(), $context);
                } else {
                    return $value->getCode();
                }
            }
        }

        if ($value instanceof Variable) {
            $value = $this->getVariableCode($value);
        }

        return $value;
    }

    public function updateProperty(Variable $symbolVariable, $propertyName, $value, CompilationContext $context)
    {
        //TODO: maybe optimizations as well as above
        $value = $this->resolveValue($value, $context);
        if ($propertyName instanceof Variable) {
            $context->codePrinter->output('zephir_update_property_zval_zval('.$this->getVariableCode($symbolVariable).', '.$this->getVariableCode($propertyName).', '.$value.' TSRMLS_CC);');
        } else {
            $context->codePrinter->output('zephir_update_property_zval('.$this->getVariableCode($symbolVariable).', SL("'.$propertyName.'"), '.$value.');');
        }
    }

    public function updateStaticProperty($classEntry, $property, $value, CompilationContext $context)
    {
        $value = $this->resolveValue($value, $context);
        $context->codePrinter->output('zephir_update_static_property('.$classEntry.', ZEND_STRL("'.$property.'"), '.$value.');');
    }

    public function assignArrayProperty(Variable $variable, $property, $key, $value, CompilationContext $context)
    {
        $resolveValue = $this->resolveValue($value, $context);
        if (isset($key)) {
            $context->codePrinter->output('zephir_update_property_array('.$this->getVariableCode($variable).', SL("'.$property.'"), '.$this->getVariableCode($key).', '.$resolveValue.');');
        } else {
            $context->codePrinter->output('zephir_update_property_array_append('.$this->getVariableCode($variable).', SL("'.$property.'"), '.$resolveValue.');');
        }
        if (\is_object($value) && $value instanceof Variable && $value->isTemporal()) {
            $value->initVariant($context);
        }
    }

    public function checkConstructor(Variable $var, CompilationContext $context)
    {
        $context->codePrinter->output('if (zephir_has_constructor('.$this->getVariableCode($var).' TSRMLS_CC)) {');
    }

    public function callMethod($symbolVariable, Variable $variable, $methodName, $cachePointer, $params, CompilationContext $context)
    {
        $paramStr = null != $params ? ', '.implode(', ', $params) : '';
        $macro = 'CALL_METHOD';
        if ($methodName instanceof Variable) {
            $macro = 'CALL_METHOD_ZVAL';
            $methodName = $this->getVariableCode($methodName);
        } else {
            $methodName = '"'.$methodName.'"';
        }
        if (!isset($symbolVariable)) {
            $context->codePrinter->output('ZEPHIR_'.$macro.'(NULL, '.$this->getVariableCode($variable).', '.$methodName.', '.$cachePointer.$paramStr.');');
        } elseif ('return_value' == $symbolVariable->getName()) {
            $context->codePrinter->output('ZEPHIR_RETURN_'.$macro.'('.$this->getVariableCode($variable).', '.$methodName.', '.$cachePointer.$paramStr.');');
        } else {
            $symbol = $this->getVariableCode($symbolVariable);
            $context->codePrinter->output('ZEPHIR_'.$macro.'('.$symbol.', '.$this->getVariableCode($variable).', '.$methodName.', '.$cachePointer.$paramStr.');');
        }
    }

    public function callDynamicFunction($symbolVariable, Variable $variable, CompilationContext $context, $params = [], $cache = 'NULL', $cacheSlot = 0)
    {
        $paramStr = null != $params ? ', '.implode(', ', $params) : '';
        if (!isset($symbolVariable)) {
            $context->codePrinter->output('ZEPHIR_CALL_ZVAL_FUNCTION(NULL, '.$this->getVariableCode($variable).', '.$cache.', '.$cacheSlot.$paramStr.');');
        } elseif ('return_value' == $symbolVariable->getName()) {
            $context->codePrinter->output('ZEPHIR_RETURN_CALL_ZVAL_FUNCTION('.$this->getVariableCode($variable).', '.$cache.', '.$cacheSlot.$paramStr.');');
        } else {
            $context->codePrinter->output('ZEPHIR_CALL_ZVAL_FUNCTION('.$this->getVariableCode($symbolVariable).', '.$this->getVariableCode($variable).', '.$cache.', '.$cacheSlot.$paramStr.');');
        }
    }

    public function zvalOperator($zvalOperator, Variable $expected, Variable $variableLeft, Variable $variableRight, CompilationContext $compilationContext)
    {
        $expected = $this->getVariableCode($expected);
        $op1 = $this->getVariableCode($variableLeft);
        $op2 = $this->getVariableCode($variableRight);

        $params = ' TSRMLS_CC';
        if ('zephir_add_function' == $zvalOperator || 'zephir_sub_function' == $zvalOperator) {
            $params = '';
        }
        $compilationContext->codePrinter->output($zvalOperator.'('.$expected.', '.$op1.', '.$op2.$params.');');
    }

    public function maybeSeparate(Variable $variableTempSeparated, Variable $variable, CompilationContext $context)
    {
        $context->codePrinter->output($variableTempSeparated->getName().' = zephir_maybe_separate_zval('.$this->getVariableCode($variable).');');
    }

    public function setSymbolIfSeparated(Variable $variableTempSeparated, Variable $variable, CompilationContext $context)
    {
        $context->codePrinter->output('if ('.$variableTempSeparated->getName().') {');
        $context->codePrinter->output("\t".'ZEPHIR_SET_SYMBOL(&EG(symbol_table), "'.$variable->getName().'", &'.$variable->getName().');');
        $context->codePrinter->output('}');
    }

    public function copyOnWrite(Variable $target, $var, CompilationContext $context)
    {
        if ('EG(exception)' == $var) {
            $context->codePrinter->output('ZVAL_OBJ('.$this->getVariableCode($target).', EG(exception));');
            $context->codePrinter->output('Z_ADDREF_P('.$this->getVariableCode($target).');');

            return;
        }
		$context->codePrinter->output('ZEPHIR_CPY_WRT('.$this->getVariableCode($target).', '.$this->resolveValue($var, $context).');');
    }

    public function forStatement(Variable $exprVariable, $keyVariable, $variable, $duplicateKey, $duplicateHash, $statement, $statementBlock, CompilationContext $compilationContext)
    {
        /*
         * Create a temporary zval to fetch the items from the hash.
         */
        $compilationContext->headersManager->add('kernel/fcall');
        $compilationContext->symbolTable->mustGrownStack(true);
        if (!$compilationContext->symbolTable->hasVariable('ZEPHIR_LAST_CALL_STATUS')) {
            $callStatus = new Variable('int', 'ZEPHIR_LAST_CALL_STATUS', $compilationContext->branchManager->getCurrentBranch());
            $callStatus->setIsInitialized(true, $compilationContext);
            $callStatus->increaseUses();
            $callStatus->setReadOnly(true);
            $compilationContext->symbolTable->addRawVariable($callStatus);
        }
        $tempVariable = $compilationContext->symbolTable->addTemp('variable', $compilationContext);
        $tempVariable->setIsDoublePointer(true);
        $tempValidVariable = $compilationContext->symbolTable->addTemp('variable', $compilationContext);
        $codePrinter = $compilationContext->codePrinter;

        $codePrinter->output('zephir_is_iterable('.$this->getVariableCode($exprVariable).', '.$duplicateHash.', "'.Compiler::getShortUserPath($statement['file']).'", '.$statement['line'].');');

        $codePrinter->output('if (Z_TYPE_P('.$this->getVariableCode($exprVariable).') == IS_ARRAY) {');
        $codePrinter->increaseLevel();

        $macro = null;
        $reverse = $statement['reverse'] ? 'REVERSE_' : '';

        if (isset($keyVariable)) {
            $arrayNumKey = $compilationContext->symbolTable->addTemp('zend_ulong', $compilationContext);
            $arrayStrKey = $compilationContext->symbolTable->addTemp('zend_string', $compilationContext);
        }

        if (isset($keyVariable) && isset($variable)) {
            $macro = 'ZEND_HASH_'.$reverse.'FOREACH_KEY_VAL';
            $codePrinter->output($macro.'(Z_ARRVAL_P('.$this->getVariableCode($exprVariable).'), '.$arrayNumKey->getName().', '.$arrayStrKey->getName().', '.$tempVariable->getName().')');
        } elseif (isset($keyVariable)) {
            $macro = 'ZEND_HASH_'.$reverse.'FOREACH_KEY';
            $codePrinter->output($macro.'(Z_ARRVAL_P('.$this->getVariableCode($exprVariable).'), '.$arrayNumKey->getName().', '.$arrayStrKey->getName().')');
        } else {
            $macro = 'ZEND_HASH_'.$reverse.'FOREACH_VAL';
            $codePrinter->output($macro.'(Z_ARRVAL_P('.$this->getVariableCode($exprVariable).'), '.$tempVariable->getName().')');
        }

        $codePrinter->output('{');

        if (isset($keyVariable)) {
            $codePrinter->increaseLevel();
            if ($duplicateKey) {
                $compilationContext->symbolTable->mustGrownStack(true);
                $keyVariable->initVariant($compilationContext);
            }
            $codePrinter->output('if ('.$arrayStrKey->getName().' != NULL) { ');
            $codePrinter->increaseLevel();
            if ($duplicateKey) {
                $codePrinter->output('ZVAL_STR_COPY('.$this->getVariableCode($keyVariable).', '.$arrayStrKey->getName().');');
            } else {
                $codePrinter->output('ZVAL_STR('.$this->getVariableCode($keyVariable).', '.$arrayStrKey->getName().');');
            }
            $codePrinter->decreaseLevel();
            $codePrinter->output('} else {');
            $codePrinter->increaseLevel();
            $codePrinter->output('ZVAL_LONG('.$this->getVariableCode($keyVariable).', '.$arrayNumKey->getName().');');
            $codePrinter->decreaseLevel();
            $codePrinter->output('}');
            $codePrinter->decreaseLevel();
        }

        if (isset($variable)) {
            $compilationContext->symbolTable->mustGrownStack(true);
            $codePrinter->increaseLevel();
            $variable->initVariant($compilationContext);
            $codePrinter->output('ZEPHIR_CPY_WRT('.$this->getVariableCode($variable).', '.$this->getVariableCode($tempVariable).');');
            $codePrinter->decreaseLevel();
        }

        /*
         * Compile statements in the 'for' block
         */
        if (isset($statement['statements'])) {
            $statementBlock->isLoop(true);
            if (isset($statement['key'])) {
                $statementBlock->getMutateGatherer()->increaseMutations($statement['key']);
            }
            $statementBlock->getMutateGatherer()->increaseMutations($statement['value']);
            $statementBlock->compile($compilationContext);
        }

        $codePrinter->output('} ZEND_HASH_FOREACH_END();');
        $codePrinter->decreaseLevel();

        $codePrinter->output('} else {');
        $codePrinter->increaseLevel();

        $codePrinter->output('ZEPHIR_CALL_METHOD(NULL, '.$this->getVariableCode($exprVariable).', "rewind", NULL, 0);');
        $codePrinter->output('zephir_check_call_status();');

        $codePrinter->output('while (1) {');
        $codePrinter->increaseLevel();

        $codePrinter->output('ZEPHIR_CALL_METHOD(&'.$tempValidVariable->getName().', '.$this->getVariableCode($exprVariable).', "valid", NULL, 0);');
        $codePrinter->output('zephir_check_call_status();');
        $codePrinter->output('if (!zend_is_true(&'.$tempValidVariable->getName().')) {');
        $codePrinter->increaseLevel();
        $codePrinter->output('break;');
        $codePrinter->decreaseLevel();
        $codePrinter->output('}');

        if (isset($keyVariable)) {
            $codePrinter->output('ZEPHIR_CALL_METHOD('.$this->getVariableCode($keyVariable).', '.$this->getVariableCode($exprVariable).', "key", NULL, 0);');
            $codePrinter->output('zephir_check_call_status();');
        }

        if (isset($variable)) {
            $codePrinter->output('ZEPHIR_CALL_METHOD('.$this->getVariableCode($variable).', '.$this->getVariableCode($exprVariable).', "current", NULL, 0);');
            $codePrinter->output('zephir_check_call_status();');
        }

        if (isset($statement['statements'])) {
            $statementBlock->isLoop(true);
            if (isset($statement['key'])) {
                $statementBlock->getMutateGatherer()->increaseMutations($statement['key']);
            }
            $statementBlock->getMutateGatherer()->increaseMutations($statement['value']);
            $statementBlock->compile($compilationContext);
        }

        $codePrinter->output('ZEPHIR_CALL_METHOD(NULL, '.$this->getVariableCode($exprVariable).', "next", NULL, 0);');
        $codePrinter->output('zephir_check_call_status();');

        $codePrinter->decreaseLevel();
        $codePrinter->output('}');

        $codePrinter->decreaseLevel();
        $codePrinter->output('}');

        /* Since we do not observe, still do cleanup */
        if (isset($variable)) {
            $variable->initVariant($compilationContext);
        }
        if (isset($keyVariable)) {
            $keyVariable->initVariant($compilationContext);
        }
    }

    public function forStatementIterator(Variable $iteratorVariable, Variable $targetVariable, CompilationContext $compilationContext)
    {
        $compilationContext->symbolTable->mustGrownStack(true);
        $compilationContext->codePrinter->output('ZEPHIR_ITERATOR_COPY('.$this->getVariableCode($targetVariable).', '.$iteratorVariable->getName().');');
    }

    public function destroyIterator(Variable $iteratorVariable, CompilationContext $context)
    {
        $context->codePrinter->output('zend_iterator_dtor('.$iteratorVariable->getName().');');
    }

    public function ifVariableValueUndefined(Variable $var, CompilationContext $context, $useBody = false, $useCodePrinter = true)
    {
        if ($var->isDoublePointer()) {
            $body = '!'.$var->getName();
            $output = 'if ('.$body.') {';
            if ($useCodePrinter) {
                $context->codePrinter->output($output);
            }
            return $useBody ? $body : $output;
        }
        $body = 'Z_TYPE_P('.$this->getVariableCode($var).') == IS_UNDEF';
        $output = 'if ('.$body.') {';
        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $useBody ? $body : $output;
    }

    public function checkStrictType($type, $var, CompilationContext $context)
    {
        $codePrinter = $context->codePrinter;
        $conditions = [];

        $inputParamVariable = $context->symbolTable->getVariableForWrite($var['name'], $context);
        $inputParamCode = $this->getVariableCode($inputParamVariable);
        $cond = 'Z_TYPE_P('.$inputParamCode.') != ';
        if ($context->symbolTable->hasVariable($var['name'].'_param')) {
            $parameterVariable = $context->symbolTable->getVariableForWrite($var['name'].'_param', $context);
            $parameterCode = $context->backend->getVariableCode($parameterVariable);
            $cond = 'Z_TYPE_P('.$parameterCode.') != ';
        }

        switch ($type) {
            case 'int':
            case 'uint':
            case 'long':
                $conditions[] = $cond.'IS_LONG';
                break;
            case 'bool':
                if (!$this->isZE3()) {
                    $conditions[] = $cond.'IS_BOOL';
                } else {
                    $conditions[] = $cond.'IS_TRUE';
                    $conditions[] = $cond.'IS_FALSE';
                }
                break;
            case 'double':
                $conditions[] = $cond.'IS_DOUBLE';
                break;
            case 'string':
            case 'ulong':
                $conditions[] = $cond.'IS_STRING';
                $conditions[] = $cond.'IS_NULL';
                break;
            case 'array':
                break;
            case 'object':
            case 'resource':
                $conditions[] = $cond.'IS_'.strtoupper($type);
                break;
            case 'callable':
                $conditions[] = 'zephir_is_callable('.$inputParamCode.' TSRMLS_CC) != 1';
                break;
            default:
                throw new CompilerException('Unknown type '.$type);
        }

        /* Generate verification code */
        if (\count($conditions)) {
            $codePrinter->output('if (UNEXPECTED('.implode(' && ', $conditions).')) {');
            $codePrinter->increaseLevel();

            $exceptionMessage = sprintf('SL("Parameter \'%s\' must be of the type %s")', $var['name'], $type);
            $codePrinter->output(
                sprintf(
                    'zephir_throw_exception_string(spl_ce_InvalidArgumentException, %s TSRMLS_CC);',
                    $exceptionMessage
                )
            );

            $codePrinter->output('RETURN_MM_NULL();');
            $codePrinter->decreaseLevel();
            $codePrinter->output('}');
        }

        /* Assign param */
        switch ($type) {
            case 'int':
            case 'uint':
            case 'long':
                $codePrinter->output($var['name'].' = Z_LVAL_P('.$parameterCode.');');
                break;
            case 'bool':
                $codePrinter->output($var['name'].' = '.$this->getBoolCode($parameterVariable, $context, false).';');
                break;
            case 'double':
                $codePrinter->output($var['name'].' = Z_DVAL_P('.$parameterCode.');');
                break;
            case 'string':
            case 'ulong':
                $context->headersManager->add('kernel/operators');
                $codePrinter->output('if (EXPECTED(Z_TYPE_P('.$parameterCode.') == IS_STRING)) {');
                $codePrinter->increaseLevel();
                $targetVar = $var['name'];
                if ($this->isZE3()) {
                    $targetVar = '&'.$targetVar;
                }
                $codePrinter->output('zephir_get_strval('.$targetVar.', '.$var['name'].'_param);');
                $codePrinter->decreaseLevel();
                $codePrinter->output('} else {');
                $codePrinter->increaseLevel();
                $codePrinter->output('ZEPHIR_MM_ZVAL_EMPTY_STRING('.$inputParamCode.');');
                $codePrinter->decreaseLevel();
                $codePrinter->output('}');
                break;
            case 'array':
                $context->backend->assignZval($inputParamVariable, $parameterVariable, $context);
                break;
            case 'object':
            case 'resource':
            case 'callable':
                break;
            default:
                throw new CompilerException('Unknown type: '.$type);
        }
    }

    public function fetchClassEntry($str)
    {
        return 'zephir_get_internal_ce(SL("'.$str.'"))';
    }

    public function getScalarTempVariable($type, CompilationContext $compilationContext, $isLocal = true)
    {
        return $compilationContext->symbolTable->getTempNonTrackedVariable($type, $compilationContext);
    }

    /* Assign value to variable */
    protected function assignHelper($macro, $variableName, $value, CompilationContext $context, $useCodePrinter, $doCopy = null)
    {
        if ($value instanceof Variable) {
            $value = $value->getName();
        } else {
            $value = 'ZEPHIR_MM_ZVAL_STRING' == $macro ? '"'.$value.'"' : $value;
			$doCopy = NULL;
        }

        $copyStr = '';
        if (true === $doCopy) {
            $copyStr = ', 1';
        } elseif (false === $doCopy) {
            $copyStr = ', 0';
        } elseif (isset($doCopy)) {
            $copyStr = ', '.$doCopy;
        }

        $output = $macro.'('.$variableName.', '.$value.$copyStr.');';
        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $output;
    }

    protected function returnHelper($macro, $value, CompilationContext $context, $useCodePrinter, $doCopy = null)
    {
        if ($value instanceof Variable) {
            $value = $value->getName();
        } else {
            $value = 'RETURN_MM_STRING' == $macro ? '"'.$value.'"' : $value;
        }

        $copyStr = '';
        if (true === $doCopy) {
            $copyStr = ', 1';
        } elseif (false === $doCopy) {
            $copyStr = ', 0';
        } elseif (isset($doCopy)) {
            $copyStr = ', '.$doCopy;
        }

        $output = $macro.'('.$value.$copyStr.');';
        if ($useCodePrinter) {
            $context->codePrinter->output($output);
        }

        return $output;
    }

    /**
     * Resolve expressions.
     *
     * @param CompiledExpression[]|string[] $offsetExprs
     * @param CompilationContext            $compilationContext
     *
     * @throws CompilerException
     *
     * @return array
     */
    private function resolveOffsetExprs($offsetExprs, CompilationContext $compilationContext)
    {
        $keys = '';
        $offsetItems = [];
        $numberParams = 0;

        foreach ($offsetExprs as $offsetExpr) {
            if ('a' == $offsetExpr) {
                $keys .= 'a';
                ++$numberParams;
                continue;
            }
            switch ($offsetExpr->getType()) {
                case 'int':
                case 'uint':
                case 'long':
                case 'ulong':
                    $keys .= 'l';
                    $offsetItems[] = $offsetExpr->getCode();
                    ++$numberParams;
                    break;

                case 'string':
                    $keys .= 's';
                    $offsetItems[] = 'SL("'.$offsetExpr->getCode().'")';
                    $numberParams += 2;
                    break;

                case 'variable':
                    $variableIndex = $compilationContext->symbolTable->getVariableForRead(
                        $offsetExpr->getCode(),
                        $compilationContext,
                        null
                    );

                    switch ($variableIndex->getType()) {
                        case 'int':
                        case 'uint':
                        case 'long':
                        case 'ulong':
                            $keys .= 'l';
                            $offsetItems[] = $this->getVariableCode($variableIndex);
                            ++$numberParams;
                            break;
                        case 'string':
                        case 'variable':
                            $keys .= 'z';
                            $offsetItems[] = $this->getVariableCode($variableIndex);
                            ++$numberParams;
                            break;
                        default:
                            throw new CompilerException(
                                sprintf('Variable: %s cannot be used as array index', $variableIndex->getType()),
                                $offsetExpr->getOriginal()
                            );
                    }
                    break;

                default:
                    throw new CompilerException(
                        sprintf('Value: %s cannot be used as array index', $offsetExpr->getType()),
                        $offsetExpr->getOriginal()
                    );
            }
        }

        return [$keys, $offsetItems, $numberParams];
    }

    public function createSymbolTable(CompilationContext $context)
    {
        $context->codePrinter->output('zephir_create_symbol_table(&zephir_memory);');
    }
}
