<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Compiler;

use Zephir\ClassDefinition;

/**
 * FileInterface
 *
 * Provides a common interface for compiler files
 */
interface FileInterface
{
    /**
     * Checks if the class file belongs to an external dependency or not.
     *
     * @return bool
     */
    public function isExternal();

    /**
     * Returns the class definition related to the compiled file.
     *
     * @return ClassDefinition
     */
    public function getClassDefinition();
}
