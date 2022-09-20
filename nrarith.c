/* ----------------- */
/* --- nrarith.c --- */
/* ----------------- */

/*
 * Copyright (c) 2000, Lionel Lacassagne LIS-UPMC + Imasys
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
#include "nrarith.h"

/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) split_rgb8vector(rgb8 *x, long nl, long nh, byte *r, byte *g, byte *b)
/* ----------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) {
    r[i] = x[i].r;
    g[i] = x[i].g;
    b[i] = x[i].b;
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) split_rgb32vector(rgb32 *x, long nl, long nh, int32 *r, int32 *g, int32 *b)
/* ---------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) {
    r[i] = x[i].r;
    g[i] = x[i].g;
    b[i] = x[i].b;
  }
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) merge_rgb8vector(byte *r, byte *g, byte *b, long nl, long nh, rgb8 *x)
/* ----------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) {
     x[i].r = r[i];
     x[i].g = g[i];
     x[i].b = b[i];
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) merge_rgb32vector(int32 *r, int32 *g, int32 *b, long nl, long nh, rgb32 *x)
/* ---------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) {
     x[i].r = r[i];
     x[i].g = g[i];
     x[i].b = b[i];
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_i32vector_bvector(int32 *x, long nl, long nh, byte *y)
/* --------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) y[i] = (byte) x[i];
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_i32vector_ui16vector(int32 *x, long nl, long nh, uint16 *y)
/* -------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) y[i] = (uint16) x[i];
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_ui32vector_bvector(uint32 *x, long nl, long nh, byte *y)
/* ----------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) y[i] = (byte) x[i];
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_ui32vector_ui16vector(uint32 *x, long nl, long nh, uint16 *y)
/* ---------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) y[i] = (uint16) x[i];
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_rgb32vector_rgb8vector(rgb32 *x, long nl, long nh, rgb8 *y)
/* -------------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) {
    y[i].r = (byte) x[i].r;
    y[i].g = (byte) x[i].g;
    y[i].b = (byte) x[i].b;
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_bvector_rgb8vector(byte *x, long nl, long nh, rgb8 *y)
/* --------------------------------------------------------------------------- */
{
  rgb8 t;
  long j;
  for(j=nl; j<=nh; j++) {
    t.b = (3 &  x[j]       ) << 6;
    t.g = (7 & (x[j] >>  2)) << 5;
    t.r = (7 & (x[j] >>  5)) << 5;
    y[j] = t;
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_ui16vector_rgb8vector(uint16 *x, long nl, long nh, rgb8 *y)
/* ------------------------------------------------------------------------------ */
{
  rgb8 t;
  long j;
  for(j=nl; j<=nh; j++) {
    t.b = (63 &  x[j]       ) << 4;
    t.g = (63 & (x[j] >>  6)) << 4;
    t.r = (63 & (x[j] >> 12)) << 4;
    y[j] = t;
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_rgb8vector_bvector(rgb8 *x, long nl, long nh, byte *y)
/* --------------------------------------------------------------------------- */
{
  rgb8 t;
  uint16 r, g, b, u;
  long j;

  for(j=nl; j<=nh; j++) {
    t = x[j];
    r = (uint16) (t.r >> 5);
    g = (uint16) (t.g >> 5);
    b = (uint16) (t.b >> 6);
    u = (r << 5)  | (g << 2) | b;
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_rgb8vector_ui16vector(rgb8 *x, long nl, long nh, uint16 *y)
/* ------------------------------------------------------------------------------ */
{
  rgb8 t;
  uint16 r, g, b, u;
  long j;

  for(j=nl; j<=nh; j++) {
    t = x[j];
    r = (uint16) (t.r >> 4);
    g = (uint16) (t.g >> 4);
    b = (uint16) (t.b >> 4);
    u = (r << 12)  | (g << 6) | b;
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_bmatrix_rgb8matrix(byte **x, long nrl, long nrh, long ncl, long nch, rgb8 **y)
/* --------------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++) {
    convert_bvector_rgb8vector(x[i], ncl, nch, y[i]);
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_ui16matrix_rgb8matrix(uint16 **x, long nrl, long nrh, long ncl, long nch, rgb8 **y)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i;
  for(i=nrl; i<=nrh; i++) {
    convert_ui16vector_rgb8vector(x[i], ncl, nch, y[i]);
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_rgb8matrix_bmatrix(rgb8 **x, long nrl, long nrh, long ncl, long nch, byte **y)
/* --------------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++) {
    convert_rgb8vector_bvector(x[i], ncl, nch, y[i]);
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_rgb8matrix_ui16matrix(rgb8 **x, long nrl, long nrh, long ncl, long nch, uint16 **y)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i;
  for(i=nrl; i<=nrh; i++) {
    convert_rgb8vector_ui16vector(x[i], ncl, nch, y[i]);
  }
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) zero_bmatrix(byte **m, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------- */
{
  long i,j;
  byte *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = 0;
    }
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) zero_smatrix(short **m, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  long i,j;
  short *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = 0;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) zero_usmatrix(ushort **m, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  long i,j;
  ushort *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = 0;
    }
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) zero_imatrix(int **m, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  long i,j;
  int *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = 0;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) zero_i32matrix(int32 **m, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  long i,j;
  int32 *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = 0;
    }
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) zero_matrix(float **m, long nrl,long nrh,long ncl,long nch)
/* ------------------------------------------------------------------------ */
{
  long i,j;
  float *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = (float) 0.0;
    }
  }
}
/* -------------------------------------------------------- */
IMAGE_EXPORT(void) zero_matrix0(float **m, long nrow,long ncol)
/* --------------------------------------------------------- */
{
  long i,j;
  float *mi;

  for(i=0; i<=nrow; i++) {
    mi = m[i];
    for(j=0; j<=ncol; j++) {
      mi[j] = (float) 0.0;
    }
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) zero_dmatrix(double **m, long nrl,long nrh,long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  long i,j;
  double *mi;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = 0.0;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) zero_rgb8matrix(rgb8 **m, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  long i,j;
  rgb8 z, *mi;;

  z.r = 0;
  z.g = 0;
  z.g = 0;

  for(i=nrl; i<=nrh; i++) {
    mi = m[i];
    for(j=ncl; j<=nch; j++) {
      mi[j] = z;
    }
  }
}
/* ---------------------------- */
/* --- Left & right Rotate  --- */
/* ---------------------------- */
// (i,j) -> (n-j,i) -> (n-i,n-j) -> (j,n-i) ->
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch, byte **D)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_smatrix(short **S, long nrl,long nrh,long ncl, long nch, short **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lrotate_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch, int16 **D)
/* ------------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D)
/* --------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lrotate_imatrix(int **S, long nrl,long nrh,long ncl, long nch, int **D)
/* ------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch, uint **D)
/* --------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lrotate_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch, int32 **D)
/* ------------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D)
/* --------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_matrix(float **S, long nrl,long nrh,long ncl, long nch, float **D)
/* --------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lrotate_dmatrix(double **S, long nrl,long nrh,long ncl, long nch, double **D)
/* ------------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch, rgb8 **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-j][i] = S[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch, byte **D)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_smatrix(short **S, long nrl,long nrh,long ncl, long nch, short **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) rrotate_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch, int16 **D)
/* ------------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D)
/* --------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) rrotate_imatrix(int **S, long nrl,long nrh,long ncl, long nch, int **D)
/* ------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch, uint **D)
/* --------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) rrotate_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch, int32 **D)
/* ------------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D)
/* --------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_matrix(float **S, long nrl,long nrh,long ncl, long nch, float **D)
/* --------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) rrotate_dmatrix(double **S, long nrl,long nrh,long ncl, long nch, double **D)
/* ------------------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch, rgb8 **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][j] = S[n-j][i];
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  byte t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lrotate1_smatrix(short **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  short t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  ushort t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_imatrix(int **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lrotate1_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  uint t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_matrix(float **S, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  float t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_dmatrix(double **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  double t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lrotate1_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  rgb8 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-j][i];
      S[n-j][i] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  byte t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) rrotate1_smatrix(short **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  short t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  ushort t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_imatrix(int **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) rrotate1_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  uint t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_matrix(float **S, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  float t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_dmatrix(double **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  double t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rrotate1_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  rgb8 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][j];
      S[i][j]   = S[n-j][i];
      S[n-j][i] = t;
    }
  }
}

/* ---------------------------------- */
/* --- Horizontal & Vertical Flip --- */
/* ---------------------------------- */

/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) hflip_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch, byte **D)
/* ------------------------------------------------------------------------------------ */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_smatrix(short **S, long nrl,long nrh,long ncl, long nch, short **D)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch, int16 **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_imatrix(int **S, long nrl,long nrh,long ncl, long nch, int **D)
/* ---------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch, uint **D)
/* ------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_i32matrix (int32 **S, long nrl,long nrh,long ncl, long nch, int32 **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_matrix(float **S, long nrl,long nrh,long ncl, long nch, float **D)
/* ------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_dmatrix(double **S, long nrl,long nrh,long ncl, long nch, double **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch, rgb8 **D)
/* --------------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[i][n-j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_bmatrix(byte  **S, long nrl,long nrh,long ncl, long nch, byte **D)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_smatrix(short **S, long nrl,long nrh,long ncl, long nch, short **D)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch, int16 **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_imatrix(int **S, long nrl,long nrh,long ncl, long nch, int **D)
/* ---------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch, uint **D)
/* ------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch, int32 **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_matrix(float **S, long nrl,long nrh,long ncl, long nch, float **D)
/* ------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_dmatrix(double **S, long nrl,long nrh,long ncl, long nch, double **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch, rgb8 **D)
/* --------------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      D[n-i][j] = S[i][j];
    }
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  byte t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_smatrix(short **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  short t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) hflip1_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = ncl + nch;
  ushort t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) hflip1_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = ncl + nch;
  int16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  uint16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_imatrix(int **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  int t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  uint t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_i32matrix (int32 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  int32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  uint32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_matrix(float **S, long nrl,long nrh,long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  float t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) hflip1_dmatrix(double **S, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------- */
{
  int i, j, n = ncl + nch;
  double t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) hflip1_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = ncl + nch;
  rgb8 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[i][n-j];
      S[i][n-j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_bmatrix(byte  **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  byte t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_smatrix(short **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  short t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) vflip1_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  ushort t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) vflip1_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  int16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint16 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_imatrix(int **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  int t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) vflip1_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  int32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  uint32 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_matrix(float **S, long nrl,long nrh,long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  float t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) vflip1_dmatrix(double **S, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------------- */
{
  int i, j, n = nrl + nrh;
  double t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) vflip1_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j, n = nrl + nrh;
  rgb8 t;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      t         = S[n-i][j];
      S[n-i][j] = S[i][j];
      S[i][j]   = t;
    }
  }
}
/* -------------------------- */
/* --- Transpose function --- */
/* -------------------------- */

