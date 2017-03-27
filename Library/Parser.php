<?php

/*
 +--------------------------------------------------------------------------+
 | Zephir Language                                                          |
 +--------------------------------------------------------------------------+
 | Copyright (c) 2013-2017 Zephir Team and contributors                     |
 +--------------------------------------------------------------------------+
 | This source file is subject the MIT license, that is bundled with        |
 | this package in the file LICENSE, and is available through the           |
 | world-wide-web at the following url:                                     |
 | https://zephir-lang.com/license.html                                     |
 |                                                                          |
 | If you did not receive a copy of the MIT license and are unable          |
 | to obtain it through the world-wide-web, please send a note to           |
 | license@zephir-lang.com so we can mail you a copy immediately.           |
 +--------------------------------------------------------------------------+
*/

namespace Zephir;

use Zephir\Parser\ParseException;

/**
 * Zephir\Parser
 *
 * @package Zephir
 */
class Parser
{
    /**
     * Check if Zephir Parser available.
     *
     * @return bool
     */
    public function isAvailable()
    {
        return function_exists('zephir_parse_file');
    }

    /**
     * Parses a file and returning an intermediate array representation.
     *
     * @param string $filepath
     * @return array
     * @throws ParseException
     */
    public function parse($filepath)
    {
        if (!$this->isAvailable()) {
            throw new ParseException("Parser extension couldn't be loaded");
        }

        $content = file_get_contents($filepath);

        return zephir_parse_file($content, $filepath);
    }
}
