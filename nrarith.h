/* ----------------- */
/* --- NRARITH.H --- */
/* ----------------- */

/*
 * Copyright (c) 1994 LRE
 * Copyright (c) 1997-1999 LIS - EIA
 * Copyright (c) 1999-2000 IMASYS
 * Copyright (c) 2000- LIS-UPMC
 */

/*
 * Modif 17/01/2001 : add transpose_matrix
 * Modif 08/10/2001 : fix zero_vector bug when nl != 0
 * Modif 09/10/2001 : add min_pos & max_pos
 */

#ifndef _NRARITH_H_
#define _NRARITH_H_

#ifdef __cplusplus
#pragma message ("C++")
extern "C" {
#endif

#pragma message("- include nrarith.h")

static float maxarg1,maxarg2;
#define FMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ? (maxarg1) : (maxarg2))

static float minarg1,minarg2;
#define FMIN(a,b) (minarg1=(a),minarg2=(b),(minarg1) < (minarg2) ? (minarg1) : (minarg2))

static double dmaxarg1,dmaxarg2;
#define DMAX(a,b) (maxarg1=(a),maxarg2=(b),(maxarg1) > (maxarg2) ? (maxarg1) : (maxarg2))

static double dminarg1,dminarg2;
#define DMIN(a,b) (minarg1=(a),minarg2=(b),(minarg1) < (minarg2) ? (minarg1) : (minarg2))

static byte bmaxarg1,bmaxarg2;
#define BMAX(a,b) (bmaxarg1=(a),bmaxarg2=(b),(bmaxarg1) > (bmaxarg2) ? (bmaxarg1) : (bmaxarg2))

static byte bminarg1,bminarg2;
#define BMIN(a,b) (bminarg1=(a),bminarg2=(b),(bminarg1) < (bminarg2) ? (bminarg1) : (bminarg2))

static int imaxarg1,imaxarg2;
#define IMAX(a,b) (imaxarg1=(a),imaxarg2=(b),(imaxarg1) > (imaxarg2) ? (imaxarg1) : (imaxarg2))



/* ------------------ */
/* --- Conversion --- */
/* ------------------ */
IMAGE_EXPORT(void) split_rgb8vector  (rgb8  *x, long nl, long nh, byte  *r, byte  *g, byte  *b);
IMAGE_EXPORT(void) split_rgb32vector (rgb32 *x, long nl, long nh, int32 *r, int32 *g, int32 *b);

IMAGE_EXPORT(void) merge_rgb8vector (byte  *r, byte  *g, byte  *b, long nl, long nh, rgb8  *x);
IMAGE_EXPORT(void) merge_rgb32vector(int32 *r, int32 *g, int32 *b, long nl, long nh, rgb32 *x);

IMAGE_EXPORT(void) convert_i32vector_bvector    (int32 *x, long nl, long nh, byte   *y);
IMAGE_EXPORT(void) convert_i32vector_ui16vector (int32 *x, long nl, long nh, uint16 *y);

IMAGE_EXPORT(void) convert_ui32vector_bvector    (uint32 *x, long nl, long nh, byte   *y);
IMAGE_EXPORT(void) convert_ui32vector_ui16vector (uint32 *x, long nl, long nh, uint16 *y);

IMAGE_EXPORT(void) convert_rgb32vector_rgb8vector(rgb32  *x, long nl, long nh, rgb8   *y);

IMAGE_EXPORT(void) convert_bvector_rgb8vector(byte *x, long nl,  long nh, rgb8 *y);
IMAGE_EXPORT(void) convert_rgb8vector_bvector(rgb8 *x, long nl,  long nh, byte *y);

IMAGE_EXPORT(void) convert_bmatrix_rgb8matrix(byte **x, long nrl, long nrh, long ncl, long nch, rgb8 **y);
IMAGE_EXPORT(void) convert_rgb8matrix_bmatrix(rgb8 **x, long nrl, long nrh, long ncl, long nch, byte **y);

IMAGE_EXPORT(void) convert_ui16vector_rgb8vector(uint16 *x, long nl,  long nh, rgb8   *y);
IMAGE_EXPORT(void) convert_rgb8vector_ui16vector(rgb8   *x, long nl,  long nh, uint16 *y);

IMAGE_EXPORT(void) convert_ui16matrix_rgb8matrix(uint16 **x, long nrl, long nrh, long ncl, long nch, rgb8   **y);
IMAGE_EXPORT(void) convert_rgb8matrix_ui16matrix(rgb8   **x, long nrl, long nrh, long ncl, long nch, uint16 **y);

/* ------------ */
/* --- Zero --- */
/* ------------ */

IMAGE_EXPORT(void) zero_bvector    (byte   *v, long nl, long nh);
IMAGE_EXPORT(void) zero_svector    (short  *v, long nl, long nh);
IMAGE_EXPORT(void) zero_usvector   (ushort *v, long nl, long nh);
IMAGE_EXPORT(void) zero_i16vector  (int16  *v, long nl, long nh);
IMAGE_EXPORT(void) zero_ui16vector (uint16 *v, long nl, long nh);
IMAGE_EXPORT(void) zero_i32vector  (int32  *v, long nl, long nh);
IMAGE_EXPORT(void) zero_ivector    (int    *v, long nl, long nh);
IMAGE_EXPORT(void) zero_lvector    (long   *v, long nl, long nh);
IMAGE_EXPORT(void) zero_rgb8vector (rgb8   *v, long nl, long nh);
IMAGE_EXPORT(void) zero_rgb32vector(rgb32   *v, long nl, long nh);// pour les lut
IMAGE_EXPORT(void) zero_vvector    (void  **v, long nl, long nh);


IMAGE_EXPORT(void) zero_bmatrix   (byte   **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_smatrix   (short  **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_usmatrix  (ushort **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_imatrix   (int    **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_i32matrix (int32  **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_matrix    (float  **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_dmatrix   (double **m, long nrl,long nrh,long ncl,long nch);
IMAGE_EXPORT(void) zero_rgb8matrix(rgb8   **m, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(void) zero_matrix0(float  **m, long nrow,long ncol);

/* ------------ */
/* --- Init --- */
/* ------------ */
IMAGE_EXPORT(void) init_bvector_hexa(byte   *src, long nl, long nh, int32 init);
IMAGE_EXPORT(void) init_bvector     (byte   *src, long nl, long nh, char *init);
IMAGE_EXPORT(void) init_svector     (short  *src, long nl, long nh, char *init);
IMAGE_EXPORT(void) init_usvector    (ushort *src, long nl, long nh, char *init);

/* --------------------------- */
/* --- Fill with constante --- */
/* --------------------------- */
IMAGE_EXPORT(void) set_bvector    (byte   *v, long nl, long nh, byte   cte);
IMAGE_EXPORT(void) set_svector    (short  *v, long nl, long nh, short  cte);
IMAGE_EXPORT(void) set_usvector   (ushort *v, long nl, long nh, ushort cte);
IMAGE_EXPORT(void) set_i16vector  (int16  *v, long nl, long nh, int16  cte);
IMAGE_EXPORT(void) set_ui16vector (uint16 *v, long nl, long nh, uint16 cte);
IMAGE_EXPORT(void) set_ivector    (int    *v, long nl, long nh, int    cte);
IMAGE_EXPORT(void) set_uivector   (uint   *v, long nl, long nh, uint   cte);
IMAGE_EXPORT(void) set_i32vector  (int32  *v, long nl, long nh, int32  cte);
IMAGE_EXPORT(void) set_yi32vector (uint32 *v, long nl, long nh, uint32 cte);
IMAGE_EXPORT(void) set_vector     (float  *v, long nl, long nh, float  cte);
IMAGE_EXPORT(void) set_dvector    (double *v, long nl, long nh, double cte);
IMAGE_EXPORT(void) set_rgb8vector (rgb8   *v, long nl, long nh, rgb8   cte);
IMAGE_EXPORT(void) set_rgbx8vector(rgbx8  *v, long nl, long nh, rgbx8  cte);

IMAGE_EXPORT(void) set_bvector_j (byte   *v, long nl, long nh);
IMAGE_EXPORT(void) set_svector_j (short  *v, long nl, long nh);
IMAGE_EXPORT(void) set_usvector_j(ushort *v, long nl, long nh);
IMAGE_EXPORT(void) set_ivector_j (int    *v, long nl, long nh);
IMAGE_EXPORT(void) set_uivector_j(uint   *v, long nl, long nh);
IMAGE_EXPORT(void) set_vector_j  (float  *v, long nl, long nh);
IMAGE_EXPORT(void) set_dvector_j (double *v, long nl, long nh);

IMAGE_EXPORT(void) set_bmatrix    (byte   **m,long nrl,long nrh,long ncl, long nch, byte   cte);
IMAGE_EXPORT(void) set_smatrix    (short  **m,long nrl,long nrh,long ncl, long nch, short  cte);
IMAGE_EXPORT(void) set_usmatrix   (ushort **m,long nrl,long nrh,long ncl, long nch, ushort cte);
IMAGE_EXPORT(void) set_i16matrix  (int16  **m,long nrl,long nrh,long ncl, long nch, int16  cte);
IMAGE_EXPORT(void) set_ui16matrix (uint16 **m,long nrl,long nrh,long ncl, long nch, uint16 cte);
IMAGE_EXPORT(void) set_imatrix    (int    **m,long nrl,long nrh,long ncl, long nch, int    cte);
IMAGE_EXPORT(void) set_uimatrix   (uint   **m,long nrl,long nrh,long ncl, long nch, uint   cte);
IMAGE_EXPORT(void) set_i32matrix  (int32  **m,long nrl,long nrh,long ncl, long nch, int32  cte);
IMAGE_EXPORT(void) set_ui32matrix (uint32 **m,long nrl,long nrh,long ncl, long nch, uint32 cte);
IMAGE_EXPORT(void) set_matrix     (float  **m,long nrl,long nrh,long ncl, long nch, float  cte);
IMAGE_EXPORT(void) set_dmatrix    (double **m,long nrl,long nrh,long ncl, long nch, double cte);
IMAGE_EXPORT(void) set_rgb8matrix (rgb8   **m,long nrl,long nrh,long ncl, long nch, rgb8   cte);
IMAGE_EXPORT(void) set_rgbx8matrix(rgbx8  **m,long nrl,long nrh,long ncl, long nch, rgbx8  cte);

IMAGE_EXPORT(void) set_bmatrix_border1(byte **m,long nrl,long nrh,long ncl, long nch,         byte cte);
IMAGE_EXPORT(void) set_bmatrix_border (byte **m,long nrl,long nrh,long ncl, long nch, long n, byte cte);
/*
 * Initialisation des bords
 */
IMAGE_EXPORT(void) set_bmatrix_i (byte   **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) set_smatrix_i (short  **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) set_usmatrix_i(ushort **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) set_imatrix_i (int    **m,long nrl,long nrh,long ncl, long nch);
/*
 *      [1 1 1]   [nrl .. nrl]
 * m <- [2 2 2] = [...    ...]
 *      [3 3 3]   [nrh .. nrh]
 */

IMAGE_EXPORT(void) set_bmatrix_j (byte   **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) set_smatrix_j (short  **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) set_usmatrix_j(ushort **m,long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) set_imatrix_j (int    **m,long nrl,long nrh,long ncl, long nch);
/*
 *      [1 2 3]   [ncl .. nch]
 * m <- [1 2 3] = [ncl .. nch]
 *      [1 2 3]   [ncl .. nch]
 */

/* ----------------------- */
/* -- Rotation and Flip -- */
/* ----------------------- */
// no check performed on size, S and D must be different
IMAGE_EXPORT(void) lrotate_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch, byte   **D);
IMAGE_EXPORT(void) lrotate_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch, short  **D);
IMAGE_EXPORT(void) lrotate_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D);
IMAGE_EXPORT(void) lrotate_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch, int16  **D);
IMAGE_EXPORT(void) lrotate_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D);
IMAGE_EXPORT(void) lrotate_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch, int    **D);
IMAGE_EXPORT(void) lrotate_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch, uint   **D);
IMAGE_EXPORT(void) lrotate_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch, int32  **D);
IMAGE_EXPORT(void) lrotate_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D);
IMAGE_EXPORT(void) lrotate_matrix    (float  **S, long nrl,long nrh,long ncl, long nch, float  **D);
IMAGE_EXPORT(void) lrotate_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch, double **D);
IMAGE_EXPORT(void) lrotate_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch, rgb8   **D);

