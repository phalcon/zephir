<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Extension\Properties;

use Zephir\Support\TestCase;

class PrivatePropertiesTest extends TestCase
{
    public function testAssertations()
    {
        $t = new \Test\Properties\PrivateProperties();

        $this->assertNull($t->getSomeNull());
        $this->assertNull($t->getSomeNullInitial());
        $this->assertFalse($t->getSomeFalse());
        $this->assertTrue($t->getSomeTrue());
        $this->assertSame($t->getSomeInteger(), 10);
        $this->assertSame($t->getSomeDouble(), 10.25);
        $this->assertSame($t->getSomeString(), 'test');
    }
}
