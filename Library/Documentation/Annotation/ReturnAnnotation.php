<?php

/**
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Documentation\Annotation;

use Zephir\Documentation\Annotation;

/**
 * A return annotation that looks like  `(@)return type description`
 */
class ReturnAnnotation extends Annotation
{
    protected $returnType;
    protected $description;


    protected function parseContent()
    {
        $spaceIndex = strpos($this->string, " ");

        if (false !== $spaceIndex) {
            $this->returnType = substr($this->string, 0, $spaceIndex);
            $this->description = substr($this->string, $spaceIndex + 1);
        } else {
            $this->returnType = $this->string;
        }

        $this->contentParsed = true;
    }

    public function getReturnType()
    {
        if (!$this->contentParsed) {
            $this->parseContent();
        }

        return $this->returnType;
    }

    public function getDescription()
    {
        if (!$this->contentParsed) {
            $this->parseContent();
        }

        return $this->description;
    }
}
