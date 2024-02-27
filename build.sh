#!/bin/sh

cmake -S . -B build $@
cd build >/dev/null && make && cd - >/dev/null
