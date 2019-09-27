<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Extension\Flow;

use PHPUnit\Framework\TestCase;
use Test\Flow\SwitchFlow;

class SwitchFlowTest extends TestCase
{
    public function testSwitch()
    {
        $t = new SwitchFlow();

        $this->assertSame(10, $t->testSwitch1());
        $this->assertTrue($t->testSwitch2());
        $this->assertFalse($t->testSwitch3());
        $this->assertSame(2, $t->testSwitch4());
        $this->assertSame(1, $t->testSwitch5());
        $this->assertSame(1, $t->testSwitch6());
        $this->assertSame(1, $t->testSwitch7());
        $this->assertSame(2, $t->testSwitch8());
        $this->assertSame(2, $t->testSwitch9());
        $this->assertSame(2, $t->testSwitch10());
        $this->assertSame(1, $t->testSwitch11());
        $this->assertSame(1, $t->testSwitch12(10, 6));
        $this->assertSame(0, $t->testSwitch12(6, 10));
        $this->assertSame(2, $t->testSwitch12(2, 3));
        $this->assertSame('aaa', $t->testSwitch14(1));
        $this->assertSame('bbb', $t->testSwitch14(99));
    }
}
