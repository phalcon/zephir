<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Console;

use Symfony\Component\Console\Application as BaseApplication;
use Symfony\Component\Console\Input\InputDefinition;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Input\InputOption;
use Symfony\Component\Console\Output\OutputInterface;
use Zephir\Zephir;

final class Application extends BaseApplication
{
    public function __construct()
    {
        parent::__construct('Zephir', Zephir::VERSION);
    }

    /**
     * {@inheritdoc}
     *
     * @return string
     */
    public function getHelp()
    {
        return Zephir::LOGO.parent::getHelp();
    }

    /**
     * {@inheritdoc}
     *
     * @return string The application version
     */
    public function getVersion()
    {
        $version = \explode('-', parent::getVersion());

        if (isset($version[1]) && 0 === \strpos($version[1], '$')) {
            return "{$version[0]}-source";
        }

        return implode('-', $version);
    }

    /**
     * {@inheritdoc}
     *
     * @return string The long application version
     */
    public function getLongVersion()
    {
        $version = explode('-', $this->getVersion());
        $commit = "({$version[1]})";

        return \trim(
            \sprintf(
                '%s <info>%s</info> by <comment>Andres Gutierrez</comment> and <comment>Serghei Iakovlev</comment> %s',
                $this->getName(),
                $version[0],
                $commit
            )
        );
    }

    /**
     * {@inheritdoc}
     *
     * @param InputInterface  $input
     * @param OutputInterface $output
     *
     * @throws \Exception|\Throwable
     *
     * @return int
     */
    public function doRun(InputInterface $input, OutputInterface $output)
    {
        if (true === $input->hasParameterOption(['--dumpversion'], true)) {
            $output->writeln($this->getVersion());

            return 0;
        }

        return parent::doRun($input, $output);
    }

    /**
     * {@inheritdoc}
     *
     * @return InputDefinition
     */
    protected function getDefaultInputDefinition()
    {
        $definition = parent::getDefaultInputDefinition();

        $definition->addOption(
            new InputOption(
                'dumpversion',
                null,
                InputOption::VALUE_NONE,
                "Print the Zephir version — and don't do anything else"
            )
        );

        return $definition;
    }
}
