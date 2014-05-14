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

namespace Zephir\Cache;

use Zephir\CompilationContext;
use Zephir\ClassMethod;
use Zephir\Call;

/**
 * StaticMethodCache
 *
 * Calls in Zephir implement monomorphic and polimorphic caches to
 * improve performance. Method/Functions lookups are cached in a standard
 * first-level method lookup cache.
 *
 * The concept of inline caching is based on the empirical observation
 * that the objects that occur at a particular call site are often of the same type
 * Internal functions are considered monomorphic since they do not change across execution.
 * Final and private methods are also monomorphic because of their own nature.
 * Due to the Ahead-Of-Time compilation approach provided by Zephir, is not possible
 * to implement inline caches, however is possible to add barriers/guards to
 * take advantage of profile guided optimizations (PGO) and branch prediction.
 *
 * This implementation is based on the work of Hölzle, Chambers and Ungar [1].
 *
 * [1] http://www.cs.ucsb.edu/~urs/oocsb/papers/ecoop91.pdf
 */
class StaticMethodCache
{
    protected $cache = array();

    /**
     * @param CompilationContext $compilationContext
     * @param ClassMethod|\ReflectionMethod $method
     * @param boolean $allowNtsCache
     */
    public function get(CompilationContext $compilationContext, $method, $allowNtsCache = true)
    {
        if (!is_object($method)) {
            return 'NULL';
        }

        if (!($method instanceof \ReflectionMethod)) {

            if (isset($this->cache[$method->getClassDefinition()->getCompleteName()][$method->getName()])) {
                return '&' . $this->cache[$method->getClassDefinition()->getCompleteName()][$method->getName()]->getName();
            }

            if ($method->getClassDefinition()->isInterface()) {
                return 'NULL';
            }

        }

        $mustBeCached = false;
        if (!$compilationContext->insideCycle) {

            if (!($method instanceof \ReflectionMethod)) {
                $classDefinition = $method->getClassDefinition();
                if (!$classDefinition->isInternal() && $allowNtsCache) {
                    $mustBeCached = true;
                } else {
                    if (!$method->isPrivate() && !$method->isFinal()) {
                        return 'NULL';
                    }
                }
            } else {
                if (!$method->isPrivate() && !$method->isFinal()) {
                    return 'NULL';
                }
            }

        }


        if ($method->isPrivate() || $method->isFinal() || $mustBeCached) {
            $functionCache = $compilationContext->symbolTable->getTempVariableForWrite('static_zephir_fcall_cache_entry', $compilationContext);
        } else {
            $functionCache = $compilationContext->symbolTable->getTempVariableForWrite('zephir_fcall_cache_entry', $compilationContext);
        }

        $functionCache->setMustInitNull(true);
        $functionCache->setReusable(false);

        if (!($method instanceof \ReflectionMethod)) {
            $this->cache[$method->getClassDefinition()->getCompleteName()][$method->getName()] = $functionCache;
        }

        return '&' . $functionCache->getName();
    }
}
