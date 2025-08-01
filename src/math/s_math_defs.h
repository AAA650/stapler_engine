// s_math_defs.h
// definations of math

#ifndef S_MATH_DEFS_H
#define S_MATH_DEFS_H

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef USE_HIGH_PRECISION
typedef double float_precision;
#	define EPS 1e-15
#else
	typedef float float_precision;
#	define EPS 1e-8f
#endif

#endif
