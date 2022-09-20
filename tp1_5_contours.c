#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "nrio.h"
#include "nrarith.h"
#include "nralloc.h"

#define THRESHOLD 20

int main(void)
{
    int horizontalFilter[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int verticalFilter[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    long nrh, nrl, nch, ncl;
    //byte** I = LoadPGM_bmatrix("../imagetp/route0.pgm", &nrl, &nrh, &ncl, &nch);
    byte** I = LoadPGM_bmatrix("archivePPMPGM/archive10pgm/arbre1.pgm", &nrl, &nrh, &ncl, &nch);
    byte** Ix = bmatrix(nrl, nrh, ncl, nch);
    byte** Iy = bmatrix(nrl, nrh, ncl, nch);
    byte** In = bmatrix(nrl, nrh, ncl, nch);

    
    for (long h = nrl + 1; h < nrh; h++)
    {
        for (long w = ncl + 1; w < nch; w++)
        {
            // horizontal gradient
            long totalH = 0l;
            // top line
            totalH += I[h - 1][w - 1] * horizontalFilter[0][0];
            totalH += I[h - 1][w] * horizontalFilter[0][1];
            totalH += I[h - 1][w + 1] * horizontalFilter[0][2];
            // middle line
            totalH += I[h][w - 1] * horizontalFilter[1][0];
            totalH += I[h][w] * horizontalFilter[1][1];
            totalH += I[h][w + 1] * horizontalFilter[1][2];
            // bottom line
            totalH += I[h + 1][w - 1] * horizontalFilter[2][0];
            totalH += I[h + 1][w] * horizontalFilter[2][1];
            totalH += I[h + 1][w + 1] * horizontalFilter[2][2];

            totalH = abs(totalH) / 4l;
            Ix[h][w] = abs(totalH);

            
            // vertical gradient
            long totalV = 0l;
            // top line
            totalV += I[h - 1][w - 1] * verticalFilter[0][0];
            totalV += I[h - 1][w] * verticalFilter[0][1];
            totalV += I[h - 1][w + 1] * verticalFilter[0][2];
            // middle line
            totalV += I[h][w - 1] * verticalFilter[1][0];
            totalV += I[h][w] * verticalFilter[1][1];
            totalV += I[h][w + 1] * verticalFilter[1][2];
            // bottom line
            totalV += I[h + 1][w - 1] * verticalFilter[2][0];
            totalV += I[h + 1][w] * verticalFilter[2][1];
            totalV += I[h + 1][w + 1] * verticalFilter[2][2];

            totalV = abs(totalV) / 4l;
            Iy[h][w] = totalV;
            
            
            // gradient norm
            byte norm = sqrt((totalH * totalH) + (totalV * totalV));
            // apply the threshold
            byte finalNorm = norm > THRESHOLD ? 255 : 0;
            In[h][w] = finalNorm;
        }
    }


    SavePGM_bmatrix(In, nrl, nrh, ncl, nch, "contours.pgm");
    free_bmatrix(I, nrl, nrh, ncl, nch);
    free_bmatrix(Ix, nrl, nrh, ncl, nch);
    free_bmatrix(Iy, nrl, nrh, ncl, nch);
    free_bmatrix(In, nrl, nrh, ncl, nch);
    return 0;
}