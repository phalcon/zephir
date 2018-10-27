<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Extension;

use Zephir\Support\TestCase;

class BranchPredictionTest extends TestCase
{
    public function testVariants()
    {
        $b = new \Test\BranchPrediction();

        $this->assertTrue($b->testLikely1());
        $this->assertFalse($b->testLikely2(false));
        $this->assertTrue($b->testUnlikely1());
        $this->assertFalse($b->testUnlikely2(false));
    }
}
