<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Stubs;

use Zephir\ClassConstant;
use Zephir\ClassDefinition;
use Zephir\ClassMethod;
use Zephir\ClassProperty;
use Zephir\CompilerFile;
use Zephir\Config;
use Zephir\Exception;
use Zephir\Types;

/**
 * Stubs Generator.
 */
class Generator
{
    /**
     * Not php visible style variants.
     *
     * @var array
     */
    protected $ignoreModifiers = [
        'inline',
        'internal',
        'scoped',
        'deprecated',
    ];

    /**
     * @var CompilerFile[]
     */
    protected $files;

    /**
     * @var Config
     */
    protected $config;

    /**
     * @param CompilerFile[] $files
     * @param Config         $config
     */
    public function __construct(array $files, Config $config)
    {
        $this->files = $files;
        $this->config = $config;
    }

    /**
     * Generates stubs.
     *
     * @param string $path
     */
    public function generate($path)
    {
        if ('tabs' === $this->config->get('indent', 'extra')) {
            $indent = "\t";
        } else {
            $indent = '    ';
        }

        $namespace = $this->config->get('namespace');

        foreach ($this->files as $file) {
            $class = $file->getClassDefinition();
            $source = $this->buildClass($class, $indent);

            $filename = ucfirst($class->getName()).'.zep.php';
            $filePath = $path.str_replace(
                $namespace,
                '',
                str_replace($namespace.'\\\\', \DIRECTORY_SEPARATOR, strtolower($class->getNamespace()))
            );
            $filePath = str_replace('\\', \DIRECTORY_SEPARATOR, $filePath);
            $filePath = str_replace(\DIRECTORY_SEPARATOR.\DIRECTORY_SEPARATOR, \DIRECTORY_SEPARATOR, $filePath);

            if (!is_dir($filePath)) {
                mkdir($filePath, 0777, true);
            }

            $filePath = realpath($filePath).'/';
            file_put_contents($filePath.$filename, $source);
        }
    }

    /**
     * Build class.
     *
     * @param ClassDefinition $class
     * @param string          $indent
     *
     * @return string
     */
    protected function buildClass(ClassDefinition $class, $indent)
    {
        $source = <<<EOF
<?php

namespace {$class->getNamespace()};


EOF;

        $source .= (new DocBlock($class->getDocBlock(), ''))."\n";

        if ($class->isFinal()) {
            $source .= 'final ';
        } elseif ($class->isAbstract()) {
            $source .= 'abstract ';
        }

        $source .= $class->getType().' '.$class->getName();

        if ($class->getExtendsClass()) {
            $extendsClassDefinition = $class->getExtendsClassDefinition();
            if (!$extendsClassDefinition) {
                throw new \RuntimeException('Class "'.$class->getName().'" does not have a extendsClassDefinition');
            }

            $source .= ' extends '.($extendsClassDefinition->isBundled() ? '' : '\\').trim($extendsClassDefinition->getCompleteName(), '\\');
        }

        if ($implementedInterfaces = $class->getImplementedInterfaces()) {
            $interfaces = array_map(function ($val) {
                return '\\'.trim($val, '\\');
            }, $implementedInterfaces);

            $keyword = 'interface' == $class->getType() ? ' extends ' : ' implements ';
            $source .= $keyword.implode(', ', $interfaces);
        }

        $source .= PHP_EOL.'{'.PHP_EOL;

        foreach ($class->getConstants() as $constant) {
            $source .= $this->buildConstant($constant, $indent).PHP_EOL.PHP_EOL;
        }

        foreach ($class->getProperties() as $property) {
            $source .= $this->buildProperty($property, $indent).PHP_EOL.PHP_EOL;
        }

        $source .= PHP_EOL;

        foreach ($class->getMethods() as $method) {
            if ($method->isInternal()) {
                continue;
            }

            $source .= $this->buildMethod($method, 'interface' === $class->getType(), $indent)."\n\n";
        }

        return $source.'}'.PHP_EOL;
    }

    /**
     * Build property.
     *
     * @param ClassProperty $property
     * @param string        $indent
     *
     * @return string
     */
    protected function buildProperty(ClassProperty $property, $indent)
    {
        $visibility = 'public';

        if (false === $property->isPublic()) {
            $visibility = $property->isProtected() ? 'protected' : 'private';
        }

        if ($property->isStatic()) {
            $visibility = 'static '.$visibility;
        }

        $source = $visibility.' $'.$property->getName();
        $original = $property->getOriginal();

        if (isset($original['default'])) {
            $source .= ' = '.$this->wrapPHPValue([
                'default' => $original['default'],
            ]);
        }

        $docBlock = new DocBlock($property->getDocBlock(), $indent);

        return $docBlock."\n".$indent.$source.';';
    }

    /**
     * @param ClassConstant $constant
     * @param string        $indent
     *
     * @return string
     */
    protected function buildConstant(ClassConstant $constant, $indent)
    {
        $source = 'const '.$constant->getName();

        $value = $this->wrapPHPValue([
            'default' => $constant->getValue(),
        ]);

        $docBlock = new DocBlock($constant->getDocBlock(), $indent);

        return $docBlock."\n".$indent.$source.' = '.$value.';';
    }

