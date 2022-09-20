/* ----------------- */
/* --- NRALLOC.H --- */
/* ----------------- */


/* --- Light version of the memory allocation functions of NRC --- */

/*
 * Note :
 * WARNING, this is a short version of NRutil.c,
 * which does not contain the K&R version of the functions
 * Only ANSI version of allocation functions have been included
 *
 * Copyright (c) 1994 LRE
 * Copyright (c) 1997-1999 LIS - EIA
 * Copyright (c) 1999-2000 IMASYS
 * Copyright (c) 2000-2001 LIS-UPMC
 */

#ifndef _NRALLOC_H_
#define _NRALLOC_H_

#ifdef __cplusplus
#pragma message ("C++")
extern "C" {
#endif

#pragma message("- include nralloc.h")
#pragma message("  ATTENTION memory transferts are done with MEMCOPY MEMSET")

#define NR_END 0
#define FREE_ARG char*

extern long nr_end;

#ifndef FREE_ARG
#define FREE_ARG char*
#endif

#define NR_ERROR_HANDLER
// if not defined return NULL when error occurs

/* ------------- */
/* --- Alloc --- */
/* ------------- */
void nrerror(char error_text[]);

IMAGE_EXPORT(float*)            vector  (long nl, long nh);
IMAGE_EXPORT(float*)            vector0 (long nl, long nh);
IMAGE_EXPORT(double*)          dvector  (long nl, long nh);
IMAGE_EXPORT(double*)          dvector0 (long nl, long nh);
IMAGE_EXPORT(unsigned char*)   cvector  (long nl, long nh);
IMAGE_EXPORT(byte*)            bvector  (long nl, long nh);
IMAGE_EXPORT(byte*)            bvector0 (long nl, long nh);
IMAGE_EXPORT(byte*)            bvector1 (long nl, long nh);
IMAGE_EXPORT(short*)           svector  (long nl, long nh);
IMAGE_EXPORT(short*)           svector0 (long nl, long nh);
IMAGE_EXPORT(ushort*)         usvector  (long nl, long nh);
IMAGE_EXPORT(ushort*)         usvector0 (long nl, long nh);
IMAGE_EXPORT(ushort*)       ui16vector  (long nl, long nh);
IMAGE_EXPORT(ushort*)       ui16vector0 (long nl, long nh);
IMAGE_EXPORT(int*)             ivector  (long nl, long nh);
IMAGE_EXPORT(int*)             ivector0 (long nl, long nh);
IMAGE_EXPORT(int*)             ivector1 (long nl, long nh);
IMAGE_EXPORT(int32*)         i32vector  (long nl, long nh);
IMAGE_EXPORT(int32*)         i32vector0 (long nl, long nh);
IMAGE_EXPORT(unsigned long*)   lvector  (long nl, long nh);
IMAGE_EXPORT(rgb8*)         rgb8vector  (long nl, long nh);
IMAGE_EXPORT(rgb8*)         rgb8vector0 (long nl, long nh);
IMAGE_EXPORT(rgb32*)       rgb32vector  (long nl, long nh);
IMAGE_EXPORT(rgb32*)       rgb32vector0 (long nl, long nh);
IMAGE_EXPORT(void**)           vvector  (long nl, long nh);
IMAGE_EXPORT(void**)           vvector0 (long nl, long nh);




IMAGE_EXPORT(unsigned char**)   cmatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(byte**)            bmatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(short**)           smatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(ushort**)         usmatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int16**)         i16matrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint16**)       ui16matrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int**)             imatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint**)           uimatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(long**)            lmatrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(rgb8**)         rgb8matrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(rgbx8**)       rgbx8matrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(float**)            matrix  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(double**)          dmatrix  (long nrl, long nrh, long ncl, long nch);

