#/!bin/sh
set -e

gcc -Wall -g -o tp1_4_gradients tp1_4_gradients.c nrio.c nralloc.c nrarith.c -lm
./tp1_4_gradients