IMAGE_EXPORT(void) rrotate_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch, byte   **D);
IMAGE_EXPORT(void) rrotate_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch, short  **D);
IMAGE_EXPORT(void) rrotate_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D);
IMAGE_EXPORT(void) rrotate_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch, int16  **D);
IMAGE_EXPORT(void) rrotate_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D);
IMAGE_EXPORT(void) rrotate_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch, int    **D);
IMAGE_EXPORT(void) rrotate_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch, uint   **D);
IMAGE_EXPORT(void) rrotate_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch, int32  **D);
IMAGE_EXPORT(void) rrotate_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D);
IMAGE_EXPORT(void) rrotate_matrix    (float  **S, long nrl,long nrh,long ncl, long nch, float  **D);
IMAGE_EXPORT(void) rrotate_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch, double **D);
IMAGE_EXPORT(void) rrotate_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch, rgb8   **D);

IMAGE_EXPORT(void) lrotate1_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_matrix    (float  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) lrotate1_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(void) rrotate1_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_matrix    (float  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) rrotate1_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(void) hflip_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch, byte   **D);
IMAGE_EXPORT(void) hflip_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch, short  **D);
IMAGE_EXPORT(void) hflip_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D);
IMAGE_EXPORT(void) hflip_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch, int16  **D);
IMAGE_EXPORT(void) hflip_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D);
IMAGE_EXPORT(void) hflip_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch, int    **D);
IMAGE_EXPORT(void) hflip_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch, uint   **D);
IMAGE_EXPORT(void) hflip_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch, int32  **D);
IMAGE_EXPORT(void) hflip_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D);
IMAGE_EXPORT(void) hflip_matrix    (float  **S, long nrl,long nrh,long ncl, long nch, float  **D);
IMAGE_EXPORT(void) hflip_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch, double **D);
IMAGE_EXPORT(void) hflip_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch, rgb8   **D);