IMAGE_EXPORT(byte**)            bmatrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(short**)           smatrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(ushort**)         usmatrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int**)             imatrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint**)           uimatrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int16**)         i16matrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint16**)       ui16matrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(float**)            matrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(double**)          dmatrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(rgb8**)         rgb8matrix0 (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(rgbx8**)       rgbx8matrix0 (long nrl, long nrh, long ncl, long nch);


IMAGE_EXPORT(float***)         f3tensor  (long nrl, long nrh, long ncl, long nch, long ndl, long ndh);
IMAGE_EXPORT(double***)        d3tensor  (long nrl, long nrh, long ncl, long nch, long ndl, long ndh);
IMAGE_EXPORT(byte***)          b3tensor  (long nrl, long nrh, long ncl, long nch, long ndl, long ndh);
IMAGE_EXPORT(short***)         s3tensor  (long nrl, long nrh, long ncl, long nch, long ndl, long ndh);
IMAGE_EXPORT(ushort***)        us3tensor (long nrl, long nrh, long ncl, long nch, long ndl, long ndh);
IMAGE_EXPORT(int***)           i3tensor  (long nrl, long nrh, long ncl, long nch, long ndl, long ndh);

/* ------------ */
/* --- cube --- */
/* ------------ */

// Warning : tensor(row, column, depth) cube(depth, row, column);

IMAGE_EXPORT(int8***)            i8cube (long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int16***)          i16cube (long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint16***)        ui16cube (long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int32***)          i32cube (long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint32***)        ui32cube (long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(float32***)        f32cube (long ndl, long ndh, long nrl, long nrh, long ncl, long nch);

/* --------------- */
/* --- Mapping --- */
/* --------------- */

/* ------------------- */
/* -- empty mapping -- */
/* ------------------- */
IMAGE_EXPORT(byte**)            bmatrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(short**)           smatrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(ushort**)         usmatrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(uint16**)       ui16matrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT( int16**)        i16matrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(int**)             imatrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(float**)            matrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(double**)          dmatrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(rgb8**)         rgb8matrix_map  (long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(rgbx8**)       rgbx8matrix_map  (long nrl, long nrh, long ncl, long nch);


IMAGE_EXPORT(void)      free_bmatrix_map(byte   **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)      free_smatrix_map(short  **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)     free_usmatrix_map(ushort **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)   free_ui16matrix_map(uint16 **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)   free_i16matrix_map (int16  **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)   free_rgb8matrix_map(rgb8   **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)   free_rgb8map       (rgb8   **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)  free_rgbx8matrix_map(rgbx8  **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)  free_rgbx8map       (rgbx8  **m, long nrl, long nrh, long ncl, long nch);

/* -- old -- */

IMAGE_EXPORT(byte**)             bmatrix_map_2D(long nrl, long nrh, long ncl, long nch, void **data_2D);
IMAGE_EXPORT(short**)            smatrix_map_2D(long nrl, long nrh, long ncl, long nch, void **data_2D);
IMAGE_EXPORT(ushort**)          usmatrix_map_2D(long nrl, long nrh, long ncl, long nch, void **data_2D);
//IMAGE_EXPORT(int**)             imatrix_map(long nrl, long nrh, long ncl, long nch, void **data_2D);

/* ------------------ */
/* --- 1D Mapping --- */
/* ------------------ */

IMAGE_EXPORT(byte**)         bmatrix_map_1D_pitch(byte   **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(short**)        smatrix_map_1D_pitch(short  **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(ushort**)      usmatrix_map_1D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(uint16**)    ui16matrix_map_1D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(rgb8**)      rgb8matrix_map_1D_pitch(rgb8   **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(rgbx8**)    rgbx8matrix_map_1D_pitch(rgbx8  **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);

IMAGE_EXPORT(byte**)         bmatrix_remap_1D_pitch(byte   **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(short**)        smatrix_remap_1D_pitch(short  **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(ushort**)      usmatrix_remap_1D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(int16**)      i16matrix_remap_1D_pitch(int16  **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(uint16**)    ui16matrix_remap_1D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(rgb8**)      rgb8matrix_remap_1D_pitch(rgb8   **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);
IMAGE_EXPORT(rgbx8**)    rgbx8matrix_remap_1D_pitch(rgbx8  **m, long nrl, long nrh, long ncl, long nch, void *data_1D, long pitch);

/* ------------------ */
/* --- 2D Mapping --- */
/* ------------------ */

IMAGE_EXPORT(byte**)         bmatrix_map_2D_pitch(byte   **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(short**)        smatrix_map_2D_pitch(short  **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(ushort**)      usmatrix_map_2D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(int16**)      i16matrix_map_2D_pitch(int16  **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(uint16**)    ui16matrix_map_2D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(rgb8**)      rgb8matrix_map_2D_pitch(rgb8   **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(rgbx8**)    rgbx8matrix_map_2D_pitch(rgbx8  **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);

IMAGE_EXPORT(byte**)         bmatrix_remap_2D_pitch(byte   **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(short**)        smatrix_remap_2D_pitch(short  **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(ushort**)      usmatrix_remap_2D_pitch(ushort **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(int16**)      i16matrix_remap_2D_pitch(int16  **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(uint16**)    ui16matrix_remap_2D_pitch(uint16 **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(rgb8**)      rgb8matrix_remap_2D_pitch(rgb8   **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);
IMAGE_EXPORT(rgbx8**)    rgbx8matrix_remap_2D_pitch(rgbx8  **m, long nrl, long nrh, long ncl, long nch, void **data_2D, long pitch);

/* ------------------- */
/* --- ROI Mapping --- */
/* ------------------- */

IMAGE_EXPORT(byte**)    bmatrix_map_pitch_ROI(byte **X, long nrl, long nrh, long ncl, long nch, long pitch, long nrl2, long nrh2, long ncl2, long nch2, long nr0, long nc0);
IMAGE_EXPORT(rgb8**) rgb8matrix_map_pitch_ROI(rgb8 **X, long nrl, long nrh, long ncl, long nch, long pitch, long nrl2, long nrh2, long ncl2, long nch2, long nr0, long nc0);


// pour image avec padding
IMAGE_EXPORT(void)  bmatrix_map_roi00 (byte **m,long nrl0, long nrh0, long ncl0, long nch0,  long nrl1, long nrh1, long ncl1, long nch1);
IMAGE_EXPORT(void)  smatrix_map_roi00 (short **m,long nrl0, long nrh0, long ncl0, long nch0, long nrl1, long nrh1, long ncl1, long nch1);
IMAGE_EXPORT(void) usmatrix_map_roi00(ushort **m,long nrl0, long nrh0, long ncl0, long nch0, long nrl1, long nrh1, long ncl1, long nch1);

                                 /*
 * a partir d'une image       [nrl0..nrh0]x[ncl0..nch0]
 * remappe m, pour que la roi [nrl1..nrh1]x[ncl1..nch1]
 * ait comme coordonnees dans le nouveau repere
 * [0..nrh1-nrl1+1][0..nch1-nch0+1]
 */

IMAGE_EXPORT(void) bmatrix_unmap_roi00 (byte **m, long nrl0, long nrh0, long ncl0, long nch0, long nrl1, long nrh1, long ncl1, long nch1);
IMAGE_EXPORT(void) smatrix_unmap_roi00(short **m, long nrl0, long nrh0, long ncl0, long nch0, long nrl1, long nrh1, long ncl1, long nch1);


IMAGE_EXPORT(void)  bmatrix_reverse( byte  **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void)  smatrix_reverse( short **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) usmatrix_reverse(ushort **m, long nrl, long nrh, long ncl, long nch);
/*
 * Inversion du tableau de pointeur sur ligne.
 * La premiere ligne devient la derniere, etc ...
 */

IMAGE_EXPORT(void) shrink_bmatrix (byte   **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) shrink_smatrix (short  **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) shrink_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) shrink_imatrix (int    **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) shrink_lmatrix (long   **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) shrink_matrix  (float  **m, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) shrink_dmatrix (double **m, long nrl, long nrh, long ncl, long nch);
/* shrink is devoted to benchmarking, not for to real life */

IMAGE_EXPORT(void) resize_bmatrix (byte   **m, long nrl,  long nrh, long ncl, long nch);
IMAGE_EXPORT(void) resize_smatrix (short  **m, long nrl,  long nrh, long ncl, long nch);
IMAGE_EXPORT(void) resize_usmatrix(ushort **m, long nrl,  long nrh, long ncl, long nch);
IMAGE_EXPORT(void) resize_imatrix (int    **m, long nrl,  long nrh, long ncl, long nch);
IMAGE_EXPORT(void) resize_bmatrix0(byte   **m, long nrow, long ncol);
IMAGE_EXPORT(void) resize_smatrix0(short  **m, long nrow, long ncol);
IMAGE_EXPORT(void) resize_imatrix0(int    **m, long nrow, long ncol);

/*
 * resize : comme shrink (ancien nom)
 * resize0 : 0-align matrix
 */

/* -------------------- */
/* --- Reallocation --- */
/* -------------------- */
IMAGE_EXPORT(byte**)   addrow_bmatrix (byte   **m, long nrl, long nrh, long ncl, long nch, long nr);
IMAGE_EXPORT(short**)  addrow_smatrix (short  **m, long nrl, long nrh, long ncl, long nch, long nr);
IMAGE_EXPORT(ushort**) addrow_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch, long nr);
IMAGE_EXPORT(int**)    addrow_imatrix (int    **m, long nrl, long nrh, long ncl, long nch, long nr);
/*
 * add nr row to the matrix,
 * the added rows are not connected to the matrix
 */

IMAGE_EXPORT(byte*)   realloc_bvector (byte   *v, long nl, long nh, long n);
IMAGE_EXPORT(short*)  realloc_svector (short  *v, long nl, long nh, long n);
IMAGE_EXPORT(ushort*) realloc_usvector(ushort *v, long nl, long nh, long n);
IMAGE_EXPORT(int*)    realloc_ivector (int    *v, long nl, long nh, long n);
IMAGE_EXPORT(void**)  realloc_vvector (void  **v, long nl, long nh, long n);

IMAGE_EXPORT(byte**)  realloc_bmatrix (byte   **m, long nrl, long nrh, long ncl, long nch, long nr);
IMAGE_EXPORT(short**) realloc_smatrix (short  **m, long nrl, long nrh, long ncl, long nch, long nr);
IMAGE_EXPORT(ushort**)realloc_usmatrix(ushort **m, long nrl, long nrh, long ncl, long nch, long nr);
IMAGE_EXPORT(int**)   realloc_imatrix (int    **m, long nrl, long nrh, long ncl, long nch, long nr);
/*
 * add nr row to the matrix,
 * the added rows are connected to the matrix
 */

/* ------------ */
/* --- Free --- */
/* ------------ */

IMAGE_EXPORT(void) free_vector     (float         *v, long nl, long nh);
IMAGE_EXPORT(void) free_dvector    (double        *v, long nl, long nh);
IMAGE_EXPORT(void) free_cvector    (unsigned char *v, long nl, long nh);
IMAGE_EXPORT(void) free_bvector    (byte          *v, long nl, long nh);
IMAGE_EXPORT(void) free_svector    (short         *v, long nl, long nh);
IMAGE_EXPORT(void) free_usvector   (ushort        *v, long nl, long nh);
IMAGE_EXPORT(void) free_i16vector  (int16         *v, long nl, long nh);
IMAGE_EXPORT(void) free_ui16vector (uint16        *v, long nl, long nh);
IMAGE_EXPORT(void) free_ivector    (int           *v, long nl, long nh);
IMAGE_EXPORT(void) free_i32vector  (int32         *v, long nl, long nh);
IMAGE_EXPORT(void) free_lvector    (unsigned long *v, long nl, long nh);
IMAGE_EXPORT(void) free_rgb8vector (rgb8          *v, long nl, long nh);
IMAGE_EXPORT(void) free_rgb32vector(rgb32         *v, long nl, long nh);
IMAGE_EXPORT(void) free_vvector    (void         **v, long nl, long nh);

IMAGE_EXPORT(void) free_matrix     (float         **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_dmatrix    (double        **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_cmatrix    (unsigned char **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_bmatrix    (byte          **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_smatrix    (short         **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_usmatrix   (ushort        **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_i16matrix  (int16         **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_ui16matrix (uint16        **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_imatrix    (int           **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_uimatrix   (uint          **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_lmatrix    (long          **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_rgb8matrix (rgb8          **m,long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) free_rgbx8matrix(rgbx8         **m,long nrl,long nrh,long ncl,long nch);

IMAGE_EXPORT(void) free_f3tensor (float   ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh);
IMAGE_EXPORT(void) free_d3tensor (double  ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh);
IMAGE_EXPORT(void) free_b3tensor (byte    ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh);
IMAGE_EXPORT(void) free_s3tensor (short   ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh);
IMAGE_EXPORT(void) free_us3tensor(ushort  ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh);
IMAGE_EXPORT(void) free_i3tensor (int     ***t,long nrl,long nrh,long ncl,long nch,long ndl,long ndh);

/* ------------ */
/* --- cube --- */
/* ------------ */

// Warning : tensor(row, column, depth) cube(depth, row, column);

IMAGE_EXPORT(void) free_i8cube  (int8    ***m, long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) free_i16cube (int16   ***m, long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) free_ui16cube(uint16  ***m, long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) free_i32cube (int32   ***m, long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) free_ui32cube(uint32  ***m, long ndl, long ndh, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) free_f32cube (float32 ***m, long ndl, long ndh, long nrl, long nrh, long ncl, long nch);

/* ---------------- */
/* -- Convertion -- */
/* ---------------- */
IMAGE_EXPORT(void) convert_svector_vector  (short  *X, long nl, long nh, float  *Y);
IMAGE_EXPORT(void) convert_svector_dvector (short  *X, long nl, long nh, double *Y);
IMAGE_EXPORT(void) convert_usvector_vector (ushort *X, long nl, long nh, float  *Y);
IMAGE_EXPORT(void) convert_usvector_dvector(ushort *X, long nl, long nh, double *Y);
IMAGE_EXPORT(void) convert_ivector_vector  (int    *X, long nl, long nh, float  *Y);
IMAGE_EXPORT(void) convert_ivector_dvector (int    *X, long nl, long nh, double *Y);
IMAGE_EXPORT(void) convert_uivector_vector (uint   *X, long nl, long nh, float  *Y);
IMAGE_EXPORT(void) convert_uivector_dvector(uint   *X, long nl, long nh, double *Y);

IMAGE_EXPORT(void) convert_vector_ivector (float  *X, long nl, long nh, int    *Y);
IMAGE_EXPORT(void) convert_dvector_ivector(double *X, long nl, long nh, int    *Y);

IMAGE_EXPORT(void) convert_smatrix_matrix  (short   **X, long nrl,long nrh,long ncl,long nch, float  **Y);
IMAGE_EXPORT(void) convert_smatrix_dmatrix (short   **X, long nrl,long nrh,long ncl,long nch, double **Y);
IMAGE_EXPORT(void) convert_usmatrix_matrix (ushort  **X, long nrl,long nrh,long ncl,long nch, float  **Y);
IMAGE_EXPORT(void) convert_usmatrix_dmatrix(ushort  **X, long nrl,long nrh,long ncl,long nch, double **Y);
IMAGE_EXPORT(void) convert_imatrix_matrix  (int     **X, long nrl,long nrh,long ncl,long nch, float  **Y);
IMAGE_EXPORT(void) convert_imatrix_dmatrix (int     **X, long nrl,long nrh,long ncl,long nch, double **Y);
IMAGE_EXPORT(void) convert_uimatrix_matrix (uint    **X, long nrl,long nrh,long ncl,long nch, float  **Y);
IMAGE_EXPORT(void) convert_uimatrix_dmatrix(uint    **X, long nrl,long nrh,long ncl,long nch, double **Y);
IMAGE_EXPORT(void) convert_matrix_imatrix  (float   **X, long nrl,long nrh,long ncl,long nch, int    **Y);
IMAGE_EXPORT(void) convert_dmatrix_imatrix (double  **X, long nrl,long nrh,long ncl,long nch, int    **Y);

/* =============================================================== */
/* === # copy # ================================================== */
/* =============================================================== */

IMAGE_EXPORT(void) copy_bvector    (byte   *src, long nl1, long nh1, byte   *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_svector    (short  *src, long nl1, long nh1, short  *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_usvector   (ushort *src, long nl1, long nh1, ushort *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_i16vector  (int16  *src, long nl1, long nh1, int16  *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_ui16vector (uint16 *src, long nl1, long nh1, uint16 *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_ivector    (int    *src, long nl1, long nh1, int    *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_uivector   (uint   *src, long nl1, long nh1, uint   *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_vector     (float  *src, long nl1, long nh1, float  *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_dvector    (double *src, long nl1, long nh1, double *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_rgb8vector (rgb8   *src, long nl1, long nh1, rgb8   *dst, long nl2, long nh2);
IMAGE_EXPORT(void) copy_rgbx8vector(rgbx8  *src, long nl1, long nh1, rgbx8  *dst, long nl2, long nh2);

IMAGE_EXPORT(void) dup_bvector    (byte    *src, long nl, long nh, byte   *dst);
IMAGE_EXPORT(void) dup_svector    (short   *src, long nl, long nh, short  *dst);
IMAGE_EXPORT(void) dup_usvector   (ushort  *src, long nl, long nh, ushort *dst);
IMAGE_EXPORT(void) dup_i16vector  (int16   *src, long nl, long nh, int16  *dst);
IMAGE_EXPORT(void) dup_ui16vector (uint16  *src, long nl, long nh, uint16 *dst);
IMAGE_EXPORT(void) dup_ivector    (int     *src, long nl, long nh, int    *dst);
IMAGE_EXPORT(void) dup_i32vector  (int32   *src, long nl, long nh, int32  *dst);
IMAGE_EXPORT(void) dup_uivector   (uint    *src, long nl, long nh, uint   *dst);
IMAGE_EXPORT(void) dup_vector     (float   *src, long nl, long nh, float  *dst);
IMAGE_EXPORT(void) dup_dvector    (double  *src, long nl, long nh, double *dst);
IMAGE_EXPORT(void) dup_rgb8vector (rgb8    *src, long nl, long nh, rgb8   *dst);
IMAGE_EXPORT(void) dup_rgbx8vector(rgbx8   *src, long nl, long nh, rgbx8  *dst);

IMAGE_EXPORT(void) copy1c_bvector    (byte   *src, long nc, byte   *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_svector    (short  *src, long nc, short  *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_usvector   (ushort *src, long nc, ushort *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_i16vector  (int16  *src, long nc, int16  *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_ui16vector (uint16 *src, long nc, uint16 *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_ivector    (int    *src, long nc, int    *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_rgb8vector (rgb8   *src, long nc, rgb8   *dst, long nl, long nh);
IMAGE_EXPORT(void) copy1c_rgbx8vector(rgbx8  *src, long nc, rgbx8  *dst, long nl, long nh);

/* version non optimisee ie sans memcopy */

IMAGE_EXPORT(void) copy_bvector_mod (byte   *src, long nl, long nh, long m, byte   *dst);
IMAGE_EXPORT(void) copy_svector_mod (short  *src, long nl, long nh, long m, short  *dst);
IMAGE_EXPORT(void) copy_usvector_mod(short  *src, long nl, long nh, long m, ushort *dst);
IMAGE_EXPORT(void) copy_ivector_mod (int    *src, long nl, long nh, long m, int    *dst);

IMAGE_EXPORT(void) copy_vector_mod  (float  *src, long nl, long nh, long m, float  *dst);
IMAGE_EXPORT(void) copy_dvector_mod (double *src, long nl, long nh, long m, double *dst);

IMAGE_EXPORT(void) complete_border_bmatrix (byte **m, long nrl,long nrh,long ncl, long nch, long n);
IMAGE_EXPORT(void) complete_border1_bmatrix(byte **m, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(void) dup_bmatrix    (byte   **X, long nrl,long nrh,long ncl, long nch, byte   **Y);
IMAGE_EXPORT(void) dup_smatrix    (short  **X, long nrl,long nrh,long ncl, long nch, short  **Y);
IMAGE_EXPORT(void) dup_usmatrix   (ushort **X, long nrl,long nrh,long ncl, long nch, ushort **Y);
IMAGE_EXPORT(void) dup_ui16matrix (uint16 **X, long nrl,long nrh,long ncl, long nch, uint16 **Y);
IMAGE_EXPORT(void) dup_imatrix    (int    **X, long nrl,long nrh,long ncl, long nch, int    **Y);
IMAGE_EXPORT(void) dup_matrix     (float  **X, long nrl,long nrh,long ncl, long nch, float  **Y);
IMAGE_EXPORT(void) dup_dmatrix    (double **X, long nrl,long nrh,long ncl, long nch, double **Y);
IMAGE_EXPORT(void) dup_rgb8matrix (rgb8   **X, long nrl,long nrh,long ncl, long nch, rgb8   **Y);
IMAGE_EXPORT(void) dup_rgbx8matrix(rgbx8  **X, long nrl,long nrh,long ncl, long nch, rgbx8  **Y);

//duplication of 1 column on a range
IMAGE_EXPORT(void) copy1c_bmatrix     (byte   **X, long nc, byte   **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_smatrix     (short  **X, long nc, short  **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_usmatrix    (ushort **X, long nc, ushort **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_imatrix     (int    **X, long nc, int    **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_uimatrix    (uint   **X, long nc, uint   **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_matrix      (float  **X, long nc, float  **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_dmatrix     (double **X, long nc, double **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_rgb8matrix  (rgb8   **X, long nc, rgb8   **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1c_rgbx8matrix (rgbx8  **X, long nc, rgbx8  **Y, long nrl, long nrh, long ncl, long nch);

IMAGE_EXPORT(void) copy1r_bmatrix     (byte   **X, long nr, byte   **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_smatrix     (short  **X, long nr, short  **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_usmatrix    (ushort **X, long nr, ushort **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_imatrix     (int    **X, long nr, int    **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_uimatrix    (uint   **X, long nr, uint   **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_matrix      (float  **X, long nr, float  **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_dmatrix     (double **X, long nr, double **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_rgb8matrix  (rgb8   **X, long nr, rgb8   **Y, long nrl, long nrh, long ncl, long nch);
IMAGE_EXPORT(void) copy1r_rgbx8matrix (rgbx8  **X, long nr, rgbx8  **Y, long nrl, long nrh, long ncl, long nch);

IMAGE_EXPORT(void) copy_bmatrix     (byte   **m1, long nrl1,long nrh1,long ncl1, long nch1, byte   **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_smatrix     (short  **m1, long nrl1,long nrh1,long ncl1, long nch1, short  **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_usmatrix    (ushort **m1, long nrl1,long nrh1,long ncl1, long nch1, ushort **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_imatrix     (int    **m1, long nrl1,long nrh1,long ncl1, long nch1, int    **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_uimatrix    (uint   **m1, long nrl1,long nrh1,long ncl1, long nch1, uint   **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_matrix      (float  **m1, long nrl1,long nrh1,long ncl1, long nch1, float  **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_dmatrix     (double **m1, long nrl1,long nrh1,long ncl1, long nch1, double **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_rgb8matrix  (rgb8   **m1, long nrl1,long nrh1,long ncl1, long nch1, rgb8   **m2, long nrl2, long nrh2, long ncl2, long nch2);
IMAGE_EXPORT(void) copy_rgbx8matrix (rgbx8  **m1, long nrl1,long nrh1,long ncl1, long nch1, rgbx8  **m2, long nrl2, long nrh2, long ncl2, long nch2);

IMAGE_EXPORT(void) copy_sub_bmatrix(byte **src, long nrl,long nrh,long ncl, long nch, byte **dst);
IMAGE_EXPORT(void) copy_sub_imatrix(int  **src, long nrl,long nrh,long ncl, long nch, int  **dst);
IMAGE_EXPORT(void) copy_center_bmatrix(byte **src, long nrl0,long nrh0,long ncl0, long nch0, byte **dst, long nrl1,long nrh1,long ncl1, long nch1);

IMAGE_EXPORT(void) copy_sub_imatrix_index(int  **src, long nrl,long nrh,long ncl, long nch, int  **dst, int *index);
/*
 * Comme copy_sub_imatrix, mais l'ordre de copie des lignes
 * est donne par l'index
 */

IMAGE_EXPORT(void) extract_bmatrix (byte   **src, long nrl,long nrh,long ncl, long nch, byte   **dst);
IMAGE_EXPORT(void) extract_smatrix (short  **src, long nrl,long nrh,long ncl, long nch, short  **dst);
IMAGE_EXPORT(void) extract_usmatrix(ushort **src, long nrl,long nrh,long ncl, long nch, ushort **dst);
IMAGE_EXPORT(void) extract_imatrix (int    **src, long nrl,long nrh,long ncl, long nch, int    **dst);
IMAGE_EXPORT(void) extract_uimatrix(uint   **src, long nrl,long nrh,long ncl, long nch, uint   **dst);
IMAGE_EXPORT(void) extract_matrix  (float  **src, long nrl,long nrh,long ncl, long nch, float  **dst);
IMAGE_EXPORT(void) extract_dmatrix (double **src, long nrl,long nrh,long ncl, long nch, double **dst);

/*
 * copy :    [nrl0..nrh0] x [ncl0..nch0] -> [nrl1..nrh1] x [ncl1..nch1]
 *
 * extract : [nrl..nrh] x [ncl..nch] -> [0..nrh-nrl] x [0..nch-ncl]
 */

/*
 * copie sans verification
 */

IMAGE_EXPORT(float**) submatrix (float **a, long oldrl, long oldrh, long oldcl, long oldch, long newrl, long newcl);
IMAGE_EXPORT(float**) convert_matrix(float *a, long nrl, long nrh, long ncl, long nch);

#ifdef __cplusplus
}
#endif

#else
#pragma message(" Warning : attemp to re-include nralloc.h")
#endif /* _NRALLOC_H_ */
