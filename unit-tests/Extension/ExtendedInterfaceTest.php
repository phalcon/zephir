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

use Test\ExtendedInterface;
use Zephir\Support\TestCase;

class ExtendedInterfaceTest extends TestCase
{
    /** @test */
    public function shouldExtendsInterfaces()
    {
        try {
            $reflection = new \ReflectionClass(ExtendedInterface::class);
        } catch (\ReflectionException $e) {
            $this->fail($e->getMessage());
            return;
        }

        $this->assertTrue($reflection->isInterface());
        $this->assertContains('IteratorAggregate', $reflection->getInterfaceNames());
        $this->assertContains('Countable', $reflection->getInterfaceNames());
    }
}
