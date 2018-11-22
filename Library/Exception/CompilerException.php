<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Exception;

/**
 * Zephir\Exception\CompilerException
 *
 * Exceptions generated by the compiler
 */
class CompilerException extends RuntimeException
{
    /**
     * CompilerException constructor.
     *
     * @param string $message The Exception message to throw [optional].
     * @param array|null $extra Extra info [optional].
     * @param int $code The Exception code [optional].
     * @param \Exception|\Throwable $previous The previous throwable used for the exception chaining [optional].
     */
    public function __construct($message = '', $extra = null, $code = 0, $previous = null)
    {
        if (is_array($extra) && isset($extra['file'])) {
            $message .= ' in ' . $extra['file'] . ' on line ' . $extra['line'];
        }

        $this->extra = $extra;

        parent::__construct($message, $code, $previous);
    }
}
