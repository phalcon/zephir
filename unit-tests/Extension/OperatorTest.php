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

namespace Extension;

use Test\Operator;

class OperatorTest extends \PHPUnit_Framework_TestCase
{
    public function test404Issue()
    {
        $t = new Operator();

        $this->assertFalse($t->testIdentical(true, 1));
        $this->assertFalse($t->testIdentical(true, 'phalcon'));
        $this->assertFalse($t->testIdentical(false, 0));
        $this->assertFalse($t->testIdentical(1, '1'));
        $this->assertTrue($t->testIdentical(1, 1));
        $this->assertTrue($t->testIdentical(true, true));
        $this->assertTrue($t->testIdentical('phalcon', 'phalcon'));
    }

    public function testExponential()
    {
        $t = new Operator();

        $this->assertEquals(8, $t->testExponential(2, 3, 1));
    }
}
