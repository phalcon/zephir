<?php

/*
 * This file is part of the Zephir.
 *
 * (c) Zephir Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Zephir\Console\Command;

use Symfony\Component\Console\Command\Command;
use Symfony\Component\Console\Input\InputInterface;
use Symfony\Component\Console\Output\OutputInterface;
use Symfony\Component\Console\Style\SymfonyStyle;
use Zephir\Exception\FileSystemException;
use Zephir\FileSystem\FileSystemInterface;
use function Zephir\is_windows;

/**
 * Zephir\Console\Command\CleanCommand.
 *
 * Cleans any object files created by the extension.
 */
final class CleanCommand extends Command
{
    private $filesystem;

    public function __construct(FileSystemInterface $filesystem)
    {
        $this->filesystem = $filesystem;

        parent::__construct();
    }

    protected function configure()
    {
        $this
            ->setName('clean')
            ->setDescription('Cleans any object files created by the extension');
    }

    protected function execute(InputInterface $input, OutputInterface $output)
    {
        $this->filesystem->clean();

        $io = new SymfonyStyle($input, $output);

        try {
            $this->filesystem->clean();

            if (is_windows()) {
                \system('cd ext && nmake clean-all');
            } else {
                \system('cd ext && make clean > /dev/null');
            }
        } catch (FileSystemException $e) {
            $io->error(
                sprintf(
                    "For reasons beyond Zephir's control, a filesystem error has occurred. ".
                    'Please note: On Linux/Unix systems the current user must have the delete and execute '.
                    'permissions on the internal cache directory,  For more information see chmod(1) and chown(1). '.
                    'System error was: %s',
                    $e->getMessage()
                )
            );

            return 1;
        } catch (\Exception $e) {
            $io->error($e->getMessage());

            return 1;
        } catch (\Throwable $e) {
            $io->error($e->getMessage());

            return 1;
        }

        return 0;
    }
}