IMAGE_EXPORT(void) vflip_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch, byte   **D);
IMAGE_EXPORT(void) vflip_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch, short  **D);
IMAGE_EXPORT(void) vflip_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D);
IMAGE_EXPORT(void) vflip_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch, int16  **D);
IMAGE_EXPORT(void) vflip_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D);
IMAGE_EXPORT(void) vflip_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch, int    **D);
IMAGE_EXPORT(void) vflip_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch, uint   **D);
IMAGE_EXPORT(void) vflip_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch, int32  **D);
IMAGE_EXPORT(void) vflip_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D);
IMAGE_EXPORT(void) vflip_matrix    (float  **S, long nrl,long nrh,long ncl, long nch, float  **D);
IMAGE_EXPORT(void) vflip_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch, double **D);
IMAGE_EXPORT(void) vflip_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch, rgb8   **D);

IMAGE_EXPORT(void) hflip1_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_matrix    (float  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) hflip1_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(void) vflip1_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_matrix    (float  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) vflip1_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch);


/* ------------------- */
/* -- Transposition -- */
/* ------------------- */
// no check performed on size, S and D must be different
IMAGE_EXPORT(void) transpose_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch, byte   **D);
IMAGE_EXPORT(void) transpose_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch, short  **D);
IMAGE_EXPORT(void) transpose_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch, ushort **D);
IMAGE_EXPORT(void) transpose_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch, int16  **D);
IMAGE_EXPORT(void) transpose_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch, uint16 **D);
IMAGE_EXPORT(void) transpose_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch, int    **D);
IMAGE_EXPORT(void) transpose_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch, uint   **D);
IMAGE_EXPORT(void) transpose_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch, int32  **D);
IMAGE_EXPORT(void) transpose_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch, uint32 **D);
IMAGE_EXPORT(void) transpose_matrix    (float  **S, long nrl,long nrh,long ncl, long nch, float  **D);
IMAGE_EXPORT(void) transpose_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch, double **D);
IMAGE_EXPORT(void) transpose_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch, rgb8   **D);

