#ifndef ATELIER_INDEXATION_FUNCTIONS_H
#define ATELIER_INDEXATION_FUNCTIONS_H

#include "def.h"
#include <stdio.h>

/*
 * PrintMask allows you to print the selected mask in the console.
 * VerifyMask allows you to post process and verify that the value from the mask convolution is correct.
 * ApplyMastToMatrix applies the selected 3*3 mask to the targeted matrix.
 * Binarises replaces each pixel by a white or a black one in function of its value.
 */


void printMask(const int mask[3][3]);
int verifyRGBValue(int value);
void initMatrix(byte **matrix, long nrh, long nch);
void applyMaskToMatrix(int mask[3][3], byte **matrix, byte **outputMatrix, int matrix_max_x, int matrix_max_y);
void applyMaskToMatrix_bounded(const int mask[3][3], byte **matrix, byte **outputMatrix, int nrl, int nrh, int ncl, int nch);
void binariesPicture(byte **matrix, byte **output, int matrix_max_x, int matrix_max_y, int limit);
void greyScalesRGBPicture(rgb8 **matrix, byte **output, int matrix_max_x, int matrix_max_y);
void histogramme(byte** img,int nrh , int nch,double *histogramme);
void histogrammeRGB(rgb8 **img, int nrh, int nch, double *histogrammeR, double * histogrammeG, double* histogrammeB);
double bhattacharyyaDistance(double* hist1,double* hist2);
void tauxDeCouleurs(rgb8 **img,double *tauxr, double *tauxg, double *tauxb, long nrl, long nrh, long ncl, long nch);
void detectionBords (byte** img, byte** output, long threshold, double* moyenneNormeGradient, double* nbPixelBord, long nrl , long nrh,long ncl,long nch);
void sauvegardeHistogramme(double* histogramme,FILE* f);
int lectureDossier(char *nomdossier);
int lectureDossierSansHist(char *nomdossier);
//int colored(rgb8** img,int nrh , int nch);
int colored(double*histogrammeBW ,double* histogrammeC,double SEUIL);
void matriceDesDistance(double **disttable,int size);
void sauvegardeTableHistogramme(double *histogramme, FILE *f,char * nom,int *index);
double euclidienneDistance(double* hist1,double* hist2);
extern const int horizontal_gradient [3][3] ;
extern const int vertical_gradient[3][3];

const int impulse_response[3][3] = {
        {1,1,1},
        {1,1,1},
        {1,1,1}
    };

    const int horizontal_gradient[3][3] = {
            {-1,0,1},
            {-2,0,2},
            {-1,0,1}
    };

    const int vertical_gradient[3][3] = {
            {-1,-2,-1},
            {0,0,0},
            {1,2,1}
    };
//void b_distToCSV(char *directory);
#endif //ATELIER_INDEXATION_FUNCTIONS_H