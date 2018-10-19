#!/usr/bin/env bash

set -e

phpenv config-rm zephir-parser.ini || true

pushd "${TRAVIS_BUILD_DIR}/ext"

$(phpenv which phpize)

./configure --with-php-config=$(phpenv which php-config) --enable-test

make -j"$(getconf _NPROCESSORS_ONLN)"
make install

popd

exit $?
