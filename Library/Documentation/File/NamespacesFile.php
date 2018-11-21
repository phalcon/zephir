<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Documentation\File;

use Zephir\Documentation\AbstractFile;
use Zephir\Documentation\NamespaceAccessor;

class NamespacesFile extends AbstractFile
{
    /**
     * @var NamespaceAccessor
     */
    protected $namespaceAccessor;

    public function __construct($config, NamespaceAccessor $namespaceAccessor)
    {
        $this->namespaceAccessor = $namespaceAccessor;
    }

    public function getTemplateName()
    {
        return "namespaces.phtml";
    }

    public function getData()
    {
        return [
            "namespaceAccessor" => $this->namespaceAccessor,
            "namespacesTree" => $this->namespaceAccessor->getNamespaceTree(),
            "namespaces" => $this->namespaceAccessor->getByNamespace()
        ];
    }

    public function getOutputFile()
    {
        return "namespaces.html";
    }
}
