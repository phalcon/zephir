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
use Stub\Compare;

final class CompareTest extends TestCase
{
    private Compare $test;

    protected function setUp(): void
    {
        $this->test = new Compare();
    }

    public function testLess(): void
    {
        $this->assertTrue($this->test->isLessInt(1, 2));
        $this->assertTrue($this->test->isLessDouble(1.1, 1.2));
        $this->assertFalse($this->test->isLessInt(20, 10));
    }

    public function testGreaterEqual(): void
    {
        $this->assertTrue($this->test->isGreaterEqual(3, 2));
        $this->assertTrue($this->test->isGreaterEqual(2, 2));
        $this->assertFalse($this->test->isGreaterEqual(1, 2));
    }

    public function testConst(): void
    {
        $this->assertTrue($this->test->isLessThenPi(3.12));
        $this->assertTrue($this->test->isMoreThenPi(3.15));
    }

    public function testVarWithStringEquals(): void
    {
        $this->assertSame('NOK', $this->test->testVarWithStringEquals('wrong testing'));
        $this->assertSame('NOK', $this->test->testVarWithStringEquals('another testing'));
        $this->assertSame('OK', $this->test->testVarWithStringEquals('testing'));
        $this->assertSame('NOK', $this->test->testVarWithStringEquals('testing nok'));
    }

    public function testEquals(): void
    {
        $this->assertTrue($this->test->testVarEqualsNull(null));
        $this->assertFalse($this->test->testVarEqualsNull(1));

        $this->assertTrue($this->test->testNullEqualsVar(null));
        $this->assertFalse($this->test->testNullEqualsVar(1));
    }

    public function testNotEquals(): void
    {
        $this->assertTrue($this->test->testNotIdenticalZeroVar());
        $this->assertTrue($this->test->testNotIdenticalZeroInt());
        $this->assertTrue($this->test->testNotIdenticalZeroLong());
    }
}
