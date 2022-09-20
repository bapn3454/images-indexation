/* --------------- */
/* --- nralloc --- */
/* --------------- */

/*
 * Copyright (c) 2000, Lionel Lacassagne LIS-UPMC + Imasys
 */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h> /* isdigit */
#include <string.h> /* memcpy */
#include <math.h> /* fabs */
/*#include <memory.h> /* memcpy */

#include "def.h"
#include "nralloc.h"
#include "nrarith.h"

//NR_END est maintenant defini dans nrutil.h

//#define NR_END 1
//#define FREE_ARG char*

long nr_end = NR_END;

/* ------------------------- */
void nrerror(char error_text[])
/* ------------------------- */
/* Numerical Recipes standard error handler */
{
  fprintf(stderr,"Numerical Recipes run-time error...\n");
  fprintf(stderr,"%s\n",error_text);
  fprintf(stderr,"...now exiting to system...\n");
  exit(1);
}
/* ------------------------------------- */
IMAGE_EXPORT(float*) vector(long nl, long nh)
/* ------------------------------------- */
/* allocate a float vector with subscript range v[nl..nh] */
{
  float *v;

  v=(float *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(float)));
  if (!v) nrerror("allocation failure in vector()");
  if(!v) return NULL;
  return v-nl+NR_END;
}
/* ---------------------------------------- */
IMAGE_EXPORT(float*) vector0(long nl, long nh)
/* ---------------------------------------- */
/* allocate a float vector with subscript range v[nl..nh] */
{
        float *v;

        v=(float *) calloc ( (size_t) (nh-nl+1+NR_END), sizeof(float) );
        //if (!v) nrerror("allocation failure in vector0()");
        return v-nl+NR_END;
}
/* --------------------------- */
IMAGE_EXPORT(double*) dvector(long nl, long nh)
/* --------------------------- */

/* allocate a double vector with subscript range v[nl..nh] */
{
        double *v;

        v=(double *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(double)));
        if (!v) nrerror("allocation failure in dvector()");
        return v-nl+NR_END;
}
/* --------------------------- */
IMAGE_EXPORT(double*) dvector0(long nl, long nh)
/* --------------------------- */
/* allocate a float vector with subscript range v[nl..nh] */
{
        double *v;

        v=(double *) calloc ( (size_t) (nh-nl+1+NR_END), sizeof(double) );
        if (!v) nrerror("allocation failure in dvector0()");
        return v-nl+NR_END;
}
/* ---------------------------------- */
IMAGE_EXPORT(unsigned char*) cvector(long nl, long nh)
/* ---------------------------------- */
/* allocate an unsigned char vector with subscript range v[nl..nh] */
{
        unsigned char *v;

        v=(unsigned char *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(unsigned char)));
        if (!v) nrerror("allocation failure in cvector()");
        return v-nl+NR_END;
}
/* -------------------------- */
IMAGE_EXPORT(byte*) bvector(long nl, long nh)
/* ------------------------- */
/* allocate an unsigned byte vector with subscript range v[nl..nh] */
{
        byte *v;

        v=(byte *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(byte)));
        if (!v) nrerror("allocation failure in bvector()");
        return v-nl+NR_END;
}
/* -------------------------- */
IMAGE_EXPORT(byte*) bvector0(long nl, long nh)
/* -------------------------- */
/* allocate an unsigned byte vector with subscript range v[nl..nh] */
{
        byte *v;

        v=(byte *) calloc ((size_t) (nh-nl+1+NR_END), sizeof(byte));
        if (!v) nrerror("allocation failure in bvector0()");
        return v-nl+NR_END;
}
/* -------------------------- */
IMAGE_EXPORT(byte*) bvector1(long nl, long nh)
/* -------------------------- */
/* allocate an unsigned byte vector with subscript range v[nl..nh] */
{
  byte *v;

  v=bvector(nl, nh);
  set_bvector(v, nl, nh, 1);

  return v;
}
/* -------------------------------------- */
IMAGE_EXPORT(short*) svector(long nl, long nh)
/* -------------------------------------- */
/* allocate a signed short vector (16 bits) with subscript range v[nl..nh] */
{
        short *v;

        v=(short *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(short)));
        if (!v) nrerror("allocation failure in svector()");
        return v-nl+NR_END;
}
/* ---------------------------------------- */
IMAGE_EXPORT(int16*) i16vector(long nl, long nh)
/* ---------------------------------------- */
{
  int16 *v;

  v=(int16 *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int16)));
  if (!v) nrerror("allocation failure in i16vector()");
  return v-nl+NR_END;
}
/* ------------------------------------------ */
IMAGE_EXPORT(uint16*) ui16vector(long nl, long nh)
/* ------------------------------------------ */
{
  uint16 *v;

  v=(uint16 *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(uint16)));
  if (!v) nrerror("allocation failure in ui16vector()");
  return v-nl+NR_END;
}
/* ---------------------------------------- */
IMAGE_EXPORT(ushort*) usvector(long nl, long nh)
/* ---------------------------------------- */
/* allocate a unsigned short vector (16 bits) with subscript range v[nl..nh] */
{
        ushort *v;

        v=(ushort *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(ushort)));
        if (!v) nrerror("allocation failure in usvector()");
        return v-nl+NR_END;
}
/* --------------------------------------- */
IMAGE_EXPORT(short*) svector0(long nl, long nh)
/* --------------------------------------- */
/* allocate a unsigned short vector (16 bits) with subscript range v[nl..nh] */
{
        short *v;

        v=(short *) calloc((size_t) (nh-nl+1+NR_END),sizeof(short));
        if (!v) nrerror("allocation failure in svector0()");
        return v-nl+NR_END;
}
/* ----------------------------------------- */
IMAGE_EXPORT(ushort*) usvector0(long nl, long nh)
/* ----------------------------------------- */
/* allocate a unsigned short vector (16 bits) with subscript range v[nl..nh] */
{
  ushort *v;

  v=(ushort *) calloc((size_t) (nh-nl+1+NR_END),sizeof(ushort));
  if (!v) nrerror("allocation failure in usvector0()");
  return v-nl+NR_END;
}
/* ----------------------------------------- */
IMAGE_EXPORT(int16*) i16vector0(long nl, long nh)
/* ----------------------------------------- */
{
  int16 *v;

  v=(int16 *)calloc((size_t) ((nh-nl+1+NR_END)), sizeof(int16));
  if (!v) nrerror("allocation failure in i16vector0()");
  return v-nl+NR_END;
}
/* ------------------------------------------- */
IMAGE_EXPORT(uint16*) ui16vector0(long nl, long nh)
/* ------------------------------------------- */
{
  uint16 *v;

  v=(uint16 *)calloc((size_t) ((nh-nl+1+NR_END)), sizeof(uint16));
  if (!v) nrerror("allocation failure in ui16vector0()");
  return v-nl+NR_END;
}
/* ------------------------------------ */
IMAGE_EXPORT(int*) ivector(long nl, long nh)
/* ------------------------------------ */
/* allocate an int vector with subscript range v[nl..nh] */
{
        int *v;

        v=(int *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int)));
        if (!v) nrerror("allocation failure in ivector()");
        return v-nl+NR_END;
}
/* ------------------------------------- */
IMAGE_EXPORT(int*) ivector0(long nl, long nh)
/* ------------------------------------- */
/* allocate an int vector with subscript range v[nl..nh] */
{
  int *v;

  v=(int *) calloc((size_t) (nh-nl+1+NR_END),sizeof(int));
  if (!v) nrerror("allocation failure in ivector0()");
  return v-nl+NR_END;
}
/* ------------------------------------- */
IMAGE_EXPORT(int*) ivector1(long nl, long nh)
/* ------------------------------------- */
{
  int *v;

  v=ivector(nl, nh);
  set_ivector(v, nl, nh, 1);

  return v;
}
/* ---------------------------------------- */
IMAGE_EXPORT(int32*) i32vector(long nl, long nh)
/* ---------------------------------------- */
/* allocate an int vector with subscript range v[nl..nh] */
{
        int32 *v;

        v=(int32 *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(int32)));
        if (!v) nrerror("allocation failure in i32vector()");
        return v-nl+NR_END;
}
/* ----------------------------------------- */
IMAGE_EXPORT(int32*) i32vector0(long nl, long nh)
/* ----------------------------------------- */
/* allocate an int vector with subscript range v[nl..nh] */
{
  int32 *v;

  v=(int32 *) calloc((size_t) (nh-nl+1+NR_END),sizeof(int32));
  if (!v) nrerror("allocation failure in i32vector0()");
  return v-nl+NR_END;
}
/* ---------------------------------------------- */
IMAGE_EXPORT(unsigned long*) lvector(long nl, long nh)
/* ---------------------------------------------- */
/* allocate an unsigned long vector with subscript range v[nl..nh] */
{
        unsigned long *v;

        v=(unsigned long *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(long)));
        if (!v) nrerror("allocation failure in lvector()");
        return v-nl+NR_END;
}
/* ---------------------------------------- */
IMAGE_EXPORT(rgb8*) rgb8vector(long nl, long nh)
/* ---------------------------------------- */
{
  rgb8 *v;

  v=(rgb8 *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(rgb8)));
  if (!v) nrerror("allocation failure in rgb8vector()");
  return v-nl+NR_END;
}
/* ----------------------------------------- */
IMAGE_EXPORT(rgb8*) rgb8vector0(long nl, long nh)
/* ----------------------------------------- */
{
  rgb8 *v;

  v=(rgb8 *)calloc((size_t) ((nh-nl+1+NR_END)), sizeof(rgb8));
  if (!v) nrerror("allocation failure in rgb8vector()");
  return v-nl+NR_END;
}
/* ------------------------------------------ */
IMAGE_EXPORT(rgb32*) rgb32vector(long nl, long nh)
/* ------------------------------------------ */
{
  rgb32 *v;

  v=(rgb32 *)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(rgb32)));
  if (!v) nrerror("allocation failure in rgb32vector()");
  return v-nl+NR_END;
}
/* ------------------------------------------- */
IMAGE_EXPORT(rgb32*) rgb32vector0(long nl, long nh)
/* ------------------------------------------- */
{
  rgb32 *v;

  v=(rgb32 *)calloc((size_t) ((nh-nl+1+NR_END)), sizeof(rgb32));
  if (!v) nrerror("allocation failure in rgb32vector()");
  return v-nl+NR_END;
}