/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch, byte **D)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_smatrix(short  **S, long nrl,long nrh,long ncl, long nch, short **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch, int16 **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D)
/* ----------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_imatrix(int **S, long nrl,long nrh,long ncl, long nch, int **D)
/* -------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch, uint **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch, int32 **D)
/* -------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D)
/* ----------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_matrix(float **S, long nrl,long nrh,long ncl, long nch, float **D)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_dmatrix(double **S, long nrl,long nrh,long ncl, long nch, double **D)
/* -------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch, rgb8 **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j;

  for(i=nrl; i<=nch; i++) {
    for(j=ncl; j<=nch; j++) {
      D[j][i] = S[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j;
  byte t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_smatrix(short **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j;
  short t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j;
  ushort t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_i16matrix(int16 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j;
  int16 t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) transpose1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------------ */
{
  int i, j;
  uint16 t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) transpose1_imatrix(int **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j;
  int t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_uimatrix(uint **S, long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  int i, j;
  uint t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_i32matrix(int32 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j;
  int32 t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) transpose1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------------ */
{
  int i, j;
  uint32 t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_matrix(float **S, long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j;
  float t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_dmatrix(double **S, long nrl,long nrh,long ncl, long nch)
/* --------------------------------------------------------------------------------- */
{
  int i, j;
  double t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose1_rgb8matrix(rgb8 **S, long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  int i, j;
  rgb8 t;

  for(i=nrl; i<=nch; i++) {
    for(j=i+1; j<=nch; j++) {
      t       = S[j][i];
      S[j][i] = S[i][j];
      S[i][j] = t;
    }
  }
}

// old version for benchmarking
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_matrix01(float **m, long nrow, long ncol, float **transposed)
/* ---------------------------------------------------------------------- */
{
  long i,j;
  float m0;
  float *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++;
      transposed[j][i] = m0;
    }
  }
}

/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_matrix02(float **m, long nrow, long ncol, float **transposed)
/* ---------------------------------------------------------------------- */
{
  long i,j;
  float m0, m1;
  float *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++;
      m1 = *pm++;
      transposed[j++][i] = m0;
      transposed[j][i] = m1;
    }
  }
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_matrix04(float **m, long nrow, long ncol, float **transposed)
/* ---------------------------------------------------------------------- */
{
  long i,j;
  float m0, m1, m2, m3;
  float *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++;
      m1 = *pm++;
      m2 = *pm++;
      m3 = *pm++;
      transposed[j++][i] = m0;
      transposed[j++][i] = m1;
      transposed[j++][i] = m2;
      transposed[j][i] = m3;

    }
  }
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_matrix08(float **m, long nrow, long ncol, float **transposed)
/* ---------------------------------------------------------------------- */
{
  long i,j;
  float m0, m1, m2, m3, m4, m5, m6,m7;
  float *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++; m1 = *pm++;
      m2 = *pm++; m3 = *pm++;
      m4 = *pm++; m5 = *pm++;
      m6 = *pm++; m7 = *pm++;

      transposed[j++][i] = m0;
      transposed[j++][i] = m1;
      transposed[j++][i] = m2;
      transposed[j++][i] = m3;
      transposed[j++][i] = m4;
      transposed[j++][i] = m5;
      transposed[j++][i] = m6;
      transposed[j][i] = m7;
    }
  }
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_matrix00(float **m, long nrow, long ncol, float **transposed)
/* ---------------------------------------------------------------------- */
{
  long i,j;

  for(i=0; i<nrow; i++) {
    for(j=0; j<ncol; j++) {
      transposed[j][i] = m[i][j];

    }
  }
}

/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_bmatrix01(byte **m, long nrow, long ncol, byte **transposed)
/* --------------------------------------------------------------------- */
{
  long i,j;
  byte m0;
  byte *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++;
      transposed[j][i] = m0;
    }
  }
}

