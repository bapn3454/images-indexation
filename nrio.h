/* -------------- */
/* --- nrio.h --- */
/* -------------- */

/*
 * Copyright (c) 1994 LRE
 * Copyright (c) 1997-1999 LIS - EIA
 * Copyright (c) 1999-2000 IMASYS
 * Copyright (c) 2000-2001 LIS-UPMC
 */

/*
 *
 * modif 22-02-2001 : display_cube, write_cube, fwrite_cube, fread_cube
 * 
 */

#ifndef _NRIO_H_
#define _NRIO_H_

#ifdef __cplusplus
#pragma message ("C++")
extern "C" {
#endif

#pragma message("- include nrio.h")

IMAGE_EXPORT(void) display_bvector   (byte   *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_svector   (short  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_usvector  (ushort *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_i16vector (int16  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_ui16vector(uint16 *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_ivector   (int    *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_uivector  (uint   *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_i32vector (int32  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_ui32vector(uint32 *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_vector    (float  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_dvector   (double *v,long nl,long nh, char *format, char *name);

IMAGE_EXPORT(void) display_bvector_number   (byte   *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_svector_number   (short  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_usvector_number  (ushort *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_i16vector_number (int16  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_ui16vector_number(uint16 *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_ivector_number   (int    *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_uivector_number  (uint   *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_i32vector_number (int32  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_ui32vector_number(uint32 *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_vector           (float  *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_dvector          (double *v,long nl,long nh, char *format, char *name);


IMAGE_EXPORT(void) display_bvector_cycle  (byte    *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_svector_cycle  (short   *v,long nl,long nh, char *format, char *name);
IMAGE_EXPORT(void) display_usvector_cycle (ushort  *v,long nl,long nh, char *format, char *name);
/*
 * quand le vector represente un ensemble de cycles d'equivalence
 */

IMAGE_EXPORT(void) display_bmatrix0(byte  **m, long nrow, long ncol, char *format, char *name);
IMAGE_EXPORT(void) display_imatrix0(int   **m, long nrow, long ncol, char *format, char *name);
IMAGE_EXPORT(void) display_matrix0 (float **m, long nrow, long ncol, char *format, char *name);

IMAGE_EXPORT(void) display_bmatrix     (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_smatrix     (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_usmatrix    (ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_i16matrix   (int16  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_ui16matrix  (uint16 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_i32matrix   (int32  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_ui32matrix  (uint32 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_imatrix     (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_matrix      (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_dmatrix     (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_rgb8matrix  (rgb8   **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);

IMAGE_EXPORT(void) display_bmatrix_number     (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_smatrix_number     (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_usmatrix_number    (ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_i16matrix_number   (int16  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_ui16matrix_number  (uint16 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_i32matrix_number   (int32  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_ui32matrix_number  (uint32 **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_imatrix_number     (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_matrix_number      (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_dmatrix_number     (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *name);

/* ------------------ */
/* -- display_cube -- */
/* ------------------ */
IMAGE_EXPORT(void) display_i8cube  ( int8   ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_i16cube ( int16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_ui16cube(uint16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_i32cube ( int32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_ui32cube(uint32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) display_f32cube (float32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);

/* ------------------ */
/* -- write_vector -- */
/* ------------------ */
IMAGE_EXPORT(void) write_vector     (float    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_bvector    (byte     *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_svector    (short    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_usvector   (ushort   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i16vector  (int16    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ui16vector (uint16   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ivector    (int      *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i32vector  (int32    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_dvector    (double   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb8vector (rgb8     *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb32vector(rgb32    *v,long nl,long nh, char *format, char *filename);
/* -------------------- */
/* -- write_vector_T -- */
/* -------------------- */
IMAGE_EXPORT(void) write_vector     (float    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_bvector    (byte     *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_svector    (short    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_usvector   (ushort   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ui16vector (uint16   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i16vector  (int16    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ivector    (int      *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i32vector  (int32    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_dvector    (double   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb8vector (rgb8     *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb32vector(rgb32    *v,long nl,long nh, char *format, char *filename);
/* ------------------------- */
/* -- write_vector_number -- */
/* ------------------------- */
IMAGE_EXPORT(void) write_vector_number     (float  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_bvector_number    (byte   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_svector_number    (short  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_usvector_number   (ushort *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ui16vector_number (uint16 *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i16vector_number  (int16  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ivector_number    (int    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i32vector_number  (int32  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_dvector_number    (double *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb8vector_number (rgb8   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb32vector_number(rgb32  *v,long nl,long nh, char *format, char *filename);
/* --------------------------- */
/* -- write_vector_T_number -- */
/* --------------------------- */
IMAGE_EXPORT(void) write_vector_T_number     (float  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_bvector_T_number    (byte   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_svector_T_number    (short  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_usvector_T_number   (ushort *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ui16vector_T_number (uint16 *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i16vector_T_number  (int16  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_ivector_T_number    (int    *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_i32vector_T_number  (int32  *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_dvector_T_number    (double *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb8vector_T_number (rgb8   *v,long nl,long nh, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb32vector_T_number(rgb32  *v,long nl,long nh, char *format, char *filename);
/* -------------------- */
/* -- write_vector_k -- */
/* -------------------- */
IMAGE_EXPORT(void) write_vector_k  (float  *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_bvector_k (byte   *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_svector_k (short  *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_usvector_k(ushort *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_ivector_k (int    *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_dvector_k (double *v,long nl,long nh, char *format, char *filename, int k);
/* --------------------------- */
/* -- write_vector_number_k -- */
/* --------------------------- */
IMAGE_EXPORT(void) write_vector_number_k  (float  *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_bvector_number_k (byte   *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_svector_number_k (short  *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_usvector_number_k(ushort *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_ivector_number_k (int    *v,long nl,long nh, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_dvector_number_k (double *v,long nl,long nh, char *format, char *filename, int k);
/* ------------------ */
/* -- write_matrix -- */
/* ------------------ */
IMAGE_EXPORT(void) write_matrix    (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_bmatrix   (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_smatrix   (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_usmatrix  (ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_imatrix   (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_dmatrix   (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_rgb8matrix(rgb8   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
/* ------------------------- */
/* -- write_matrix_number -- */
/* ------------------------- */
IMAGE_EXPORT(void) write_matrix_number   (float **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_bmatrix_number (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_smatrix_number (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_usmatrix_number(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_imatrix_number (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_dmatrix_number  (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
/* -------------------- */
/* -- write_matrix_T -- */
/* -------------------- */
IMAGE_EXPORT(void) write_matrix_T  (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_bmatrix_T (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_smatrix_T (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_usmatrix_T(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_imatrix_T (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_dmatrix_T (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
/* --------------------------- */
/* -- write_matrix_T_number -- */
/* --------------------------- */
IMAGE_EXPORT(void) write_matrix_T_number (float   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_bmatrix_T_number (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_smatrix_T_number (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_usmatrix_T_number(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_imatrix_T_number (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);
IMAGE_EXPORT(void) write_dmatrix_T_number (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename);

/* -------------------- */
/* -- write_matrix_k -- */
/* -------------------- */
IMAGE_EXPORT(void) write_matrix_k  (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_bmatrix_k (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_smatrix_k (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_usmatrix_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_imatrix_k (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_dmatrix_k (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
/* --------------------------- */
/* -- write_matrix_number_k -- */
/* --------------------------- */
IMAGE_EXPORT(void) write_matrix_number_k (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_bmatrix_number_k (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_smatrix_number_k (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_usmatrix_number_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_imatrix_number_k (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_dmatrix_number_k (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
/* ---------------------- */
/* -- write_matrix_T_k -- */
/* ---------------------- */
IMAGE_EXPORT(void) write_matrix_T_k (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_bmatrix_T_k (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_smatrix_T_k (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_usmatrix_T_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_imatrix_T_k (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_dmatrix_T_k (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
/* ----------------------------- */
/* -- write_matrix_T_number_k -- */
/* ----------------------------- */
IMAGE_EXPORT(void) write_matrix_T_number_k  (float  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_bmatrix_T_number_k (byte   **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_smatrix_T_number_k (short  **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_usmatrix_T_number_k(ushort **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_imatrix_T_number_k (int    **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);
IMAGE_EXPORT(void) write_dmatrix_T_number_k (double **m,long nrl,long nrh,long ncl, long nch, char *format, char *filename, int k);

/* ---------------- */
/* -- write_cube -- */
/* ---------------- */
IMAGE_EXPORT(void) write_i8cube  ( int8   ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) write_i16cube ( int16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) write_ui16cube(uint16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) write_i32cube ( int32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) write_ui32cube(uint32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);
IMAGE_EXPORT(void) write_f32cube (float32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *format, char *name);

/* ---------------- */
/* -- fread_cube -- */
/* ---------------- */
IMAGE_EXPORT(void) fread_i8cube  (char *filename,  int8   ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_i16cube (char *filename,  int16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_ui16cube(char *filename, uint16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_i32cube (char *filename,  int32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_ui32cube(char *filename, uint32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_f32cube (char *filename, float32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch);

/* ----------------- */
/* -- fwrite_cube -- */
/* ----------------- */
IMAGE_EXPORT(void) fwrite_i8cube  ( int8   ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *name);
IMAGE_EXPORT(void) fwrite_i16cube ( int16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *name);
IMAGE_EXPORT(void) fwrite_ui16cube(uint16  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *name);
IMAGE_EXPORT(void) fwrite_i32cube ( int32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *name);
IMAGE_EXPORT(void) fwrite_ui32cube(uint32  ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *name);
IMAGE_EXPORT(void) fwrite_f32cube (float32 ***c,long ndl, long ndh, long nrl,long nrh,long ncl, long nch, char *name);

/* ------------------- */
/* -- fwrite_vector -- */
/* ------------------- */
IMAGE_EXPORT(void) fwrite_bvector (byte   *v,long nl,long nh, char *filename);
IMAGE_EXPORT(void) fwrite_svector (short  *v,long nl,long nh, char *filename);
IMAGE_EXPORT(void) fwrite_usvector(ushort *v,long nl,long nh, char *filename);
IMAGE_EXPORT(void) fwrite_ivector (int    *v,long nl,long nh, char *filename);
IMAGE_EXPORT(void) fwrite_uivector(uint   *v,long nl,long nh, char *filename);
IMAGE_EXPORT(void) fwrite_vector  (float  *v,long nl,long nh, char *filename);
IMAGE_EXPORT(void) fwrite_dvector (double *v,long nl,long nh, char *filename);

/* ------------------ */
/* -- fread_vector -- */
/* ------------------ */
IMAGE_EXPORT(void) fread_bvector (char *filename, byte   *v,long nl,long nh);
IMAGE_EXPORT(void) fread_svector (char *filename, short  *v,long nl,long nh);
IMAGE_EXPORT(void) fread_usvector(char *filename, ushort *v,long nl,long nh);
IMAGE_EXPORT(void) fread_ivector (char *filename, int    *v,long nl,long nh);
IMAGE_EXPORT(void) fread_uivector(char *filename, uint   *v,long nl,long nh);
IMAGE_EXPORT(void) fread_vector  (char *filename, float  *v,long nl,long nh);
IMAGE_EXPORT(void) fread_dvector (char *filename, double *v,long nl,long nh);

/* ------------------ */
/* -- fread_matrix -- */
/* ------------------ */
IMAGE_EXPORT(void) fread_bmatrix (char *filename, byte   **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_smatrix (char *filename, short  **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_usmatrix(char *filename, ushort **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_imatrix (char *filename, int    **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_uimatrix(char *filename, uint   **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_matrix  (char *filename, float  **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) fread_dmatrix (char *filename, double **m,long nrl,long nrh,long ncl, long nch);

/* ------------------- */
/* -- fwrite_matrix -- */
/* ------------------- */
IMAGE_EXPORT(void) fwrite_bmatrix (byte   **m,long nrl,long nrh,long ncl, long nch, char *filename);
IMAGE_EXPORT(void) fwrite_smatrix (short  **m,long nrl,long nrh,long ncl, long nch, char *filename);
IMAGE_EXPORT(void) fwrite_usmatrix(ushort **m,long nrl,long nrh,long ncl, long nch, char *filename);
IMAGE_EXPORT(void) fwrite_imatrix (int    **m,long nrl,long nrh,long ncl, long nch, char *filename);
IMAGE_EXPORT(void) fwrite_uimatrix(uint   **m,long nrl,long nrh,long ncl, long nch, char *filename);
IMAGE_EXPORT(void) fwrite_matrix  (float  **m,long nrl,long nrh,long ncl, long nch, char *filename);
IMAGE_EXPORT(void) fwrite_dmatrix (double **m,long nrl,long nrh,long ncl, long nch, char *filename);


/* -- other --*/
void write_i3tensor(int    ***m,long nrl,long nrh,long ncl, long nch, long ndl, long ndh, char *format, char *filename);

IMAGE_EXPORT(void) save_bvector (byte   *v,long nl, long nh, char *path, char *filename);
IMAGE_EXPORT(void) save_svector (short  *v,long nl, long nh, char *path, char *filename);
IMAGE_EXPORT(void) save_usvector(ushort *v,long nl, long nh, char *path, char *filename);
IMAGE_EXPORT(void) save_ivector (int    *v,long nl, long nh, char *path, char *filename);

IMAGE_EXPORT(void) save_bmatrix (byte   **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename);
IMAGE_EXPORT(void) save_smatrix (short  **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename);
IMAGE_EXPORT(void) save_usmatrix(ushort **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename);
IMAGE_EXPORT(void) save_imatrix (int    **m,long nrl, long nrh, long ncl, long nch, char *path, char *filename);

IMAGE_EXPORT(void) save_svector2 (short *v, long nl, long nh, char *path, char *filename, int seuil, int nb_iter, int balayage, int maj, int alpha_update);
IMAGE_EXPORT(void) save_usvector2(ushort *v, long nl, long nh, char *path, char *filename, int seuil, int nb_iter, int balayage, int maj, int alpha_update);
IMAGE_EXPORT(void) save_imatrix2(int  **m, long nrl, long nrh, long ncl, long nch, char *path, char *filename, int seuil, int nb_iter, int balayage, int maj, int alpha_update);

/* ------------------------------- */
/* -- PGM and PNM binary format -- */
/* ------------------------------- */

IMAGE_EXPORT(byte **) LoadPGM_bmatrix(char *filename, long *nrl, long *nrh, long *ncl, long *nch);
IMAGE_EXPORT(void)    SavePGM_bmatrix(byte **m,       long  nrl, long  nrh, long  ncl, long  nch, char *filename);

IMAGE_EXPORT(rgb8 **) LoadPPM_rgb8matrix(char *filename, long *nrl, long *nrh, long *ncl, long *nch);
IMAGE_EXPORT(void)    SavePPM_rgb8matrix(rgb8 **m,       long  nrl, long  nrh, long  ncl, long  nch, char *filename);

#ifdef __cplusplus
}
#endif

#endif /* _NRIO_H_ */
