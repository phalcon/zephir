#!/bin/bash

phpenv rehash
sudo apt-get -qq install re2c valgrind
git submodule --quiet update --init --recursive

git clone --depth=1 https://github.com/json-c/json-c.git
cd json-c
sh autogen.sh 2&>1 /dev/null
./configure --silent
make --silent
sudo make --silent install
