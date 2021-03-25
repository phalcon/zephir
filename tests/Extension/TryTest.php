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

namespace Extension;

use PHPUnit\Framework\TestCase;

final class TryTest extends TestCase
{
    public function testThrow1(): void
    {
        $this->expectException('\Exception');

        $test = new \Stub\TryTest();
        $test->testThrow1();
    }

    public function testThrow2(): void
    {
        $this->expectException('\Exception');

        $test = new \Stub\TryTest();
        $test->testThrow2();
    }
}
