#/!bin/sh
set -e

gcc -Wall -g -o tp1_3_convolution tp1_3_convolution.c nrio.c nralloc.c nrarith.c
./tp1_3_convolution