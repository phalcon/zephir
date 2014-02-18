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

namespace Exstension;


class FcallTest
    extends \PHPUnit_Framework_TestCase
{
    public function testCall()
    {
        $t = new \Test\Fcall();
        $this->assertTrue($t->testCall1() === 0);
        $this->assertTrue($t->testCall2() > -1);
        $this->assertTrue($t->testCall1FromVar() === 2);
    }

    public function testStrtok()
    {
        $t = new \Test\Fcall();
        $this->assertTrue($t->testStrtokFalse() === false);
        $this->assertTrue($t->testStrtokVarBySlash('test') === 'test');
    }

    public function testFunctionGetArgs()
    {
        $t = new \Test\Fcall();
        $this->assertTrue($t->testFunctionGetArgs(true, false) === array(true, false));
        $this->assertTrue($t->testFunctionGetArgs(1025, false) === array(1025, false));
        $this->assertTrue($t->testFunctionGetArgs(false, 1234) === array(false, 1234));
        $this->assertTrue($t->testFunctionGetArgs(array(1, 2, 3), false) === array(array(1, 2, 3), false));
    }
} 