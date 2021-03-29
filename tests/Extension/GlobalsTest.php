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
use Stub\Globals;

/**
 * Extension\GlobalsTest.
 */
final class GlobalsTest extends TestCase
{
    private Globals $test;

    protected function setUp(): void
    {
        $this->test = new Globals();
    }

    public function testShouldGetGlobalExtensionSettings(): void
    {
        $this->assertFalse($this->test->getDefaultGlobals1());

        $this->assertTrue($this->test->getDefaultGlobals4());

        $this->assertSame(100, $this->test->getDefaultGlobals2());
        $this->assertSame(7.5, $this->test->getDefaultGlobals3());
        $this->assertSame(10, $this->test->getDefaultGlobals5());
        $this->assertSame(15.2, $this->test->getDefaultGlobals6());
        $this->assertSame(65, $this->test->getDefaultGlobals7());
    }

    public function testShouldSetGlobalExtensionSetting(): void
    {
        $this->test->setBoolValueUsingDotNotation(false);

        $this->assertFalse($this->test->getDefaultGlobals1());
    }

    public function testSetIntValueUsingDotNotation(): void
    {
        $this->test->setIntValueUsingDotNotation(900);

        $this->assertSame(900, $this->test->getDefaultGlobals2());
    }

    public function testSetCharValueUsingString(): void
    {
        $this->test->setCharValue('B');

        $this->assertSame(66, $this->test->getDefaultGlobals7());
    }

    public function testSetCharValueUsingInt(): void
    {
        $this->test->setCharValue(90);

        $this->assertSame(90, $this->test->getDefaultGlobals7());
    }

    public function testSetBoolValueUsingInt(): void
    {
        $this->test->setBoolValue(0);

        $this->assertFalse($this->test->getDefaultGlobals4());
    }

    public function testSetBoolValueUsingBool(): void
    {
        $this->test->setBoolValue(true);
        $this->assertTrue($this->test->getDefaultGlobals4());

        $this->test->setBoolValue(false);
        $this->assertFalse($this->test->getDefaultGlobals4());
    }

    public function testShouldSetGlobalExtensionOrmCacheLevel(): void
    {
        $this->test->setDefaultGlobalsOrmCacheLevel(3);

        $this->assertSame(3, $this->test->getDefaultGlobalsOrmCacheLevel());
    }
}
