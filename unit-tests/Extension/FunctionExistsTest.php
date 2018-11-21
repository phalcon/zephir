<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Extension;

use Test\FunctionExists;
use Zephir\Support\TestCase;

class FunctionExistsTest extends TestCase
{
    /**
     * @test
     * @dataProvider providerInternalFunctions
     * @issue https://github.com/phalcon/zephir/issues/1547
     * @param string $func The internal (built-in) function name
     */
    public function shouldCorrectDetectestExistenceWithPassedName($func)
    {
        $t = new FunctionExists();
        $this->assertTrue($t->testWithPassedName($func));
    }

    /**
     * @test
     * @issue https://github.com/phalcon/zephir/issues/1547
     */
    public function shouldCorrectDetectestExistenceInsideTheZephirCode()
    {
        $t = new FunctionExists();
        $expected = [
            'substr' => true,
            'cubstr' => false,
            'ucfirst' => true,
            'bcfirst' => false,
            'stripos' => true,
            'ktripos' => false,
            'trim' => true,
            'prim' => false,
        ];

        $this->assertSame($expected, $t->testBuiltInFunctions());
    }

    /**
     * @test
     * @issue https://github.com/phalcon/zephir/issues/1547
     */
    public function shouldCorrectDetectestExistenceByUsingString()
    {
        $t = new FunctionExists();
        $this->assertTrue($t->testWithString());
    }

    public function providerInternalFunctions()
    {
        $allFunctions = get_defined_functions();
        shuffle($allFunctions['internal']);

        $functions = array_map(
            function ($value) {
                return [$value];
            },
            $allFunctions['internal']
        );

        return array_slice($functions, 0, 10);
    }
}