// no check performed on size, S and D must be different
IMAGE_EXPORT(void) transpose1_bmatrix   (byte   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_smatrix   (short  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_usmatrix  (ushort **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_i16matrix (int16  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_ui16matrix(uint16 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_imatrix   (int    **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_uimatrix  (uint   **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_i32matrix (int32  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_ui32matrix(uint32 **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_matrix    (float  **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_dmatrix   (double **S, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(void) transpose1_rgb8matrix(rgb8   **S, long nrl,long nrh,long ncl, long nch);


IMAGE_EXPORT(void) transpose_bmatrix00(byte **m, long nrow, long ncol, byte **transposed);
IMAGE_EXPORT(void) transpose_bmatrix01(byte **m, long nrow, long ncol, byte **transposed);
IMAGE_EXPORT(void) transpose_bmatrix02(byte **m, long nrow, long ncol, byte **transposed);
IMAGE_EXPORT(void) transpose_bmatrix04(byte **m, long nrow, long ncol, byte **transposed);
IMAGE_EXPORT(void) transpose_bmatrix08(byte **m, long nrow, long ncol, byte **transposed);

IMAGE_EXPORT(void) transpose_matrix00(float **m, long nrow, long ncol, float **transposed);
IMAGE_EXPORT(void) transpose_matrix01(float **m, long nrow, long ncol, float **transposed);
IMAGE_EXPORT(void) transpose_matrix02(float **m, long nrow, long ncol, float **transposed);
IMAGE_EXPORT(void) transpose_matrix04(float **m, long nrow, long ncol, float **transposed);
IMAGE_EXPORT(void) transpose_matrix08(float **m, long nrow, long ncol, float **transposed);
/*
 * Sans loop-unrolling
 * Avec un loop-unrolling de 2, 4 ,8
 */

IMAGE_EXPORT(void) roll_svector(short *v, long nl, long nh);

/* ======================================================================== */
/* === Sort =============================================================== */
/* ======================================================================== */

IMAGE_EXPORT(void) sort_index_dvector_selection     (double *key, long nl, long nh, int *index);
IMAGE_EXPORT(void) sort_index_ivector_selection_min (int    *key, long nl, long nh, int *index);
IMAGE_EXPORT(void) sort_index_ivector_selection_max (int    *key, long nl, long nh, int *index);
IMAGE_EXPORT(void) sort_index_ivector_selection_kmin(int    *key, long nl, long nh, int *index, int k);
IMAGE_EXPORT(void) sort_index_ivector_selection_kmax(int    *key, long nl, long nh, int *index, int k);

IMAGE_EXPORT(void) sort_index_vector_selection_min (float    *key, long nl, long nh, int *index);
IMAGE_EXPORT(void) sort_index_vector_selection_max (float    *key, long nl, long nh, int *index);

/*
 * ATTENTION le tableau index DOIT etre initialise (et alloue)
 */

IMAGE_EXPORT(void) sort_dmatrix_selection (double *m, long nl, long nh);

IMAGE_EXPORT(void) sort_imatrix_selection2(int **m, long nl, long nh);
IMAGE_EXPORT(void) sort_imatrix_selection (int **m, long nrl, long nrh, long ncl, long nch, long nrow);

IMAGE_EXPORT(void) sort_imatrix_leftpart_selection2(int **m, long nl, long nh, long len);
/*
 * Sort the first len item of a 2-row matrix
 */

IMAGE_EXPORT(void) sort_index_imatrix_selection_kmin(int   **key, long nrl,long nrh,long ncl, long nch, int **index, int k);
IMAGE_EXPORT(void) sort_index_imatrix_selection_kmax(int   **key, long nrl,long nrh,long ncl, long nch, int **index, int k);
/*
 * appel de "sort_index_ivector_selection_k" pour chaque ligne
 * ATTENTION L'initialisation du tableau index est fait ici
 */

IMAGE_EXPORT(void) sortv_imatrix_selection_min(int **m, long nrl,long nrh,long ncl, long nch, long nc);
IMAGE_EXPORT(void) sortv_imatrix_selection_max(int **m, long nrl,long nrh,long ncl, long nch, long nc);

IMAGE_EXPORT(void) sortv_imatrix_selection_kmin(int **m, long nrl,long nrh,long ncl, long nch, long nc, int k);
IMAGE_EXPORT(void) sortv_imatrix_selection_kmax(int **m, long nrl,long nrh,long ncl, long nch, long nc, int k);

/*
 * tri vertical, de toutes les lignes
 * tri vertical, d'une partie des lignes
 */
IMAGE_EXPORT(void) sortv_index_imatrix_selection_max(int **key, long nrl,long nrh,long ncl, long nch, int *index, int nc);
IMAGE_EXPORT(void) sortv_index_imatrix_selection_min(int **key, long nrl,long nrh,long ncl, long nch, int *index, int nc);
/*
 * trie de la colonne nc de la matrice key, nc[ncl..nch]
 * la matrice reste inchangee, seule l'index est modifie
 */

IMAGE_EXPORT(void) sort_bvector_selection_min(byte *v, long nl, long nh);

/* ======================================================================== */
/* == Select = order/rank filter = median ================================= */
/* ======================================================================== */

IMAGE_EXPORT(byte) select_bvector   (byte *v, long nl, long nh, long k);
IMAGE_EXPORT(rgb8) select_rgb8vector(rgb8 *v, long nl, long nh, long k);

/* ======================================================================== */
/* === Operation unaire =================================================== */
/* ======================================================================== */
IMAGE_EXPORT(byte)   min_bvector  (byte   *v, long nl, long nh);
IMAGE_EXPORT(short)  min_svector  (short  *v, long nl, long nh);
IMAGE_EXPORT(ushort) min_usvector (ushort *v, long nl, long nh);
IMAGE_EXPORT(int)    min_ivector  (int    *v, long nl, long nh);
IMAGE_EXPORT(uint)   min_uivector (uint   *v, long nl, long nh);
IMAGE_EXPORT(int32)  min_i32vector(int32  *v, long nl, long nh);
IMAGE_EXPORT(float)  min_vector   (float  *v, long nl, long nh);
IMAGE_EXPORT(double) min_dvector  (double *v, long nl, long nh);

IMAGE_EXPORT(byte)   max_bvector  (byte   *v, long nl, long nh);
IMAGE_EXPORT(short)  max_svector  (short  *v, long nl, long nh);
IMAGE_EXPORT(ushort) max_usvector (ushort *v, long nl, long nh);
IMAGE_EXPORT(int)    max_ivector  (int    *v, long nl, long nh);
IMAGE_EXPORT(uint)   max_uivector (uint   *v, long nl, long nh);
IMAGE_EXPORT(int32)  max_i32vector(int32  *v, long nl, long nh);
IMAGE_EXPORT(float)  max_vector   (float  *v, long nl, long nh);
IMAGE_EXPORT(double) max_dvector  (double *v, long nl, long nh);

IMAGE_EXPORT(byte)   min_bvector_pos  (byte   *v, long nl, long nh, int *pos);
IMAGE_EXPORT(short)  min_svector_pos  (short  *v, long nl, long nh, int *pos);
IMAGE_EXPORT(ushort) min_usvector_pos (ushort *v, long nl, long nh, int *pos);
IMAGE_EXPORT(int)    min_ivector_pos  (int    *v, long nl, long nh, int *pos);
IMAGE_EXPORT(uint)   min_uivector_pos (uint   *v, long nl, long nh, int *pos);
IMAGE_EXPORT(int32)  min_i32vector_pos(int32  *v, long nl, long nh, int *pos);
IMAGE_EXPORT(float)  min_vector_pos   (float  *v, long nl, long nh, int *pos);
IMAGE_EXPORT(double) min_dvector_pos  (double *v, long nl, long nh, int *pos);

IMAGE_EXPORT(byte)   max_bvector_pos  (byte   *v, long nl, long nh, int *pos);
IMAGE_EXPORT(short)  max_svector_pos  (short  *v, long nl, long nh, int *pos);
IMAGE_EXPORT(ushort) max_usvector_pos (ushort *v, long nl, long nh, int *pos);
IMAGE_EXPORT(int)    max_ivector_pos  (int    *v, long nl, long nh, int *pos);
IMAGE_EXPORT(uint)   max_uivector_pos (uint   *v, long nl, long nh, int *pos);
IMAGE_EXPORT(int32)  max_i32vector_pos(int32  *v, long nl, long nh, int *pos);
IMAGE_EXPORT(float)  max_vector_pos   (float  *v, long nl, long nh, int *pos);
IMAGE_EXPORT(double) max_dvector_pos  (double *v, long nl, long nh, int *pos);

IMAGE_EXPORT(byte)   min_bmatrix (byte   **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(short)  min_smatrix (short  **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(ushort) min_usmatrix(ushort **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(int)    min_imatrix (int    **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(uint)   min_uimatrix(uint   **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(float)  min_matrix  (float  **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(double) min_dmatrix (double **m, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(byte)   max_bmatrix (byte   **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(short)  max_smatrix (short  **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(ushort) max_usmatrix(ushort **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(int)    max_imatrix (int    **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(uint)   max_uimatrix(uint   **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(float)  max_matrix  (float  **m, long nrl,long nrh,long ncl, long nch);
IMAGE_EXPORT(double) max_dmatrix (double **m, long nrl,long nrh,long ncl, long nch);

IMAGE_EXPORT(void) init_blut   (byte   *v, int nl, int nh, int n0, int n1, byte   k);
IMAGE_EXPORT(void) init_i16lut (int16  *v, int nl, int nh, int n0, int n1, int16  k);
IMAGE_EXPORT(void) init_ui16lut(uint16 *v, int nl, int nh, int n0, int n1, uint16 k);
IMAGE_EXPORT(void) init_rgb8lut(rgb8   *v, int nl, int nh, int n0, int n1, rgb8   k);

IMAGE_EXPORT(void) lut_bmatrix   ( byte   **S, long nrl, long nrh, long ncl, long nch, byte   *L, byte   **D);
IMAGE_EXPORT(void) lut_i16matrix ( int16  **S, long nrl, long nrh, long ncl, long nch, int16  *L, int16  **D);
IMAGE_EXPORT(void) lut_ui16matrix( uint16 **S, long nrl, long nrh, long ncl, long nch, uint16 *L, uint16 **D);
IMAGE_EXPORT(void) lut_rgb8matrix( rgb8   **S, long nrl, long nrh, long ncl, long nch, rgb8   *L, rgb8   **D);

IMAGE_EXPORT(void) lut_i16matrix_bmatrix (int16  **S, long nrl, long nrh, long ncl, long nch, int16  *L, byte **D);
IMAGE_EXPORT(void) lut_ui16matrix_bmatrix(uint16 **S, long nrl, long nrh, long ncl, long nch, uint16 *L, byte **D);
                 
IMAGE_EXPORT(void) histogram_bmatrix   (byte   **S, long nrl, long nrh, long ncl, long nch, int32 *H);
IMAGE_EXPORT(void) histogram_ui16matrix(uint16 **S, long nrl, long nrh, long ncl, long nch, int32 *H);
IMAGE_EXPORT(void) histogram_rgb8matrix(rgb8   **S, long nrl, long nrh, long ncl, long nch, rgb32 *H);

/* ----------- */
/* --- Add --- */
/* ----------- */
IMAGE_EXPORT(void) beta_sum_rgb32vector    (rgb32 *S,long nl,long nh, rgb32 *D);
IMAGE_EXPORT(void) beta_average_rgb32vector(rgb32 *S,long nl,long nh, rgb32 *D);

IMAGE_EXPORT(void) add_i32vector(int32 *S1, long nl,long nh, int32 *S2, int32 *D);
IMAGE_EXPORT(void) sub_i32vector(int32 *S1, long nl,long nh, int32 *S2, int32 *D);

IMAGE_EXPORT(void) cumulleft_i32vector  (int32 *S, long nl, long nh, int32 *D);
IMAGE_EXPORT(void) cumulleft_rgb32vector(rgb32 *S, long nl, long nh, rgb32 *D);

IMAGE_EXPORT(void) cumulright_i32vector  (int32 *S, long nl, long nh, int32 *D);
IMAGE_EXPORT(void) cumulright_rgb32vector(rgb32 *S, long nl, long nh, rgb32 *D);

IMAGE_EXPORT(void) mulc_i32vector     (int32 *S, long nl, long nh, int32 c, int32 *D);
IMAGE_EXPORT(void) mulc_rgb32vector   (rgb32 *S, long nl, long nh, int32 c, rgb32 *D);
IMAGE_EXPORT(void) divc_i32vector     (int32 *S, long nl, long nh, int32 c, int32 *D);
IMAGE_EXPORT(void) divc_rgb32vector   (rgb32 *S, long nl, long nh, int32 c, rgb32 *D);

IMAGE_EXPORT(void) mulfrac_i32vector  (int32 *S, long nl, long nh, int32 a, int32 b, int32 *D);
IMAGE_EXPORT(void) mulfrac_rgb32vector(rgb32 *S, long nl, long nh, int32 a, int32 b, rgb32 *D);


IMAGE_EXPORT(void) addc_bmatrix (byte   **src,long nrl,long nrh,long ncl, long nch, byte  cte, byte   **dst);
IMAGE_EXPORT(void) addc_smatrix (short  **src,long nrl,long nrh,long ncl, long nch, short cte, short  **dst);
IMAGE_EXPORT(void) addc_usmatrix(ushort **src,long nrl,long nrh,long ncl, long nch, short cte, ushort **dst);

IMAGE_EXPORT(void) addandc_bmatrix (byte   **src,long nrl,long nrh,long ncl, long nch, byte  cte, byte   **dst);
IMAGE_EXPORT(void) addandc_smatrix (short  **src,long nrl,long nrh,long ncl, long nch, short cte, short  **dst);
IMAGE_EXPORT(void) addandc_usmatrix(ushort **src,long nrl,long nrh,long ncl, long nch, short cte, ushort **dst);

IMAGE_EXPORT(void) addcnz_bmatrix(byte  **src,long nrl,long nrh,long ncl, long nch, byte  cte, byte  **dst);

IMAGE_EXPORT(void) and_bmatrix (byte  **src,long nrl,long nrh,long ncl, long nch, byte **cond, byte **dst);
IMAGE_EXPORT(void) and2_bmatrix(byte  **src,long nrl,long nrh,long ncl, long nch, byte **cond, byte **dst);

IMAGE_EXPORT(void) copyc_bmatrix(byte  **src,long nrl,long nrh,long ncl, long nch, byte **cond, byte c, byte **dst);

/*
 * copie dans src->dst si la condition est remplie
 * dst(i,j) = src(i,j) si cond(i,j) == c
 */

IMAGE_EXPORT(int) count_bmatrix(byte **m, long nrl,long nrh,long ncl, long nch);
/*
 * renvoie la somme des points de la matrice
 */

IMAGE_EXPORT(void) lowpart_smatrix (short  **X, long nrl,long nrh,long ncl, long nch, byte **Y);
IMAGE_EXPORT(void) lowpart_usmatrix(ushort **X, long nrl,long nrh,long ncl, long nch, byte **Y);

/* --------------------------- */
/* --- Operations binaires --- */
/* --------------------------- */

IMAGE_EXPORT(byte) compare_bmatrix (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2);
IMAGE_EXPORT(byte) compare_smatrix (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2);
IMAGE_EXPORT(byte) compare_usmatrix(ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2);
IMAGE_EXPORT(byte) compare_imatrix (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2);

/* ========================= */
/* === Logical operation === */
/* ========================= */

/* ----------- */
/* --- Not --- */
/* ----------- */
/* m2 = ! m2 */
IMAGE_EXPORT(void) not_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2);
IMAGE_EXPORT(void) not_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2);
IMAGE_EXPORT(void) not_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2);
IMAGE_EXPORT(void) not_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2);
IMAGE_EXPORT(void) not_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2);
IMAGE_EXPORT(void) not_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2);
IMAGE_EXPORT(void) not_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2);
IMAGE_EXPORT(void) not_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2);
IMAGE_EXPORT(void) not_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2);
IMAGE_EXPORT(void) not_matrix     (float  **m1, long nrl,long nrh,long ncl, long nch, float  **m2);
IMAGE_EXPORT(void) not_dmatrix    (double **m1, long nrl,long nrh,long ncl, long nch, double **m2);
IMAGE_EXPORT(void) not_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2);
IMAGE_EXPORT(void) not_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2);

/* ---------- */
/* --- Or --- */
/* ---------- */
/* m3 = m1 | m2 */

IMAGE_EXPORT(void) or_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2, byte    **m3);
IMAGE_EXPORT(void) or_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2, short   **m3);
IMAGE_EXPORT(void) or_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort  **m3);
IMAGE_EXPORT(void) or_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2, int16   **m3);
IMAGE_EXPORT(void) or_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16  **m3);
IMAGE_EXPORT(void) or_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2, int     **m3);
IMAGE_EXPORT(void) or_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2, uint    **m3);
IMAGE_EXPORT(void) or_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2, int32   **m3);
IMAGE_EXPORT(void) or_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32  **m3);
IMAGE_EXPORT(void) or_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2, rgb8    **m3);
IMAGE_EXPORT(void) or_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2, rgbx8   **m3);

IMAGE_EXPORT(void) orc_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   c, byte    **m2);
IMAGE_EXPORT(void) orc_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  c, short   **m2);
IMAGE_EXPORT(void) orc_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort  **m2);
IMAGE_EXPORT(void) orc_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  c, int16   **m2);
IMAGE_EXPORT(void) orc_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16  **m2);
IMAGE_EXPORT(void) orc_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    c, int     **m2);
IMAGE_EXPORT(void) orc_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   c, uint    **m2);
IMAGE_EXPORT(void) orc_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  c, int32   **m2);
IMAGE_EXPORT(void) orc_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32  **m2);
IMAGE_EXPORT(void) orc_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   c, rgb8    **m2);
IMAGE_EXPORT(void) orc_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  c, rgbx8   **m2);

