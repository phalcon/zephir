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

use PHPUnit\Framework\TestCase;

class ExtensionInfoTest extends TestCase
{
    /**
     * @see config.json for Directive keys
     */
    public function directiveProvider(): array
    {
        return [
            ['Test Extension => enabled', true],
            ['Test Extension support => Value', true],
            ['Test variable => Value', true],
            ['extension.test_ini_variable => On => On', true],
            ['ini-entry.my_setting_1', true],
            ['test.db.my_setting_1', true],
            ['test.orm.cache_enable', true],
            ['test.test.my_setting_1', false],
            ['test.test.test_setting_1', false],
            ['test.test.', false],
        ];
    }

    /**
     * @dataProvider directiveProvider()
     * @test
     */
    public function shouldBeWithoutDuplicatesNamespace(string $var, bool $contains)
    {
        ob_start();

        phpinfo(INFO_MODULES);
        $phpinfo = ob_get_contents();

        ob_end_clean();

        if ($contains) {
            $this->assertContains($var, $phpinfo);
        } else {
            $this->assertNotContains($var, $phpinfo);
        }
    }
}
