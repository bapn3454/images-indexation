#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "def.h"
#include "nrio.h"
#include "nrarith.h"
#include "nralloc.h"

#define THRESHOLD_RED 35
#define THRESHOLD_GREEN 35
#define THRESHOLD_BLUE 35

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
    //rgb8** I = LoadPPM_rgb8matrix("../imagetp/ppm/kids.ppm", &nrl, &nrh, &ncl, &nch);
    rgb8** I = LoadPPM_rgb8matrix("archivePPMPGM/archive10ppm/arbre1.ppm", &nrl, &nrh, &ncl, &nch);

    byte** Ix = bmatrix(nrl, nrh, ncl, nch);
    byte** Iy = bmatrix(nrl, nrh, ncl, nch);

    byte** Rmatrix = bmatrix(nrl, nrh, ncl, nch);
    byte** Gmatrix = bmatrix(nrl, nrh, ncl, nch);
    byte** Bmatrix = bmatrix(nrl, nrh, ncl, nch);

    rgb8** In = rgb8matrix(nrl, nrh, ncl, nch);

    
    for (long h = nrl + 1; h < nrh; h++)
    {
        for (long w = ncl + 1; w < nch; w++)
        {
            // ==== RED ====
            long totalH = 0l;
            totalH += I[h - 1][w - 1].r * horizontalFilter[0][0];
            totalH += I[h - 1][w].r * horizontalFilter[0][1];
            totalH += I[h - 1][w + 1].r * horizontalFilter[0][2];
            totalH += I[h][w - 1].r * horizontalFilter[1][0];
            totalH += I[h][w].r * horizontalFilter[1][1];
            totalH += I[h][w + 1].r * horizontalFilter[1][2];
            totalH += I[h + 1][w - 1].r * horizontalFilter[2][0];
            totalH += I[h + 1][w].r * horizontalFilter[2][1];
            totalH += I[h + 1][w + 1].r * horizontalFilter[2][2];

            totalH = abs(totalH) / 4l;
            Ix[h][w] = totalH;
            
            long totalV = 0l;
            totalV += I[h - 1][w - 1].r * verticalFilter[0][0];
            totalV += I[h - 1][w].r * verticalFilter[0][1];
            totalV += I[h - 1][w + 1].r * verticalFilter[0][2];
            totalV += I[h][w - 1].r * verticalFilter[1][0];
            totalV += I[h][w].r * verticalFilter[1][1];
            totalV += I[h][w + 1].r * verticalFilter[1][2];
            totalV += I[h + 1][w - 1].r * verticalFilter[2][0];
            totalV += I[h + 1][w].r * verticalFilter[2][1];
            totalV += I[h + 1][w + 1].r * verticalFilter[2][2];

            totalV = abs(totalV) / 4l;
            Iy[h][w] = totalV;
            
            // gradient norm
            byte norm = sqrt((totalH * totalH) + (totalV * totalV));
            // apply the threshold
            byte finalNorm = norm > THRESHOLD_RED ? 255 : 0;
            Rmatrix[h][w] = finalNorm;

            // ==== GREEN ====
            totalH = 0l;
            totalH += I[h - 1][w - 1].g * horizontalFilter[0][0];
            totalH += I[h - 1][w].g * horizontalFilter[0][1];
            totalH += I[h - 1][w + 1].g * horizontalFilter[0][2];
            totalH += I[h][w - 1].g * horizontalFilter[1][0];
            totalH += I[h][w].g * horizontalFilter[1][1];
            totalH += I[h][w + 1].g * horizontalFilter[1][2];
            totalH += I[h + 1][w - 1].g * horizontalFilter[2][0];
            totalH += I[h + 1][w].g * horizontalFilter[2][1];
            totalH += I[h + 1][w + 1].g * horizontalFilter[2][2];

            totalH = abs(totalH) / 4l;
            Ix[h][w] = totalH;
            
            totalV = 0l;
            totalV += I[h - 1][w - 1].g * verticalFilter[0][0];
            totalV += I[h - 1][w].g * verticalFilter[0][1];
            totalV += I[h - 1][w + 1].g * verticalFilter[0][2];
            totalV += I[h][w - 1].g * verticalFilter[1][0];
            totalV += I[h][w].g * verticalFilter[1][1];
            totalV += I[h][w + 1].g * verticalFilter[1][2];
            totalV += I[h + 1][w - 1].g * verticalFilter[2][0];
            totalV += I[h + 1][w].g * verticalFilter[2][1];
            totalV += I[h + 1][w + 1].g * verticalFilter[2][2];

            totalV = abs(totalV) / 4l;
            Iy[h][w] = totalV;
            
            // gradient norm
            norm = sqrt((totalH * totalH) + (totalV * totalV));
            // apply the threshold
            finalNorm = norm > THRESHOLD_GREEN ? 255 : 0;
            Gmatrix[h][w] = finalNorm;

            // ==== BLUE ====
            totalH = 0l;
            totalH += I[h - 1][w - 1].b * horizontalFilter[0][0];
            totalH += I[h - 1][w].b * horizontalFilter[0][1];
            totalH += I[h - 1][w + 1].b * horizontalFilter[0][2];
            totalH += I[h][w - 1].b * horizontalFilter[1][0];
            totalH += I[h][w].b * horizontalFilter[1][1];
            totalH += I[h][w + 1].b * horizontalFilter[1][2];
            totalH += I[h + 1][w - 1].b * horizontalFilter[2][0];
            totalH += I[h + 1][w].b * horizontalFilter[2][1];
            totalH += I[h + 1][w + 1].b * horizontalFilter[2][2];

            totalH = abs(totalH) / 4l;
            Ix[h][w] = totalH;
            
            totalV = 0l;
            totalV += I[h - 1][w - 1].b * verticalFilter[0][0];
            totalV += I[h - 1][w].b * verticalFilter[0][1];
            totalV += I[h - 1][w + 1].b * verticalFilter[0][2];
            totalV += I[h][w - 1].b * verticalFilter[1][0];
            totalV += I[h][w].b * verticalFilter[1][1];
            totalV += I[h][w + 1].b * verticalFilter[1][2];
            totalV += I[h + 1][w - 1].b * verticalFilter[2][0];
            totalV += I[h + 1][w].b * verticalFilter[2][1];
            totalV += I[h + 1][w + 1].b * verticalFilter[2][2];

            totalV = abs(totalV) / 4l;
            Iy[h][w] = totalV;
            
            // gradient norm
            norm = sqrt((totalH * totalH) + (totalV * totalV));
            // apply the threshold
            finalNorm = norm > THRESHOLD_BLUE ? 255 : 0;
            Bmatrix[h][w] = finalNorm;
        }
    }


    SavePGM_bmatrix(Rmatrix, nrl, nrh, ncl, nch, "contour_couleur_R.pgm");
    SavePGM_bmatrix(Gmatrix, nrl, nrh, ncl, nch, "contour_couleur_G.pgm");
    SavePGM_bmatrix(Bmatrix, nrl, nrh, ncl, nch, "contour_couleur_B.pgm");
    free_bmatrix(I, nrl, nrh, ncl, nch);
    free_bmatrix(Ix, nrl, nrh, ncl, nch);
    free_bmatrix(Iy, nrl, nrh, ncl, nch);
    free_bmatrix(Rmatrix, nrl, nrh, ncl, nch);
    free_bmatrix(Gmatrix, nrl, nrh, ncl, nch);
    free_bmatrix(Bmatrix, nrl, nrh, ncl, nch);
    return 0;
}