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

class ResourceTest extends \PHPUnit_Framework_TestCase
{
    public function testLetStatementAssign()
    {
        $t = new \Test\Resource();
        $this->assertInternalType('resource', $t->testLetStatementSTDIN());
        $this->assertInternalType('resource', $t->testLetStatementSTDOUT());
        $this->assertInternalType('resource', $t->testLetStatementSTDERR());
    }

    public function testTypeOffResource()
    {
        $t = new \Test\Resource();
        $this->assertEquals('resource', $t->testTypeOffResource());
    }

    public function testIsResource()
    {
        $t = new \Test\Resource();
        $this->assertTrue($t->testIsResource());
    }
}
