#!/bin/bash

cd freetype-2.9.1
./autogen.sh
emconfigure ./configure --host=asmjs --build=$(uname -m)
emmake make
emcc -I ./include -o ../freetype.o ../freetype.c
emcc -O3 --llvm-lto 1 -s ALLOW_MEMORY_GROWTH=1 -s 'EXTRA_EXPORTED_RUNTIME_METHODS=[\"writeArrayToMemory\"]' -s WASM=0 -s NO_EXIT_RUNTIME=1 -s AGGRESSIVE_VARIABLE_ELIMINATION=1 -s NO_DYNAMIC_EXECUTION=1 --memory-init-file 0 -s NO_FILESYSTEM=1 -s ../freetype.o objs/.libs/libfreetype.a -o ../freetype.js
