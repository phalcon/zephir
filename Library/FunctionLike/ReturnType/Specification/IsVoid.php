<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 */

namespace Zephir\FunctionLike\ReturnType\Specification;

use Zephir\FunctionLike\ReturnType;
use Zephir\Types;

final class IsVoid extends ReturnType\CompositeSpecification
{
    /**
     * {@inheritdoc}
     *
     * @param ReturnType\TypeInterface $type
     *
     * @return bool
     */
    public function isSatisfiedBy(ReturnType\TypeInterface $type)
    {
        return $type->isReal() && Types::T_VOID == $type->getDataType();
    }
}
