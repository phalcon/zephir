<?php

declare(strict_types=1);

/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view
 * the LICENSE file that was distributed with this source code.
 */

namespace Extension\Optimizers;

use PHPUnit\Framework\TestCase;
use Stub\Optimizers\ArrayMerge;

final class ArrayMergeTest extends TestCase
{
    public function testTwoArrays(): void
    {
        $this->assertSame([1, 2, 3, 4, 5], ArrayMerge::mergeTwoRequiredArrays([1, 2, 3], [4, 5]));
        $this->assertSame([1, 2, 3], ArrayMerge::mergeTwoRequiredArrays([1, 2, 3], []));
        $this->assertSame([1, 2, 3], ArrayMerge::mergeTwoRequiredArrays([], [1, 2, 3]));
    }
}
