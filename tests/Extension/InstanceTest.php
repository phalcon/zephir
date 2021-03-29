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
use Stub\Instance;

final class InstanceTest extends TestCase
{
    /**
     * @issue https://github.com/zephir-lang/zephir/issues/1339
     */
    public function testShouldCreateAnInstanceUsingMoreThan10Parameters(): void
    {
        $this->assertInstanceOf(Instance::class, Instance::testIssue1339());
    }
}