/* ----------- */
/* --- Xor --- */
/* ----------- */
/* m3 = m1 ^ m2 */
IMAGE_EXPORT(void) xor_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2, byte    **m3);
IMAGE_EXPORT(void) xor_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2, short   **m3);
IMAGE_EXPORT(void) xor_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort  **m3);
IMAGE_EXPORT(void) xor_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2, int16   **m3);
IMAGE_EXPORT(void) xor_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16  **m3);
IMAGE_EXPORT(void) xor_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2, int     **m3);
IMAGE_EXPORT(void) xor_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2, uint    **m3);
IMAGE_EXPORT(void) xor_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2, int32   **m3);
IMAGE_EXPORT(void) xor_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32  **m3);
IMAGE_EXPORT(void) xor_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2, rgb8    **m3);
IMAGE_EXPORT(void) xor_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2, rgbx8   **m3);
/* m2 = m1 ^ c */
IMAGE_EXPORT(void) xorc_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   c, byte    **m2);
IMAGE_EXPORT(void) xorc_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  c, short   **m2);
IMAGE_EXPORT(void) xorc_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort  **m2);
IMAGE_EXPORT(void) xorc_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  c, int16   **m2);
IMAGE_EXPORT(void) xorc_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16  **m2);
IMAGE_EXPORT(void) xorc_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    c, int     **m2);
IMAGE_EXPORT(void) xorc_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   c, uint    **m2);
IMAGE_EXPORT(void) xorc_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  c, int32   **m2);
IMAGE_EXPORT(void) xorc_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32  **m2);
IMAGE_EXPORT(void) xorc_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   c, rgb8    **m2);
IMAGE_EXPORT(void) xorc_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  c, rgbx8   **m2);

