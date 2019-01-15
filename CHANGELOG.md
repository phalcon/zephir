# Change Log
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/)
and this project adheres to [Semantic Versioning](http://semver.org/).

## [Unreleased]

## [0.11.9] - 2019-01-15
- Fixed `zend_closure` declaration to reflect PHP 7.3 changes.

## [0.11.8] - 2018-12-01
### Fixed
- Fixed compilation error with inheritance of prototype interfaces
  [#1758](https://github.com/phalcon/zephir/issues/1758)
- Fixed compilation error when a new file is added or removed to the project
  [#1776](https://github.com/phalcon/zephir/issues/1776)

## [0.11.7] - 2018-11-27
### Changed
- The cache directory, formerly known as `.temp`, used for temporary operations was moved to
  the new `.zephir` directory. The algorithm for calculating cache path is as follows:
  `%CWD%/.zephir/%HASH%/cache/IR` where `%CWD%` is the current working directory and `%HASH%`
  means a hash calculated from the current Zephir version, environment and configuration
- The compiler's messages was divided into streams. Thus, now it is possible to redirect compiler's
  output as follows: `zephir generate 2> errors.log 1> /dev/null`
- Fixed type hints for scalar arguments for PHP < 7.2
  [#1658](https://github.com/phalcon/zephir/pull/1658)
- Coloring the compiler messages in the terminal is temporarily disabled

### Fixed
- Fixed incorrect behavior of `func_get_arg` and `func_get_args` functions for PHP 7.3

## [0.11.6] - 2018-11-19
### Fixed
- Fixed incorrect behavior of `require` statement for ZendEngine3
  [#1621](https://github.com/phalcon/zephir/issues/1621)
  [#1403](https://github.com/phalcon/zephir/issues/1403)
  [#1428](https://github.com/phalcon/zephir/pull/1428)

## [0.11.4] - 2018-11-18
### Added
- Introduced a brand new CLI interface
- The preferred method of installation is to use the Zephir PHAR
  which can be downloaded from the most recent Github Release
- Added `--no-dev` option to force building the extension in production mode
  [#1520](https://github.com/phalcon/zephir/issues/1520)
- Zephir development mode will be enabled silently if your PHP binary was compiled in
  a debug configuration [#1520](https://github.com/phalcon/zephir/issues/1520)
- Added missed CLI option `--export-classes` to flag whether classes must be exported.
  If export-classes is enabled all headers are copied to `include/php/ext`.

### Fixed
- Fixed regression introduced in the 0.10.12 related to `require` file using protocols
  [#1713](https://github.com/phalcon/zephir/issues/1713)

## [0.11.3] - 2018-11-13
### Changed
- Remove legacy installers and provide a common way to install Zephir
  [#1714](https://github.com/phalcon/zephir/issues/1714). Supported installation strategies are:
  - Install as a global application (using `composer global require`)
  - Install as a PHAR file. (this feature currently in the testing phase and not released officially)
  - Install as a Git clone (using `git clone` and `composer install` inside cloned project)
  - Install as a project's dependency (using `composer require`)

## [0.11.2] - 2018-11-11
### Added
- Introduced an ability to pack project into one `zephir.phar` file (for PHP 7.1 and later)

### Changed
- Composer now is a mandatory dependency
- Improved Zephir's Compiler error reporting

### Removed
- PHP 5.5 no longer supported

### Fixed
- Correct return types hint check

[Unreleased]: https://github.com/phalcon/zephir/compare/0.11.8...HEAD
[0.11.8]: https://github.com/phalcon/zephir/compare/0.11.7...0.11.8
[0.11.7]: https://github.com/phalcon/zephir/compare/0.11.6...0.11.7
[0.11.6]: https://github.com/phalcon/zephir/compare/0.11.4...0.11.6
[0.11.4]: https://github.com/phalcon/zephir/compare/0.11.3...0.11.4
[0.11.3]: https://github.com/phalcon/zephir/compare/0.11.2...0.11.3
[0.11.2]: https://github.com/phalcon/zephir/compare/0.11.1...0.11.2