/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_bmatrix02(byte **m, long nrow, long ncol, byte **transposed)
/* --------------------------------------------------------------------- */
{
  long i,j;
  byte m0, m1;
  byte *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++;
      m1 = *pm++;
      transposed[j++][i] = m0;
      transposed[j][i] = m1;
    }
  }
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_bmatrix04(byte **m, long nrow, long ncol, byte **transposed)
/* --------------------------------------------------------------------- */
{
  long i,j;
  byte m0, m1, m2, m3;
  byte *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++;
      m1 = *pm++;
      m2 = *pm++;
      m3 = *pm++;
      transposed[j++][i] = m0;
      transposed[j++][i] = m1;
      transposed[j++][i] = m2;
      transposed[j][i] = m3;

    }
  }
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_bmatrix08(byte **m, long nrow, long ncol, byte **transposed)
/* --------------------------------------------------------------------- */
{
  long i,j;
  byte m0, m1, m2, m3, m4, m5, m6,m7;
  byte *pm;

  for(i=0; i<nrow; i++) {
    pm = m[i];
    for(j=0; j<ncol; j++) {
      m0 = *pm++; m1 = *pm++;
      m2 = *pm++; m3 = *pm++;
      m4 = *pm++; m5 = *pm++;
      m6 = *pm++; m7 = *pm++;

      transposed[j++][i] = m0;
      transposed[j++][i] = m1;
      transposed[j++][i] = m2;
      transposed[j++][i] = m3;
      transposed[j++][i] = m4;
      transposed[j++][i] = m5;
      transposed[j++][i] = m6;
      transposed[j][i] = m7;
    }
  }
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) transpose_bmatrix00(byte **m, long nrow, long ncol, byte **transposed)
/* --------------------------------------------------------------------- */
{
  long i,j;

  for(i=0; i<nrow; i++) {
    for(j=0; j<ncol; j++) {
      transposed[j][i] = m[i][j];

    }
  }
}
/* --------------------------------------- */
IMAGE_EXPORT(void) roll_svector(short *v, long nl, long nh)
/* --------------------------------------- */
/* 
 * left rotate a short vector with subscript range v[nl..nh]
 * nl & nh can be, respectively bigger and smaller than the
 * values used to allocate the vector (svector)
 * no check on nl and nh is done
 */
{
  long i;
  short tmp;

  tmp = v[nl];
  for(i=nl; i<nh; i++) {
    v[i] = v[i+1];
  }
  v[nh] = tmp;
}
/* ----------------------------------------- */
IMAGE_EXPORT(void) roll_usvector(ushort *v, long nl, long nh)
/* ----------------------------------------- */
/* 
 * left rotate a short vector with subscript range v[nl..nh]
 * nl & nh can be, respectively bigger and smaller than the
 * values used to allocate the vector (svector)
 * no check on nl and nh is done
 */
{
  long i;
  ushort tmp;

  tmp = v[nl];
  for(i=nl; i<nh; i++) {
    v[i] = v[i+1];
  }
  v[nh] = tmp;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_imatrix_selection2(int **m, long nl, long nh)
/* --------------------------------------------------------------- */
/*
 * sort an matrix of int with the selection algorithm
 * the key is supposed to be in row 1
 * the flag associated, in row 0
 */
{
  int i, j;
  int x, min, pos, tmp;

  /*display_imatrix(m, 0, 1, nl, nh, "%10d", "Before");/**/

  for(i=nl; i<nh; i++) {
    min = m[1][i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = m[1][j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    m[1][pos] = m[1][i];
    m[1][i]   = min;

    tmp       = m[0][i];
    m[0][i]   = m[0][pos];
    m[0][pos] = tmp;
  }
  /*display_imatrix(m, 0, 1, nl, nh, "%10d", "After");/**/
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_imatrix_leftpart_selection2(int **m, long nl, long nh, long len)
/* ---------------------------------------------------------------------------------- */
/*
 * sort an matrix of int with the selection algorithm
 * the key is supposed to be in row 1
 * the flag associated, in row 0
 * the sort is performed only on the len first items
 * for selecting the len first smallest values (for Tracking algo)
 */
{
  int i, j;
  int x, min, pos, tmp;
  long ih = nl + len - 1;
  int *X, *F;

  /*display_imatrix(m, 0, 1, nl, nh, "%10d", "Before");/**/

  F = m[0];
  X = m[1];


  for(i=nl; i<=ih; i++) {
    min = X[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = X[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    X[pos] = X[i];
    X[i]   = min;

    tmp    = F[i];
    F[i]   = F[pos];
    F[pos] = tmp;
  }
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_dmatrix_selection(double *m, long nl, long nh)
/* ---------------------------------------------------------------- */
{
  int i, j, pos;
  double x, min;

  for(i=nl; i<nh; i++) {
    min = m[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = m[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    m[pos] = m[i];
    m[i]   = min;
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_imatrix_selection(int **m, long nrl, long nrh, long ncl, long nch, long nrow)
/* ----------------------------------------------------------------------------------------------- */
/*
 * sort an matrix of int with the selection algorithm
 * the key is supposed to be in row nrow
 */
{
  int i, j, k;
  int x, min, pos, tmp;

  display_imatrix(m, nrl, nrh, ncl, nch, "%10d", NULL);
  for(i=ncl; i<nch; i++) {
    min = m[nrow][i];
    pos = i;
    for(j=i+1; j<=nch; j++) {
      x = m[nrow][j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    
    /* big swap */
    for(k=nrl; k<=nrh; k++) {
      tmp = m[k][i];
      m[k][i] = m[k][pos];
      m[k][pos] = tmp;
    } /* k */
    /*display_imatrix(m, nrl, nrh, ncl, nch, "%10d", NULL);/**/

  } /* i */
}    
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sortv_imatrix_selection_min(int **m, long nrl, long nrh, long ncl, long nch, long nc)
/* -------------------------------------------------------------------------------------------------- */
{
  /*
   * sort an matrix of int, with the selection algorithm.
   * the key is in column nc
   * the sort is performed, by doing a purmutation on the lines,
   * instead of copying the lines.
   */
  int i, j;

  int x, min, pos;
  int *ptr;

  /*display_imatrix(m, nrl, nrh, ncl, nch, "%10d", NULL);/**/
  for(i=nrl; i<nrh; i++) {
    min = m[i][nc];
    pos = i;
    for(j=i+1; j<=nrh; j++) {
      x = m[j][nc];
      if(x < min) {
        min = x;
        pos = j;
      }
    } /* j */

    /* permutation des pointeurs de ligne de la matrice */
    ptr    = m[i];
    m[i]   = m[pos];
    m[pos] = ptr;
    
  } /* i */
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sortv_imatrix_selection_kmin(int **m, long nrl, long nrh, long ncl, long nch, long nc, int k)
/* ---------------------------------------------------------------------------------------------------------- */
{
  /*
   * sort an matrix of int, with the selection algorithm.
   * the key is in column nc
   * the sort is performed, by doing a purmutation on the lines,
   * instead of copying the lines.
   */
  int i, j;
  int il = nrl;
  int ih = nrl + k;

  int x, min, pos;
  int *ptr;

  /*display_imatrix(m, nrl, nrh, ncl, nch, "%10d", NULL);/**/
  for(i=il; i<ih; i++) {
    min = m[i][nc];
    pos = i;
    for(j=i+1; j<=nrh; j++) {
      x = m[j][nc];
      if(x < min) {
        min = x;
        pos = j;
      }
    } /* j */

    /* permutation des pointeurs de ligne de la matrice */
    ptr    = m[i];
    m[i]   = m[pos];
    m[pos] = ptr;
    
  } /* i */
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sortv_imatrix_selection_max(int **m, long nrl, long nrh, long ncl, long nch, long nc)
/* -------------------------------------------------------------------------------------------------- */
{
  /*
   * sort an matrix of int, with the selection algorithm.
   * from max to min
   * the key is in column nc
   * the sort is performed, by doing a purmutation on the lines,
   * instead of copying the lines.
   */
  int i, j;

  int x, max, pos;
  int *ptr;

  /*display_imatrix(m, nrl, nrh, ncl, nch, "%10d", NULL);/**/
  for(i=nrl; i<nrh; i++) {
    max = m[i][nc];
    pos = i;
    for(j=i+1; j<=nrh; j++) {
      x = m[j][nc];
      if(x > max) {
        max = x;
        pos = j;
      }
    } /* j */

    /* permutation des pointeurs de ligne de la matrice */
    ptr    = m[i];
    m[i]   = m[pos];
    m[pos] = ptr;
    
  } /* i */
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sortv_imatrix_selection_kmax(int **m, long nrl, long nrh, long ncl, long nch, long nc, int k)
/* ---------------------------------------------------------------------------------------------------------- */
{
  /*
   * sort an matrix of int, with the selection algorithm.
   * from max to min
   * the key is in column nc
   * the sort is performed, by doing a purmutation on the lines,
   * instead of copying the lines.
   */
  int i, j;
  int il = nrl;
  int ik = nrl + k;

  int x, max, pos;
  int *ptr;

  /*display_imatrix(m, nrl, nrh, ncl, nch, "%10d", NULL);/**/
  for(i=nrl; i<nrh; i++) {
    max = m[i][nc];
    pos = i;
    for(j=i+1; j<=nrh; j++) {
      x = m[j][nc];
      if(x > max) {
        max = x;
        pos = j;
      }
    } /* j */

    /* permutation des pointeurs de ligne de la matrice */
    ptr    = m[i];
    m[i]   = m[pos];
    m[pos] = ptr;
    
  } /* i */
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) sort_index_dvector_selection(double *key, long nl, long nh, int *index)
/* ------------------------------------------------------------------------------------ */
{
  int i, j, pos, tmp;
  double x, min;

  for(i=nl; i<=nh; i++) {
    index[i] = i-nl;
  }

  for(i=nl; i<nh; i++) {
    min = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = min;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_ivector_selection_min(int *key, long nl, long nh, int *index)
/* ------------------------------------------------------------------------------------- */
//#pragma message("ATTENTION --------------------------------------")
//#pragma message("ATTENTION erreur possible dans le calcul d'index")
//#pragma message("ATTENTION --------------------------------------")
{
  int i, j, pos, tmp;
  int x, min;

  for(i=nl; i<=nh; i++) {
    /*index[i] = i-nl;/**/
    index[i] = i;/**/
  }

  for(i=nl; i<nh; i++) {
    min = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = min;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_ivector_selection_max(int *key, long nl, long nh, int *index)
/* ------------------------------------------------------------------------------------- */
{
  int i, j, pos, tmp;
  int x, max;

  for(i=nl; i<=nh; i++) {
    /*index[i] = i-nl;/**/
    index[i] = i;/**/
  }

  for(i=nl; i<nh; i++) {
    max = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x > max) {
        max = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = max;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_vector_selection_min(float *key, long nl, long nh, int *index)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, pos, tmp;
  float x, min;

  for(i=nl; i<=nh; i++) {
    /*index[i] = i-nl;/**/
    index[i] = i;/**/
  }

  for(i=nl; i<nh; i++) {
    min = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = min;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_vector_selection_max(float *key, long nl, long nh, int *index)
/* -------------------------------------------------------------------------------------- */
{
  int i, j, pos, tmp;
  float x, max;

  for(i=nl; i<=nh; i++) {
    /*index[i] = i-nl;/**/
    index[i] = i;/**/
  }

  for(i=nl; i<nh; i++) {
    max = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x > max) {
        max = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = max;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}

/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_ivector_selection_kmin(int *key, long nl, long nh, int *index, int k)
/* --------------------------------------------------------------------------------------------- */
{
  /*
   * ATTENTION, ke tableau index DOIT etre initialise
   */
  int i, j, pos, tmp, il, ih;
  int x, min;

  il = nl;
  ih = il + k;

  /*for(i=il; i<=ih; i++) {
    index[i] = i-il;
  }/**/

  for(i=il; i<ih; i++) {
    min = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = min;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_imatrix_selection_kmin(int **key, long nrl,long nrh,long ncl, long nch, int **index, int k)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i;

  set_imatrix_j(index, nrl,nrh, ncl,nch);

  for(i=nrl; i<=nrh; i++) {
    /*printf("-------------------- %d --------------------\n", i);
    display_ivector(key[i],   ncl, nch, "%4d", "key0");
    display_ivector(index[i], ncl, nch, "%4d", "index0");/**/

    sort_index_ivector_selection_kmin(key[i], ncl, nch, index[i], k);

    /*display_ivector(key[i],   ncl, nch, "%4d", "key1");
    display_ivector(index[i], ncl, nch, "%4d", "index1");/**/
    
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_ivector_selection_kmax(int *key, long nl, long nh, int *index, int k)
/* --------------------------------------------------------------------------------------------- */
{
  /*
   * ATTENTION, ke tableau index DOIT etre initialise
   */
  int i, j, pos, tmp, il, ih;
  int x, max;

  il = nl;
  ih = il + k;

  /*for(i=il; i<=ih; i++) {
    index[i] = i-il;
  }/**/

  for(i=il; i<ih; i++) {
    max = key[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = key[j];
      if(x > max) {
        max = x;
        pos = j;
      }
    }
    key[pos] = key[i];
    key[i]   = max;

    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sort_index_imatrix_selection_kmax(int **key, long nrl,long nrh,long ncl, long nch, int **index, int k)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i;

  set_imatrix_j(index, nrl,nrh, ncl,nch);

  for(i=nrl; i<=nrh; i++) {
    /*printf("-------------------- %d --------------------\n", i);
    display_ivector(key[i],   ncl, nch, "%4d", "key0\n");
    display_ivector(index[i], ncl, nch, "%4d", "index0\n");/**/

    sort_index_ivector_selection_kmax(key[i], ncl, nch, index[i], k);

    /*display_ivector(key[i],   ncl, nch, "%4d", "key1\n");
    display_ivector(index[i], ncl, nch, "%4d", "index1\n");/**/
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sortv_index_imatrix_selection_max(int **key, long nrl,long nrh,long ncl, long nch, int *index, int nc)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, pos, tmp, il, ih;
  int x, max;
  int *ptr;

  il = nrl;
  ih = nrh;

  for(i=il; i<=ih; i++) {
    index[i] = i;
  }/**/

  for(i=il; i<ih; i++) {
    max = key[i][nc];
    pos = i;
    for(j=i+1; j<=nrh; j++) {
      x = key[j][nc];
      if(x > max) {
        max = x;
        pos = j;
      }
    }
    //printf("Max = %d, swap (%d, %d)\n", max, i, pos);
    /* permutation des pointeurs de ligne de la matrice */
    ptr      = key[i];
    key[i]   = key[pos];
    key[pos] = ptr;

    /* permutation des indices de l'index */
    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sortv_index_imatrix_selection_min(int **key, long nrl,long nrh,long ncl, long nch, int *index, int nc)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, pos, tmp, il, ih;
  int x, min;
  int *ptr;

  il = nrl;
  ih = nrh;

  for(i=il; i<=ih; i++) {
    index[i] = i;
  }/**/

  for(i=il; i<ih; i++) {
    min = key[i][nc];
    pos = i;
    for(j=i+1; j<=nrh; j++) {
      x = key[j][nc];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    //printf("Max = %d, swap (%d, %d)\n", max, i, pos);
    /* permutation des pointeurs de ligne de la matrice */
    ptr      = key[i];
    key[i]   = key[pos];
    key[pos] = ptr;

    /* permutation des indices de l'index */
    tmp        = index[i];
    index[i]   = index[pos];
    index[pos] = tmp;
  }
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) sort_bvector_selection_min(byte *v, long nl, long nh)
/* ------------------------------------------------------------------ */
{
  int i, j;
  int x, min, pos;

  for(i=nl; i<nh; i++) {
    min = v[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = v[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    v[pos] = v[i];
    v[i]   = min;
  }
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(byte) select_bvector(byte *v, long nl, long nh, long k)
/* -------------------------------------------------------------- */
{
  int i, j, il, ih;
  int x, min, pos;

  il = nl;
  ih = il + k;

  for(i=il; i<ih; i++) {
    min = v[i];
    pos = i;
    for(j=i+1; j<=nh; j++) {
      x = v[j];
      if(x < min) {
        min = x;
        pos = j;
      }
    }
    v[pos] = v[i];
    v[i]   = min;
  }
  return v[ih];
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(rgb8) select_rgb8vector(rgb8 *v, long nl, long nh, long k)
/* ----------------------------------------------------------------- */
{
  int i, j, il, ih;

  int rpos, gpos, bpos;
  rgb8 xi, xj;
  byte r,g,b;
  byte rmin, gmin, bmin;

  il = nl;
  ih = il + k;

  for(i=il; i<ih; i++) {

    xi = v[i];
    rmin = xi.r; gmin = xi.g; bmin = xi.b;
    rpos = gpos = bpos = i;
    
    for(j=i+1; j<=nh; j++) {
      xj = v[j];
      r = xj.r; g = xj.g; b = xj.b;
      if(r < rmin) { rmin = r; rpos = j; }
      if(g < gmin) { gmin = r; gpos = j; }
      if(b < bmin) { bmin = r; bpos = j; }
    }
    v[rpos].r = v[i].r; v[i].r = rmin;
    v[rpos].g = v[i].g; v[i].g = gmin;
    v[rpos].b = v[i].b; v[i].b = bmin;
  }
  return v[ih];
}
/* --------------------------------------------------- */
IMAGE_EXPORT(byte) min_bvector(byte *v, long nl, long nh)
/* --------------------------------------------------- */
{
  int i;
  byte  m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(short) min_svector(short *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  int i;
  short m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(int16) min_i16vector(int16 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  int i;
  int16 m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ---------------------------------------------------------- */
IMAGE_EXPORT(uint16) min_ui16vector(uint16 *v, long nl, long nh)
/* ---------------------------------------------------------- */
{
  int i;
  uint16 m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------- */
IMAGE_EXPORT(int) min_ivector(int *v, long nl, long nh)
/* ------------------------------------------------- */
{
  int i;
  int m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(int32) min_i32vector(int32 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  int i;
  int32 m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(uint) min_uivector(uint *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  int i;
  uint m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(float) min_vector(float *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  int i;
  float m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(double) min_dvector(double *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  int i;
  double m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]<m) m = v[i];
  }
  return m;
}
/* --------------------------------------------------- */
IMAGE_EXPORT(byte) max_bvector(byte *v, long nl, long nh)
/* --------------------------------------------------- */
{
  int i;
  byte  m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(short) max_svector(short *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  int i;
  short m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* -------------------------------------------------------- */
IMAGE_EXPORT(ushort) max_usvector(ushort *v, long nl, long nh)
/* -------------------------------------------------------- */
{
  int i; 
  //int pos;
  ushort m;

  m = v[nl];
  //pos = nl;
  for(i=nl+1; i<=nh; i++) {
    //if(v[i]>m) { m = v[i]; pos = i;}
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(int16) max_i16vector(int16 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  int i; 
  int16 m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* --------------------------------------------------------- */
IMAGE_EXPORT(int16) max_ui16vector(uint16 *v, long nl, long nh)
/* --------------------------------------------------------- */
{
  int i; 
  uint16 m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------- */
IMAGE_EXPORT(int) max_ivector(int *v, long nl, long nh)
/* ------------------------------------------------- */
{
  int i;
  int m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(uint) max_uivector(uint *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  int i;
  uint m;
  int pos = nl;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(int) max_i32vector(int32 *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  int i;
  int32 m;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(float) max_vector(float *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  int i;
  float m;
  int pos = nl;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(double) max_dvector(double *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  int i;
  double m;
  int pos = nl;

  m = v[nl];
  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) m = v[i];
  }
  return m;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(byte) min_bvector_pos(byte *v, long nl, long nh, int *pos)
/* ----------------------------------------------------------------- */
{
  int i;
  byte  m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(short) min_svector_pos(short *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------- */
{
  int i;
  short m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(int16) min_i16vector_pos(int16 *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------------- */
{
  int i;
  int16 m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(uint16) min_ui16vector_pos(uint16 *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------------ */
{
  int i;
  uint16 m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(int) min_ivector_pos(int *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------- */
{
  int i;
  int m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(int32) min_i32vector_pos(int32 *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------------- */
{
  int i;
  int32 m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(uint) min_uivector_pos(uint *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------ */
{
  int i;
  uint m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(float) min_vector_pos(float *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------ */
{
  int i;
  float m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(double) min_dvector_pos(double *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------------- */
{
  int i;
  double m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(byte) max_bvector_pos(byte *v, long nl, long nh, int *pos)
/* ----------------------------------------------------------------- */
{
  int i;
  byte m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(short) max_svector_pos(short *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------- */
{
  int i;
  short m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(ushort) max_usvector_pos(ushort *v, long nl, long nh, int *pos)
/* ---------------------------------------------------------------------- */
{
  int i; 
  ushort m  = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(int16) max_i16vector_pos(int16 *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------------- */
{
  int i; 
  int16 m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;
  return m;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(int16) max_ui16vector_pos(uint16 *v, long nl, long nh, int *pos)
/* ----------------------------------------------------------------------- */
{
  int i; 
  uint16 m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(int) max_ivector_pos(int *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------- */
{
  int i;
  int m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(uint) max_uivector_pos(uint *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------ */
{
  int i;
  uint m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(int) max_i32vector_pos(int32 *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------- */
{
  int i;
  int32 m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(float) max_vector_pos(float *v, long nl, long nh, int *pos)
/* ------------------------------------------------------------------ */
{
  int i;
  float m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(double) max_dvector_pos(double *v, long nl, long nh, int *pos)
/* --------------------------------------------------------------------- */
{
  int i;
  double m = v[nl];
  int  p = nl;

  for(i=nl+1; i<=nh; i++) {
    if(v[i]>m) { m = v[i]; p = i;}
  }
  *pos = p;

  return m;
}/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(byte) min_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  int i, j;
  byte minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(short) min_smatrix(short **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j;
  short minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort) min_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j;
  ushort minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(int) min_imatrix(int **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  int i, j;
  int minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(uint) min_uimatrix(uint **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j;
  uint minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(float) min_matrix(float **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j;
  float minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(double) min_dmatrix(double **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j;
  double minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]<minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(byte) max_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  int i, j;
  byte minimum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>minimum) minimum = m[i][j];
    }
  }
  return minimum;
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(short) max_smatrix(short **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j;
  short maximum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>maximum) maximum = m[i][j];
    }
  }
  return maximum;
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort) max_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  int i, j;
  ushort maximum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>maximum) maximum = m[i][j];
    }
  }
  return maximum;
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(int) max_imatrix(int **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  int i, j;
  int maximum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>maximum) maximum = m[i][j];
    }
  }
  return maximum;
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(uint) max_uimatrix(uint **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j;
  uint maximum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>maximum) maximum = m[i][j];
    }
  }
  return maximum;
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(float) max_matrix(float **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  int i, j;
  float maximum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>maximum) maximum = m[i][j];
    }
  }
  return maximum;
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(double) max_dmatrix(double **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  int i, j;
  double maximum = m[nrl][ncl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      if(m[i][j]>maximum) maximum = m[i][j];
    }
  }
  return maximum;
}

/* ---------------------------------------------------- */
IMAGE_EXPORT(void) zero_bvector(byte *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  memset(v+nl, 0, len);/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(void) zero_svector(short *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) (v+nl);
  memset(bv, 0, len*sizeof(short));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(void) zero_usvector(ushort *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) (v+nl);
  memset(bv, 0, len*sizeof(short));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(void) zero_i16vector(int16 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(int16));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* --------------------------------------------------------- */
IMAGE_EXPORT(void) zero_ui16vector(uint16 *v, long nl, long nh)
/* --------------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(uint16));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* --------------------------------------------------- */
IMAGE_EXPORT(void) zero_ivector(int *v, long nl, long nh)
/* --------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(int));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(void) zero_i32vector(int32 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(int32));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(void) zero_lvector(long *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(long));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* --------------------------------------------------------- */
IMAGE_EXPORT(void) zero_rgb8vector(rgb8 *v, long nl, long nh)
/* --------------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(rgb32));/**/
  int i;
  rgb8 z;
  z.r = 0; z.g = 0; z.b = 0;
  for(i=nl; i<=nh; i++) v[i] = z;
}
/* --------------------------------------------------------- */
IMAGE_EXPORT(void) zero_rgb32vector(rgb32 *v, long nl, long nh)
/* --------------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(rgb32));/**/
  int i;
  rgb32 z;
  z.r = 0; z.g = 0; z.b = 0;
  for(i=nl; i<=nh; i++) v[i] = z;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(void) zero_vvector(void **v, long nl, long nh)
/* ----------------------------------------------------- */
{
  /*long len = nh - nl + 1;
  byte *bv = (byte*) v+nl;
  memset(bv, 0, len*sizeof(void*));/**/
  int i;
  for(i=nl; i<=nh; i++) v[i] = 0;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) init_bvector_hexa(byte *src, long nl, long nh, int32 init)
/* ----------------------------------------------------------------------- */
{
  int i;
  for(i=nh; i>=nl; i--) {
    src[i] = init&1;
    init = init >> 1;
  }
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) init_bvector(byte *src, long nl, long nh, char *init)
/* ------------------------------------------------------------------ */
{
  int i;
  char c[1];
  for(i=nl; i<=nh; i++) {
    *c = *init++;
    if(isdigit(*c))
      src[i] = (byte) atoi(c);
    else
      src[i] = (byte) 0;
  }
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) init_svector(short *src, long nl, long nh, char *init)
/* ------------------------------------------------------------------- */
{
  int i;
  char c[1];
  for(i=nl; i<=nh; i++) {
    *c = *init++;
    if(isdigit(*c))
      src[i] = (short) atoi(c);
    else
      src[i] = (short) 0;
  }
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) init_usvector(ushort *src, long nl, long nh, char *init)
/* --------------------------------------------------------------------- */
{
  int i;
  char c[1];
  for(i=nl; i<=nh; i++) {
    *c = *init++;
    if(isdigit(*c))
      src[i] = (ushort) atoi(c);
    else
      src[i] = (ushort) 0;
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(byte) compare_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2)
/* -------------------------------------------------------------------------- */
{
  int i, j;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j] != Yi[j]) return 1;
    }
  }
  return 0;
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(byte) compare_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2)
/* ---------------------------------------------------------------------------- */
{
  int i, j;
  short *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j] != Yi[j]) return 1;
    }
  }
  return 0;
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte) compare_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2)
/* ------------------------------------------------------------------------------- */
{
  int i, j;
  ushort *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j] != Yi[j]) return 1;
    }
  }
  return 0;
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(byte) compare_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int  **m2)
/* ------------------------------------------------------------------------- */
{
  int i, j;
  int *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j] != Yi[j]) return 1;
    }
  }
  return 0;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) init_blut(byte *v, int nl, int nh, int n0, int n1, byte k)
/* ----------------------------------------------------------------------- */
{
  int i;

  if(nl<=nh) {
    // normal case 
    for(i=nl;   i< n0; i++) v[i] = 0;
    for(i=n0;   i<=n1; i++) v[i] = k;
    for(i=n1+1; i<nh; i++)  v[i] = 0;
  } else {
    for(i=nl;   i< n1; i++) v[i] = k;
    for(i=n1;   i<=n0; i++) v[i] = 0;
    for(i=n1+1; i<nh;  i++) v[i] = k;
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) init_i16lut(int16 *v, int nl, int nh, int n0, int n1, int16 k)
/* --------------------------------------------------------------------------- */
{
  int i;

  if(nl<=nh) {
    // normal case 
    for(i=nl;   i< n0; i++) v[i] = 0;
    for(i=n0;   i<=n1; i++) v[i] = k;
    for(i=n1+1; i<=nh; i++) v[i] = 0;
  } else {
    for(i=nl;   i< n1; i++) v[i] = k;
    for(i=n1;   i<=n0; i++) v[i] = 0;
    for(i=n1+1; i<=nh; i++) v[i] = k;
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) init_rgb8lut(rgb8 *v, int nl, int nh, int n0, int n1, rgb8 k)
/* -------------------------------------------------------------------------- */
{
  int i;

  if(nl<=nh) {
    // normal case 
    for(i=nl;   i< n0; i++) { v[i].r = 0;   v[i].g = 0;   v[i].b = 0;}
    for(i=n0;   i<=n1; i++) { v[i].r = k.r; v[i].g = k.g; v[i].b = k.b;}
    for(i=n1+1; i<=nh; i++)  { v[i].r = 0;   v[i].g = 0;  v[i].b = 0;}
  } else {
    for(i=nl;   i< n1; i++) { v[i].r = k.r; v[i].g = k.g; v[i].b = k.b;}
    for(i=n1;   i<=n0; i++) { v[i].r = 0;   v[i].g = 0;   v[i].b = 0;}
    for(i=n1+1; i<=nh; i++) { v[i].r = k.r; v[i].g = k.g; v[i].b = k.b;}
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lut_bmatrix(byte **S, long nrl,long nrh,long ncl, long nch, byte *L, byte **D)
/* ------------------------------------------------------------------------------------------- */
{
  int i, j;
  byte *Si, *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = L[Si[j]];
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lut_smatrix(short **S, long nrl,long nrh,long ncl, long nch, short *L, short **D)
/* -------------------------------------------------------------------------------------------- */
{
  int i, j;
  short *Si, *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = L[Si[j]];
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lut_usmatrix(ushort **S, long nrl,long nrh,long ncl, long nch, ushort *L, ushort **D)
/* ------------------------------------------------------------------------------------------------ */
{
  int i, j;
  ushort *Si, *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = L[Si[j]];
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lut_i16matrix(int16 **S, long nrl, long nrh, long ncl, long nch, int16 *L, int16 **D)
/* -------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int16 *Si, *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = L[Si[j]];
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lut_ui16matrix(uint16 **S, long nrl, long nrh, long ncl, long nch, uint16 *L, uint16 **D)
/* ------------------------------------------------------------------------------------------------------ */
{
  int i, j;
  uint16 *Si, *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = L[Si[j]];
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lut_rgb8matrix(rgb8 **S, long nrl, long nrh, long ncl, long nch, rgb8 *L, rgb8 **D)
/* ------------------------------------------------------------------------------------------------ */
{
  int i, j;
  rgb8 *Si, *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {

      Di[j].r = L[Si[j].r].r;
      Di[j].g = L[Si[j].g].g;
      Di[j].b = L[Si[j].b].b; 
    }
  }
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lut_i16matrix_bmatrix(int16 **S, long nrl, long nrh, long ncl, long nch, int16 *L, byte **D)
/* --------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int16 *Si;
  byte  *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = (byte) L[Si[j]];
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) lut_ui16matrix_bmatrix(uint16 **S, long nrl, long nrh, long ncl, long nch, uint16 *L, byte **D)
/* ------------------------------------------------------------------------------------------------------------ */
{
  int i, j;
  uint16 *Si;
  byte   *Di;

  for(i=nrl; i<=nrh; i++) {
    Si = S[i]; Di = D[i];
    for(j=ncl; j<=nch; j++) {
      Di[j] = (byte) L[Si[j]];
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) histogram_bmatrix(byte **S, long nrl, long nrh, long ncl, long nch, int32 *H)
/* ---------------------------------------------------------------------------- */
{
  int i, j;
  byte *Si;
  
  for(i=nrl; i<=nrh; i++) {
    Si = S[i];
    for(j=ncl; j<=nch; j++) {
      H[Si[j]]++;
    }
  }
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) histogram_ui16matrix(uint16 **S, long nrl, long nrh, long ncl, long nch, int32 *H)
/* --------------------------------------------------------------------------------- */
{
  int i, j;
  uint16 *Si;
  
  for(i=nrl; i<=nrh; i++) {
    Si = S[i];
    for(j=ncl; j<=nch; j++) {
      H[Si[j]]++;
    }
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) histogram_rgb8matrix(rgb8 **S, long nrl, long nrh, long ncl, long nch, rgb32 *H)
/* ------------------------------------------------------------------------------- */
{
  int i, j;
  rgb8 *Si;
  int r, b, g;
  
  //FUNCTION_NAME("Histogram_rgbmatrix");
  
  for(i=nrl; i<=nrh; i++) {
    Si = S[i];
    //PROGRESS_INFO(function_name, i, nrl, nrh);
    for(j=ncl; j<=nch; j++) {

      /*H[Si[j].r].r++;
      H[Si[j].g].g++;
      H[Si[j].b].b++;/**/

      r = S[i][j].r;
      g = S[i][j].g;
      b = S[i][j].b;

      H[r].r++;
      H[g].g++;
      H[b].b++;/**/
    }
  }

  //END;
  return;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) beta_sum_rgb32vector(rgb32 *S,long nl,long nh, rgb32 *D)
/* ------------------------------------------------------------------- */
{
  long i;
  int32 r, g, b, s;
  for(i=nl; i<=nh; i++){
    r = S[i].r;
    g = S[i].g;
    b = S[i].b;
    s = r + g + b;
    D[i].r = s;
    D[i].g = s;
    D[i].b = s;
  }
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) beta_average_rgb32vector(rgb32 *S,long nl,long nh, rgb32 *D)
/* ----------------------------------------------------------------------- */
{
  long i;
  int32 r, g, b, s;
  for(i=nl; i<=nh; i++){
    r = S[i].r;
    g = S[i].g;
    b = S[i].b;
    s = (r + g + b) / 3;
    D[i].r = s;
    D[i].g = s;
    D[i].b = s;
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) add_i32vector(int32 *S1,long nl,long nh, int32 *S2, int32 *D)
/* ------------------------------------------------------------------------ */
{
  long i;
  for(i=nl; i<=nh; i++) D[i] = S1[i] + S2[i];
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) sub_i32vector(int32 *S1,long nl,long nh, int32 *S2, int32 *D)
/* ------------------------------------------------------------------------ */
{
  long i;
  for(i=nl; i<=nh; i++) D[i] = S1[i] - S2[i];
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulc_i32vector(int32 *S,long nl,long nh, int32 c, int32 *D)
/* ---------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++) D[i] = c * S[i];
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) mulc_rgb32vector(rgb32 *S,long nl,long nh, int32 c, rgb32 *D)
/* ------------------------------------------------------------------------ */
{
  long i;

  for(i=nl; i<=nh; i++) {
    D[i].r = c * S[i].r;
    D[i].g = c * S[i].g;
    D[i].b = c * S[i].b;
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) divc_i32vector(int32 *S,long nl,long nh, int32 c, int32 *D)
/* ------------------------------------------------------------------------ */
{
  long i;
  for(i=nl; i<=nh; i++) D[i] = S[i]  / c;
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) divc_rgb32vector(rgb32 *S,long nl,long nh, int32 c, rgb32 *D)
/* -------------------------------------------------------------------------- */
{
  long i;

  for(i=nl; i<=nh; i++) {
    D[i].r = S[i].r / c;
    D[i].g = S[i].g / c;
    D[i].b = S[i].b / c;
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addc_bmatrix(byte **src,long nrl,long nrh,long ncl, long nch, byte  cte, byte **dst)
/* ------------------------------------------------------------------------------------------------- */
{
  long i,j;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j] + cte;
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addc_smatrix(short **src,long nrl,long nrh,long ncl, long nch, short cte, short **dst)
/* ------------------------------------------------------------------------------------- */
{
  long i,j;
  short *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j] + cte;
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addc_usmatrix(ushort **src,long nrl,long nrh,long ncl, long nch, short cte, ushort **dst)
/* ---------------------------------------------------------------------------------------- */
{
  long i,j;
  ushort *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j] + cte;
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addcnz_bmatrix(byte **src,long nrl,long nrh,long ncl, long nch, byte  cte, byte **dst)
/* ------------------------------------------------------------------------------------- */
{
  long i,j;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j])
        Yi[j] = Xi[j] + cte;
      else
        Yi[j] = Xi[j];
    }
  }
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addandc_bmatrix(byte **src,long nrl,long nrh,long ncl, long nch, byte  cte, byte **dst)
/* ----------------------------------------------------------------------------------- */
{
  long i,j;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j])
        Yi[j] = Xi[j] + cte;
      else
        Yi[j] = Xi[i];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addandc_smatrix(short **src,long nrl,long nrh,long ncl, long nch, short cte, short **dst)
/* ---------------------------------------------------------------------------------------- */
{
  long i,j;
  short *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j]) Yi[j] = Xi[j] + cte;
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) addandc_usmatrix(ushort **src,long nrl,long nrh,long ncl, long nch, short cte, ushort **dst)
/* ------------------------------------------------------------------------------------------- */
{
  long i,j;
  ushort *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = src[i];
    Yi = dst[i];
    for(j=ncl; j<=nch; j++) {
      if(Xi[j]) Yi[j] = Xi[j] + cte;
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and2_bmatrix(byte **src,long nrl,long nrh,long ncl, long nch, byte **cond, byte **dst)
/* ------------------------------------------------------------------------------------- */
{
  long i, j;
  byte *Xi, *Yi, *Ci;

  for(i=nrl; i<=nrh; i++) {
    Xi = src [i];
    Yi = dst [i];
    Ci = cond[i];
    for(j=ncl; j<=nch; j++) {
      if(Ci[j]) Yi[j] = Xi[j]; else Yi[j] = 0;
    }
  }
}
/* ----------------------------------------------------------- */
IMAGE_EXPORT(int) count_bmatrix(byte **m, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------- */
{
  long i, j;
  int s = 0;
  byte *Xi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    for(j=ncl; j<=nch; j++) {
      s += Xi[j];
    }
  }

  return s;
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) not_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2)
/* ------------------------------------------------------------------------------------ */
{
  long i, j;
  byte x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2)
/* -------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2)
/* ----------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2)
/* ---------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2)
/* ------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2)
/* ---------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2)
/* ------------------------------------------------------------------------------------- */
{
  long i, j;
  uint x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32 **m2)
/* ---------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2)
/* ------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = ! x;
      Yi[j] = y;
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) not_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2)
/* --------------------------------------------------------------------------------------- */
{
  long i, j;
  rgb8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_NOT(x,y);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) not_rgbx8matrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 **m2)
/* ------------------------------------------------------------------------------------------ */
{
  long i, j;
  rgbx8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGBX8_NOT(x,y);
      Yi[j] = y;
    }
  }
}
/* ---------- */
/* --- Or --- */
/* ---------- */
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2, byte **m3)
/* ---------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2, short **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort **m3)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2, int16 **m3)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16 **m3)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2, int **m3)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2, uint **m3)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
   uint x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_i32matrix(int **m1, long nrl,long nrh,long ncl, long nch, int32 **m2, int32 **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32 **m3)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, j;
   uint32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x | y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2, rgb8 **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgb8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGB8_OR(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) or_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 **m2, rgbx8 **m3)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgbx8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGBX8_OR(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ----------- */
/* --- Xor --- */
/* ----------- */
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2, byte **m3)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2, short **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xor_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort **m3)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  ushort x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2, int16 **m3)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2, int **m3)
/* -------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xor_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2, uint **m3)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
   uint x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_i32matrix(int **m1, long nrl,long nrh,long ncl, long nch, int32 **m2, int32 **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
   uint32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x ^ y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xor_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2, rgb8 **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgb8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGB8_XOR(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xor_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 **m2, rgbx8 **m3)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
   rgbx8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGBX8_XOR(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ----------- */
/* --- And --- */
/* ----------- */
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2, byte **m3)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2, short **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) and_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort **m3)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  ushort x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2, int16 **m3)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2, int **m3)
/* -------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) and_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2, uint **m3)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
   uint x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_i32matrix(int **m1, long nrl,long nrh,long ncl, long nch, int32 **m2, int32 **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
   uint32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x & y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) and_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2, rgb8 **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgb8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGB8_AND(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) and_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 **m2, rgbx8 **m3)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
   rgbx8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGBX8_AND(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ------------ */
/* --- Nand --- */
/* ------------ */
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) nand_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2, byte **m3)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  byte x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2, short **m3)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort **m3)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2, int16 **m3)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16 **m3)
/* --------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2, int **m3)
/* --------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2, uint **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
   uint x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_i32matrix(int **m1, long nrl,long nrh,long ncl, long nch, int32 **m2, int32 **m3)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32 **m3)
/* --------------------------------------------------------------------------------------------------------- */
{
  long i, j;
   uint32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = !(x & y);
      Zi[j] = z;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2, rgb8 **m3)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgb8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGB8_NAND(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nand_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 **m2, rgbx8 **m3)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgbx8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGBX8_NAND(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ----------- */
/* --- Orc --- */
/* ----------- */
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte c, byte **m2)
/* -------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short c, short **m2)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort **m2)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 c, int16 **m2)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16 **m2)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int c, int **m2)
/* ----------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint c, uint **m2)
/* --------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_i32matrix(int **m1, long nrl,long nrh,long ncl, long nch, int32 c, int32 **m2)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32 **m2)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x | c;
      Yi[j] =y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 c, rgb8 **m2)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgb8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_OR(x,c,y);
      Yi[j] =y;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) orc_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 c, rgbx8 **m2)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgbx8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGBX8_OR(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ------------ */
/* --- Xorc --- */
/* ------------ */
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xorc_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte c, byte **m2)
/* --------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xorc_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short c, short **m2)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  short x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xorc_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort **m2)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xorc_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 c, int16 **m2)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xorc_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16 **m2)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  uint16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xorc_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int c, int **m2)
/* ------------------------------------------------------------------------------------------ */
{
  long i, j;
  int x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xorc_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint c, uint **m2)
/* ---------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xorc_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32 c, int32 **m2)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xorc_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32 **m2)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  uint32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x ^ c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) xorc_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 c, rgb8 **m2)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  rgb8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_XOR(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) xorc_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 c, rgbx8 **m2)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgbx8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_XOR(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ------------ */
/* --- Andc --- */
/* ------------ */
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) andc_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte c, byte **m2)
/* --------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) andc_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short c, short **m2)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  short x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) andc_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort **m2)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) andc_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 c, int16 **m2)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) andc_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16 **m2)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  uint16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) andc_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int c, int **m2)
/* ------------------------------------------------------------------------------------------ */
{
  long i, j;
  int x, y, *Xi, *Yi;
 
  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) andc_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint c, uint **m2)
/* ---------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) andc_i32matrix(int **m1, long nrl,long nrh,long ncl, long nch, int32 c, int32 **m2)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  int32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) andc_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32 **m2)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  uint32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & c;
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) andc_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 c, rgb8 **m2)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  rgb8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_AND(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) andc_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 c, rgbx8 **m2)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgbx8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGBX8_AND(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ------------- */
/* --- Nandc --- */
/* ------------- */
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte c, byte **m2)
/* ---------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short c, short **m2)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort **m2)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  ushort x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 c, int16 **m2)
/* --------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16 **m2)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int c, int **m2)
/* ------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint c, uint **m2)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32 c, int32 **m2)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32 **m2)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint32 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = !(x & c);
      Yi[j] = y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 c, rgb8 **m2)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgb8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_NAND(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) nandc_rgb8xmatrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx8 c, rgbx8 **m2)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgbx8 x, y, *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGBX8_NAND(x,c,y);
      Yi[j] = y;
    }
  }
}
/* ----------- */
/* --- Add --- */
/* ----------- */
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2, byte **m3)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      //Zi[j] = Xi[j] + Yi[j];
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2, short **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) add_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort **m3)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  ushort x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2, int16 **m3)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2, int **m3)
/* -------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) add_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2, uint **m3)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  uint x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32 **m2, int32 **m3)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_matrix(float **m1, long nrl,long nrh,long ncl, long nch, float **m2, float **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  float x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_dmatrix(double **m1, long nrl,long nrh,long ncl, long nch, double **m2, double **m3)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  double x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x + y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) add_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2, rgb8 **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  rgb8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      //z = x + y;
      RGB8_ADD(x,y,z);
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, byte **m2, byte **m3)
/* ----------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      //Zi[j] = Xi[j] - Yi[j];
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, short **m2, short **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
  short x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      //Zi[j] = Xi[j] - Yi[j];
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) sub_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort **m3)
/* ------------------------------------------------------------------------------------------------------ */
{
  long i, j;
  ushort x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int16 **m2, int16 **m3)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint16 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int **m2, int **m3)
/* -------------------------------------------------------------------------------------------- */
{
  long i, j;
  int x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) sub_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, uint **m2, uint **m3)
/* ------------------------------------------------------------------------------------------------ */
{
  long i, j;
  uint x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32 **m2, int32 **m3)
/* ---------------------------------------------------------------------------------------------------- */
{
  long i, j;
  int32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32 **m3)
/* -------------------------------------------------------------------------------------------------------- */
{
  long i, j;
  uint32 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_matrix(float **m1, long nrl,long nrh,long ncl, long nch, float **m2, float **m3)
/* ------------------------------------------------------------------------------------------------- */
{
  long i, j;
  float x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_dmatrix(double **m1, long nrl,long nrh,long ncl, long nch, double **m2, double **m3)
/* ----------------------------------------------------------------------------------------------------- */
{
  long i, j;
  double x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      z = x - y;
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) sub_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb8 **m2, rgb8 **m3)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, j;
   rgb8 x, y, z, *Xi, *Yi, *Zi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    Zi = m3[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = Yi[j];
      RGB8_SUB(x,y,z);
      Zi[j] = z;
    }
  }
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) cumulleft_i32vector(int32 *S, long nl,long nh, int32 *D)
/* -------------------------------------------------------------------- */
{
  // for histogram
  long i;
 
  for(i=nh-1; i>=nl; i--) {
    D[i] += S[i+1];
  }
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) cumulleft_rgb32vector(rgb32 *S, long nl,long nh, rgb32 *D)
/* --------------------------------------------------------------------- */
{
  // for histogram
  long i;
 
  for(i=nh-1; i>=nl; i--) {
    D[i].r += S[i+1].r;
    D[i].g += S[i+1].g;
    D[i].b += S[i+1].b;
  }
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) cumulright_i32vector(int32 *S, long nl,long nh, int32 *D)
/* -------------------------------------------------------------------- */
{
  // for histogram
  long i;
 
  for(i=nl+1; i<=nh; i++) {
    D[i] += S[i-1];
  }
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) cumulright_rgb32vector(rgb32 *S, long nl,long nh, rgb32 *D)
/* ---------------------------------------------------------------------- */
{
  // for histogram
  long i;
 
  for(i=nl+1; i<=nh; i++) {
    D[i].r += S[i-1].r;
    D[i].g += S[i-1].g;
    D[i].b += S[i-1].b;
  }
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_i32vector(int32 *S, long nl,long nh, int32 a, int32 b, int32 *D)
/* ----------------------------------------------------------------------------------- */
{
  long i;
 
  for(i=nl; i<=nh; i++) {
    //D[i] = (a * S[i] + b) / b;
    D[i] = (a * S[i]) / b;
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_rgb32vector(rgb32 *S, long nl,long nh, int32 a, int32 b, rgb32 *D)
/* ------------------------------------------------------------------------------------- */
{
  long i;
 
  for(i=nl; i<=nh; i++) {
    //D[i].r = (a * S[i].r + b) / b;
    //D[i].g = (a * S[i].g + b) / b;
    //D[i].b = (a * S[i].b + b) / b;
    D[i].r = (a * S[i].r) / b;
    D[i].g = (a * S[i].g) / b;
    D[i].b = (a * S[i].b) / b;
  }
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) quadratic_error_smatrix(short **m1,long nrl,long nrh,long ncl, long nch, short **m2, int **m3)
/* --------------------------------------------------------------------------------------------------------- */
{
}
/* ------------------------------------------------------------- */
IMAGE_EXPORT(void) set_bvector(byte *v, long nl, long nh, byte cte)
/* ------------------------------------------------------------- */
{
  int n = nh - nl + 1;

  memset(v+nl, cte, n);
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) set_svector(short *v, long nl, long nh, short cte)
/* --------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) set_usvector(ushort *v, long nl, long nh, ushort cte)
/* ------------------------------------------------------------------ */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) set_i16vector(int16 *v, long nl, long nh, int16 cte)
/* ----------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_ui16vector(uint16 *v, long nl, long nh, uint16 cte)
/* -------------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ----------------------------------------------------------- */
IMAGE_EXPORT(void) set_ivector(int *v, long nl, long nh, int cte)
/* ----------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) set_uivector(uint *v, long nl, long nh, uint cte)
/* -------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) set_i32vector(int32 *v, long nl, long nh, int32 cte)
/* ----------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_ui32vector(uint32 *v, long nl, long nh, uint32 cte)
/* -------------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) set_vector(float *v, long nl, long nh, float cte)
/* -------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) set_dvector(double *v, long nl, long nh, double cte)
/* ----------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) set_rgb8vector(rgb8 *v, long nl, long nh, rgb8 cte)
/* ---------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_rgbx8vector(rgbx8 *v, long nl, long nh, rgbx8 cte)
/* ------------------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = cte;
}
/* ------------------------------------------------------ */
IMAGE_EXPORT(void) set_bvector_j(byte  *v, long nl, long nh)
/* ------------------------------------------------------ */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (byte) i;
}
/* ------------------------------------------------------ */
IMAGE_EXPORT(void) set_svector_j(short *v, long nl, long nh)
/* ------------------------------------------------------ */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (short) i;
}
/* -------------------------------------------------------- */
IMAGE_EXPORT(void) set_usvector_j(ushort *v, long nl, long nh)
/* -------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (ushort) i;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(void) set_ivector_j(int  *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (int) i;
}
/* ------------------------------------------------------ */
IMAGE_EXPORT(void) set_uivector_j(uint *v, long nl, long nh)
/* ------------------------------------------------------ */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (uint) i;
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(void) set_vector_j(float *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (float) i;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(void) set_dvector_j(double *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  int i;

  for(i=nl; i<=nh; i++)
    v[i] = (double) i;
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_bmatrix(byte **m,long nrl,long nrh,long ncl, long nch, byte cte)
/* --------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_bvector(m[i], ncl, nch, cte);
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_i16matrix(int16 **m,long nrl,long nrh,long ncl, long nch, int16 cte)
/* ------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_i16vector(m[i], ncl, nch, cte);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_ui16matrix(uint16 **m,long nrl,long nrh,long ncl, long nch, uint16 cte)
/* ---------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_ui16vector(m[i], ncl, nch, cte);
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_smatrix(short **m,long nrl,long nrh,long ncl, long nch, short cte)
/* ----------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_svector(m[i], ncl, nch, cte);
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_usmatrix(ushort **m,long nrl,long nrh,long ncl, long nch, ushort cte)
/* -------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_usvector(m[i], ncl, nch, cte);
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_imatrix(int **m,long nrl,long nrh,long ncl, long nch, int cte)
/* ------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_ivector(m[i], ncl, nch, cte);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_uimatrix(uint **m,long nrl,long nrh,long ncl, long nch, uint cte)
/* ---------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_uivector(m[i], ncl, nch, cte);
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_i32matrix(int32 **m,long nrl,long nrh,long ncl, long nch, int32 cte)
/* ------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_i32vector(m[i], ncl, nch, cte);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_ui32matrix(uint32 **m,long nrl,long nrh,long ncl, long nch, uint32 cte)
/* ---------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_ui32vector(m[i], ncl, nch, cte);
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_matrix(float **m,long nrl,long nrh,long ncl, long nch, float cte)
/* ---------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_vector(m[i], ncl, nch, cte);
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_dmatrix(double **m,long nrl,long nrh,long ncl, long nch, double cte)
/* ------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_dvector(m[i], ncl, nch, cte);
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) set_rgb8matrix(rgb8 **m,long nrl,long nrh,long ncl, long nch, rgb8 cte)
/* ------------------------------------------------------------------------------------ */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_rgb8vector(m[i], ncl, nch, cte);
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_rgbx8matrix(rgbx8 **m,long nrl,long nrh,long ncl, long nch, rgbx8 cte)
/* --------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++)
    set_rgbx8vector(m[i], ncl, nch, cte);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_bmatrix_border1(byte **m,long nrl,long nrh,long ncl, long nch, byte cte)
/* ----------------------------------------------------------------------------------------- */
{
  int i;

  set_bvector(m[nrl], ncl, nch, cte);

  for(i=nrl+1; i<=nrh-1; i++) {
    m[i][ncl] = cte;
    m[i][nch] = cte;
  }

  set_bvector(m[nrl], ncl, nch, cte);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) set_bmatrix_border(byte **m,long nrl,long nrh,long ncl, long nch, long n, byte cte)
/* ------------------------------------------------------------------------------------------------ */
{
  int i, j;
  byte *Xi;

  for(i=nrl; i<nrl+n; i++) {
    Xi = m[i];
    for(j=ncl; j<=nch; j++) {
      Xi[j] = cte;
    }
  }

  for(i=nrl+n; i<nrh; i++) {
    Xi = m[i];
    for(j=0; j<n; j++) {
      Xi[ncl+j] = cte;
      Xi[nch-j] = cte;
    }
  }

  for(i=nrh-n+1; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      Xi[j] = cte;
    }
  }
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_bmatrix_i(byte **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------- */
{
  int i, j;
  byte *Xi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    for(j=ncl; j<=nch; j++) {
      Xi[j] = i;
    }
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_smatrix_i(short **m,long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  int i, j;
  short *Xi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    for(j=ncl; j<=nch; j++) {
      Xi[j] = i;
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_usmatrix_i(ushort **m,long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j;
  ushort *Xi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    for(j=ncl; j<=nch; j++) {
      Xi[j] = i;
    }
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) set_imatrix_i(int **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  int i, j;
  int *Xi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    for(j=ncl; j<=nch; j++) {
      Xi[j] = i;
    }
  }
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_bmatrix_j(byte **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------- */
{
  int i, j;
  int ncol=nch-ncl+1;

  byte *Li, *L0 = m[nrl];

  /* set the first line */
  for(j=ncl; j<=nch; j++) {
    L0[j] = j;
  }

  /* set the other line */
  for(i=nrl+1; i<=nrh; i++) {
    Li = m[i];
    memcpy(Li, L0, ncol);
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_smatrix_j(short **m,long nrl,long nrh,long ncl, long nch)
/* -------------------------------------------------------------------------- */
{
  int i, j;
  int ncol=nch-ncl+1;
  int ncol4 = 4 * ncol;

  short *Li, *L0 = m[nrl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      m[i][j] = j;
    }
  }
  return;

  /* fill the first line */
  for(j=ncl; j<=nch; j++) {
    L0[j] = j;
  }

  /* fill the other line */
  for(i=nrl+1; i<=nrh; i++) {
    Li = m[i]+ncl;
    memcpy(Li, L0, ncol4);
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) set_usmatrix_j(ushort **m,long nrl,long nrh,long ncl, long nch)
/* ---------------------------------------------------------------------------- */
{
  int i, j;
  int ncol=nch-ncl+1;
  int ncol2 = 2 * ncol;

  ushort *Li, *L0 = m[nrl];

  /* fill the first line */
  for(j=ncl; j<=nch; j++) {
    L0[j] = j;
  }

  /* fill the other line */
  for(i=nrl+1; i<=nrh; i++) {
    Li = m[i];
    memcpy(Li, L0, ncol);
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) set_imatrix_j(int **m,long nrl,long nrh,long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  int i, j;
  int ncol=nch-ncl+1;
  int ncol4 = 4 * ncol;

  int *Li, *L0 = m[nrl];

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      m[i][j] = j;
    }
  }
  return;

  /* fill the first line */
  for(j=ncl; j<=nch; j++) {
    L0[j] = j;
  }

  /* fill the other line */
  for(i=nrl+1; i<=nrh; i++) {
    Li = m[i]+ncl;
    memcpy(Li, L0, ncol4);
  }
}
/* --------------- */
/* --- MulFrac --- */
/* --------------- */
// m2 = (a*m1)/b
/* ------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) mulfrac_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, byte **m2)
/* ------------------------------------------------------------------------------------------------------------ */
{
  int i, j;
  int32 x, y;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (byte) y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, short **m2)
/* -------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  short *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (short) y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, ushort **m2)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  ushort *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (ushort) y;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, int16 **m2)
/* --------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  int16 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (int16) y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, uint16 **m2)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  uint16 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (uint16) y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, int **m2)
/* ---------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  int *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (int) y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, uint **m2)
/* ------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  uint *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (uint) y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, int32 **m2)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  int32 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (int32) y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, uint32 **m2)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  uint32 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) / b;
      Yi[j] = (uint32) y;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrac_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb32  a, rgb32  b, rgb8 **m2)
/* --------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgb32 y;
  rgb8 x, y8;
  rgb8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_MULFRAC(x,a,b,y);
      RGB32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) mulfrac_rgbx8matrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx32 a, rgbx32 b, rgbx8 **m2)
/* ------------------------------------------------------------------------------------------------------------------ */
{
  int i, j;
  rgbx32 y;
  rgbx8 x, y8;
  rgbx8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_MULFRAC(x,a,b,y);
      RGB32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrack_rgb8matrix (rgb8 **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 b, rgb8 **m2)
/* --------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgb32 y;
  rgb8 x, y8;
  rgb8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_MULFRACK(x,a,b,y);
      RGB32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulfrack_rgbx8matrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 b, rgbx8 **m2)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgbx32 y;
  rgbx8 x, y8;
  rgbx8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGBX8_MULFRACK(x,a,b,y);
      RGBX32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* ---------------- */
/* --- MulShift --- */
/* ---------------- */
// m3 = (a*m1)>>s
/* ------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_bmatrix(byte **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, byte **m2)
/* ------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (byte) y;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_smatrix(short **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, short **m2)
/* --------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  short *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (short) y;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) mulshift_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, ushort **m2)
/* ------------------------------------------------------------------------------------------------------------------ */
{
  int i, j;
  int32 x, y;
  ushort *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (ushort) y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_i16matrix(int16 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, int16 **m2)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  int16 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (int16) y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_ui16matrix(uint16 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, uint16 **m2)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  uint16 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (uint16) y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_imatrix(int **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, int **m2)
/* ----------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  int *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (int) y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_uimatrix(uint **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, uint **m2)
/* -------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  uint *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (uint) y;
    }
  }
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_i32matrix(int32 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, int32 **m2)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  int32 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (int32) y;
    }
  }
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_ui32matrix(uint32 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, uint32 **m2)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  int32 x, y;
  uint32 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = (a * x) >> s;
      Yi[j] = (uint32) y;
    }
  }
}
/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, rgb32  a, rgb32  s, rgb8 **m2)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgb32 y;
  rgb8 x, y8;
  rgb8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_MULSHIFT(x,a,s,y);
      RGB32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshift_rgbx8matrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, rgbx32 a, rgbx32 s, rgbx8 **m2)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgbx32 y;
  rgbx8 x, y8;
  rgbx8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_MULSHIFT(x,a,s,y);
      RGB32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshiftk_rgb8matrix(rgb8 **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 s, rgb8 **m2)
/* --------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgb32 y;
  rgb8  x, y8;
  rgb8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGB8_MULSHIFTK(x,a,s,y);
      RGB32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) mulshiftk_rgbx8matrix(rgbx8 **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 s, rgbx8 **m2)
/* ------------------------------------------------------------------------------------------------------------------- */
{
  int i, j;
  rgbx32 y;
  rgbx8  x, y8;
  rgbx8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m1[i];
    Yi = m2[i];
    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      RGBX8_MULSHIFTK(x,a,s,y);
      RGBX32CAST8(y,y8);
      Yi[j] = y8;
    }
  }
}
/* ---------------------------------- */
/* --- Cube Rotation Left & Right --- */
/* ---------------------------------- */
// Seko Latidine
/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rd_rotate_i16cube_buffer(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;
  int16 ** plane;

  plane = i16matrix(nrl, nrh, ncl, nch);
  
  for(k=ndl; k<ndh; k++)
  {
    for(i=ncl; i<nch; i++)
      for(j=nrl; j<nrh; j++)
      {
         plane[i][j] = S[k][i][j]; 
      }
    rrotate_i16matrix (plane, nrl, nrh, ncl, nch, D[k]);
  }
  free_i16matrix(plane, nrl, nrh, ncl, nch);
}
/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) ld_rotate_i16cube_buffer(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;
  int16 ** plane;
  plane = i16matrix(nrl, nrh, ncl, nch);

  for(k=ndl; k<ndh; k++)
  {
    for(i=ncl; i<nch; i++)
      for(j=nrl; j<nrh; j++)
      {
         plane[i][j] = S[k][i][j]; 
      }
    lrotate_i16matrix (plane, nrl, nrh, ncl, nch, D[k]);
  }
  free_i16matrix(plane, nrl, nrh, ncl, nch);
}

/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lr_rotate_i16cube_buffer(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;
  int16 ** plane;
  plane = i16matrix(ndl, ndh, ncl, nch);

  for(j=nrl; j<nrh; j++)
  {
    for(i=ncl; i<nch; i++)
      for(k=ndl; k<ndh; k++)
      {
         plane[i][k] = S[k][i][j]; 
      }
    lrotate_i16matrix (plane, ndl, ndh, ncl, nch, D[k]);
  }
  free_i16matrix(plane, ndl, ndh, ncl, nch);
}

/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rr_rotate_i16cube_buffer(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;
  int16 ** plane;
  plane = i16matrix(ndl, ndh, ncl, nch);

  for(j=nrl; j<nrh; j++)
  {
    for(i=ncl; i<nch; i++)
      for(k=ndl; k<ndh; k++)
      {
         plane[i][k] = S[k][i][j]; 
      }
    rrotate_i16matrix (plane, ndl, ndh, ncl, nch, D[k]);
  }
  free_i16matrix(plane, ndl, ndh, ncl, nch);
}

/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lc_rotate_i16cube_buffer(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;
  int16 ** plane;
  plane = i16matrix(ndl, ndh, nrl, nrh);

  for(i=ncl; i<nch; i++)
  {
    for(j=nrl; j<nrh; j++)
      for(k=ndl; k<ndh; k++)
      {
         plane[j][k] = S[k][i][j]; 
      }
    lrotate_i16matrix (plane, ndl, ndh, nrl, nrh, D[k]);
  }
  free_i16matrix(plane, ndl, ndh, nrl, nrh);
}

/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) rc_rotate_i16cube_buffer(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  int i, j, k;
  int16 ** plane;
  plane = i16matrix(ndl, ndh, nrl, nrh);

  for(i=ncl; i<nch; i++)
  {
    for(j=nrl; j<nrh; j++)
      for(k=ndl; k<ndh; k++)
      {
         plane[j][k] = S[k][i][j]; 
      }
    rrotate_i16matrix (plane, ndl, ndh, nrl, nrh, D[k]);
  }
  free_i16matrix(plane, ndl, ndh, nrl, nrh);
}