/* ----------- */
/* --- And --- */
/* ----------- */
/* m3 = m1 & m2 */
IMAGE_EXPORT(void) and_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2, byte    **m3);
IMAGE_EXPORT(void) and_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2, short   **m3);
IMAGE_EXPORT(void) and_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort  **m3);
IMAGE_EXPORT(void) and_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2, int16   **m3);
IMAGE_EXPORT(void) and_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16  **m3);
IMAGE_EXPORT(void) and_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2, int     **m3);
IMAGE_EXPORT(void) and_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2, uint    **m3);
IMAGE_EXPORT(void) and_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2, int32   **m3);
IMAGE_EXPORT(void) and_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32  **m3);
IMAGE_EXPORT(void) and_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2, rgb8    **m3);
IMAGE_EXPORT(void) and_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2, rgbx8   **m3);
/* m2 = m1 & c */
IMAGE_EXPORT(void) andc_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   c, byte    **m2);
IMAGE_EXPORT(void) andc_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  c, short   **m2);
IMAGE_EXPORT(void) andc_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort  **m2);
IMAGE_EXPORT(void) andc_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  c, int16   **m2);
IMAGE_EXPORT(void) andc_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16  **m2);
IMAGE_EXPORT(void) andc_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    c, int     **m2);
IMAGE_EXPORT(void) andc_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   c, uint    **m2);
IMAGE_EXPORT(void) andc_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  c, int32   **m2);
IMAGE_EXPORT(void) andc_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32  **m2);
IMAGE_EXPORT(void) andc_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   c, rgb8    **m2);
IMAGE_EXPORT(void) andc_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  c, rgbx8   **m2);

