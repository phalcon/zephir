#!/bin/sh
#
# This file is part of the Zephir.
#
# (c) Zephir Team <team@zephir-lang.com>
#
# For the full copyright and license information, please view the LICENSE
# file that was distributed with this source code.

# -e	Exit immediately if a command exits with a non-zero status.
# -u	Treat unset variables as an error when substituting.
set -eu

PROJECT_ROOT=$(readlink -enq "$(dirname $0)/../")

gcov_report=${PROJECT_ROOT}/unit-tests/output/lcov.info
phpunit_report=${PROJECT_ROOT}/unit-tests/output/clover.xml

if [ -z ${COLLECT_COVERAGE+x} ] || [ "$COLLECT_COVERAGE" != "true" ]; then
	printf "Uploading reports is not enabled.\nSkip uploading reports to Codecov.\n"
	exit 0
fi

if [ ! -z ${TRAVIS+x} ] && [ "$TRAVIS" = "true" ]; then
	if [ "$TRAVIS_PHP_VERSION" = "5.6" ]; then
		printf "Collecting coverage date is disabled for PHP 5.6.\nSkip uploading reports to Codecov.\n"
		exit 0
	fi
fi

if [ $(which lcov 2>/dev/null) = "" ]; then
	printf "lcov does not exist.\nSkip capturing coverage data.\n"
else
	# Capture coverage data
	lcov \
		--quiet \
		--no-checksum \
		--directory ext \
		--base-directory=${PROJECT_ROOT} \
		--capture \
		--compat-libtool \
		--output-file ${gcov_report} 2>/dev/null

	# Remove files matching non-project patterns
	lcov \
		--quiet \
		--remove ${gcov_report} "/usr*" \
		--remove ${gcov_report} "${HOME}/.phpenv/*" \
		--compat-libtool \
		--output-file ${gcov_report} 2>/dev/null

	# FIXME: Fix the report
	# 	Cannot open source file ${PROJECT_ROOT}/kernel/fcall.h
	sed -i.bak s_${PROJECT_ROOT}/kernel_${PROJECT_ROOT}/ext/kernel_g ${gcov_report}
fi

# Note: to upload a coverage report, set the CODECOV_TOKEN environment variable
#    export CODECOV_TOKEN=<codecov token>

if [ -z ${CODECOV_TOKEN+x} ]; then
	printf "The CODECOV_TOKEN variable is absent or empty.\nSkip uploading reports to Codecov.\n"
	exit 0
fi

curl -sSl https://codecov.io/bash -o "${HOME}/bin/codecov"
chmod +x "${HOME}/bin/codecov"

if [ -f ${gcov_report} ]; then
	codecov -f ${gcov_report}
fi

if [ -f ${phpunit_report} ]; then
	codecov -f ${phpunit_report}
fi
