#/!bin/sh
set -e

gcc -Wall -g -o tp1_5_contours tp1_5_contours.c nrio.c nralloc.c nrarith.c -lm
./tp1_5_contours