/* ------------ */
/* --- Nand --- */
/* ------------ */
/* m3 = m1  m2 */
IMAGE_EXPORT(void) nand_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2, byte    **m3);
IMAGE_EXPORT(void) nand_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2, short   **m3);
IMAGE_EXPORT(void) nand_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort  **m3);
IMAGE_EXPORT(void) nand_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2, int16   **m3);
IMAGE_EXPORT(void) nand_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16  **m3);
IMAGE_EXPORT(void) nand_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2, int     **m3);
IMAGE_EXPORT(void) nand_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2, uint    **m3);
IMAGE_EXPORT(void) nand_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2, int32   **m3);
IMAGE_EXPORT(void) nand_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32  **m3);
IMAGE_EXPORT(void) nand_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2, rgb8    **m3);
IMAGE_EXPORT(void) nand_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2, rgbx8   **m3);
/* m3 = m1  m2 */
IMAGE_EXPORT(void) nandc_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   c, byte    **m2);
IMAGE_EXPORT(void) nandc_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  c, short   **m2);
IMAGE_EXPORT(void) nandc_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort c, ushort  **m2);
IMAGE_EXPORT(void) nandc_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  c, int16   **m2);
IMAGE_EXPORT(void) nandc_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 c, uint16  **m2);
IMAGE_EXPORT(void) nandc_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    c, int     **m2);
IMAGE_EXPORT(void) nandc_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   c, uint    **m2);
IMAGE_EXPORT(void) nandc_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  c, int32   **m2);
IMAGE_EXPORT(void) nandc_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 c, uint32  **m2);
IMAGE_EXPORT(void) nandc_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   c, rgb8    **m2);
IMAGE_EXPORT(void) nandc_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  c, rgbx8   **m2);

