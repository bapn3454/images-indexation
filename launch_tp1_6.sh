#/!bin/sh
set -e

gcc -g -o tp1_6_hystheresis tp1_6_hystheresis.c nrio.c nralloc.c nrarith.c -lm
./tp1_6_hystheresis