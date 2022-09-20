/* ------------- */
/* --- def.h --- */
/* ------------- */

/*
 * Copyright (c) 2000, Lionel Lacassagne LIS-UPMC + Imasys
 * Modif : 15/01/2001 : rgb16, rgb32 are now signed (int16, int32)
 * modif : 22/02/2001 : new types : float32 & float64
 */

#ifndef __DEF_H__
#define __DEF_H__

#ifdef __cplusplus
#pragma message ("C++")
extern "C" {
#endif

#pragma message ("- ** include def.h **")

/* ------------------- */
/* --- Exportation --- */
/* ------------------- */
#define IMAGE_EXPORT(x) x
#define GPC_EXPORT(x) x __stdcall

#pragma message("GPC_EXPORT == __stdcall")
//#define IMAGE_EXPORT(x) x __stdcall

/* ---------------- */
/* --- Compiler --- */
/* ---------------- */

#define COMPILER VISUAL
//#define COMPILER CODEWARRIOR
//#define COMPILER INTEL
//#define COMPILER KCC
//#define COMPILER GCC
/*#if COMPILER == VISUAL
#pragma message ("Info : Visual compiler")
#endif
#if COMPILER == INTEL
#pragma message ("Info : Intel compiler")
#endif
#if COMPILER == CODEWARRIOR
#pragma message ("Info : Codewarrior compiler")
#endif
#if COMPILER == KCC
#pragma message ("Info : KCC compiler")
#endif
#if COMPILER == GCC
#pragma message ("Info : GCC compiler")
#endif
*/
/* --------------------- */
/* --- Progress Info --- */
/* --------------------- */

#define PROGRESS_INFO_ENABLED

#ifdef PROGRESS_INFO_ENABLED
#define PROGRESS_INFO(str, i, i0, i1) // ProgressInfo(str, i,i0, i1);
#else 
#define PROGRESS_INFO(str, i, i0, i1) // no progress
#endif

/* ------------- */
/* --- Debug --- */
/* ------------- */

#ifdef _DEBUG
#pragma message ("Info : DEBUG is ON")
#define LL_DEBUG(x) x
#define DEBUG(x) x
#define VERBOSE(x) x
#define LL_OPTIMIZE(x)
//#define FUNCTION_NAME(x) NameFunction(x)
#define FUNCTION_NAME(x)
#define NAME_FUNCTION(x)
#endif /* _DEBUG */

/* --------------- */
/* --- Release --- */
/* --------------- */

#ifdef NDEBUG
#pragma message ("Info : DEBUG is OFF")
#define LL_DEBUG(x) 
#define DEBUG(x)
#define VERBOSE(x)
#define LL_OPTIMIZE(x) x
#define FUNCTION_NAME(x)
#define NAME_FUNCTION(x)
#endif /* NDEBUG */

#define PI 3.1415926535897932384626433832795028841972
/* pi par Donald E. Knuth
 * PI 3.14159.26535.89793.23846.26433.83279.50288.41972
 */

/* --------------------- */
/* --- Error Handler --- */
/* --------------------- */
#define RCCHECK(rc) if(rc) return rc;

/* ---------------- */
/* --- Modifier --- */
/* ---------------- */
#ifndef ROUTINE
#ifndef _cplusplus
#define ROUTINE __inline
#define ROUTINE_EXPORT(X) __inline x
#define GPC_ROUTINE_EXPORT(x) __inline x __stdcall
#else
#define ROUTINE inline
#define ROUTINE_EXPORT(X) inline x
#define GPC_ROUTINE_EXPORT(x) inline x __stdcall
#endif
#endif

#ifndef PRIVATE
#define PRIVATE static
#else
#pragma message("  ATTENTION : PRIVATE  already defined")
#endif

#ifndef PUBLIC
#define PUBLIC
#else
#pragma message("  ATTENTION : PUBLIC  already defined")
#endif

/*#ifndef BOOLEAN
#define BOOLEAN int
#else
#pragma message("  ATTENTION : BOOLEAN  already defined")
#endif/**/

typedef unsigned char BOOLEAN;
typedef unsigned char boolean;
typedef          int  BOOL;
#pragma message("boolean")


#ifndef TRUE
#define TRUE 1
#else
#pragma message("  ATTENTION : TRUE  already defined")
#endif

#ifndef FALSE
#define FALSE 0
#else
#pragma message("  ATTENTION : FALSE  already defined")
#endif

/* ------------------------- */
/* --- (un)signed C type --- */
/* ------------------------- */

#ifndef BYTE_AS_UNSIGNED_CHAR
#define BYTE_AS_UNSIGNED_CHAR
typedef unsigned char byte;
//#pragma message("typedef unsigned char byte")
#else
#pragma message("  ATTENTION : BYTE_AS_UNSIGNED_CHAR already defined")
#endif

#ifndef SBYTE_AS_SIGNED_CHAR
#define SBYTE_AS_SIGNED_CHAR
typedef signed char sbyte;
//#pragma message("typedef signed char sbyte")
#else
#pragma message("  ATTENTION : SBYTE_AS_SIGNED_CHAR already defined")
#endif

#ifndef USHORT_AS_UNSIGNED_SHORT
#define USHORT_AS_UNSIGNED_SHORT
typedef unsigned short ushort;
//#pragma message("typedef unsigned short ushort")
#else
#pragma message("  ATTENTION : USHORT_AS_UNSIGNED_SHORT already defined")
#endif

#ifndef SSHORT_AS_SIGNED_SHORT
#define SSHORT_AS_SIGNED_SHORT
typedef signed short sshort;
//#pragma message("typedef signed short sshort")
#else
#pragma message("  ATTENTION : SSHORT_AS_SIGNED_SHORT already defined")
#endif

#ifndef UINT_AS_UNSIGNED_INT
#define UINT_AS_UNSIGNED_INT
typedef unsigned int uint;
//#pragma message("typedef unsigned int uint")
#else
#pragma message("  ATTENTION : UINT_AS_UNSIGNED_INT already defined")
#endif

#ifndef SINT_AS_SIGNED_INT
#define SINT_AS_SIGNED_INT
typedef signed int sint;
//#pragma message("typedef signed int sint;")
#else
#pragma message("  ATTENTION : SINT_AS_SIGNED_INT already defined")
#endif
/* ---------------- */
/* --- bitfield --- */
/* ---------------- */
typedef struct {
  unsigned int b0  : 1;
  unsigned int b1  : 1;
  unsigned int b2  : 1;
  unsigned int b3  : 1;
  unsigned int b4  : 1;
  unsigned int b5  : 1;
  unsigned int b6  : 1;
  unsigned int b7  : 1;
  unsigned int b8  : 1;
  unsigned int b9  : 1;
  unsigned int b10 : 1;
  unsigned int b11 : 1;
  unsigned int b12 : 1;
  unsigned int b13 : 1;
  unsigned int b14 : 1;
  unsigned int b15 : 1;
  unsigned int b16 : 1;
  unsigned int b17 : 1;
  unsigned int b18 : 1;
  unsigned int b19 : 1;
  unsigned int b20 : 1;
  unsigned int b21 : 1;
  unsigned int b22 : 1;
  unsigned int b23 : 1;
  unsigned int b24 : 1;
  unsigned int b25 : 1;
  unsigned int b26 : 1;
  unsigned int b27 : 1;
  unsigned int b28 : 1;
  unsigned int b29 : 1;
  unsigned int b30 : 1;
  unsigned int b31 : 1;
} bitfield32;

typedef struct {
  unsigned int b0  : 1;
  unsigned int b1  : 1;
  unsigned int b2  : 1;
  unsigned int b3  : 1;
  unsigned int b4  : 1;
  unsigned int b5  : 1;
  unsigned int b6  : 1;
  unsigned int b7  : 1;
  unsigned int b8  : 1;
  unsigned int b9  : 1;
  unsigned int b10 : 1;
  unsigned int b11 : 1;
  unsigned int b12 : 1;
  unsigned int b13 : 1;
  unsigned int b14 : 1;
  unsigned int b15 : 1;
} bitfield16;
    
typedef struct {
  unsigned int b0  : 1;
  unsigned int b1  : 1;
  unsigned int b2  : 1;
  unsigned int b3  : 1;
  unsigned int b4  : 1;
  unsigned int b5  : 1;
  unsigned int b6  : 1;
  unsigned int b7  : 1;
} bitfield8;
   
/* ------------------------------- */
/* --- 8, 16, 32, 64 bit types --- */
/* ------------------------------- */

#define INT8_MIN UCHAR_MIN
#define INT8_MAX UCHAR_MAX

#define INT16_MIN SHRT_MIN
#define INT16_MAX SHRT_MAX

#define INT32_MIN INT_MIN
#define INT32_MAX INT_MAX

#define INT64_MIN _I64_MIN
#define INT64_MAX _I64_MAX

#ifndef INT8_AS_CHAR
#define INT8_AS_CHAR
typedef          char  int8;
typedef   signed char sint8;
typedef unsigned char uint8;
#pragma message("int8 as char")
#else
#pragma message("  ATTENTION : INT8_AS_CHAR already defined")
#endif

#ifndef INT16_AS_SHORT
#define INT16_AS_SHORT
typedef          short  int16;
typedef   signed short sint16;
typedef unsigned short uint16;
#pragma message("int16 as short")
#else
#pragma message("  ATTENTION : INT16_AS_SHORT already defined")
#endif

#ifndef INT32_AS_INT
#define INT32_AS_INT
typedef          int  int32;
typedef   signed int sint32;
typedef unsigned int uint32;
#pragma message("int32 as int")
#else
#pragma message("  ATTENTION : INT32_AS_INT already defined")
#endif

#ifndef INT64_AS_INT64
#define INT64_AS_INT64

//#if COMPILER == VISUAL || COMPILER == INTEL
//typedef          __int64  int64;
//typedef   signed __int64 sint64;
//typedef unsigned __int64 uint64;
//#endif
/*#if COMPILER == CODEWARRIOR
typedef          long long  int64;
typedef   signed long long sint64;
typedef unsigned long long uint64;
#endif/**/
#else
#pragma message("  ATTENTION : INT64_AS_INT64 already defined")
#endif

#ifndef FLOAT32_AS_FLOAT
#define FLOAT32_AS_FLOAT
typedef          float  float32;
#pragma message("float32 as float")
#else
#pragma message("  ATTENTION : FLOAT32_AS_FLOAT already defined")
#endif

#ifndef FLOAT64_AS_DOUBLE
#define FLOAT64_AS_DOUBLE
typedef          double  double32;
#pragma message("float64 as double")
#else
#pragma message("  ATTENTION : FLOAT64_AS_DOUBLE already defined")
#endif

/* --------------------- */
/* --- RGB, BGR type --- */
/* --------------------- */
typedef struct { byte  r; byte  g; byte  b; } rgb8;
//typedef struct { byte  b; byte  g; byte  r; } rgb8;
typedef struct { int16 r; int16 g; int16 b; } rgb16;
typedef struct { int32 r; int32 g; int32 b; } rgb32;

typedef struct { byte  b; byte  g; byte  r; } bgr8;
typedef struct { int16 b; int16 g; int16 r; } bgr16;
typedef struct { int32 b; int32 g; int32 r; } bgr32;

typedef struct { byte  r; byte  g; byte  b; byte  x; } rgbx8;
typedef struct { int16 r; int16 g; int16 b; int16 x; } rgbx16;
typedef struct { int32 r; int32 g; int32 b; int32 x; } rgbx32;

typedef struct { byte  x; byte  b; byte  g; byte  r; } bgrx8;
typedef struct { int16 x; int16 b; int16 g; int16 r; } bgrx16;
typedef struct { int32 x; int32 b; int32 g; int32 r; } bgrx32;

/* ------------ */
/* --- Cast --- */
/* ------------ */
/*
#ifndef BYTE
#define BYTE (byte)
#else
#pragma message("  ATTENTION : BYTE already defined")
#endif

#ifndef INT8
#define INT8 (int8)
#else
#pragma message("  ATTENTION : INT8 already defined")
#endif

#ifndef UINT8
#define UINT8 (uint8)
#else
#pragma message("  ATTENTION : UINT8 already defined")
#endif

#ifndef INT16
#define INT16 (int16)
#else
#pragma message("  ATTENTION : INT16 already defined")
#endif

#ifndef UINT16
#define UINT16 (uint16)
#else
#pragma message("  ATTENTION : UINT16 already defined")
#endif

#ifndef INT32
#define INT32 (int32)
#else
#pragma message("  ATTENTION : INT32 already defined")
#endif

#ifndef UINT32
#define UINT32 (uint32)
#else
#pragma message("  ATTENTION : UINT32 already defined")
#endif
/**/
/* ----------------- */
/* --- RGB Macro --- */
/* ----------------- */

#define RGB32CAST8(s,d) d.r=(byte)s.r; d.g=(byte)s.g; d.b=(byte)s.b 
#define RGBX32CAST8(s,d) d.r=(byte)s.r; d.g=(byte)s.g; d.b=(byte)s.b; d.x=(byte)s.x  

#define RGB8_NOT(s,d)      d.r=!s.r;       d.g=!s.g;       d.b=!s.b
#define RGB8_OR(s1,s2,d)   d.r=s1.r|s2.r;  d.g=s1.g|s2.g;  d.b=s1.b|s2.b
#define RGB8_XOR(s1,s2,d)  d.r=s1.r^s2.r;  d.g=s1.g^s2.g;  d.b=s1.b^s2.b
#define RGB8_AND(s1,s2,d)  d.r=s1.r&s2.r;  d.g=s1.g&s2.g;  d.b=s1.b&s2.b
#define RGB8_NAND(s1,s2,d) d.r=!(s1.r&s2.r); d.g=!(s1.g&s2.g); d.b=!(s1.b&s2.b)

#define RGBX8_NOT(s,d)      d.r=!s.r;       d.g=!s.g;       d.b=!s.b;       d.x=!s.x
#define RGBX8_OR(s1,s2,d)   d.r=s1.r|s2.r;  d.g=s1.g|s2.g;  d.b=s1.b|s2.b;   d.x=s1.x|s2.x
#define RGBX8_XOR(s1,s2,d)  d.r=s1.r^s2.r;  d.g=s1.g^s2.g;  d.b=s1.b^s2.b;   d.x=s1.x^s2.x
#define RGBX8_AND(s1,s2,d)  d.r=s1.r&s2.r;  d.g=s1.g&s2.g;  d.b=s1.b&s2.b;   d.x=s1.x&s2.x
#define RGBX8_NAND(s1,s2,d) d.r=!(s1.r&s2.r); d.g=!(s1.g&s2.g); d.b=!(s1.b&s2.b);  d.x=!(s1.x&s2.x)

#define RGB8_ZERO(s) s.r=0; s.g=0; s.b=0
#define RGBX8_ZERO(s) s.r=0; s.g=0; s.b=0; s.x=0

#define RGB8_NEG(s,d) d.r=-s.r; d.g=-s.g; d.b=-s.b
#define RGBX8_NEG(s,d) d.r=-s.r; d.g=-s.g; d.b=-s.b; d.x=-s.x

#define RGB8_ABS(s,d) d.r=abs(s.r); d.g=abs(s.g); d.b=abs(s.b)
#define RGBX8_ABS(s,d) d.r=abs(s.r); d.g=abs(s.g); d.b=abs(s.b); d.x=abs(s.x)

#define RGB8_SAT(s, sat, d)  if(s.r>sat.r) d.r=sat.r; if(s.g>sat.g) d.g=sat.g; if(s.b>sat.b) d.b=sat.b 
#define RGB8_SATK(s, sat, d) if(s.r>sat)   d.r=sat;   if(s.g>sat)   d.g=sat;   if(s.b>sat)   d.b=sat; 

#define RGBX8_SAT(s, sat, d)  if(s.r>sat.r) d.r=sat.r; if(s.g>sat.g) d.g=sat.g; if(s.b>sat.b) d.b=sat.b; if(s.x>sat.x) s.x=sat.x
#define RGBX8_SATK(s, sat, d) if(s.r>sat)   d.r=sat;   if(s.g>sat)   d.g=sat;   if(s.b>sat)   d.b=sat;   if(s.x>sat)     s.x=sat

#define RGB8_ADDK(s,c,d) d.r=s.r+c; d.g=s.g+c; d.b=s.b+c
#define RGB8_SUBK(s,c,d) d.r=s.r-c; d.g=s.g-c; d.b=s.b-c
#define RGB8_MULK(s,c,d) d.r=s.r*c; d.g=s.g*c; d.b=s.b*c
#define RGB8_DIVK(s,c,d) d.r=s.r/c; d.g=s.g/c; d.b=s.b/c

#define RGB8_ADD(s1,s2,d) d.r=s1.r+s2.r; d.g=s1.g+s2.g; d.b=s1.b+s2.b
#define RGB8_SUB(s1,s2,d) d.r=s1.r-s2.r; d.g=s1.g-s2.g; d.b=s1.b-s2.b
#define RGB8_MUL(s1,s2,d) d.r=s1.r*s2.r; d.g=s1.g*s2.g; d.b=s1.b*s2.b
#define RGB8_DIV(s1,s2,d) d.r=s1.r/s2.r; d.g=s1.g/s2.g; d.b=s1.b/s2.b

#define RGB8_SET(s,d) d.r=s.r; d.g=s.g; d.b=s.b 
#define RGB8_SETNEG(s,d) d.r=-s.r; d.g=-s.g; d.b=-s.b 

#define RGB8_ACC(s,d) d.r+=s.r; d.g+=s.g; d.b+=s.b
#define RGB8_SCC(s,d) d.r-=s.r; d.g-=s.g; d.b-=s.b

#define RGB8_MUL2(s, d) d.r=s.r<<1; d.g=s.g<<1; d.b=s.b<<1
#define RGB8_MUL4(s, d) d.r=s.r<<2; d.g=s.g<<2; d.b=s.b<<2
#define RGB8_MUL6(s, d) d.r=6*s.r;  d.g=6*s.g;  d.b=6*s.b

#define RGB8_MAC(s,c,d) d.r+=c*s.r; d.g+=c*s.g;d.b+=c*s.b

#define RGB8_MAC2(s, d) d.r+=s.r<<1; d.g+=s.g<<1; d.b+=s.b<<1
#define RGB8_MAC4(s, d) d.r+=s.r<<2; d.g+=s.g<<2; d.b+=s.b<<2
#define RGB8_MAC6(s, d) d.r+=6*s.r;  d.g+=6*s.g;  d.b+=6*s.b

#define RGB8_MSC(s,c,d) d.r-=c*s.r; d.g-=c*s.g;d.b-=c*s.b

#define RGB8_MSC2(s, d) d.r-=s.r<<1; d.g-=s.g<<1; d.b-=s.b<<1
#define RGB8_MSC4(s, d) d.r-=s.r<<2; d.g-=s.g<<2; d.b-=s.b<<2
#define RGB8_MSC6(s, d) d.r-=6*s.r;  d.g-=6*s.g;  d.b-=6*s.b

#define RGB8_DIV2(s, d) d.r=s.r>>1; d.g=s.g>>1; d.b=s.b>>1
#define RGB8_DIV4(s, d) d.r=s.r>>2; d.g=s.g>>2; d.b=s.b>>2

#define RGB8_MULFRAC(s, a, b, d) d.r=(a.r*s.r)/b.r; d.g=(a.g*s.g)/b.g; d.b=(a.b*s.b)/b.b
#define RGB8_MULFRACK(s, a, b, d) d.r=(a*s.r)/b; d.g=(a*s.g)/b; d.b=(a*s.b)/b

#define RGBX8_MULFRAC(s, a, b, d) d.r=(a.r*s.r)/b.r; d.g=(a.g*s.g)/b.g; d.b=(a.b*s.b)/b.b;  d.x=(a.x*s.x)/b.x
#define RGBX8_MULFRACK(s, a, b, d) d.r=(a*s.r)/b; d.g=(a*s.g)/b; d.b=(a*s.b)/b;  d.x=(a*s.x)/b

#define RGB8_MULSHIFT(s, a, n, d) d.r=(a.r*s.r)>>n.r; d.g=(a.g*s.g)>>n.g; d.b=(a.b*s.b)>>n.b
#define RGBX8_MULSHIFT(s, a, n, d) d.r=(a.r*s.r)>>n.r; d.g=(a.g*s.g)>>n.g; d.b=(a.b*s.b)>>n.b;  d.x=(a.x*s.x)>>n.x

#define RGB8_MULSHIFTK(s, a, n, d) d.r=(a*s.r)>>n; d.g=(a*s.g)>>n; d.b=(a*s.b)>>n
#define RGBX8_MULSHIFTK(s, a, n, d) d.r=(a*s.r)>>n; d.g=(a*s.g)>>n; d.b=(a*s.b)>>n;  d.x=(a*s.x)>>n


#define RGB8_LSHIFT(s, n, d) d.r=s.r<<n; d.g=s.g<<n; d.b=s.b<<n
#define RGB8_RSHIFT(s, n, d) d.r=s.r>>n; d.g=s.g>>n; d.b=s.b>>n

#define RGB8_RR5(x0, x1, x2, x3, x4) x0=x1; x1=x2; x2=x3; x3=x4

#ifdef __cplusplus
}
#endif

#endif /* __DEF_H__ */