    /**
     * @param ClassMethod $method
     * @param bool        $isInterface
     * @param string      $indent
     *
     * @return string
     */
    protected function buildMethod(ClassMethod $method, $isInterface, $indent)
    {
        $modifier = implode(' ', array_diff($method->getVisibility(), $this->ignoreModifiers));

        $methodParameters = $method->getParameters();
        $aliasManager = $method->getClassDefinition()->getAliasManager();
        $docBlock = new MethodDocBlock($method, $aliasManager, $indent);

        $parameters = [];

        if ($methodParameters) {
            foreach ($methodParameters->getParameters() as $parameter) {
                $paramStr = '';
                if (isset($parameter['cast'])) {
                    if ($aliasManager->isAlias($parameter['cast']['value'])) {
                        $cast = '\\'.$aliasManager->getAlias($parameter['cast']['value']);
                    } else {
                        $cast = $parameter['cast']['value'];
                    }
                    $paramStr .= $cast.' ';
                } elseif (isset($parameter['data-type']) && 'array' == $parameter['data-type']) {
                    $paramStr .= 'array ';
                } elseif (isset($parameter['data-type']) && version_compare(PHP_VERSION, '7.0.0', '>=')) {
                    if (\in_array($parameter['data-type'], ['bool', 'boolean'])) {
                        $paramStr .= 'bool ';
                    } elseif ('double' == $parameter['data-type']) {
                        $paramStr .= 'float ';
                    } elseif (\in_array($parameter['data-type'], ['int', 'uint', 'long', 'ulong', 'uchar'])) {
                        $paramStr .= 'int ';
                    } elseif (\in_array($parameter['data-type'], ['char', 'string'])) {
                        $paramStr .= 'string ';
                    }
                }

                $paramStr .= '$'.$parameter['name'];

                if (isset($parameter['default'])) {
                    $paramStr .= ' = '.$this->wrapPHPValue($parameter);
                }

                $parameters[] = $paramStr;
            }
        }

        $return = '';
        $returnTypes = $method->getReturnTypes();
        if (version_compare(PHP_VERSION, '7.0.0', '>=') && $returnTypes->hasReturnTypes()) {
            $supported = 0;

            $objects = $returnTypes->getObjectLikeReturnTypes();
            if (1 == \count($objects)) {
                $return = $objects[0]->getValue();
                ++$supported;
            }

            if ($returnTypes->areReturnTypesIntCompatible()) {
                $return = Types::T_INT;
                ++$supported;
            }

            if ($returnTypes->areReturnTypesDoubleCompatible()) {
                $return = Types::T_FLOAT;
                ++$supported;
            }

            if ($returnTypes->areReturnTypesBoolCompatible()) {
                $return = Types::T_BOOL;
                ++$supported;
            }

            if ($returnTypes->areReturnTypesStringCompatible()) {
                $return = Types::T_STRING;
                ++$supported;
            }

            if ($returnTypes->areReturnTypesArrayCompatible()) {
                $return = Types::T_ARRAY;
                ++$supported;
            }

            if ($returnTypes->areReturnTypesNullCompatible()) {
                if (version_compare(PHP_VERSION, '7.1.0', '>=')) {
                    $return = '?'.$return;
                } else {
                    $return = '';
                }
            }

            // PHP doesn't support multiple return types (yet?)
            if ($supported > 1) {
                $return = '';
            }
        }
        if (!empty($return)) {
            $return = ': '.$return;
        }

        $methodBody = sprintf(
            '%s%s %s(%s)%s',
            $indent,
            trim($modifier.' function', ' '),
            $method->getName(),
            implode(', ', $parameters),
            $return
        );

        if ($isInterface || $method->isAbstract()) {
            $methodBody .= ';';
        } else {
            $methodBody .= ' {}';
        }

        return $docBlock."\n".$methodBody;
    }

    /**
     * Prepare AST default value to PHP code print.
     *
     * @param $parameter
     *
     * @throws Exception
     *
     * @return string
     */
    protected function wrapPHPValue($parameter)
    {
        switch ($parameter['default']['type']) {
            case Types::T_NULL:
                return Types::T_NULL;
                break;

            case Types::T_STRING:
            case Types::T_CHAR:
                return '\''.addslashes($parameter['default']['value']).'\'';
                break;

            case 'empty-array':
                return 'array()';
                break;

            case Types::T_ARRAY:
                $parameters = [];

                foreach ($parameter['default']['left'] as $value) {
                    $source = '';

                    if (isset($value['key'])) {
                        $source .= $this->wrapPHPValue([
                            'default' => $value['key'],
                            'type' => $value['key']['type'],
                        ]).' => ';
                    }

                    $parameters[] = $source.$this->wrapPHPValue([
                        'default' => $value['value'],
                        'type' => $value['value']['type'],
                    ]);
                }

                return 'array('.implode(', ', $parameters).')';
                break;

            case 'static-constant-access':
                return $parameter['default']['left']['value'].'::'.$parameter['default']['right']['value'];
                break;

            case Types::T_INT:
            case Types::T_DOUBLE:
            case Types::T_BOOL:
                return $parameter['default']['value'];
                break;

            default:
                throw new Exception('Stubs - value with type: '.$parameter['default']['type'].' is not supported');
                break;
        }
    }
}
