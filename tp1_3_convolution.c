#include<stdio.h>
#include<stdlib.h>

#include "def.h"
#include "nrio.h"
#include "nrarith.h"
#include "nralloc.h"

#define FILTER_WIDTH 3
#define FILTER_HEIGHT 3

int main(void)
{
    byte filter[FILTER_WIDTH][FILTER_HEIGHT] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    byte totalFilterWeights = 9;

    long nrh, nrl, nch, ncl;
    byte** I = LoadPGM_bmatrix("cubesx3.pgm", &nrl, &nrh, &ncl, &nch);
    byte** M = bmatrix(nrl, nrh, ncl, nch);

    // convolutions !
    // nrh = height - 1, nch = width - 1 (others are just zeros)
    for (long h = nrl + 1; h < nrh; h++)
    {
        for (long w = ncl + 1; w < nch; w++)
        {
            long total = 0l;
            // top line
            total += I[h - 1][w - 1] * filter[0][0];
            total += I[h - 1][w] * filter[0][1];
            total += I[h - 1][w + 1] * filter[0][2];
            // middle line
            total += I[h][w - 1] * filter[1][0];
            total += I[h][w] * filter[1][1];
            total += I[h][w + 1] * filter[1][2];
            // bottom line
            total += I[h + 1][w - 1] * filter[2][0];
            total += I[h + 1][w] * filter[2][1];
            total += I[h + 1][w + 1] * filter[2][2];

            total /= totalFilterWeights;
            M[h][w] = total;
        }
    }


    SavePGM_bmatrix(M, nrl, nrh, ncl, nch, "convolution.pgm");
    free_bmatrix(I, nrl, nrh, ncl, nch);
    free_bmatrix(M, nrl, nrh, ncl, nch);
    return 0;
}