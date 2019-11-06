<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 */

namespace Zephir;

final class Types
{
    const T_INT = 'int';
    const T_UINT = 'uint';
    const T_CHAR = 'char';
    const T_UCHAR = 'uchar';
    const T_LONG = 'long';
    const T_ULONG = 'ulong';
    const T_DOUBLE = 'double';
    const T_FLOAT = 'float';
    const T_NUMBER = 'number';
    const T_NULL = 'null';
    const T_BOOL = 'bool';
    const T_STRING = 'string';
    const T_ISTRING = 'istring';
    const T_VARIABLE = 'variable';
    const T_MIXED = 'mixed';
    const T_ARRAY = 'array';
    const T_VOID = 'void';
    const T_OBJECT = 'object';
    const T_CALLABLE = 'callable';
    const T_RESOURCE = 'resource';
    const T_ITERABLE = 'iterable';
    const T_UNDEFINED = 'undefined';

    const COMPATIBLETYPES = [
        self::T_INT => [
            self::T_INT,
            self::T_UINT,
            self::T_CHAR,
            self::T_UCHAR,
            self::T_LONG,
            self::T_ULONG,
        ],
        self::T_FLOAT => [
            self::T_FLOAT,
            self::T_DOUBLE,
        ],
        self::T_BOOL => [
            self::T_BOOL,
        ],
        self::T_STRING => [
            self::T_STRING,
            self::T_ISTRING,
        ],
        self::T_NULL => [
            self::T_NULL,
        ],
        self::T_ARRAY => [
            self::T_ARRAY,
        ],
        self::T_OBJECT => [
            self::T_OBJECT,
        ],
        self::T_ITERABLE => [
            self::T_ITERABLE,
        ],
        self::T_RESOURCE => [
            self::T_RESOURCE,
        ],
        self::T_VOID => [
            self::T_VOID,
        ],
    ];

    /**
     * Gets PHP compatible return type from class method.
     *
     * @param ClassMethod $method
     *
     * @return string
     */
    public function getCompatibleReturnType(ClassMethod $method, array $returnTypes = null): string
    {
        if (!$method->hasReturnTypes() && !$method->isVoid()) {
            return '';
        }

        $returnTypes = $returnTypes ?? $method->getReturnTypes();
        $typesCount = \count($returnTypes);

        $isNullable = $method->areReturnTypesNullCompatible() && 1 !== $typesCount;
        $isInteger = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_INT]);
        $isDouble = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_FLOAT]);
        $isBool = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_BOOL]);
        $isString = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_STRING], $isNullable);
        $isNull = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_NULL]);
        $isArray = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_ARRAY]);
        $isObject = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_OBJECT]);
        $isIterable = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_ITERABLE]);
        $isResource = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_RESOURCE]);
        $isVoid = $this->areReturnTypesCompatible($returnTypes, static::COMPATIBLETYPES[static::T_VOID]);

        $nullable = $isNullable ? '|null' : '';

        if ($method->isVoid() || $isVoid) {
            return static::T_VOID;
        }

        if ($isInteger) {
            return static::T_INT.$nullable;
        }

        if ($isDouble) {
            return static::T_FLOAT.$nullable;
        }

        if ($isBool) {
            return static::T_BOOL.$nullable;
        }

        if ($isString) {
            return static::T_STRING.$nullable;
        }

        if ($isNull && 1 === $typesCount) {
            return static::T_NULL;
        }

        if ($isArray) {
            return static::T_ARRAY;
        }

        if ($isObject) {
            return static::T_OBJECT;
        }

        if ($isIterable) {
            return static::T_ITERABLE;
        }

        if ($isResource) {
            return static::T_RESOURCE;
        }

        if ($method->areReturnTypesCompatible()) {
            return static::T_MIXED.$nullable;
        }

        return static::T_MIXED.$nullable;
    }

    /**
     * Match if return types from Zephire are compatible
     * with allowed return types from PHP.
     *
     * @param array $types        - Return types from parser
     * @param array $allowedTypes - Allowed return types
     *
     * @return bool
     */
    private function areReturnTypesCompatible(array $types, array $allowedTypes, bool $isNullable = false): bool
    {
        $result = null;
        $areEquals = false;

        if ($isNullable) {
            array_push($allowedTypes, static::T_NULL);
        }

        foreach ($types as $type => $data) {
            $areEquals = \in_array($type, $allowedTypes);

            $result = isset($result) ? ($areEquals && $result) : $areEquals;
        }

        return $result ?? false;
    }
}