/* -------------------------------------- */
IMAGE_EXPORT(void**) vvector(long nl, long nh)
/* -------------------------------------- */
/* allocate an void pointert vector with subscript range v[nl..nh] */
{
  void **v;

        v=(void**)malloc((size_t) ((nh-nl+1+NR_END)*sizeof(void*)));
        if (!v) nrerror("allocation failure in vvector()");
        return v-nl+NR_END;
}
/* --------------------------- */
IMAGE_EXPORT(void**) vvector0(long nl, long nh)
/* --------------------------- */
/* allocate an int vector with subscript range v[nl..nh] */
{
  void  **v;

  v=(void**) calloc((size_t) (nh-nl+1+NR_END),sizeof(void*));
  if (!v) nrerror("allocation failure in vvector0()");
  return v-nl+NR_END;
}
/* -------------------------------------------------- */
IMAGE_EXPORT(byte*) realloc_bvector(byte *v, long nl, long nh, long n)
/* -------------------------------------------------- */
{
  v += nl;
  v -= NR_END;
  v=(byte *)realloc(v, (size_t) ((nh-nl+1+n+NR_END)*sizeof(byte)));
  if (!v) nrerror("allocation failure in realloc bvector()");

  return v-nl+NR_END;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(short*) realloc_svector(short *v, long nl, long nh, long n)
/* ---------------------------------------------------- */
{
  v += nl;
  v -= NR_END;
  v=(short *)realloc(v, (size_t) ((nh-nl+1+n+NR_END)*sizeof(short)));
  if (!v) nrerror("allocation failure in realloc svector()");

  return v-nl+NR_END;
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(ushort*) realloc_usvector(ushort *v, long nl, long nh, long n)
/* ------------------------------------------------------- */
{
  v += nl;
  v -= NR_END;
  v=(ushort *)realloc(v, (size_t) ((nh-nl+1+n+NR_END)*sizeof(ushort)));
  if (!v) nrerror("allocation failure in realloc usvector()");

  return v-nl+NR_END;
}
/* ------------------------------------------------ */
IMAGE_EXPORT(int*) realloc_ivector(int *v, long nl, long nh, long n)
/* ------------------------------------------------ */
/*
 * add n item to an int vector with subscript range
 * fromv[nl..nh] to [nl..nh+n]
 */
{
  v += nl;
  v -= NR_END;
  v=(int *)realloc(v, (size_t) ((nh-nl+1+n+NR_END)*sizeof(int)));
  if (!v) nrerror("allocation failure in realloc ivector()");

  return v-nl+NR_END;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(void**) realloc_vvector(void **v, long nl, long nh, long n)
/* ---------------------------------------------------- */
/*
 * add n item to an void* vector with subscript range
 * fromv[nl..nh] to [nl..nh+n] */
{
  v += nl;
  v -= NR_END;
  v=(void**)realloc(v, (size_t) ((nh-nl+1+n+NR_END)*sizeof(void*)));
  if (!v) nrerror("allocation failure in realloc vvector()");

  return v-nl+NR_END;
}
/* ------------------------------------------------ */
IMAGE_EXPORT(float**) matrix(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------ */

/* allocate a float matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        float **m;

        /* allocate pointers to rows */
        m=(float **) malloc((size_t)((nrow+NR_END)*sizeof(float*)));
        if (!m) nrerror("allocation failure 1 in matrix()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(float *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(float)));
        if (!m[nrl]) nrerror("allocation failure 2 in matrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* ------------------------------------------------- */
IMAGE_EXPORT(float**) matrix0(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------- */

/* allocate a float matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        float **m;

        /* allocate pointers to rows */
        m=(float **) malloc((size_t)((nrow+NR_END)*sizeof(float*)));
        if (!m) nrerror("allocation failure 1 in matrix0()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(float *) calloc((size_t)(nrow*ncol+NR_END),(size_t)(sizeof(float)));
        if (!m[nrl]) nrerror("allocation failure 2 in matrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_matrix(float **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* -------------------------------------------------- */
IMAGE_EXPORT(double**) dmatrix(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------- */

/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        double **m;

        /* allocate pointers to rows */
        m=(double **) malloc((size_t)((nrow+NR_END)*sizeof(double*)));
        if (!m) nrerror("allocation failure 1 in dmatrix()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(double *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(double)));
        if (!m[nrl]) nrerror("allocation failure 2 in dmatrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* --------------------------------------------------- */
IMAGE_EXPORT(double**) dmatrix0(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------- */

/* allocate a double matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        double **m;

        /* allocate pointers to rows */
        m=(double **) malloc((size_t)((nrow+NR_END)*sizeof(double*)));
        if (!m) nrerror("allocation failure 1 in dmatrix0()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(double *) calloc( (size_t)(nrow*ncol+NR_END) , (size_t)(sizeof(double)) );
        if (!m[nrl]) nrerror("allocation failure 2 in dmatrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* --------------------------------------------------------- */
IMAGE_EXPORT(unsigned char**) cmatrix(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------- */
/* allocate an uchar matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        unsigned char **m;

        /* allocate pointers to rows */
        m=(unsigned char **) malloc((size_t)((nrow+NR_END)*sizeof(unsigned char*)));
        if (!m) nrerror("allocation failure 1 in cmatrix()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(unsigned char *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(unsigned char)));
        if (!m[nrl]) nrerror("allocation failure 2 in cmatrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* ------------------------------------------------ */
IMAGE_EXPORT(byte**) bmatrix(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------ */
/* allocate an uchar matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        byte **m;

        /* allocate pointers to rows */
        m=(byte **) malloc((size_t)((nrow+NR_END)*sizeof(byte*)));
        if (!m) nrerror("allocation failure 1 in bmatrix()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(byte *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(byte)));
        if (!m[nrl]) nrerror("allocation failure 2 in bmatrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(byte**) bmatrix0(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
/* allocate an uchar matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        byte **m;

        /* allocate pointers to rows */
        m=(byte **) malloc((size_t)((nrow+NR_END)*sizeof(byte*)));
        if (!m) nrerror("allocation failure 1 in bmatrix0()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(byte *) calloc( (size_t)(nrow*ncol+NR_END), sizeof(byte));
        if (!m[nrl]) nrerror("allocation failure 2 in bmatrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        short **m;

        /* allocate pointers to rows */
        m=(short **) malloc((size_t)((nrow+NR_END)*sizeof(short*)));
        if (!m) nrerror("allocation failure 1 in smatrix()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(short *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(short)));
        if (!m[nrl]) nrerror("allocation failure 2 in smatrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* --------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  ushort **m;

  /* allocate pointers to rows */
  m=(ushort **) malloc((size_t)((nrow+NR_END)*sizeof(ushort*)));
  if (!m) nrerror("allocation failure 1 in usmatrix()");
  m += NR_END;
  m -= nrl;


  /* allocate rows and set pointers to them */
  m[nrl]=(ushort *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(ushort)));
  if (!m[nrl]) nrerror("allocation failure 2 in smatrix()");
  m[nrl] += NR_END;
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(int16**) i16matrix(long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  int16 **m;

  /* allocate pointers to rows */
  m=(int16 **) malloc((size_t)((nrow+NR_END)*sizeof(int16*)));
  if (!m) nrerror("allocation failure 1 in i16matrix()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(int16 *) malloc((size_t)((nrow*ncol)*sizeof(int16)));
  if (!m[nrl]) nrerror("allocation failure 2 in i16matrix()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  uint16 **m;

  /* allocate pointers to rows */
  m=(uint16 **) malloc((size_t)((nrow+NR_END)*sizeof(uint16*)));
  if (!m) nrerror("allocation failure 1 in ui16matrix()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(uint16 *) malloc((size_t)((nrow*ncol)*sizeof(uint16)));
  if (!m[nrl]) nrerror("allocation failure 2 in ui16matrix()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------- */
IMAGE_EXPORT(int**) imatrix(long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------- */
/* allocate a int matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        int **m;

        /* allocate pointers to rows */
        m=(int **) malloc((size_t)((nrow+NR_END)*sizeof(int*)));
        if (!m) nrerror("allocation failure 1 in imatrix()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(int *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(int)));
        if (!m[nrl]) nrerror("allocation failure 2 in imatrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* ------------------------------------------------ */
IMAGE_EXPORT(int**) imatrix0(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------ */
/* allocate a int matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        int **m;

        /* allocate pointers to rows */
        m=(int **) malloc((size_t)((nrow+NR_END)*sizeof(int*)));
        if (!m) nrerror("allocation failure 1 in imatrix0()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(int *) calloc((size_t)(nrow*ncol+NR_END),sizeof(int));
        if (!m[nrl]) nrerror("allocation failure 2 in imatrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* -------------------------------------------------- */
IMAGE_EXPORT(uint**) uimatrix(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------- */
/* allocate a uint matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        uint **m;

        /* allocate pointers to rows */
        m=(uint **) malloc((size_t)((nrow+NR_END)*sizeof(uint*)));
        if (!m) nrerror("allocation failure 1 in uimatrix0()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(uint *) malloc((size_t)(nrow*ncol+NR_END)*sizeof(uint));
        if (!m[nrl]) nrerror("allocation failure 2 in uimatrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* -------------------------------------------------- */
IMAGE_EXPORT(uint**) uimatrix0(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------- */
/* allocate a uint matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        uint **m;

        /* allocate pointers to rows */
        m=(uint **) malloc((size_t)((nrow+NR_END)*sizeof(uint*)));
        if (!m) nrerror("allocation failure 1 in uimatrix0()");
        m += NR_END;
        m -= nrl;

        /* allocate rows and set pointers to them */
        m[nrl]=(uint *) calloc((size_t)(nrow*ncol+NR_END),sizeof(uint));
        if (!m[nrl]) nrerror("allocation failure 2 in uimatrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix(long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  rgb8 **m;

  /* allocate pointers to rows */
  m=(rgb8**) malloc((size_t)(nrow*sizeof(rgb8*)));
  if (!m) nrerror("allocation failure 1 in rgb8matrix()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(rgb8*) malloc((size_t)((nrow*ncol)*sizeof(rgb8)));
  if (!m[nrl]) nrerror("allocation failure 2 in rgb8matrix()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(rgbx8**) rgbx8matrix(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  rgbx8 **m;

  /* allocate pointers to rows */
  m=(rgbx8**) malloc((size_t)(nrow*sizeof(rgbx8*)));
  if (!m) nrerror("allocation failure 1 in rgbx8matrix()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(rgbx8*) malloc((size_t)((nrow*ncol)*sizeof(rgbx8)));
  if (!m[nrl]) nrerror("allocation failure 2 in rgbx8matrix()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------ */
IMAGE_EXPORT(long**) lmatrix(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------ */
/* allocate a int matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        long **m;

        /* allocate pointers to rows */
        m=(long **) malloc((size_t)((nrow+NR_END)*sizeof(long*)));
        if (!m) nrerror("allocation failure 1 in lmatrix()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(long *) malloc((size_t)((nrow*ncol+NR_END)*sizeof(long)));
        if (!m[nrl]) nrerror("allocation failure 2 in lmatrix()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* -------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix0(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
        long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
        short **m;

        /* allocate pointers to rows */
        m=(short **) malloc((size_t)((nrow+NR_END)*sizeof(short*)));
        if (!m) nrerror("allocation failure 1 in smatrix0()");
        m += NR_END;
        m -= nrl;


        /* allocate rows and set pointers to them */
        m[nrl]=(short *) calloc( (size_t)(nrow*ncol+NR_END), (size_t)(sizeof(short)) );
        if (!m[nrl]) nrerror("allocation failure 2 in smatrix0()");
        m[nrl] += NR_END;
        m[nrl] -= ncl;

        for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

        /* return pointer to array of pointers to rows */
        return m;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix0(long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------- */
/* allocate a unsigned short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  ushort **m;

   /* allocate pointers to rows */
   m=(ushort **) malloc((size_t)((nrow+NR_END)*sizeof(ushort*)));
   if (!m) nrerror("allocation failure 1 in smatrix0()");
   m += NR_END;
   m -= nrl;

   /* allocate rows and set pointers to them */
   m[nrl]=(ushort *) calloc( (size_t)(nrow*ncol+NR_END), (size_t)(sizeof(ushort)) );
   if (!m[nrl]) nrerror("allocation failure 2 in usmatrix0()");
   m[nrl] += NR_END;
   m[nrl] -= ncl;

   for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

   /* return pointer to array of pointers to rows */
   return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(int16**) i16matrix0(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------ */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  int16 **m;

  /* allocate pointers to rows */
  m=(int16 **) malloc((size_t)((nrow+NR_END)*sizeof(int16*)));
  if (!m) nrerror("allocation failure 1 in i16matrix0()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(int16 *) calloc(nrow*ncol, sizeof(int16));
  if (!m[nrl]) nrerror("allocation failure 2 in i16matrix0()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix0(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  uint16 **m;

  /* allocate pointers to rows */
  m=(uint16 **) malloc((size_t)((nrow+NR_END)*sizeof(uint16*)));
  if (!m) nrerror("allocation failure 1 in ui16matrix0()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(uint16 *) calloc(nrow*ncol, sizeof(uint16));
  if (!m[nrl]) nrerror("allocation failure 2 in ui16matrix0()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(rgb8**) rgb8matrix0(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------ */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  rgb8 **m;

  /* allocate pointers to rows */
  m=(rgb8**) malloc((size_t)(nrow*sizeof(rgb8*)));
  if (!m) nrerror("allocation failure 1 in rgb8matrix0()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(rgb8*) calloc(nrow*ncol, sizeof(rgb8));
  if (!m[nrl]) nrerror("allocation failure 2 in rgb8matrix0()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(rgbx8**) rgbx8matrix0(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------- */
/* allocate a short matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  rgbx8 **m;

  /* allocate pointers to rows */
  m=(rgbx8**) malloc((size_t)(nrow*sizeof(rgbx8*)));
  if (!m) nrerror("allocation failure 1 in rgbx8matrix()");
  m -= nrl;

  /* allocate rows and set pointers to them */
  m[nrl]=(rgbx8*) calloc(nrow*ncol, sizeof(rgbx8));
  if (!m[nrl]) nrerror("allocation failure 2 in rgbx8matrix()");
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) resize_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ---------------------------------------------- */
IMAGE_EXPORT(void) resize_bmatrix0(byte **m, long nrow, long ncol)
/* ---------------------------------------------- */
{
  long i;

  for(i=1;i<nrow;i++) m[i]=m[i-1]+ncol;
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) resize_smatrix(short **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) resize_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------ */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ----------------------------------------------- */
IMAGE_EXPORT(void) resize_smatrix0(short **m, long nrow, long ncol)
/* ----------------------------------------------- */
{
  long i;

  for(i=1;i<nrow;i++) m[i]=m[i-1]+ncol;
}
/* ------------------------------------------------- */
IMAGE_EXPORT(void) resize_usmatrix0(ushort **m, long nrow, long ncol)
/* ------------------------------------------------- */
{
  long i;

  for(i=1;i<nrow;i++) m[i]=m[i-1]+ncol;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_smatrix(short **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) shrink_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------ */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_dmatrix(double **m, long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}

/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_imatrix(int **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) resize_imatrix(int **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* --------------------------------------------- */
IMAGE_EXPORT(void) resize_imatrix0(int **m, long nrow, long ncol)
/* --------------------------------------------- */
{
  long i;

  for(i=1;i<nrow;i++) m[i]=m[i-1]+ncol;
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_uimatrix(uint **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) shrink_lmatrix(long **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;
}
/* ------------------------------------------------------------ */
IMAGE_EXPORT(byte**) bmatrix_map(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------ */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte **m;

  /* allocate pointers to rows */
  m=(byte **) malloc((size_t)(nrow*sizeof(byte*)));
  if (!m) nrerror("allocation failure 1 in bmatrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix_map(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  short **m;

  /* allocate pointers to rows */
  m=(short **) malloc((size_t)(nrow*sizeof(short*)));
  if (!m) nrerror("allocation failure 1 in smatrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix_map(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  ushort **m;

  /* allocate pointers to rows */
  m=(ushort **) malloc((size_t)(nrow*sizeof(ushort*)));
  if (!m) nrerror("allocation failure 1 in usmatrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(int16**) i16matrix_map(long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  int16 **m;

  /* allocate pointers to rows */
  m=(int16 **) malloc((size_t)(nrow*sizeof(int16*)));
  if (!m) nrerror("allocation failure 1 in i16matrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix_map(long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  uint16 **m;

  /* allocate pointers to rows */
  m=(uint16 **) malloc((size_t)(nrow*sizeof(uint16*)));
  if (!m) nrerror("allocation failure 1 in ui16matrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------- */
IMAGE_EXPORT(int**) imatrix_map(long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  int **m;

  /* allocate pointers to rows */
  m=(int **) malloc((size_t)(nrow*sizeof(int*)));
  if (!m) nrerror("allocation failure 1 in imatrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------ */
IMAGE_EXPORT(float**) matrix_map(long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------ */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  float **m;

  /* allocate pointers to rows */
  m=(float **) malloc((size_t)(nrow*sizeof(float*)));
  if (!m) nrerror("allocation failure 1 in matrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(double**) dmatrix_map(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  double **m;

  /* allocate pointers to rows */
  m=(double **) malloc((size_t)(nrow*sizeof(double*)));
  if (!m) nrerror("allocation failure 1 in dmatrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix_map(long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  rgb8 **m;

  /* allocate pointers to rows */
  m=(rgb8**) malloc((size_t)(nrow*sizeof(rgb8*)));
  if (!m) nrerror("allocation failure 1 in rgb8matrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(rgbx8**) rgbx8matrix_map(long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------- */
{
  long nrow=nrh-nrl+1,ncol=nch-ncl+1;
  rgbx8 **m;

  /* allocate pointers to rows */
  m=(rgbx8**) malloc((size_t)(nrow*sizeof(rgbx8*)));
  if (!m) nrerror("allocation failure 1 in rgbx8matrix_map()");
  m -= nrl;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte **) bmatrix_map_1D_pitch(byte **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
    
  /* map rows and set pointers to them */
  m[nrl]= (byte*) data_1D;
  #pragma message("  ATTENTION risque d'offset  incorrect")
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix_map_1D_pitch(short **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ----------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (short*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (short*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix_map_1D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* -------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (ushort*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (ushort*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(int16**) i16matrix_map_1D_pitch(int16 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  /* map rows and set pointers to them */
  m[nrl]= (int16*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (int16*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix_map_1D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* --------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  /* map rows and set pointers to them */
  m[nrl]= (uint16*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (uint16*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix_map_1D_pitch(rgb8 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (rgb8*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgb8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgbx8**) rgbx8matrix_map_1D_pitch(rgbx8 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* --------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (rgbx8*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgbx8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) bmatrix_map_pitch_ROI(byte **X, long nrl, long nrh, long ncl, long nch, long pitch, long nrl2, long nrh2, long ncl2, long nch2, long nr0, long nc0)
/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
{
  byte **Y;

  Y = bmatrix_map(nrl2, nrh2, ncl2, nch2);
  bmatrix_map_1D_pitch(Y, nrl2, nrh2, ncl2, nch2, &(X[nr0][nc0]), pitch);
  return Y;
}
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix_map_pitch_ROI(rgb8 **X, long nrl, long nrh, long ncl, long nch, long pitch, long nrl2, long nrh2, long ncl2, long nch2, long nr0, long nc0)
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */
{
  rgb8 **Y;


  Y = rgb8matrix_map(nrl2, nrh2, ncl2, nch2);
  rgb8matrix_map_1D_pitch(Y, nrl2, nrh2, ncl2, nch2, &(X[nr0][nc0]), pitch);

  return Y;
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) bmatrix_remap_1D_pitch(byte **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ---------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (byte*) data_1D;
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(short**) smatrix_remap_1D_pitch(short **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ------------------------------------------------------------------------------------------------------ */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (short*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (short*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix_remap_1D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* --------------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (ushort*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (ushort*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix_remap_1D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ----------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (uint16*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (uint16*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix_remap_1D_pitch(rgb8 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (rgb8*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgb8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ---------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgbx8**) rgbx8matrix_remap_1D_pitch(rgbx8 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch)
/* ---------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (rgbx8*) data_1D;
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgbx8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) bmatrix_map_2D_pitch(byte **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  /* map rows and set pointers to them */
  m[nrl]= (byte*) data_2D[0];
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;


  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix_map_2D_pitch(short **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------- */
/* map an empty matrix of short to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (short*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (short*) p;
  }/**/

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix_map_2D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  /* map rows and set pointers to them */
  m[nrl]= (ushort*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (ushort*) p;
  }/**/

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix_map_2D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (uint16*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (uint16*) p;
  }/**/

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(int16**) i16matrix_map_2D_pitch(int16 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* --------------------------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (int16*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (int16*) p;
  }/**/

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix_map_2D_pitch(rgb8 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;
  
  /* map rows and set pointers to them */
  m[nrl]= (rgb8*) data_2D[0];
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;

  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgb8*) p;
  }/**/

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgbx8**) rgbx8matrix_map_2D_pitch(rgbx8 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* -------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  /* map rows and set pointers to them */
  m[nrl]= (rgbx8*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgbx8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) bmatrix_remap_2D_pitch(byte **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (byte*) data_2D[0];
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix_remap_2D_pitch(short **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* --------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (short*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (short*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix_remap_2D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ----------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (ushort*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (ushort*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* -------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(uint16**) ui16matrix_remap_2D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* -------------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (uint16*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (uint16*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ---------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(rgb8**) rgb8matrix_remap_2D_pitch(rgb8 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ---------------------------------------------------------------------------------------------------------------- */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (rgb8*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgb8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(rgbx8**) rgbx8matrix_remap_2D_pitch(rgbx8 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch)
/* ------------------------------------------------------------------------------------------------------------------ */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte *p;

  m[nrl] += ncl;

  /* map rows and set pointers to them */
  m[nrl]= (rgbx8*) data_2D[0];
  m[nrl] -= ncl;

  //for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1] + pitch;
  p = (byte*) m[nrl];
  for(i=nrl+1;i<=nrh;i++) {
    p += pitch;
    m[i] = (rgbx8*) p;
  }

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_bmatrix_map(byte **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------- */
{
  free((FREE_ARG)(m+nrl));
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_smatrix_map(short **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------- */
{
  free((FREE_ARG)(m+nrl));
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_usmatrix_map(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  free((FREE_ARG)(m+nrl));
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_i16matrix_map(int16 **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  free((FREE_ARG)(m+nrl));
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_ui16matrix_map(uint16 **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------ */
{
  free((FREE_ARG)(m+nrl));
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_rgb8matrix_map(rgb8 **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
{
  free((FREE_ARG)(m+nrl));
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_rgb8map(rgb8 **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------- */
{
  free((FREE_ARG)(m+nrl));
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_rgbx8matrix_map(rgbx8 **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------ */
{
  free((FREE_ARG)(m+nrl));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_rgbx8_map(rgbx8 **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{
  free((FREE_ARG)(m+nrl));
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) bmatrix_map1D(long nrl, long nrh, long ncl, long nch, byte *data_1D, long ys, long xs)
/* --------------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
/* raw-step, colum-step */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte **m;

  /* allocate pointers to rows */
  m=(byte **) malloc((size_t)((nrow+NR_END)*sizeof(byte*)));
  if (!m) nrerror("allocation failure 1 in bmatrix_empty()");
  m += NR_END;
  m -= nrl;

  /* map rows and set pointers to them */
  m[nrl]= data_1D;
  //m[nrl] += NR_END;
#pragma message("  ATTENTION risque d'offset  incorrect")
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ys;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(byte **) bmatrix_map_2D(long nrl, long nrh, long ncl, long nch, void **data_2D)
/* ------------------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  byte **m;

  /* allocate pointers to rows */
  m=(byte **) malloc((size_t)((nrow+NR_END)*sizeof(byte*)));
  if (!m) nrerror("allocation failure 1 in bmatrix_map_2D()");
  m += NR_END;
  m -= nrl;

  /* map rows and set pointers to them */
  m[nrl]=(byte *) data_2D[0];
  //m[nrl] += NR_END;
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(short**) smatrix_map_2D(long nrl, long nrh, long ncl, long nch, void **data_2D)
/* --------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  short **m;

  /* allocate pointers to rows */
  m=(short **) malloc((size_t)((nrow+NR_END)*sizeof(short*)));
  if (!m) nrerror("allocation failure 1 in smatrix_map()");
  m += NR_END;
  m -= nrl;

  /* map rows and set pointers to them */
  m[nrl]=(short *) data_2D[0];
  //m[nrl] += NR_END;
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) usmatrix_map_2D(long nrl, long nrh, long ncl, long nch, void **data_2D)
/* ----------------------------------------------------------------------- */
/* map an empty matrix of byte to 2D area of data matrix with subscript range m[nrl..nrh][ncl..nch] */
{
  long i, nrow=nrh-nrl+1,ncol=nch-ncl+1;
  ushort **m;

  /* allocate pointers to rows */
  m=(ushort **) malloc((size_t)((nrow+NR_END)*sizeof(ushort*)));
  if (!m) nrerror("allocation failure 1 in usmatrix_map()");
  m += NR_END;
  m -= nrl;

  /* map rows and set pointers to them */
  m[nrl]=(ushort *) data_2D[0];
  //m[nrl] += NR_END;
  m[nrl] -= ncl;

  for(i=nrl+1;i<=nrh;i++) m[i]=m[i-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) bmatrix_map_roi00(byte **m,long nrl0, long nrh0, long ncl0, long nch0,
                                long nrl1, long nrh1, long ncl1, long nch1)
/* --------------------------------------------------------------------- */
{
  long i;
  long nrow1=nrh1-nrl1+1,ncol0=nch0-ncl0+1;
  long drow =nrl1-nrl0+1,dcol =ncl1-ncl0+1;

  m[NR_END] += ncl0;
  m[NR_END] += (drow * ncol0 + dcol);

  for(i=1;i<=nrow1; i++) m[i] = m[i-1] + ncol0;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) smatrix_map_roi00(short **m,long nrl0, long nrh0, long ncl0, long nch0,
                                 long nrl1, long nrh1, long ncl1, long nch1)
/* ----------------------------------------------------------------------- */
{
  long i;
  long nrow1=nrh1-nrl1+1,ncol0=nch0-ncl0+1;
  long drow =nrl1-nrl0+1,dcol =ncl1-ncl0+1;

  m[NR_END] += ncl0;
  m[NR_END] += (drow * ncol0 + dcol);

  for(i=1;i<=nrow1; i++) m[i] = m[i-1] + ncol0;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) usmatrix_map_roi00(ushort **m,long nrl0, long nrh0, long ncl0, long nch0,
                                   long nrl1, long nrh1, long ncl1, long nch1)
/* ----------------------------------------------------------------------- */
{
  long i;
  long nrow1=nrh1-nrl1+1,ncol0=nch0-ncl0+1;
  long drow =nrl1-nrl0+1,dcol =ncl1-ncl0+1;

  //m[NR_END] += ncl0;
  //m[NR_END] += (drow * ncol0 + dcol);

  m[0] += ncl0;
  m[0] += (drow * ncol0 + dcol);

  for(i=1;i<=nrow1; i++) m[i] = m[i-1] + ncol0;
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) bmatrix_unmap_roi00(byte **m, long nrl0, long nrh0, long ncl0, long nch0,
                                   long nrl1, long nrh1, long ncl1, long nch1)
/* ------------------------------------------------------------------------ */
{
  long i;
  long nrow1=nrh0-nrl0+1,ncol0=nch0-ncl0+1;
  long drow =nrl1-nrl0+1,dcol =ncl1-ncl0+1;

  m[NR_END] -= (drow * ncol0 + dcol);
  m[NR_END] -= ncl0;

  for(i=nrl0+1;i<=nrh0;i++) m[i] = m[i-1] + ncol0; // original start of line
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) smatrix_unmap_roi00(short **m, long nrl0, long nrh0, long ncl0, long nch0,
                                     long nrl1, long nrh1, long ncl1, long nch1)
/* -------------------------------------------------------------------------- */
{
  long i;
  long nrow1=nrh0-nrl0+1,ncol0=nch0-ncl0+1;
  long drow =nrl1-nrl0+1,dcol =ncl1-ncl0+1;

  m[NR_END] -= (drow * ncol0 + dcol);
  m[NR_END] -= ncl0;

  for(i=nrl0+1;i<=nrh0;i++) m[i] = m[i-1] + ncol0; // original start of line
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) usmatrix_unmap_roi00(ushort **m, long nrl0, long nrh0, long ncl0, long nch0,
                                      long nrl1, long nrh1, long ncl1, long nch1)
/* -------------------------------------------------------------------------- */
{
  long i;
  long nrow1=nrh0-nrl0+1,ncol0=nch0-ncl0+1;
  long drow =nrl1-nrl0+1,dcol =ncl1-ncl0+1;

  //m[NR_END] -= (drow * ncol0 + dcol);
  //m[NR_END] -= ncl0;

  m[0] -= (drow * ncol0 + dcol);
  m[0] -= ncl0;

  for(i=nrl0+1;i<=nrh0;i++) m[i] = m[i-1] + ncol0; // original start of line
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) bmatrix_reverse(byte **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------- */
{
  long i, mrow=(nrl+nrh+1)/2;
  byte *t;

  for(i=nrl; i<mrow; i++) {
    t        = m[i];
    m[i]     = m[nrh-i];
    m[nrh-i] = t;
  }
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) smatrix_reverse(short **m, long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------- */
{
  long i, mrow=(nrl+nrh+1)/2;
  short *t;

  for(i=nrl; i<mrow; i++) {
    t        = m[i];
    m[i]     = m[nrh-i];
    m[nrh-i] = t;
  }
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) usmatrix_reverse(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------- */
{
  long i, mrow=(nrl+nrh+1)/2;
  ushort *t;

  for(i=nrl; i<mrow; i++) {
    t        = m[i];
    m[i]     = m[nrh-i];
    m[nrh-i] = t;
  }
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(float***) f3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
/* ----------------------------------------------------------------------- */
/* allocate a float 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
        long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1,ndep=ndh-ndl+1;
        float ***t;

        /* allocate pointers to pointers to rows */
        t=(float ***) malloc((size_t)((nrow+NR_END)*sizeof(float**)));
        if (!t) nrerror("allocation failure 1 in f3tensor()");
        t += NR_END;
        t -= nrl;

        /* allocate pointers to rows and set pointers to them */
        t[nrl]=(float **) malloc((size_t)((nrow*ncol+NR_END)*sizeof(float*)));
        if (!t[nrl]) nrerror("allocation failure 2 in f3tensor()");
        t[nrl] += NR_END;
        t[nrl] -= ncl;

        /* allocate rows and set pointers to them */
        t[nrl][ncl]=(float *) malloc((size_t)((nrow*ncol*ndep+NR_END)*sizeof(float)));
        if (!t[nrl][ncl]) nrerror("allocation failure 3 in f3tensor()");
        t[nrl][ncl] += NR_END;
        t[nrl][ncl] -= ndl;

        for(j=ncl+1;j<=nch;j++) t[nrl][j]=t[nrl][j-1]+ndep;
        for(i=nrl+1;i<=nrh;i++) {
                t[i]=t[i-1]+ncol;
                t[i][ncl]=t[i-1][ncl]+ncol*ndep;
                for(j=ncl+1;j<=nch;j++) t[i][j]=t[i][j-1]+ndep;
        }

        /* return pointer to array of pointers to rows */
        return t;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(double***) d3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
/* ----------------------------------------------------------------------- */
/* allocate a float 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
        long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1,ndep=ndh-ndl+1;
        double ***t;

        /* allocate pointers to pointers to rows */
        t=(double ***) malloc((size_t)((nrow+NR_END)*sizeof(double**)));
        if (!t) nrerror("allocation failure 1 in d3tensor()");
        t += NR_END;
        t -= nrl;

        /* allocate pointers to rows and set pointers to them */
        t[nrl]=(double **) malloc((size_t)((nrow*ncol+NR_END)*sizeof(double*)));
        if (!t[nrl]) nrerror("allocation failure 2 in d3tensor()");
        t[nrl] += NR_END;
        t[nrl] -= ncl;

        /* allocate rows and set pointers to them */
        t[nrl][ncl]=(double *) malloc((size_t)((nrow*ncol*ndep+NR_END)*sizeof(double)));
        if (!t[nrl][ncl]) nrerror("allocation failure 3 in d3tensor()");
        t[nrl][ncl] += NR_END;
        t[nrl][ncl] -= ndl;

        for(j=ncl+1;j<=nch;j++) t[nrl][j]=t[nrl][j-1]+ndep;
        for(i=nrl+1;i<=nrh;i++) {
                t[i]=t[i-1]+ncol;
                t[i][ncl]=t[i-1][ncl]+ncol*ndep;
                for(j=ncl+1;j<=nch;j++) t[i][j]=t[i][j-1]+ndep;
        }

        /* return pointer to array of pointers to rows */
        return t;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(byte***) b3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
/* ----------------------------------------------------------------------- */
/* allocate a byte 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
        long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1,ndep=ndh-ndl+1;
        byte ***t;

        /* allocate pointers to pointers to rows */
        t=(byte ***) malloc((size_t)((nrow+NR_END)*sizeof(byte**)));
        if (!t) nrerror("allocation failure 1 in b3tensor()");
        t += NR_END;
        t -= nrl;

        /* allocate pointers to rows and set pointers to them */
        t[nrl]=(byte **) malloc((size_t)((nrow*ncol+NR_END)*sizeof(byte*)));
        if (!t[nrl]) nrerror("allocation failure 2 in b3tensor()");
        t[nrl] += NR_END;
        t[nrl] -= ncl;

        /* allocate rows and set pointers to them */
        t[nrl][ncl]=(byte *) malloc((size_t)((nrow*ncol*ndep+NR_END)*sizeof(byte)));
        if (!t[nrl][ncl]) nrerror("allocation failure 3 in b3tensor()");
        t[nrl][ncl] += NR_END;
        t[nrl][ncl] -= ndl;

        for(j=ncl+1;j<=nch;j++) t[nrl][j]=t[nrl][j-1]+ndep;
        for(i=nrl+1;i<=nrh;i++) {
                t[i]=t[i-1]+ncol;
                t[i][ncl]=t[i-1][ncl]+ncol*ndep;
                for(j=ncl+1;j<=nch;j++) t[i][j]=t[i][j-1]+ndep;
        }

        /* return pointer to array of pointers to rows */
        return t;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(short***) s3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
/* ----------------------------------------------------------------------- */
/* allocate a byte 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
        long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1,ndep=ndh-ndl+1;
        short ***t;

        /* allocate pointers to pointers to rows */
        t=(short ***) malloc((size_t)((nrow+NR_END)*sizeof(short**)));
        if (!t) nrerror("allocation failure 1 in b3tensor()");
        t += NR_END;
        t -= nrl;

        /* allocate pointers to rows and set pointers to them */
        t[nrl]=(short **) malloc((size_t)((nrow*ncol+NR_END)*sizeof(short*)));
        if (!t[nrl]) nrerror("allocation failure 2 in s3tensor()");
        t[nrl] += NR_END;
        t[nrl] -= ncl;

        /* allocate rows and set pointers to them */
        t[nrl][ncl]=(short *) malloc((size_t)((nrow*ncol*ndep+NR_END)*sizeof(short)));
        if (!t[nrl][ncl]) nrerror("allocation failure 3 in s3tensor()");
        t[nrl][ncl] += NR_END;
        t[nrl][ncl] -= ndl;

        for(j=ncl+1;j<=nch;j++) t[nrl][j]=t[nrl][j-1]+ndep;
        for(i=nrl+1;i<=nrh;i++) {
                t[i]=t[i-1]+ncol;
                t[i][ncl]=t[i-1][ncl]+ncol*ndep;
                for(j=ncl+1;j<=nch;j++) t[i][j]=t[i][j-1]+ndep;
        }

        /* return pointer to array of pointers to rows */
        return t;
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(ushort***) us3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
/* ----------------------------------------------------------------------- */
/* allocate a byte 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
        long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1,ndep=ndh-ndl+1;
        ushort ***t;

        /* allocate pointers to pointers to rows */
        t=(ushort ***) malloc((size_t)((nrow+NR_END)*sizeof(ushort**)));
        if (!t) nrerror("allocation failure 1 in us3tensor()");
        t += NR_END;
        t -= nrl;

        /* allocate pointers to rows and set pointers to them */
        t[nrl]=(ushort **) malloc((size_t)((nrow*ncol+NR_END)*sizeof(ushort*)));
        if (!t[nrl]) nrerror("allocation failure 2 in us3tensor()");
        t[nrl] += NR_END;
        t[nrl] -= ncl;

        /* allocate rows and set pointers to them */
        t[nrl][ncl]=(ushort *) malloc((size_t)((nrow*ncol*ndep+NR_END)*sizeof(ushort)));
        if (!t[nrl][ncl]) nrerror("allocation failure 3 in s3tensor()");
        t[nrl][ncl] += NR_END;
        t[nrl][ncl] -= ndl;

        for(j=ncl+1;j<=nch;j++) t[nrl][j]=t[nrl][j-1]+ndep;
        for(i=nrl+1;i<=nrh;i++) {
                t[i]=t[i-1]+ncol;
                t[i][ncl]=t[i-1][ncl]+ncol*ndep;
                for(j=ncl+1;j<=nch;j++) t[i][j]=t[i][j-1]+ndep;
        }

        /* return pointer to array of pointers to rows */
        return t;
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(int***) i3tensor(long nrl, long nrh, long ncl, long nch, long ndl, long ndh)
/* --------------------------------------------------------------------- */
/* allocate a byte 3tensor with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
        long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1,ndep=ndh-ndl+1;
        int ***t;

        /* allocate pointers to pointers to rows */
        t=(int ***) malloc((size_t)((nrow+NR_END)*sizeof(int**)));
        if (!t) nrerror("allocation failure 1 in i3tensor()");
        t += NR_END;
        t -= nrl;

        /* allocate pointers to rows and set pointers to them */
        t[nrl]=(int **) malloc((size_t)((nrow*ncol+NR_END)*sizeof(int*)));
        if (!t[nrl]) nrerror("allocation failure 2 in i3tensor()");
        t[nrl] += NR_END;
        t[nrl] -= ncl;

        /* allocate rows and set pointers to them */
        t[nrl][ncl]=(int *) malloc((size_t)((nrow*ncol*ndep+NR_END)*sizeof(int)));
        if (!t[nrl][ncl]) nrerror("allocation failure 3 in i3tensor()");
        t[nrl][ncl] += NR_END;
        t[nrl][ncl] -= ndl;

        for(j=ncl+1;j<=nch;j++) t[nrl][j]=t[nrl][j-1]+ndep;
        for(i=nrl+1;i<=nrh;i++) {
                t[i]=t[i-1]+ncol;
                t[i][ncl]=t[i-1][ncl]+ncol*ndep;
                for(j=ncl+1;j<=nch;j++) t[i][j]=t[i][j-1]+ndep;
        }

        /* return pointer to array of pointers to rows */
        return t;
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(int8***) i8cube(long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------- */
/* allocate a int8 cube with range t[ndl..ndh][nrl..nrh][ncl..nch] */
{
  long i,j,ndep=ndh-ndl+1,nrow=nrh-nrl+1,nrol=nch-ncl+1;
  int8 ***t;

  /* allocate pointers to pointers to rows */
  t=(int8***) malloc((size_t)((ndep+NR_END)*sizeof(int8**)));
  if (!t) nrerror("allocation failure 1 in i8cube()");
  t += NR_END;
  t -= ndl;

  /* allocate pointers to rows anc set pointers to them */
  t[ndl]=(int8**) malloc((size_t)((ndep*nrow+NR_END)*sizeof(int8*)));
  if (!t[ndl]) nrerror("allocation failure 2 in cube()");
  t[ndl] += NR_END;
  t[ndl] -= nrl;

  /* allocate rows anc set pointers to them */
  t[ndl][nrl]=(int8*) malloc((size_t)((ndep*nrow*nrol+NR_END)*sizeof(int8)));
  if (!t[ndl][nrl]) nrerror("allocation failure 3 in i16cube()");
  t[ndl][nrl] += NR_END;
  t[ndl][nrl] -= ncl;

  for(j=nrl+1;j<=nrh;j++) t[ndl][j]=t[ndl][j-1]+nrol;
  for(i=ndl+1;i<=ndh;i++) {
    t[i]=t[i-1]+nrow;
    t[i][nrl]=t[i-1][nrl]+nrow*nrol;
    for(j=nrl+1;j<=nrh;j++) t[i][j]=t[i][j-1]+nrol;
  }
  /* return pointer to array of pointers to rows */
  return t;
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(int16***) i16cube(long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------ */
/* allocate a int16 cube with range t[ndl..ndh][nrl..nrh][ncl..nch] */
{
  long i,j,ndep=ndh-ndl+1,nrow=nrh-nrl+1,nrol=nch-ncl+1;
  int16 ***t;

  /* allocate pointers to pointers to rows */
  t=(int16 ***) malloc((size_t)((ndep+NR_END)*sizeof(int16**)));
  if (!t) nrerror("allocation failure 1 in i16cube()");
  t += NR_END;
  t -= ndl;

  /* allocate pointers to rows anc set pointers to them */
  t[ndl]=(int16 **) malloc((size_t)((ndep*nrow+NR_END)*sizeof(int16*)));
  if (!t[ndl]) nrerror("allocation failure 2 in i16cube()");
  t[ndl] += NR_END;
  t[ndl] -= nrl;

  /* allocate rows anc set pointers to them */
  t[ndl][nrl]=(int16 *) malloc((size_t)((ndep*nrow*nrol+NR_END)*sizeof(int16)));
  if (!t[ndl][nrl]) nrerror("allocation failure 3 in i16cube()");
  t[ndl][nrl] += NR_END;
  t[ndl][nrl] -= ncl;

  for(j=nrl+1;j<=nrh;j++) t[ndl][j]=t[ndl][j-1]+nrol;
  for(i=ndl+1;i<=ndh;i++) {
    t[i]=t[i-1]+nrow;
    t[i][nrl]=t[i-1][nrl]+nrow*nrol;
    for(j=nrl+1;j<=nrh;j++) t[i][j]=t[i][j-1]+nrol;
  }
  /* return pointer to array of pointers to rows */
  return t;
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(uint16***) ui16cube(long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------- */
/* allocate a uint16 cube with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
  long i,j,ndep=ndh-ndl+1,nrow=nrh-nrl+1,nrol=nch-ncl+1;
  uint16 ***t;

  /* allocate pointers to pointers to rows */
  t=(uint16***) malloc((size_t)((ndep+NR_END)*sizeof(uint16**)));
  if (!t) nrerror("allocation failure 1 in ui16cube()");
  t += NR_END;
  t -= ndl;

  /* allocate pointers to rows anc set pointers to them */
  t[ndl]=(uint16**) malloc((size_t)((ndep*nrow+NR_END)*sizeof(uint16*)));
  if (!t[ndl]) nrerror("allocation failure 2 in ui16cube()");
  t[ndl] += NR_END;
  t[ndl] -= nrl;

  /* allocate rows anc set pointers to them */
  t[ndl][nrl]=(uint16*) malloc((size_t)((ndep*nrow*nrol+NR_END)*sizeof(uint16)));
  if (!t[ndl][nrl]) nrerror("allocation failure 3 in ui16cube()");
  t[ndl][nrl] += NR_END;
  t[ndl][nrl] -= ncl;

  for(j=nrl+1;j<=nrh;j++) t[ndl][j]=t[ndl][j-1]+nrol;
  for(i=ndl+1;i<=ndh;i++) {
    t[i]=t[i-1]+nrow;
    t[i][nrl]=t[i-1][nrl]+nrow*nrol;
    for(j=nrl+1;j<=nrh;j++) t[i][j]=t[i][j-1]+nrol;
  }
  /* return pointer to array of pointers to rows */
  return t;
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(int32***) i32cube(long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------ */
/* allocate a int32 cube with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
  long i,j,ndep=ndh-ndl+1,nrow=nrh-nrl+1,nrol=nch-ncl+1;
  int32 ***t;

  /* allocate pointers to pointers to rows */
  t=(int32***) malloc((size_t)((ndep+NR_END)*sizeof(int32**)));
  if (!t) nrerror("allocation failure 1 in i32cube()");
  t += NR_END;
  t -= ndl;

  /* allocate pointers to rows anc set pointers to them */
  t[ndl]=(int32**) malloc((size_t)((ndep*nrow+NR_END)*sizeof(int32*)));
  if (!t[ndl]) nrerror("allocation failure 2 in i32cube()");
  t[ndl] += NR_END;
  t[ndl] -= nrl;

  /* allocate rows anc set pointers to them */
  t[ndl][nrl]=(int32*) malloc((size_t)((ndep*nrow*nrol+NR_END)*sizeof(int32)));
  if (!t[ndl][nrl]) nrerror("allocation failure 3 in i32cube()");
  t[ndl][nrl] += NR_END;
  t[ndl][nrl] -= ncl;

  for(j=nrl+1;j<=nrh;j++) t[ndl][j]=t[ndl][j-1]+nrol;
  for(i=ndl+1;i<=ndh;i++) {
    t[i]=t[i-1]+nrow;
    t[i][nrl]=t[i-1][nrl]+nrow*nrol;
    for(j=nrl+1;j<=nrh;j++) t[i][j]=t[i][j-1]+nrol;
  }
  /* return pointer to array of pointers to rows */
  return t;
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(uint32***) ui32cube(long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------- */
/* allocate a int32 cube with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
  long i,j,ndep=ndh-ndl+1,nrow=nrh-nrl+1,nrol=nch-ncl+1;
  uint32 ***t;

  /* allocate pointers to pointers to rows */
  t=(uint32***) malloc((size_t)((ndep+NR_END)*sizeof(uint32**)));
  if (!t) nrerror("allocation failure 1 in ui32cube()");
  t += NR_END;
  t -= ndl;

  /* allocate pointers to rows anc set pointers to them */
  t[ndl]=(uint32**) malloc((size_t)((ndep*nrow+NR_END)*sizeof(uint32*)));
  if (!t[ndl]) nrerror("allocation failure 2 in ui32cube()");
  t[ndl] += NR_END;
  t[ndl] -= nrl;

  /* allocate rows anc set pointers to them */
  t[ndl][nrl]=(uint32*) malloc((size_t)((ndep*nrow*nrol+NR_END)*sizeof(uint32)));
  if (!t[ndl][nrl]) nrerror("allocation failure 3 in ui32cube()");
  t[ndl][nrl] += NR_END;
  t[ndl][nrl] -= ncl;

  for(j=nrl+1;j<=nrh;j++) t[ndl][j]=t[ndl][j-1]+nrol;
  for(i=ndl+1;i<=ndh;i++) {
    t[i]=t[i-1]+nrow;
    t[i][nrl]=t[i-1][nrl]+nrow*nrol;
    for(j=nrl+1;j<=nrh;j++) t[i][j]=t[i][j-1]+nrol;
  }
  /* return pointer to array of pointers to rows */
  return t;
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(float32***) cube(long ndl, long ndh, long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------------------------- */
/* allocate a float32 cube with range t[nrl..nrh][ncl..nch][ndl..ndh] */
{
  long i,j,ndep=ndh-ndl+1,nrow=nrh-nrl+1,nrol=nch-ncl+1;
  float32 ***t;

  /* allocate pointers to pointers to rows */
  t=(float***) malloc((size_t)((ndep+NR_END)*sizeof(float32**)));
  if (!t) nrerror("allocation failure 1 in f32cube()");
  t += NR_END;
  t -= ndl;

  /* allocate pointers to rows anc set pointers to them */
  t[ndl]=(float32**) malloc((size_t)((ndep*nrow+NR_END)*sizeof(float32*)));
  if (!t[ndl]) nrerror("allocation failure 2 in f32cube()");
  t[ndl] += NR_END;
  t[ndl] -= nrl;

  /* allocate rows anc set pointers to them */
  t[ndl][nrl]=(float32*) malloc((size_t)((ndep*nrow*nrol+NR_END)*sizeof(float32)));
  if (!t[ndl][nrl]) nrerror("allocation failure 3 in f32cube()");
  t[ndl][nrl] += NR_END;
  t[ndl][nrl] -= ncl;

  for(j=nrl+1;j<=nrh;j++) t[ndl][j]=t[ndl][j-1]+nrol;
  for(i=ndl+1;i<=ndh;i++) {
    t[i]=t[i-1]+nrow;
    t[i][nrl]=t[i-1][nrl]+nrow*nrol;
    for(j=nrl+1;j<=nrh;j++) t[i][j]=t[i][j-1]+nrol;
  }
  /* return pointer to array of pointers to rows */
  return t;
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) addrow_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch, long nr)
/* -------------------------------------------------------------------------- */
{
  return NULL;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(short**) addrow_smatrix (short **m, long nrl, long nrh, long ncl, long nch, long nr)
/* ----------------------------------------------------------------------------- */
{
  return NULL;
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) addrow_usmatrix (ushort **m, long nrl, long nrh, long ncl, long nch, long nr)
/* -------------------------------------------------------------------------------- */
{
  return NULL;
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(int**) addrow_imatrix(int **m, long nrl, long nrh, long ncl, long nch, long nr)
/* ------------------------------------------------------------------------ */
/*
 * add nr row at the end of the matrix
 * size [nrl..nrh][ncl..nch] -> [nrl..nrh+nr][ncl..nch]
 */
{
  long i,nrow=nrh-nrl+1, ncol=nch-ncl+1;

  /* reset */
  m += nrl;
  m -= NR_END;

  m=(int **) realloc(m, (size_t)((nrow+nr+NR_END)*sizeof(int*)));
  if(!m) nrerror("allocation failure 1 in realloc imatrix()");
  m += NR_END;
  m -= nrl;

  /* allocate new rows, and set pointers to them */
  m[nrh+1] = (int*) malloc((size_t)((nr*ncol+NR_END)*sizeof(int)));
  if(!m[nrh+1]) nrerror("allocation failure 2 in realloc imatrix()");
  m[nrh+1] += NR_END;
  m[nrh+1] -= ncl;

  for(i=nrh+2;i<=nrh+nr;i++) m[i]=m[i-1]+ncol;

  /* return new pointer to array of pointers to rows */
  return m;
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(byte**) realloc_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch, long nr)
/* --------------------------------------------------------------------------- */
{
  return NULL;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(short**) realloc_smatrix(short **m, long nrl, long nrh, long ncl, long nch, long nr)
/* ----------------------------------------------------------------------------- */
{
  return NULL;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(ushort**) realloc_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch, long nr)
/* ----------------------------------------------------------------------------- */
{
  return NULL;
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(int**) realloc_imatrix(int **m, long nrl, long nrh, long ncl, long nch, long nr)
/* --------------------------------------------------------------------------------------- */
//#pragma message("  ATTENTION --- realloc_imatrix jamais teste ---")
{
  /* ATTENTION a la valeur de nrow */
  long i, nrow=nrh-nrl+1+nr, ncol=nch-ncl+1;
  int **p;

  /* reset pointer to former address of rows */
  p = m;
  p[nrl] += ncl;
  p[nrl] -= NR_END;

  /* allocate rows and set pointers to them */
  p[nrl] = (int*) realloc(p[nrl], (size_t)((nrow*ncol+NR_END)*sizeof(int)));
  if(!p[nrl]) nrerror("allocation failure 1 in realloc_imatrix()");
  p[nrl] -= ncl;
  p[nrl] += NR_END;

  /* reset pointer to former address of pointers */
  p += nrl;
  p -= NR_END;

  /* allocate new rows */
  p = (int**) realloc(p, (size_t)((nrow+NR_END)*sizeof(int*)));
  if(!p) nrerror("allocation failure 2 in realloc_imatrix()");
  p += NR_END;
  p -= nrl;

  /* set pointers to the new rows */
  for(i=nrl+1;i<=nrh+nr;i++) p[i]=p[i-1]+ncol;

  return p;
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(void) free_vector(float *v, long nl, long nh)
/* ---------------------------------------------------- */
/* free a float vector allocated with vector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* ------------------------------------------------------ */
IMAGE_EXPORT(void) free_dvector(double *v, long nl, long nh)
/* ------------------------------------------------------ */
/* free a double vector allocated with dvector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* ----------------------------------------------- */
IMAGE_EXPORT(void) free_cvector(unsigned char *v, long nl, long nh)
/* ----------------------------------------------- */
/* free an unsigned char vector allocated with cvector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* -------------------------------------- */
IMAGE_EXPORT(void) free_bvector(byte *v, long nl, long nh)
/* -------------------------------------- */
/* free a byte vector allocated with bvector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* --------------------------------------- */
IMAGE_EXPORT(void) free_svector(short *v, long nl, long nh)
/* --------------------------------------- */
/* free an unsigned char vector allocated with svector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* ----------------------------------------- */
IMAGE_EXPORT(void) free_usvector(ushort *v, long nl, long nh)
/* ----------------------------------------- */
/* free an unsigned char vector allocated with usvector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(void) free_i16vector(int16 *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(void) free_ui16vector(uint16 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* ------------------------------------------------- */
IMAGE_EXPORT(void) free_ivector(int *v, long nl, long nh)
/* ------------------------------------------------- */
/* free an int vector allocated with ivector() */
{
        free((FREE_ARG) (v+nl-NR_END));
}
/* --------------------------------------------------- */
IMAGE_EXPORT(void) free_i32vector(int *v, long nl, long nh)
/* --------------------------------------------------- */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* ----------------------------------------------------------- */
IMAGE_EXPORT(void) free_lvector(unsigned long *v, long nl, long nh)
/* ----------------------------------------------------------- */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* ----------------------------------------------------- */
IMAGE_EXPORT(void) free_rgb8vector(rgb8 *v, long nl, long nh)
/* ----------------------------------------------------- */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* ------------------------------------------------------- */
IMAGE_EXPORT(void) free_rgb32vector(rgb32 *v, long nl, long nh)
/* ------------------------------------------------------- */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* --------------------------------------- */
IMAGE_EXPORT(void) free_vvector(void **v, long nl, long nh)
/* --------------------------------------- */
/* free a void vector allocated with vvector() */
{
  free((FREE_ARG) (v+nl-NR_END));
}
/* ------------------------------------------------------------- */
IMAGE_EXPORT(void) free_matrix(float **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------- */
/* free a float matrix allocated by matrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* --------------------------------------------------------------- */
IMAGE_EXPORT(void) free_dmatrix(double **m, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------- */
/* free a double matrix allocated by dmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_cmatrix(unsigned char **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------- */
/* free an uchar matrix allocated by cmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------- */
IMAGE_EXPORT(void) free_bmatrix(byte **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------- */
/* free an uchar matrix allocated by bmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) free_smatrix(short **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------- */
/* free a short matrix allocated by cmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) free_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------- */
/* free a short matrix allocated by cmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------ */
IMAGE_EXPORT(void) free_imatrix(int **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------ */
/* free an int matrix allocated by imatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) free_uimatrix(uint **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------- */
/* free an uint matrix allocated by imatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_i16matrix(int16 **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------ */
{  
  free((FREE_ARG) (m[nrl]+ncl-NR_END));
  free((FREE_ARG) (m+nrl-NR_END));
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_ui16matrix(uint16 **m, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------- */
{  
  free((FREE_ARG) (m[nrl]+ncl-NR_END));
  free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------- */
IMAGE_EXPORT(void) free_lmatrix(long **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------- */
/* free a long matrix allocated by lmatrix() */
{
        free((FREE_ARG) (m[nrl]+ncl-NR_END));
        free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_rgb8matrix(rgb8 **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  free((FREE_ARG) (m[nrl]+ncl-NR_END));
  free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_rgbx8matrix(rgbx8 **m, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------ */
{
  free((FREE_ARG) (m[nrl]+ncl-NR_END));
  free((FREE_ARG) (m+nrl-NR_END));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_f3tensor(float ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------ */

/* free a float f3tensor allocated by f3tensor() */
{
        free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
        free((FREE_ARG) (t[nrl]+ncl-NR_END));
        free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_d3tensor(double ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------ */

/* free a float f3tensor allocated by d3tensor() */
{
        free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
        free((FREE_ARG) (t[nrl]+ncl-NR_END));
        free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_b3tensor(byte ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------ */

/* free a byte f3tensor allocated by b3tensor() */
{
        free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
        free((FREE_ARG) (t[nrl]+ncl-NR_END));
        free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_s3tensor(short ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------ */

/* free a short f3tensor allocated by s3tensor() */
{
        free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
        free((FREE_ARG) (t[nrl]+ncl-NR_END));
        free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_us3tensor(ushort ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------ */
/* free a short f3tensor allocated by s3tensor() */
{
        free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
        free((FREE_ARG) (t[nrl]+ncl-NR_END));
        free((FREE_ARG) (t+nrl-NR_END));
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_i3tensor(int ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ---------------------------------------------------------------------------- */

/* free a int i3tensor allocated by i3tensor() */
{
        free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
        free((FREE_ARG) (t[nrl]+ncl-NR_END));
        free((FREE_ARG) (t+nrl-NR_END));
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_i8cube(int8 ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ----------------------------------------------------------------------------------------- */
/* free a int8 cube allocated by i8cube() */
{
  free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
  free((FREE_ARG) (t[nrl]+ncl-NR_END));
  free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_i16cube(int16 ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------------------- */
/* free a int16 cube allocated by i16cube() */
{
  free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
  free((FREE_ARG) (t[nrl]+ncl-NR_END));
  free((FREE_ARG) (t+nrl-NR_END));
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_ui16cube(uint16 ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* --------------------------------------------------------------------------------------------- */
/* free a uint16 cube allocated by ui16cube() */
{
  free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
  free((FREE_ARG) (t[nrl]+ncl-NR_END));
  free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_i32cube(int32 ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------------------- */
/* free a int32 cube allocated by i32cube() */
{
  free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
  free((FREE_ARG) (t[nrl]+ncl-NR_END));
  free((FREE_ARG) (t+nrl-NR_END));
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) free_ui32cube(uint32 ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* --------------------------------------------------------------------------------------------- */
/* free a uint32 cube allocated by ui32cube() */
{
  free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
  free((FREE_ARG) (t[nrl]+ncl-NR_END));
  free((FREE_ARG) (t+nrl-NR_END));
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) free_cube(float32 ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh)
/* ------------------------------------------------------------------------------------------ */
/* free a float32 cube allocated by f32cube() */
{
  free((FREE_ARG) (t[nrl][ncl]+ndl-NR_END));
  free((FREE_ARG) (t[nrl]+ncl-NR_END));
  free((FREE_ARG) (t+nrl-NR_END));
}

/* ---------------- */
/* -- Convertion -- */
/* ---------------- */
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_svector_vector(short *X, long nl, long nh, float *Y)
/* ------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (float) X[i];
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_svector_dvector(short *X, long nl, long nh, double *Y)
/* --------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (double) X[i];
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_usvector_vector(ushort *X, long nl, long nh, float *Y)
/* --------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (float) X[i];
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_usvector_dvector(ushort *X, long nl, long nh, double *Y)
/* ----------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (double) X[i];
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_ivector_vector(int *X, long nl, long nh, float *Y)
/* ----------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (float) X[i];
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_ivector_dvector(int *X, long nl, long nh, double *Y)
/* ------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (double) X[i];
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_uivector_vector(uint *X, long nl, long nh, float *Y)
/* ------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (float) X[i];
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_uivector_dvector(uint *X, long nl, long nh, double *Y)
/* --------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (double) X[i];
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_vector_ivector(float *X, long nl, long nh, int *Y)
/* ----------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (int) X[i];
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_dvector_ivector(double *X, long nl, long nh, int *Y)
/* ------------------------------------------------------------------------- */
{
  long i;
  for(i=nl; i<=nh; i++)
    Y[i] = (int) X[i];
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_smatrix_matrix (short **X, long nrl,long nrh,long ncl,long nch, float  **Y)
/* ------------------------------------------------------------------------------------------------ */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_svector_vector(X[i], ncl, nch, Y[i]);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_smatrix_dmatrix(short **X, long nrl,long nrh,long ncl,long nch, double **Y)
/* ------------------------------------------------------------------------------------------------ */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_svector_dvector(X[i], ncl, nch, Y[i]);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_usmatrix_matrix (ushort **X, long nrl,long nrh,long ncl,long nch, float  **Y)
/* -------------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_usvector_vector(X[i], ncl, nch, Y[i]);
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_usmatrix_dmatrix(ushort **X, long nrl,long nrh,long ncl,long nch, double **Y)
/* -------------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_usvector_dvector(X[i], ncl, nch, Y[i]);
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_imatrix_matrix(int **X, long nrl,long nrh,long ncl,long nch, float  **Y)
/* --------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_ivector_vector(X[i], ncl, nch, Y[i]);
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_imatrix_dmatrix(int **X, long nrl,long nrh,long ncl,long nch, double **Y)
/* ---------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_ivector_dvector(X[i], ncl, nch, Y[i]);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_uimatrix_matrix (uint **X, long nrl,long nrh,long ncl,long nch, float  **Y)
/* ------------------------------------------------------------------------------------------------ */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_uivector_vector(X[i], ncl, nch, Y[i]);
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) convert_uimatrix_dmatrix(uint **X, long nrl,long nrh,long ncl,long nch, double **Y)
/* ------------------------------------------------------------------------------------------------ */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_uivector_dvector(X[i], ncl, nch, Y[i]);
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_matrix_imatrix(float **X, long nrl,long nrh,long ncl,long nch, int **Y)
/* -------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_vector_ivector(X[i], ncl, nch, Y[i]);
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) convert_dmatrix_imatrix(double **X, long nrl,long nrh,long ncl,long nch, int **Y)
/* ---------------------------------------------------------------------------------------------- */
{
  long i;
  for(i=nrl; i<=nrh; i++)
    convert_dvector_ivector(X[i], ncl, nch, Y[i]);
}

/* ------------ */
/* --- Move --- */
/* ------------ */

/* -------------------------------------------------- */
IMAGE_EXPORT(void) move_bvector_1left_block(byte *v, long nl, long nh)
/* -------------------------------------------------- */
{
  memmove(v+nl-1, v+nl, nh-nl+1);
}
/* --------------------------------------------------- */
IMAGE_EXPORT(void) move_svector_1left_block(short *v, long nl, long nh)
/* --------------------------------------------------- */
{
  memmove(v+nl-1, v+nl, 2*(nh-nl+1));
}
/* ------------------------------------------------- */
IMAGE_EXPORT(void) move_ivector_1left_block(int *v, long nl, long nh)
/* ------------------------------------------------- */
{
  memmove(v+nl-1, v+nl, 4*(nh-nl+1));
}
/* --------------------------------------------------- */
IMAGE_EXPORT(void) move_bvector_1right_block(byte *v, long nl, long nh)
/* --------------------------------------------------- */
{
  memmove(v+nl+1, v+nl, nh-nl+1);
}
/* ---------------------------------------------------- */
IMAGE_EXPORT(void) move_svector_1right_block(short *v, long nl, long nh)
/* ---------------------------------------------------- */
{
  memmove(v+nl+1, v+nl, 2*(nh-nl+1));
}
/* -------------------------------------------------- */
IMAGE_EXPORT(void) move_ivector_1right_block(int *v, long nl, long nh)
/* -------------------------------------------------- */
{
  memmove(v+nl+1, v+nl, 4*(nh-nl+1));
}

/* ------------ */
/* --- COPY --- */
/* ------------ */
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_bvector(byte *src, long nl1, long nh1, byte *dst, long nl2, long nh2)
/* --------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  memcpy(dst + nl2, src + nl1, len);
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_svector(short *src, long nl1, long nh1, short *dst, long nl2, long nh2)
/* ----------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(short);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* -------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_usvector(ushort *src, long nl1, long nh1, ushort *dst, long nl2, long nh2)
/* -------------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(ushort);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_i16vector(int16 *src, long nl1, long nh1, int16 *dst, long nl2, long nh2)
/* ------------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  memcpy(dst + nl2, src + nl1, 2*len);
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_ui16vector(uint16 *src, long nl1, long nh1, uint16 *dst, long nl2, long nh2)
/* ---------------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  memcpy(dst + nl2, src + nl1, 2*len);
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_ivector(int *src, long nl1, long nh1, int *dst, long nl2, long nh2)
/* ------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(int);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_uivector(uint *src, long nl1, long nh1, uint *dst, long nl2, long nh2)
/* ---------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(uint);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_vector(float *src, long nl1, long nh1, float *dst, long nl2, long nh2)
/* ---------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(float);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* ------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_dvector(double *src, long nl1, long nh1, double *dst, long nl2, long nh2)
/* ------------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(double);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* ------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy_rgb8vector(rgb8 *src, long nl1, long nh1, rgb8 *dst, long nl2, long nh2)
/* ------------------------------------------------------------------------------------------ */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(rgb8);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_rgbx8vector(rgbx8 *src, long nl1, long nh1, rgbx8 *dst, long nl2, long nh2)
/* --------------------------------------------------------------------------------------------- */
{
  long len = nh1 - nl1 + 1;
  static long size = sizeof(rgbx8);
  memcpy(dst + nl2, src + nl1, len*size);
}
/* ---------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_bvector(byte *src, long nl, long nh, byte *dst)
/* ---------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(byte);
  /*int i;
  for(i=nl; i<=nh; i++) {
    dst[i] = src[i];
  }/**/
  memcpy(dst + nl, src + nl, len*size);
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(void) dup_svector(short *src, long nl, long nh, short *dst)
/* ------------------------------------------------------------------ */
{
  long len = nh - nl + 1;
  static long size = sizeof(short);
  memcpy(dst + nl, src + nl, len*size);
}
/* --------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_usvector(ushort *src, long nl, long nh, ushort *dst)
/* --------------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(ushort);
  memcpy(dst + nl, src + nl, len*size);
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_i16vector(int16 *src, long nl, long nh, int16 *dst)
/* -------------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  memcpy(dst + nl, src + nl, 2*len);
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_ui16vector(uint16 *src, long nl, long nh, uint16 *dst)
/* ----------------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  memcpy(dst + nl, src + nl, 2*len);
}
/* -------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_ivector(int *src, long nl, long nh, int *dst)
/* -------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(int);
  memcpy(dst + nl, src + nl, len*size);
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_i32vector(int32 *src, long nl, long nh, int32 *dst)
/* -------------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(int32);
  memcpy(dst + nl, src + nl, len*size);
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_uivector(uint *src, long nl, long nh, uint *dst)
/* ----------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(uint);
  memcpy(dst + nl, src + nl, len*size);
}
/* ----------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_vector(float *src, long nl, long nh, float *dst)
/* ----------------------------------------------------------------- */
{
  int i;
  /* Must be replaced by memcopy */
  for(i=nl; i<=nh; i++) {
    dst[i] = src[i];
  }
}
/* -------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_dvector(double *src, long nl, long nh, double *dst)
/* -------------------------------------------------------------------- */
{
  int i;
  /* Must be replaced by memcopy */
  for(i=nl; i<=nh; i++) {
    dst[i] = src[i];
  }
}
/* ------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_rgb8vector(rgb8 *src, long nl, long nh, rgb8 *dst)
/* ------------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(rgb8);
  memcpy(dst + nl, src + nl, len*size);
}
/* ---------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_rgbx8vector(rgbx8 *src, long nl, long nh, rgbx8 *dst)
/* ---------------------------------------------------------------------- */
{
  long len = nh - nl + 1;
  static long size = sizeof(rgbx8);
  memcpy(dst + nl, src + nl, len*size);
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_bvector(byte *src, long nc, byte *dst, long nl, long nh)
/* ---------------------------------------------------------------------------- */
{
  int j;
  byte c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy1c_svector(short *src, long nc, short *dst, long nl, long nh)
/* ------------------------------------------------------------------------------ */
{
  int j;
  short c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_usvector(ushort *src, long nc, ushort *dst, long nl, long nh)
/* --------------------------------------------------------------------------------- */
{
  int j;
  ushort c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_i16vector(int16 *src, long nc, int16 *dst, long nl, long nh)
/* -------------------------------------------------------------------------------- */
{
  int j;
  int16 c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ----------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_ui16vector(uint16 *src, long nc, uint16 *dst, long nl, long nh)
/* ----------------------------------------------------------------------------------- */
{
  int j;
  uint16 c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_ivector(int *src, long nc, int *dst, long nl, long nh)
/* -------------------------------------------------------------------------- */
{
  int j;
  int c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_uivector(uint *src, long nc, uint *dst, long nl, long nh)
/* ----------------------------------------------------------------------------- */
{
  int j;
  int c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_vector(float *src, long nc, float *dst, long nl, long nh)
/* ----------------------------------------------------------------------------- */
{
  int j;
  float c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_dvector(double *src, long nc, double *dst, long nl, long nh)
/* -------------------------------------------------------------------------------- */
{
  int j;
  double c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_rgb8vector(rgb8 *src, long nc, rgb8 *dst, long nl, long nh)
/* ------------------------------------------------------------------------------- */
{
  int j;
  rgb8 c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_rgbx8vector(rgbx8 *src, long nc, rgbx8 *dst, long nl, long nh)
/* ---------------------------------------------------------------------------------- */
{
  int j;
  rgbx8 c = src[nc];
  for(j=nl; j<=nh; j++) dst[j] = c;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_bvector_mod(byte *src, long nl, long nh, long m, byte *dst)
/* ----------------------------------------------------------------------------- */
{
  long len;
  long len1, len2;

  if(nh>nl) {
    len = nh - nl + 1; memcpy(dst, src + nl, len);
  } else {
    len1 = m - nl; memcpy(dst,      src + nl, len1);
    len2 = nh + 1; memcpy(dst+len1, src + nh, len2);
  }
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_svector_mod(short *src, long nl, long nh, long m, short *dst)
/* ------------------------------------------------------------------------------- */
{
  long len;
  long len1, len2;

  if(nh>nl) {
    len = nh - nl + 1; memcpy(dst, src + nl, len*2);
  } else {
    len1 = m - nl; memcpy(dst,      src + nl, 2*len1);
    len2 = nh + 1; memcpy(dst+len1, src + nh, 2*len2);
  }
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_usvector_mod(short *src, long nl, long nh, long m, ushort *dst)
/* --------------------------------------------------------------------------------- */
{
  long len;
  long len1, len2;

  if(nh>nl) {
    len = nh - nl + 1; memcpy(dst, src + nl, len*2);
  } else {
    len1 = m - nl; memcpy(dst,      src + nl, 2*len1);
    len2 = nh + 1; memcpy(dst+len1, src + nh, 2*len2);
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_ivector_mod(int *src, long nl, long nh, long m, int *dst)
/* --------------------------------------------------------------------------- */
{
  long len;
  long len1, len2;

  if(nh>nl) {
    len = nh - nl + 1; memcpy(dst, src + nl, 4*len);
  } else {
    len1 = m - nl; memcpy(dst,      src + nl, 4*len1);
    len2 = nh + 1; memcpy(dst+len1, src + nh, 4*len2);
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy_vector_mod(float *src, long nl, long nh, long m, float *dst)
/* ------------------------------------------------------------------------------ */
{
  long len;
  long len1, len2;

  if(nh>nl) {
    len = nh - nl + 1; memcpy(dst, src + nl, 4*len);
  } else {
    len1 = m - nl; memcpy(dst,      src + nl, 4*len1);
    len2 = nh + 1; memcpy(dst+len1, src + nh, 4*len2);
  }
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_dvector_mod(double *src, long nl, long nh, long m, double *dst)
/* --------------------------------------------------------------------------------- */
{
  long len;
  long len1, len2;

  if(nh>nl) {
    len = nh - nl + 1; memcpy(dst, src + nl, 4*len);
  } else {
    len1 = m - nl; memcpy(dst,      src + nl, 4*len1);
    len2 = nh + 1; memcpy(dst+len1, src + nh, 4*len2);
  }
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copyc_bmatrix(byte **src,long nrl,long nrh,long ncl, long nch, byte **cond, byte c, byte **dst)
/* ---------------------------------------------------------------------------------------------- */
{
  long i, j;
  byte *Xi, *Yi, *Ci;

  for(i=nrl; i<=nrh; i++) {
    Xi = src [i];
    Yi = dst [i];
    Ci = cond[i];
    for(j=ncl; j<=nch; j++) {
      if(Ci[j] == c) Yi[j] = Xi[j]; else Yi[j] = 0;
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) complete_border_bmatrix(byte **m, long nrl,long nrh,long ncl, long nch, long n)
/* ------------------------------------------------------------------------------ */
{
  long i, j;

  byte *Xi;

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    for(j=1; j<=n; j++) {
      Xi[ncl-j] = Xi[ncl];
      Xi[nch+j] = Xi[nch];
    }
  }
  for(i=1; i<=n; i++)
    dup_bvector(m[nrl], ncl-n, nch+n, m[nrl-i]);
  for(i=1; i<=n; i++)
    dup_bvector(m[nrh], ncl-n, nch+n, m[nrh+i]);
}
/* ----------------------------------------------------------------------- */
IMAGE_EXPORT(void) complete_border1_bmatrix(byte **m, long nrl,long nrh,long ncl, long nch)
/* ----------------------------------------------------------------------- */
{
  long i;
  byte *Xi;

  dup_bvector(m[nrl+1], ncl, nch, m[nrl]);
  dup_bvector(m[nrh-1], ncl, nch, m[nrh]);

  for(i=nrl; i<=nrh; i++) {
    Xi = m[i];
    Xi[nrl] = Xi[nrl+1];
    Xi[nrh] = Xi[nrh-1];
  }
}
/* ---------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_bmatrix(byte **X, long nrl,long nrh,long ncl, long nch, byte **Y)
/* ---------------------------------------------------------------------------------- */
{
  int i, j;
  byte *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) dup_smatrix(short **X, long nrl,long nrh,long ncl, long nch, short **Y)
/* ------------------------------------------------------------------------------------ */
{
  int i, j;
  short *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* --------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_usmatrix(ushort **X, long nrl,long nrh,long ncl, long nch, ushort **Y)
/* --------------------------------------------------------------------------------------- */
{
  int i, j;
  ushort *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* ----------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_ui16matrix(uint16 **X, long nrl,long nrh,long ncl, long nch, uint16 **Y)
/* ----------------------------------------------------------------------------------------- */
{
  int i, j;
  uint16 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_imatrix(int **X, long nrl,long nrh,long ncl, long nch, int **Y)
/* -------------------------------------------------------------------------------- */
{
  int i, j;
  int *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* ------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) dup_matrix(float **X, long nrl,long nrh,long ncl, long nch, float **Y)
/* ----------------------------------------------------------------------------------- */
{
  int i, j;
  float *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* -------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_dmatrix(double **X, long nrl,long nrh,long ncl, long nch, double **Y)
/* -------------------------------------------------------------------------------------- */
{
  int i, j;
  double *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* ------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_rgb8matrix(rgb8 **X, long nrl,long nrh,long ncl, long nch, rgb8 **Y)
/* ------------------------------------------------------------------------------------- */
{
  int i, j;
  rgb8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* ---------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) dup_rgbx8matrix(rgbx8 **X, long nrl,long nrh,long ncl, long nch, rgbx8 **Y)
/* ---------------------------------------------------------------------------------------- */
{
  int i, j;
  rgbx8 *Xi, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i]; Yi = Y[i];
    for(j=ncl; j<=nch; j++) {
      Yi[j] = Xi[j];
    }
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy1c_bmatrix(byte **X, long nc, byte **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------ */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    copy1c_bvector(X[i], nc, Y[i], ncl, nch);
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_smatrix(short **X, long nc, short **Y, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_svector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_usmatrix(ushort **X, long nc, ushort **Y, long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_usvector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_imatrix(int **X, long nc, int **Y, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_ivector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_uimatrix(uint **X, long nc, uint **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_uivector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_matrix(float **X, long nc, float **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_vector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_dmatrix(double **X, long nc, double **Y, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_dvector(X[i], nc, Y[i], ncl, nch);
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1c_rgb8matrix(rgb8 **X, long nc, rgb8 **Y, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------------------------------- */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_rgb8vector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy1c_rgbx8matrix(rgbx8 **X, long nc, rgbx8 **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------------ */
{
  int i;

  for(i=nrl; i<=nrh; i++) {
    copy1c_rgbx8vector(X[i], nc, Y[i], ncl, nch);
  }
}
/* ------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy1r_bmatrix(byte **X, long nr, byte **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------ */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_bvector(X[nr], ncl, nch, Y[i]);
  }
}
/* -------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_smatrix(short **X, long nr, short **Y, long nrl, long nrh, long ncl, long nch)
/* -------------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_svector(X[nr], ncl, nch, Y[i]);
  }
}
/* ----------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_usmatrix(ushort **X, long nr, ushort **Y, long nrl, long nrh, long ncl, long nch)
/* ----------------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_usvector(X[nr], ncl, nch, Y[i]);
  }}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_imatrix(int **X, long nr, int **Y, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_ivector(X[nr], ncl, nch, Y[i]);
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_uimatrix(uint **X, long nr, uint **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_uivector(X[nr], ncl, nch, Y[i]);
  }
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_matrix(float **X, long nr, float **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_vector(X[nr], ncl, nch, Y[i]);
  }
}
/* ---------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_dmatrix(double **X, long nr, double **Y, long nrl, long nrh, long ncl, long nch)
/* ---------------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_dvector(X[nr], ncl, nch, Y[i]);
  }
}
/* --------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy1r_rgb8matrix(rgb8 **X, long nr, rgb8 **Y, long nrl, long nrh, long ncl, long nch)
/* --------------------------------------------------------------------------------------------------- */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_rgb8vector(X[nr], ncl, nch, Y[i]);
  }
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy1r_rgbx8matrix(rgbx8 **X, long nr, rgbx8 **Y, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------------------------------------------ */
{
  int i;
  
  for(i=nrl; i<=nrh; i++) {
    dup_rgbx8vector(X[nr], ncl, nch, Y[i]);
  }
}
/* ------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_bmatrix(byte **m1, long nrl1,long nrh1,long ncl1, long nch1, byte **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* ------------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_smatrix(short **m1, long nrl1,long nrh1,long ncl1, long nch1, short **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* --------------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy_usmatrix(ushort **m1, long nrl1,long nrh1,long ncl1, long nch1, ushort **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* ------------------------------------------------------------------------------------------------------------------------------------------ */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_imatrix(int **m1, long nrl1,long nrh1,long ncl1, long nch1, int **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* --------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy_uimatrix(uint **m1, long nrl1,long nrh1,long ncl1, long nch1, uint **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* ------------------------------------------------------------------------------------------------------------------------ */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy_matrix(float **m1, long nrl1,long nrh1,long ncl1, long nch1, float **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* ------------------------------------------------------------------------------------------------------------------------ */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_dmatrix(double **m1, long nrl1,long nrh1,long ncl1, long nch1, double **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* --------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* ---------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_rgb8matrix(rgb8 **m1, long nrl1,long nrh1,long ncl1, long nch1, rgb8 **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* ---------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_rgbx8matrix(rgbx8 **m1, long nrl1,long nrh1,long ncl1, long nch1, rgbx8 **m2, long nrl2, long nrh2, long ncl2, long nch2)
/* ------------------------------------------------------------------------------------------------------------------------------------- */
{
  int i, j, ro, co; /*row offset, collum offset */

  ro = nrl2 - nrl1;
  co = ncl2 - ncl1;

  for(i=nrl1; i<=nrh1; i++) {
    for(j=ncl1; j<=nch1; j++) {
      m2[i+ro][j+co] = m1[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_sub_bmatrix(byte **src, long nrl,long nrh,long ncl, long nch, byte **dst)
/* ----------------------------------------------------------------------------- */
{
  int i, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    memcpy(dst[i]+nrl, src[i]+nrl, ncol);
  }
}

/* ------------------- */
/* --- # extract # --- */
/* ------------------- */

/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extract_bmatrix(byte **src, long nrl,long nrh,long ncl, long nch, byte **dst)
/* ---------------------------------------------------------------------------- */
{
  int i,j, ncol = nch - ncl + 1;

  /*for(i=nrl; i<=nrh; i++) {
    copy_bvector(src[i]+nrl, ncl, nch, dst[i]);
    // memcpy(dst[i], src[i]+nrl, ncol);
  }/**/
  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) extract_smatrix(short **src, long nrl,long nrh,long ncl, long nch, short **dst)
/* ------------------------------------------------------------------------------ */
{
  int i,j, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extract_usmatrix(ushort **src, long nrl,long nrh,long ncl, long nch, ushort **dst)
/* --------------------------------------------------------------------------------- */
{
  int i,j, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* -------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extract_imatrix(int **src, long nrl,long nrh,long ncl, long nch, int **dst)
/* -------------------------------------------------------------------------- */
{
  int i,j, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extract_uimatrix(uint **src, long nrl,long nrh,long ncl, long nch, uint **dst)
/* ----------------------------------------------------------------------------- */
{
  int i,j, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extract_matrix(float **src, long nrl,long nrh,long ncl, long nch, float **dst)
/* ----------------------------------------------------------------------------- */
{
  int i,j, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* -------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extract_dmatrix(double **src, long nrl,long nrh,long ncl, long nch, double **dst)
/* -------------------------------------------------------------------------------- */
{
  int i,j, ncol = nch - ncl + 1;

  for(i=nrl; i<=nrh; i++) {
    for(j=ncl; j<=nch; j++) {
      dst[i-nrl][j-ncl] = src[i][j];
    }
  }
}
/* ------------------------------------------------------------------------ */
IMAGE_EXPORT(void) copy_center_bmatrix(byte **src, long nrl0,long nrh0,long ncl0, long nch0,
                         byte **dst, long nrl1,long nrh1,long ncl1, long nch1)
/* ------------------------------------------------------------------------ */
{
  int i, j;
  long nrow0 = nrh0 - nrl0 + 1, ncol0 = nch0 - ncl0 + 1;
  long nrow1 = nrh1 - nrl1 + 1, ncol1 = nch1 - ncl1 + 1;
  long roffset = (nrow0 - nrow1) / 2;
  long coffset = (ncol0 - ncol1) / 2;

  for(i=nrl1; i<=nrh1; i++) {
    /*memcpy(dst[i]+nrl1, src[i+roffset]+nrl0+coffset, ncol1);/**/
    /*memcpy(dst[i], src[i+roffset]+coffset, ncol1);/**/
    for(j=ncl1; j<=nch1; j++) {
      dst[i][j] = src[i+roffset][j+coffset];
    }
  }
}
/* ---------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_sub_imatrix(int  **src, long nrl,long nrh,long ncl, long nch, int **dst)
/* ---------------------------------------------------------------------------- */
{
  int i, ncol = nch - ncl + 1;

  ncol = 4 * ncol; // ben oui

  for(i=nrl; i<=nrh; i++) {
    memcpy(dst[i]+nrl, src[i]+nrl, ncol);
  }
}
/* --------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) copy_sub_imatrix_index(int **src, long nrl,long nrh, long ncl, long nch, int **dst,int *index)
/* --------------------------------------------------------------------------------------------- */
{
  int i, j;
  int line;

  for(i=nrl; i<=nrh; i++) {
    line = index[i];
    for(j=ncl; j<=nch; j++) {
      dst[i][j] = src[line][j];
    }
  }
}

/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) extractnz_boundaries_bvector(byte *v, long nl, long nh, long *nlnz, long *nhnz)
/* ------------------------------------------------------------------------------ */
{
  long left = nl, right = nh;;

  while(!v[left ] && left  <= nh) left++;
  while(!v[right] && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* ------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) extractnz_boundaries_svector(short *v, long nl, long nh, long *nlnz, long *nhnz)
/* ------------------------------------------------------------------------------ */
{
  long left = nl, right = nh;;

  while(!v[left ] && left  <= nh) left++;
  while(!v[right] && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* --------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_usvector(ushort *v, long nl, long nh, long *nlnz, long *nhnz)
/* --------------------------------------------------------------------------------- */
{
  long left = nl, right = nh;;

  while(!v[left ] && left  <= nh) left++;
  while(!v[right] && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* ----------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_ivector(int *v, long nl, long nh, long *nlnz, long *nhnz)
/* ----------------------------------------------------------------------------- */
{
  long left = nl, right = nh;;

  while(!v[left ] && left  <= nh) left++;
  while(!v[right] && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* ------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_uivector(uint *v, long nl, long nh, long *nlnz, long *nhnz)
/* ------------------------------------------------------------------------------- */
{
  long left = nl, right = nh;;

  while(!v[left ] && left  <= nh) left++;
  while(!v[right] && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_vector(float *v, long nl, long nh, long *nlnz, long *nhnz, float epsillon)
/* ---------------------------------------------------------------------------------------------- */
{
  long left = nl, right = nh;;

  while(fabs(v[left ])<epsillon && left  <= nh) left++;
  while(fabs(v[right])<epsillon && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* ------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_dvector(double *v, long nl, long nh, long *nlnz, long *nhnz, double epsillon)
/* ------------------------------------------------------------------------------------------------- */
{
  long left = nl, right = nh;;

  while(fabs(v[left ])<epsillon && left  <= nh) left++;
  while(fabs(v[right])<epsillon && right >= nl) right--;

  *nlnz = left; *nhnz = right;
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) extractnz_boundaries_bmatrix(byte **m, long nrl,long nrh, long ncl, long nch, long *nclnz, long *nchnz)
/* ------------------------------------------------------------------------------------------------------ */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_bvector(m[nrl], ncl, nch, &left, &right); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_bvector(m[i], ncl, nch, &a, &b);
    if(a < left) left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right) right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_smatrix(short **m, long nrl,long nrh, long ncl, long nch, long *nclnz, long *nchnz)
/* ------------------------------------------------------------------------------------------------------- */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_svector(m[nrl], ncl, nch, &left, &right); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_svector(m[i], ncl, nch, &a, &b);
    if(a < left)
      left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right)
      right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* --------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_usmatrix(ushort **m, long nrl,long nrh, long ncl, long nch, long *nclnz, long *nchnz)
/* --------------------------------------------------------------------------------------------------------- */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_usvector(m[nrl], ncl, nch, &left, &right); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_usvector(m[i], ncl, nch, &a, &b);
    if(a < left) left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right) right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* ------------------------------------------------------------------------------------------------------ */
IMAGE_EXPORT(void) extractnz_boundaries_imatrix (int **m, long nrl,long nrh, long ncl, long nch, long *nclnz, long *nchnz)
/* ------------------------------------------------------------------------------------------------------ */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_ivector(m[nrl], ncl, nch, &left, &right); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_ivector(m[i], ncl, nch, &a, &b);
    if(a < left) left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right) right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* ------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_uimatrix(uint **m, long nrl,long nrh, long ncl, long nch, long *nclnz, long *nchnz)
/* ------------------------------------------------------------------------------------------------------- */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_uivector(m[nrl], ncl, nch, &left, &right); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_uivector(m[i], ncl, nch, &a, &b);
    if(a < left) left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right) right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* ----------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_matrix(float **m, long nrl,long nrh, long ncl, long nch, long *nclnz, long *nchnz, float  epsillon)
/* ----------------------------------------------------------------------------------------------------------------------- */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_vector(m[nrl], ncl, nch, &left, &right, epsillon); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_vector(m[i], ncl, nch, &a, &b, epsillon);
    if(a < left) left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right) right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* ------------------------------------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(void) extractnz_boundaries_dmatrix(double **m, long nrl,long nrh,long ncl, long nch, long *nclnz, long *nchnz, double epsillon)
/* ------------------------------------------------------------------------------------------------------------------------- */
{
  int i;
  long a, b;
  long left, right;

  extractnz_boundaries_dvector(m[nrl], ncl, nch, &left, &right, epsillon); // premier intervalle
  for(i=nrl+1; i<=nrh; i++) {
    extractnz_boundaries_dvector(m[i], ncl, nch, &a, &b, epsillon);
    if(a < left) left = a; // agrandissement de l'intervalle SI necessaire (et non le contraire)
    if(b > right) right = b;
  }
  *nclnz = left;
  *nchnz = right;
}
/* ---------------------------------------------------------------------------------------------- */
IMAGE_EXPORT(float**) submatrix(float **a, long oldrl, long oldrh, long oldcl, long oldch, long newrl, long newcl)
/* ---------------------------------------------------------------------------------------------- */
/* point a submatrix [newrl..][newcl..] to a[oldrl..oldrh][oldcl..oldch] */
{
  long i,j,nrow=oldrh-oldrl+1,ncol=oldcl-newcl;
  float **m;

  /* allocate array of pointers to rows */
  m=(float **) malloc((size_t) ((nrow+NR_END)*sizeof(float*)));
  if (!m) nrerror("allocation failure in submatrix()");
  m += NR_END;
  m -= newrl;

  /* set pointers to rows */
  for(i=oldrl,j=newrl;i<=oldrh;i++,j++) m[j]=a[i]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------ */
IMAGE_EXPORT(float**) convert_matrix(float *a, long nrl, long nrh, long ncl, long nch)
/* ------------------------------------------------------------------ */
/* allocate a float matrix m[nrl..nrh][ncl..nch] that points to the matrix
declared in the standard C manner as a[nrow][ncol], where nrow=nrh-nrl+1
and ncol=nch-ncl+1. The routine should be called with the address
&a[0][0] as the first argument. */
{
  long i,j,nrow=nrh-nrl+1,ncol=nch-ncl+1;
  float **m;

  /* allocate pointers to rows */
  m=(float **) malloc((size_t) ((nrow+NR_END)*sizeof(float*)));
  if (!m) nrerror("allocation failure in convert_matrix()");
  m += NR_END;
  m -= nrl;

  /* set pointers to rows */
  m[nrl]=a-ncl;
  for(i=1,j=nrl+1;i<nrow;i++,j++) m[j]=m[j-1]+ncol;

  /* return pointer to array of pointers to rows */
  return m;
}
/* ------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lowpart_smatrix(short **X, long nrl,long nrh,long ncl, long nch, byte **Y)
/* ------------------------------------------------------------------------- */
{
  long i, j;
  int s = 0;
  short x, *Xi;
  byte  y, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i];
    Yi = Y[i];

    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & 0xff;
      Yi[j] = y;
    }
  }
}
/* --------------------------------------------------------------------------- */
IMAGE_EXPORT(void) lowpart_usmatrix(ushort **X, long nrl,long nrh,long ncl, long nch, byte **Y)
/* --------------------------------------------------------------------------- */
{
  long i, j;
  int s = 0;
  ushort x, *Xi;
  byte  y, *Yi;

  for(i=nrl; i<=nrh; i++) {
    Xi = X[i];
    Yi = Y[i];

    for(j=ncl; j<=nch; j++) {
      x = Xi[j];
      y = x & 0xff;
      Yi[j] = y;
    }
  }
}