/* ----------- */
/* --- Add --- */
/* ----------- */
/* m3 = m1 + m2 */
IMAGE_EXPORT(void) add_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2, byte    **m3);
IMAGE_EXPORT(void) add_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2, short   **m3);
IMAGE_EXPORT(void) add_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort  **m3);
IMAGE_EXPORT(void) add_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2, int16   **m3);
IMAGE_EXPORT(void) add_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16  **m3);
IMAGE_EXPORT(void) add_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2, int     **m3);
IMAGE_EXPORT(void) add_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2, uint    **m3);
IMAGE_EXPORT(void) add_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2, int32   **m3);
IMAGE_EXPORT(void) add_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32  **m3);
IMAGE_EXPORT(void) add_matrix     (float  **m1, long nrl,long nrh,long ncl, long nch, float  **m2, float   **m3);
IMAGE_EXPORT(void) add_dmatrix    (double **m1, long nrl,long nrh,long ncl, long nch, double **m2, double  **m3);
IMAGE_EXPORT(void) add_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2, rgb8    **m3);
IMAGE_EXPORT(void) add_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2, rgbx8   **m3);

/* ----------- */
/* --- Sub --- */
/* ----------- */
/* m3 = m1 - m2 */
IMAGE_EXPORT(void) sub_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, byte   **m2, byte    **m3);
IMAGE_EXPORT(void) sub_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, short  **m2, short   **m3);
IMAGE_EXPORT(void) sub_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, ushort **m2, ushort  **m3);
IMAGE_EXPORT(void) sub_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int16  **m2, int16   **m3);
IMAGE_EXPORT(void) sub_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, uint16 **m2, uint16  **m3);
IMAGE_EXPORT(void) sub_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int    **m2, int     **m3);
IMAGE_EXPORT(void) sub_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, uint   **m2, uint    **m3);
IMAGE_EXPORT(void) sub_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  **m2, int32   **m3);
IMAGE_EXPORT(void) sub_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, uint32 **m2, uint32  **m3);
IMAGE_EXPORT(void) sub_matrix     (float  **m1, long nrl,long nrh,long ncl, long nch, float  **m2, float   **m3);
IMAGE_EXPORT(void) sub_dmatrix    (double **m1, long nrl,long nrh,long ncl, long nch, double **m2, double  **m3);
IMAGE_EXPORT(void) sub_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb8   **m2, rgb8    **m3);
IMAGE_EXPORT(void) sub_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx8  **m2, rgbx8   **m3);

/* --------------- */
/* --- MulFrac --- */
/* --------------- */
// m2 = (a*m1)/b
IMAGE_EXPORT(void) mulfrac_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, byte    **m2);
IMAGE_EXPORT(void) mulfrac_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, short   **m2);
IMAGE_EXPORT(void) mulfrac_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, ushort  **m2);
IMAGE_EXPORT(void) mulfrac_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, int16   **m2);
IMAGE_EXPORT(void) mulfrac_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, uint16  **m2);
IMAGE_EXPORT(void) mulfrac_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, int     **m2);
IMAGE_EXPORT(void) mulfrac_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, uint    **m2);
IMAGE_EXPORT(void) mulfrac_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, int32   **m2);
IMAGE_EXPORT(void) mulfrac_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  b, uint32  **m2);
IMAGE_EXPORT(void) mulfrac_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb32  a, rgb32  b, rgb8    **m2);
IMAGE_EXPORT(void) mulfrac_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx32 a, rgbx32 b, rgbx8   **m2);

IMAGE_EXPORT(void) mulfrack_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 b, rgb8    **m2);
IMAGE_EXPORT(void) mulfrack_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 b, rgbx8   **m2);

/* ---------------- */
/* --- MulShift --- */
/* ---------------- */
// m3 = (a*m1)>>s
IMAGE_EXPORT(void) mulshift_bmatrix    (byte   **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, byte    **m2);
IMAGE_EXPORT(void) mulshift_smatrix    (short  **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, short   **m2);
IMAGE_EXPORT(void) mulshift_usmatrix   (ushort **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, ushort  **m2);
IMAGE_EXPORT(void) mulshift_i16matrix  (int16  **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, int16   **m2);
IMAGE_EXPORT(void) mulshift_ui16matrix (uint16 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, uint16  **m2);
IMAGE_EXPORT(void) mulshift_imatrix    (int    **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, int     **m2);
IMAGE_EXPORT(void) mulshift_uimatrix   (uint   **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, uint    **m2);
IMAGE_EXPORT(void) mulshift_i32matrix  (int32  **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, int32   **m2);
IMAGE_EXPORT(void) mulshift_ui32matrix (uint32 **m1, long nrl,long nrh,long ncl, long nch, int32  a, int32  s, uint32  **m2);
IMAGE_EXPORT(void) mulshift_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, rgb32  a, rgb32  s, rgb8    **m2);
IMAGE_EXPORT(void) mulshift_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, rgbx32 a, rgbx32 s, rgbx8   **m2);

IMAGE_EXPORT(void) mulshiftk_rgb8matrix (rgb8   **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 s, rgb8    **m2);
IMAGE_EXPORT(void) mulshiftk_rgbx8matrix(rgbx8  **m1, long nrl,long nrh,long ncl, long nch, int32 a, int32 s, rgbx8   **m2);

IMAGE_EXPORT(void) rd_rotate_i16cube(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D);
IMAGE_EXPORT(void) ld_rotate_i16cube(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D);
IMAGE_EXPORT(void) lr_rotate_i16cube(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D);
IMAGE_EXPORT(void) rr_rotate_i16cube(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D);
IMAGE_EXPORT(void) lc_rotate_i16cube(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D);
IMAGE_EXPORT(void) rc_rotate_i16cube(int16 ***S, long ndl, long ndh, long nrl,long nrh,long ncl, long nch, int16 ***D);
/*
 * from NRC
 */

IMAGE_EXPORT(void) quadratic_error_smatrix(short **m1,long nrl,long nrh,long ncl, long nch, short **m2, int **m3);

#ifdef __cplusplus
}
#endif

#endif /* _NRUTIL_H_ */
