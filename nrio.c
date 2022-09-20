/* -------------- */
/* --- nrio.c --- */
/* -------------- */

/*
 * Copyright (c) 2000, Lionel Lacassagne LIS-UPMC + Imasys
 */

/*
 * modif 22-02-2001 : display_cube, write_cube, fwrite_cube, fread_cube
 * modif 06-10-2001 : Load/Write PGM and PNM files
 */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h> /* isdigit */
#include <string.h> /* memcpy */
/*#include <memory.h> /* memcpy */

#include "def.h"
#include "nralloc.h"
#include "nrio.h"

/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_bvector(byte *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s", name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_svector(short *v,long nl,long nh, char *format, char *name)
/* -------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_usvector(ushort *v,long nl,long nh, char *format, char *name)
/* ---------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i16vector(int16 *v,long nl,long nh, char *format, char *name)
/* ---------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui16vector(uint16 *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_ivector(int *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------ */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_uivector(uint *v,long nl,long nh, char *format, char *name)
/* -------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i32vector(int32 *v,long nl,long nh, char *format, char *name)
/* ---------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_ui32vector(uint32 *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------------ */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_vector(float *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_dvector(double *v,long nl,long nh, char *format, char *name)
/* --------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_bvector_number(byte *v,long nl,long nh, char *format, char *name)
/* -------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_svector_number(short *v,long nl,long nh, char *format, char *name)
/* --------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);
  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_usvector_number(ushort *v,long nl,long nh, char *format, char *name)
/* ----------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);
  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i16vector_number(int16 *v,long nl,long nh, char *format, char *name)
/* ----------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);
  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui16vector_number(uint16 *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) puts(name);
  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ivector_number(int *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_uivector_number(uint *v,long nl,long nh, char *format, char *name)
/* --------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i32vector_number(int32 *v,long nl,long nh, char *format, char *name)
/* ----------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui32vector_number(uint32 *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_vector_number(float *v,long nl,long nh, char *format, char *name)
/* -------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_dvector_number(double *v,long nl,long nh, char *format, char *name)
/* ---------------------------------------------------------------------------------------- */
{
  long i;

  if(name != NULL) printf("%s\n", name);

  for(i=nl; i<=nh; i++) {
    printf(format, i);
  }
  putchar('\n');

  for(i=nl; i<=nh; i++) {
    printf(format, v[i]);
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_bvector_cycle(byte *v,long nl,long nh, char *format, char *name)
/* ----------------------------------------------------------------------- */
{
  long i;
  byte first, next;
  byte *displayed;

  if(name != NULL) printf("%s", name);

  displayed = bvector0(nl, nh);
  
  for(i=nl; i<=nh; i++) {
    if(!displayed[i]) {
      displayed[i] = 1;
      printf(format, i);
      first = (byte) i;
      next = v[i];
      while(first != next) {
        displayed[next] = 1;
        printf(format, next);
        next = v[next];
      }
      putchar('\n');
    }
  }
  putchar('\n');
  free_bvector(displayed, nl, nh);
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_svector_cycle(short *v,long nl,long nh, char *format, char *name)
/* ------------------------------------------------------------------------ */
{
  long i;
  short first, next;
  byte *displayed;

  if(name != NULL) printf("%s", name);

  displayed = bvector0(nl, nh);
  
  for(i=nl; i<=nh; i++) {
    if(!displayed[i]) {
      displayed[i] = 1;
      printf(format, i);
      first = (short) i;
      next = v[i];
      while(first != next) {
        displayed[next] = 1;
        printf(format, next);
        next = v[next];
      }
      putchar('\n');
    }
  }
  putchar('\n');
  free_bvector(displayed, nl, nh);
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_usvector_cycle(ushort *v,long nl,long nh, char *format, char *name)
/* -------------------------------------------------------------------------- */
{
  long i;
  ushort first, next;
  byte *displayed;

  if(name != NULL) printf("%s", name);

  displayed = bvector0(nl, nh);
  
  for(i=nl; i<=nh; i++) {
    if(!displayed[i]) {
      displayed[i] = 1;
      printf(format, i);
      first = (ushort) i;
      next = v[i];
      while(first != next) {
        displayed[next] = 1;
        printf(format, next);
        next = v[next];
      }
      putchar('\n');
    }
  }
  putchar('\n');
  free_bvector(displayed, nl, nh);
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_bmatrix0(byte **m, long nrow, long ncol, char *format, char *name)
/* ------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=0; i<nrow; i++) {
    for(j=0; j<ncol; j++)
      printf(format, m[i][j]);
    putchar('\n');
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_imatrix0(int **m, long nrow, long ncol, char *format, char *name)
/* ------------------------------------------------------------------------ */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=0; i<nrow; i++) {
    for(j=0; j<ncol; j++)
      printf(format, m[i][j]);
    putchar('\n');
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_matrix0(float **m, long nrow, long ncol, char *format, char *name)
/* ------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=0; i<nrow; i++) {
    for(j=0; j<ncol; j++)
      printf(format, m[i][j]); /* "%8.4f " */
    putchar('\n');
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_bmatrix(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_smatrix(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_usmatrix(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i16matrix(int16 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui16matrix(uint16 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ---------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i32matrix(int32 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui32matrix(uint32 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ---------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_imatrix(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_matrix(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_dmatrix(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_rgb8matrix(rgb8 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j].r, m[i][j].g, m[i][j].b);
    }
    putchar('\n');
  }
}

/* ------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_bmatrix_number(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ------------------------------------------------------------------------------------------------------------ */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_smatrix_number(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_usmatrix_number(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* --------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i16matrix_number(int16 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* --------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui16matrix_number(uint16 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i32matrix_number(int32 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* --------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui32matrix_number(uint32 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_imatrix_number(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) display_matrix_number(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ------------------------------------------------------------------------------------------------------------ */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* -------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_dmatrix_number(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* -------------------------------------------------------------------------------------------------------------- */
{
  long i,j;

  if(name != NULL) puts(name);

  // 1ere ligne
  printf("%5c", '#');
  for(j=ncl; j<=nch; j++) {
    printf(format, j);
  }
  putchar('\n');
  for(i=nrl; i<=nrh; i++) {
    printf("[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      printf(format, m[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}
/* ------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i8cube(int8 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ------------------------------------------------------------------------------------------------------------------------- */
{
  long i,j,k;

  if(name != NULL) puts(name);

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        printf(format, c[k][i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
}
/* --------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i16cube(int16 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* --------------------------------------------------------------------------------------------------------------------------- */
{
  long i,j,k;

  if(name != NULL) puts(name);

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        printf(format, c[k][i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
}
/* ----------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui16cube(uint16 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------------------------------- */
{
  long i,j,k;

  if(name != NULL) puts(name);

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        printf(format, c[k][i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
}
/* --------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_i32cube(int32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* --------------------------------------------------------------------------------------------------------------------------- */
{
  long i,j,k;

  if(name != NULL) puts(name);

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        printf(format, c[k][i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
}
/* ----------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_ui32cube(uint32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------------------------------- */
{
  long i,j,k;

  if(name != NULL) puts(name);

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        printf(format, c[k][i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
}
/* ----------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) display_f32cube(float32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name)
/* ----------------------------------------------------------------------------------------------------------------------------- */
{
  long i,j,k;

  if(name != NULL) puts(name);

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        printf(format, c[k][i][j]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bvector(byte *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_bvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_svector(short *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_svector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usvector(ushort *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_usvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i16vector(int16 *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i16vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_ui16vector(uint16 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ui16vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_ivector(int *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ivector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i32vector(int32 *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i32vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_vector(float *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_vvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb8vector(rgb8 *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb8vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k].r, v[k].g, v[k].b); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_rgb32vector(rgb32 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb32vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k].r, v[k].g, v[k].b); } fputc('\n', f);
  fclose(f);
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dvector(double *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_dvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------- */
/* --- write_vector_T --- */
/* ---------------------- */
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bvector_T(byte *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_bvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_svector_T(short *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_svector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_usvector_T(ushort *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_usvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_i16vector_T(int16 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i16vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ui16vector_T(uint16 *v,long nl,long nh, char *format, char *filename)
/* -------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ui16vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ivector_T(int *v,long nl,long nh, char *format, char *filename)
/* -------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ivector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_i32vector_T(int32 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i32vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_vvector_T(float *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_vvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_rgb8vector_T(rgb8 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb8vector_T"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k].r, v[k].g, v[k].b); fputc('\n', f); }
  fclose(f);
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb32vector_T(rgb32 *v,long nl,long nh, char *format, char *filename)
/* -------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb32vector_T"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k].r, v[k].g, v[k].b); fputc('\n', f); }
  fclose(f);
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dvector_T(double *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_dvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ----------------------------- */
/* --- write_vector_T_number --- */
/* ----------------------------- */
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bvector_T_number(byte *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_bvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_svector_T_number(short *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_svector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usvector_T_number(ushort *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_usvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i16vector_T_number(int16 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i16vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ui16vector_T_number(uint16 *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ui16vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ivector_T_number(int *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ivector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i32vector_T_number(int32 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i32vector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_vvector_T_number(float *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_vvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb8vector_T_number(rgb8 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb8vector_T"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k].r, v[k].g, v[k].b); fputc('\n', f); }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb32vector_T_number(rgb32 *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb32vector_T"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k].r, v[k].g, v[k].b); fputc('\n', f); }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_dvector_T_number(double *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------ */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_dvector"); }
  for(k=nl; k<=nh; k++) { fprintf(f, "%3d ", k); fprintf(f, format, v[k]); fputc('\n', f); }
  fclose(f);
}
/* --------------------------- */
/* --- write_vector_number --- */
/* --------------------------- */
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bvector_number(byte *v,long nl,long nh, char *format, char *filename)
/* -------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_bvector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_svector_number(short *v,long nl,long nh, char *format, char *filename)
/* --------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_svector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usvector_number(ushort *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_usvector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i16vector_number(int16 *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i16vector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ui16vector_number(uint16 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ui16vector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ivector_number(int *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ivector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i32vector_number(int32 *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_i32vector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb8vector_number(rgb8 *v,long nl,long nh, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb8vector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb32vector_number(rgb32 *v,long nl,long nh, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_rgb32vector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_vector_number(float *v,long nl,long nh, char *format, char *filename)
/* -------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ivector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dvector_number(double *v,long nl,long nh, char *format, char *filename)
/* ---------------------------------------------------------------------------------------- */
{
  long  k;
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) { nrerror("Can't open file in write_ivector_number"); }
  for(k=nl; k<=nh; k++) { fprintf(f, format, k,k,k);} fputc('\n', f);
  for(k=nl; k<=nh; k++) { fprintf(f, format, v[k]); } fputc('\n', f);
  fclose(f);
}
/* ---------------------- */
/* --- write_vector_k --- */
/* ---------------------- */
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bvector_k(byte *v,long nl,long nh, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_bvector(v, nl, nh, format, filename_k);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_svector_k(short *v,long nl,long nh, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_svector(v, nl, nh, format, filename_k);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usvector_k(ushort *v,long nl,long nh, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_usvector(v, nl, nh, format, filename_k);
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ivector_k(int *v,long nl,long nh, char *format, char *filename, int k)
/* --------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_ivector(v, nl, nh, format, filename_k);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_vector_k(float *v,long nl,long nh, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_vector(v, nl, nh, format, filename_k);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_dvector_k(double *v,long nl,long nh, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------ */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_dvector(v, nl, nh, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bvector_number_k(byte *v, long nl, long nh, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_bvector_number(v, nl, nh, format, filename_k);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_svector_number_k(short *v, long nl, long nh, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_svector_number(v, nl, nh, format, filename_k);
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usvector_number_k(ushort *v, long nl, long nh, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_usvector_number(v, nl, nh, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_ivector_number_k(int *v, long nl, long nh, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------ */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_ivector_number(v, nl, nh, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_vector_number_k(float *v, long nl, long nh, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_vector_number(v, nl, nh, format, filename_k);
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dvector_number_k(double *v, long nl, long nh, char *format, char *filename, int k)
/* --------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_dvector_number(v, nl, nh, format, filename_k);
}

/* --------------------- */
/* --- write_bmatrix --- */
/* --------------------- */

/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_bmatrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_smatrix(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------ */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_smatrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_usmatrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_imatrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_matrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_dmatrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_rgb8matrix(rgb8 **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_rgb8matrix");
  }

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j].r, m[i][j].g, m[i][j].b);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix_k(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_bmatrix(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_k(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_smatrix(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_usmatrix(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix_k(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_imatrix(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix_k(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_matrix(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix_k(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_dmatrix(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix_T(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_bmatrix_T");
  }

  for(j=ncl; j<=nch; j++) {
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_T(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_smatrix_T");
  }

  for(j=ncl; j<=nch; j++) {
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix_T(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_usmatrix_T");
  }

  for(j=ncl; j<=nch; j++) {
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_imatrix_T(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------ */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_imatrix_T");
  }

  for(j=ncl; j<=nch; j++) {
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix_T(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_matrix");
  }

  for(j=ncl; j<=nch; j++) {
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix_T(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* --------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_dmatrix");
  }

  for(j=ncl; j<=nch; j++) {
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix_T_k(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_bmatrix_T(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_T_k(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_smatrix_T(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix_T_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_usmatrix_T(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix_T_k(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* --------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_imatrix_T(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix_T_k(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------------------- */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_matrix_T(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_dmatrix_T_k(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------------ */
{
  char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_dmatrix_T(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_bmatrix_number(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------------ */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_bmatrix_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(j=ncl; j<=nch; j++) {
    fprintf(f, format, j);
  }
  fputc('\n', f);

  for(i=nrl; i<=nrh; i++) {
    fprintf(f, "[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_number(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_smatrix");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(j=ncl; j<=nch; j++) {
    fprintf(f, format, j);
  }
  fputc('\n', f);

  for(i=nrl; i<=nrh; i++) {
    fprintf(f, "[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix_number(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* --------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_usmatrix");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(j=ncl; j<=nch; j++) {
    fprintf(f, format, j);
  }
  fputc('\n', f);

  for(i=nrl; i<=nrh; i++) {
    fprintf(f, "[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix_number(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ----------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_imatrix");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(j=ncl; j<=nch; j++) {
    fprintf(f, format, j);
  }
  fputc('\n', f);

  for(i=nrl; i<=nrh; i++) {
    fprintf(f, "[%3d]", i);
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_matrix_number(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------------ */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_matrix_number");
  }

  /* entete */
  fprintf(f, "%4d", 0);
  for(j=ncl; j<=nch; j++) {
    fprintf(f, format, (float)j);
  }
  fputc('\n', f);

  for(i=nrl; i<=nrh; i++) {
    fprintf(f, "%4d", i);
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix_number(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_dmatrix_number");
  }

  /* entete */
  fprintf(f, "%4d", 0);
  for(j=ncl; j<=nch; j++) {
    fprintf(f, format, (float)j);
  }
  fputc('\n', f);

  for(i=nrl; i<=nrh; i++) {
    fprintf(f, "%4d", i);
    for(j=ncl; j<=nch; j++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix_number_k(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* --------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_bmatrix_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_number_k(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ---------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_smatrix_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_usmatrix_number_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------------------ */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_usmatrix_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix_number_k(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* -------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_imatrix_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix_number_k(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* --------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_matrix_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix_number_k(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_dmatrix_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------- */
/* --- write_matrix_T_number --- */
/* ----------------------------- */
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix_T_number(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_bmatrix_T_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(i=nrl; i<=nrh; i++) {
    fprintf(f, format, i);
  }
  fputc('\n', f);


  for(j=ncl; j<=nch; j++) {
    fprintf(f, "[%3d]", j);
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_T_number(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* --------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_smatrix_T_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(i=nrl; i<=nrh; i++) {
    fprintf(f, format, i);
  }
  fputc('\n', f);


  for(j=ncl; j<=nch; j++) {
    fprintf(f, "[%3d]", j);
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix_T_number(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ----------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_usmatrix_T_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(i=nrl; i<=nrh; i++) {
    fprintf(f, format, i);
  }
  fputc('\n', f);


  for(j=ncl; j<=nch; j++) {
    fprintf(f, "[%3d]", j);
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix_T_number(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_imatrix_T_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(i=nrl; i<=nrh; i++) {
    fprintf(f, format, (float)i);
  }
  fputc('\n', f);


  for(j=ncl; j<=nch; j++) {
    fprintf(f, "[%3d]", j);
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix_T_number(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_matrix_T_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(i=nrl; i<=nrh; i++) {
    fprintf(f, format, (float)i);
  }
  fputc('\n', f);


  for(j=ncl; j<=nch; j++) {
    fprintf(f, "[%3d]", j);
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix_T_number(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------------------- */
{
  long  i,j;
  
  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_matrix_T_number");
  }

  /* 1ere ligne */
  fprintf(f, "%5c", '#');
  for(i=nrl; i<=nrh; i++) {
    fprintf(f, format, i);
  }
  fputc('\n', f);


  for(j=ncl; j<=nch; j++) {
    fprintf(f, "[%3d]", j);
    for(i=nrl; i<=nrh; i++) {
      fprintf(f, format, m[i][j]);
    }
    fputc('\n', f);
  }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_bmatrix_T_number_k(byte **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_bmatrix_T_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_smatrix_T_number_k(short **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_smatrix_T_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_usmatrix_T_number_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ------------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_usmatrix_T_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_imatrix_T_number_k(int **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_imatrix_T_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_matrix_T_number_k(float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_matrix_T_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_dmatrix_T_number_k(double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k)
/* ----------------------------------------------------------------------------------------------------------- */
{
  static char filename_k[256];

  sprintf(filename_k, "%s%02d.txt", filename, k);
  write_dmatrix_T_number(m, nrl, nrh, ncl, nch, format, filename_k);
}
/* ---------------- */
/* -- write_cube -- */
/* ---------------- */
/* ------------------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) write_i8cube(int8 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *format, char *filename)
/* ------------------------------------------------------------------------------------------------------------------------------ */
{
  int i, j, k;

  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_i8cube");
  }

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        fprintf(f, format, c[k][i][j]);
      }
      fputc('\n', f);
    }
    fputc('\n', f);
  }

  fclose(f);
}
/* -------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i16cube(int16 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;

  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_i16cube");
  }

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        fprintf(f, format, c[k][i][j]);
      }
      fputc('\n', f);
    }
    fputc('\n', f);
  }

  fclose(f);
}
/* ---------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ui16cube(uint16 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;

  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_ui16cube");
  }

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        fprintf(f, format, c[k][i][j]);
      }
      fputc('\n', f);
    }
    fputc('\n', f);
  }

  fclose(f);
}
/* -------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_i32cube(int32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *format, char *filename)
/* -------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;

  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_i32cube");
  }

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        fprintf(f, format, c[k][i][j]);
      }
      fputc('\n', f);
    }
    fputc('\n', f);
  }

  fclose(f);
}
/* ---------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_ui32cube(uint32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;

  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_ui32cube");
  }

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        fprintf(f, format, c[k][i][j]);
      }
      fputc('\n', f);
    }
    fputc('\n', f);
  }

  fclose(f);
}
/* ---------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) write_f32cube(float32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *format, char *filename)
/* ---------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;

  FILE *f;

  f = fopen(filename, "wt");
  if(f == NULL) {
    nrerror("Can't open file in write_f32cube");
  }

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      for(j=ncl; j<=nch; j++) {
        fprintf(f, format, c[k][i][j]);
      }
      fputc('\n', f);
    }
    fputc('\n', f);
  }

  fclose(f);
}

/* ------------------ */
/* -- fread_vector -- */
/* ------------------ */
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_bvector(char *filename, byte *v,long nl,long nh)
/* ------------------------------------------------------------------- */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_bvector");

  nread = fread(v+nl, sizeof(byte), ncol, f);
  if(nread != ncol) nrerror("fread_bvector can't read the whole vector");
  fclose(f);
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_svector(char *filename, short *v,long nl,long nh)
/* -------------------------------------------------------------------- */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_svector");

  nread = fread(v+nl, sizeof(short), ncol, f);
  if(nread != ncol) nrerror("fread_svector can't read the whole vector");
  fclose(f);
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_usvector(char *filename, ushort *v,long nl,long nh)
/* ---------------------------------------------------------------------- */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_svector");

  nread = fread(v+nl, sizeof(ushort), ncol, f);
  if(nread != ncol) nrerror("fread_usvector can't read the whole vector");
  fclose(f);
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) fread_ivector(char *filename, int *v,long nl,long nh)
/* ------------------------------------------------------------------ */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_ivector");

  nread = fread(v+nl, sizeof(int), ncol, f);
  if(nread != ncol) nrerror("fread_ivector can't read the whole vector");
  fclose(f);
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_uivector(char *filename, uint *v,long nl,long nh)
/* -------------------------------------------------------------------- */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_uivector");

  nread = fread(v+nl, sizeof(int), ncol, f);
  if(nread != ncol) nrerror("fread_uivector can't read the whole vector");
  fclose(f);
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_vector(char *filename, float *v,long nl,long nh)
/* ------------------------------------------------------------------- */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_vector");

  nread = fread(v+nl, sizeof(float), ncol, f);
  if(nread != ncol) nrerror("fread_fvector can't read the whole vector");
  fclose(f);
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_dvector(char *filename, double *v,long nl,long nh)
/* --------------------------------------------------------------------- */
{
  long ncol=nh-nl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_dvector");

  nread = fread(v+nl, sizeof(double), ncol, f);
  if(nread != ncol) nrerror("fread_dvector can't read the whole vector");
  fclose(f);
}
/* ------------------- */
/* -- fwrite_matrix -- */
/* ------------------- */
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) fwrite_bmatrix(byte **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------ */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL) nrerror("Can't open file in fwrite_bmatrix"); 

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(byte), ncol, f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_smatrix(short **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL) nrerror("Can't open file in fwrite_smatrix");

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(short), ncol, f);
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_usmatrix(ushort **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* --------------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL) nrerror("Can't open file in fwrite_usmatrix");

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(ushort), ncol, f);
  }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_imatrix(int **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* ----------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_imatrix");

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(int), ncol, f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_uimatrix(uint **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_uimatrix");

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(int), ncol, f);
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) fwrite_matrix(float **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------ */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL) nrerror("Can't open file in fwrite_matrix");

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(float), ncol, f);
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_dmatrix(double **m,long nrl,long nrh,long ncl, long nch, char *filename)
/* -------------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL) nrerror("Can't open file in fwrite_dmatrix");

  for(i=nrl; i<=nrh; i++) {
    fwrite(m[i]+nrl, sizeof(double), ncol, f);
  }
  fclose(f);
}
/* ------------------ */
/* -- fread_matrix -- */
/* ------------------ */
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_bmatrix(char *filename, byte **m,long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_bmatrix"); 

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(byte), ncol, f);
    if(nread != ncol) nrerror("fread_bmatrix : can't read data");
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) fread_smatrix(char *filename, short **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------------------ */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_smatrix");

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(short), ncol, f);
    if(nread != ncol)
      nrerror("fread_smatrix : can't read data");
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_usmatrix(char *filename, ushort **m,long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_usmatrix");

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(ushort), ncol, f);
    if(nread != ncol) nrerror("fread_usmatrix : can't read data");
  }
  fclose(f);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_imatrix(char *filename, int **m,long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_imatrix");

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(int), ncol, f);
    if(nread != ncol) nrerror("fread_imatrix : can't read data");
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) fread_uimatrix(char *filename, uint **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------------------ */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_uimatrix");

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(int), ncol, f);
    if(nread != ncol) nrerror("fread_uimatrix : can't read data");
  }
  fclose(f);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_matrix(char *filename, float **m,long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_matrix");

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(float), ncol, f);
    if(nread != ncol) nrerror("fread_bmatrix : can't read data");
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_dmatrix(char *filename, double **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------------------- */
{
  long  i, ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL) nrerror("Can't open file in fread_dmatrix");

  for(i=nrl; i<=nrh; i++) {
    nread = fread(m[i]+nrl, sizeof(double), ncol, f);
    if(nread != ncol) nrerror("fread_bmatrix : can't read data");
  }
  fclose(f);
}

/* ---------------- */
/* -- fread_cube -- */
/* ---------------- */
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_i8cube(char *filename, int8 ***c,long ndl,long ndh,long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_i8cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fread( &(c[k][i][ncl]), sizeof(int8), ncol, f);
      if(nread != ncol) nrerror("fread_i8cube : can't write data");
    }
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_i16cube(char *filename, int16 ***c,long ndl,long ndh,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_i16cube");

  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fread( &(c[k][i][ncl]), sizeof(int16), ncol, f);
      if(nread != ncol) nrerror("fread_i16cube : can't write data");
    }
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_ui16cube(char *filename, uint16 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_ui16cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fread( &(c[k][i][ncl]), sizeof(uint16), ncol, f);
      if(nread != ncol) nrerror("fread_ui16cube : can't write data");
    }
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) fread_i32cube(char *filename, int32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------------------------ */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_i32cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fread( &(c[k][i][ncl]), sizeof(int32), ncol, f);
      if(nread != ncol) nrerror("fread_i32cube : can't write data");
    }
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_ui32cube(char *filename, uint32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_ui32cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fread( &(c[k][i][ncl]), sizeof(uint32), ncol, f);
      if(nread != ncol) nrerror("fread_ui32cube : can't write data");
    }
  }
  fclose(f);
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fread_f32cube(char *filename, float32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "rb");
  if(f == NULL)
    nrerror("Can't open file in fread_f32cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fread( &(c[k][i][ncl]), sizeof(float32), ncol, f);
      if(nread != ncol) nrerror("fread_f32cube : can't write data");
    }
  }
  fclose(f);
}
/* ----------------- */
/* -- fwrite_cube -- */
/* ----------------- */
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_i8cube(int8 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *filename)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_i8cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fwrite( &(c[k][i][ncl]), sizeof(int8), ncol, f);
      if(nread != ncol) nrerror("fwrite_i8cube : can't write data");
    }
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_i16cube(int16 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_i16cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fwrite( &(c[k][i][ncl]), sizeof(int16), ncol, f);
      if(nread != ncol) nrerror("fwrite_i8cube : can't write data");
    }
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_ui16cube(uint16 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *filename)
/* --------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_ui16cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fwrite( &(c[k][i][ncl]), sizeof(uint16), ncol, f);
      if(nread != ncol) nrerror("fwrite_ui16cube : can't write data");
    }
  }
  fclose(f);
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_i32cube(int32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_i32cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fwrite( &(c[k][i][ncl]), sizeof(int32), ncol, f);
      if(nread != ncol) nrerror("fwrite_i32cube : can't write data");
    }
  }
  fclose(f);
}
/* --------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) fwrite_ui32cube(uint32 ***c, long ndl, long ndh, long nrl, long nrh, long ncl, long nch, char *filename)
/* --------------------------------------------------------------------------------------------------------------------- */
{
  long  i, k;
  long ncol = nch-ncl+1, nread;
  FILE *f;

  f = fopen(filename, "wb");
  if(f == NULL)
    nrerror("Can't open file in fwrite_ui32cube");


  for(k=ndl; k<=ndh; k++) {
    for(i=nrl; i<=nrh; i++) {
      nread = fwrite( &(c[k][i][ncl]), sizeof(uint32), ncol, f);
      if(nread != ncol) nrerror("fwrite_ui32cube : can't write data");
    }
  }
  fclose(f);
}
/* ---------- */
/* -- save -- */
/* ---------- */
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) save_bvector(byte *v,long nl, long nh, char *path, char *filename)
/* ----------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_bvector(v, nl, nh, "%4d", complete_filename);
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) save_svector(short *v,long nl, long nh, char *path, char *filename)
/* ------------------------------------------------------------------ */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_svector(v, nl, nh, "%4d", complete_filename);
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) save_usvector(ushort *v,long nl, long nh, char *path, char *filename)
/* -------------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_usvector(v, nl, nh, "%4d", complete_filename);
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) save_ivector(int *v,long nl, long nh, char *path, char *filename)
/* ---------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_ivector(v, nl, nh, "%4d", complete_filename);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) save_bmatrix(byte **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename)
/* ------------------------------------------------------------------------------------------------ */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_bmatrix(m, nrl, nrh, ncl, nch, "%4d", complete_filename);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) save_smatrix(short **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename)
/* ------------------------------------------------------------------------------------------------ */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_smatrix(m, nrl, nrh, ncl, nch, "%4d", complete_filename);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) save_usmatrix(ushort **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename)
/* -------------------------------------------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_usmatrix(m, nrl, nrh, ncl, nch, "%4d", complete_filename);
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) save_imatrix(int **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename)
/* --------------------------------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s", path, filename);
  write_imatrix(m, nrl, nrh, ncl, nch, "%10d", complete_filename);
}
/* ------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) save_svector2(short *v, long nl, long nh, char *path, char *filename, int seuil, int nb_iter, int balayage, int maj, int alpha_update)
/* ------------------------------------------------------------------------------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s_%d_%d_%d_%d_%d.txt", path, filename, seuil, nb_iter, balayage, maj, alpha_update);
  write_svector(v, nl, nh, "%4d", complete_filename);
}
/* --------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) save_usvector2(ushort *v, long nl, long nh, char *path, char *filename, int seuil, int nb_iter, int balayage, int maj, int alpha_update)
/* --------------------------------------------------------------------------------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s_%d_%d_%d_%d_%d.txt", path, filename, seuil, nb_iter, balayage, maj, alpha_update);
  write_usvector(v, nl, nh, "%4d", complete_filename);
}
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) save_imatrix2(int **m, long nrl, long nrh, long ncl, long nch, char *path, char *filename, int seuil, int nb_iter, int balayage, int maj, int alpha_update)
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------- */
{
  static char complete_filename[256];
  sprintf(complete_filename, "%s/%s_%d_%d_%d_%d_%d.txt", path, filename, seuil, nb_iter, balayage, maj, alpha_update);
  write_imatrix(m, nrl, nrh, ncl, nch, "%10d", complete_filename);
}
/* ------------------------ */
/* -- PGM IO for bmatrix -- */
/* ------------------------ */

PRIVATE char *readitem   (FILE *file, char *buffer);
PRIVATE void  ReadPGMrow (FILE *file, long width, byte  *line);
PRIVATE void  WritePGMrow(byte *line, long width, FILE  *file);

/* ----------------------------------------- */
PRIVATE char *readitem(FILE *file,char *buffer)
/* ----------------------------------------- */
/* lecture d'un mot */
{
  char *aux;
  int k;

  k=0;
  aux=buffer;
  while (!feof(file))
    {
      *aux=fgetc(file);
      switch(k)
        {
        case 0:
          if (*aux=='#') k=1;
          if (isalnum(*aux)) k=2,aux++;
          break;
        case 1:
          if (*aux==0xA) k=0;
          break;
        case 2:
          if (!isalnum(*aux))
            {
              *aux=0;
              return buffer;
            }
          aux++;
          break;
        }
    }
  *aux=0;
  return buffer;
}
/* ------------------------------------------------------- */
PRIVATE void ReadPGMrow(FILE  *file, long width, byte  *line)
/* ------------------------------------------------------- */
{
    /* Le fichier est ouvert (en lecture) et ne sera pas ferme a la fin */
     fread(&(line[0]), sizeof(byte), width, file);
}
/* -------------------------------------------------------- */
PRIVATE void WritePGMrow(byte  *line, long width, FILE  *file)
/* -------------------------------------------------------- */
{
/* Le fichier est deja ouvert et ne sera pas ferme a la fin */

   fwrite(&(line[0]), sizeof(byte), width, file);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte **) LoadPGM_bmatrix(char *filename, long *nrl, long *nrh, long *ncl, long *nch)
/* ------------------------------------------------------------------------------------------- */
{
  /* cette version ne lit plus que le type P5 */

  long height, width, gris;
  byte **m;
  FILE *file;
  /*int   format;/**/

  char *buffer;
  /*char  c;/**/
  int i;
  
  buffer = (char*) calloc(80, sizeof(char));
  /* ouverture du fichier */
  file = fopen(filename,"rb");
  if (file==NULL)
    nrerror("ouverture du fichier impossible\n");
    //nrerror("ouverture du fichier %s impossible\n", filename);

  /* lecture de l'entete du fichier pgm */
  readitem(file, buffer);
  /*fscanf(fichier, "%s", buffer);*/
  if(strcmp(buffer, "P5") != 0)
    nrerror("entete du fichier %s invalide\n");
    //nrerror("entete du fichier %s invalide\n", filename);

  width  = atoi(readitem(file, buffer));
  height = atoi(readitem(file, buffer));
  gris   = atoi(readitem(file, buffer));

  *nrl = 0;
  *nrh = height - 1;
  *ncl = 0;
  *nch = width - 1;
  m = bmatrix(*nrl, *nrh, *ncl, *nch);
  
  for(i=0; i<height; i++) {
    ReadPGMrow(file, width, m[i]);
  }

  fclose(file);
  free(buffer);

  return m;
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) SavePGM_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch, char *filename)
/* ---------------------------------------------------------------------------------------------- */
{
  long nrow = nrh-nrl+1;
  long ncol = nch-ncl+1;

  char buffer[80];
  
  FILE *file;
  int  i;

  file = fopen(filename, "wb");
  if (file == NULL)
    //nrerror("ouverture du fichier %s impossible dans SavePGM_bmatrix\n", filename);
    nrerror("ouverture du fichier %s impossible dans SavePGM_bmatrix\n");

  /* enregistrement de l'image au format rpgm */

  sprintf(buffer,"P5\n%d %d\n255\n",ncol, nrow);
  fwrite(buffer,strlen(buffer),1,file);
  for(i=nrl; i<=nrh; i++)
     WritePGMrow((byte*)(&m[i][ncl]), ncol, file);

  /* fermeture du fichier */
  fclose(file);
}
/* --------------------------- */
/* -- PNM IO for rgb8matrix -- */
/* --------------------------- */

/* ------------------------------------------------------- */
PRIVATE void ReadPNMrow(FILE  *file, long width, byte  *line)
/* ------------------------------------------------------- */
{
    /* Le fichier est ouvert (en lecture) et ne sera pas ferme a la fin */
     fread(&(line[0]), sizeof(byte), 3*sizeof(byte)*width, file);
}
/* -------------------------------------------------------- */
PRIVATE void WritePNMrow(byte  *line, long width, FILE  *file)
/* -------------------------------------------------------- */
{
/* Le fichier est deja ouvert et ne sera pas ferme a la fin */

   fwrite(&(line[0]), sizeof(byte), 3*sizeof(byte)*width, file);
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgb8 **) LoadPPM_rgb8matrix(char *filename, long *nrl, long *nrh, long *ncl, long *nch)
/* ---------------------------------------------------------------------------------------------- */
{
  /* cette version ne lit plus que le type P6 */

  long height, width, gris;
  rgb8 **m;
  FILE *file;
  /*int   format;/**/

  char *buffer;
  /*char  c;/**/
  int i;
  
  buffer = (char*) calloc(80, sizeof(char));
  /* ouverture du fichier */
  file = fopen(filename,"rb");
  if (file==NULL)
    //nrerror("ouverture du fichier impossible\n");
    nrerror(filename);
    //nrerror("ouverture du fichier %s impossible\n", filename);

  /* lecture de l'entete du fichier pgm */
  readitem(file, buffer);
  /*fscanf(fichier, "%s", buffer);*/
  if(strcmp(buffer, "P6") != 0)
    nrerror("entete du fichier %s invalide\n");
    //nrerror("entete du fichier %s invalide\n", filename);

  width  = atoi(readitem(file, buffer));
  height = atoi(readitem(file, buffer));
  gris   = atoi(readitem(file, buffer));

  *nrl = 0;
  *nrh = height - 1;
  *ncl = 0;
  *nch = width - 1;
  m = rgb8matrix(*nrl, *nrh, *ncl, *nch);
  
  for(i=0; i<height; i++) {
    ReadPNMrow(file, width, (byte*)m[i]);
  }

  fclose(file);
  free(buffer);

  return m;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) SavePPM_rgb8matrix(rgb8 **m, long nrl, long nrh, long ncl, long nch, char *filename)
/* ------------------------------------------------------------------------------------------------- */
{
  long nrow = nrh-nrl+1;
  long ncol = nch-ncl+1;

  char buffer[80];
  
  FILE *file;
  int  i;

  file = fopen(filename, "wb");
  if (file == NULL)
    //nrerror("ouverture du fichier %s impossible dans SavePGM_bmatrix\n", filename);
    nrerror("ouverture du fichier %s impossible dans SavePPM_bmatrix\n");

  /* enregistrement de l'image au format rpgm */

  sprintf(buffer,"P6\n%d %d\n255\n",ncol, nrow);
  fwrite(buffer,strlen(buffer),1,file);
  for(i=nrl; i<=nrh; i++)
     WritePNMrow((byte*)&(m[i][ncl]), ncol, file);

  /* fermeture du fichier */
  fclose(file);
}
