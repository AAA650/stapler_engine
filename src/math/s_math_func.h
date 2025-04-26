// s_math_func.h
// Functions of math

#ifndef S_MATH_FUNC_H
#define S_MATH_FUNC_H

#include "../core/s_object.h"

#include "s_math_defs.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SMath : public SObject
	{
	public:
		static inline double sin(double n) { return ::sin(n); };
		static inline float sin(float n) { return ::sinf(n); };

		static inline double cos(double n) { return ::cos(n); };
		static inline float cos(float n) { return ::cosf(n); };

		static inline double tan(double n) { return ::tan(n); };
		static inline float tan(float n) { return ::tanf(n); };

		static inline double sinh(double n) { return ::sinh(n); };
		static inline float sinh(float n) { return ::sinhf(n); };

		static inline double sinc(double n) { return n == 0 ? 1 : ::sin(n) / n; };
		static inline float sinc(float n) { return n == 0 ? 1 : ::sinf(n) / n; };

		static inline double sincn(double n) { return sinc(M_PI * n); };
		static inline float sincn(float n) { return sinc((float)M_PI * n); };

		static inline double cosh(double n) { return ::cosh(n); };
		static inline float cosh(float n) { return ::coshf(n); };

		static inline double tanh(double n) { return ::tanh(n); };
		static inline float tanh(float n) { return ::tanhf(n); };

		static inline double asin(double n) { return n < -1 ? (-M_PI / 2) : (n > 1 ? (M_PI / 2) : ::asin(n)); };
		static inline float asin(float n) { return n < -1 ? (float)(-M_PI / 2) : (n > 1 ? (float)(M_PI / 2) : ::asinf(n)); };

		static inline double acos(double n) { return n < -1 ? M_PI : (n > 1 ? 0 : ::acos(n)); };
		static inline float acos(float n) { return n < -1 ? (float)M_PI : (n > 1 ? 0 : ::acosf(n)); };

		static inline double atan(double n) { return ::atan(n); };
		static inline float atan(float n) { return ::atanf(n); };

		static inline double atan2(double n, double m) { return ::atan2(n, m); };
		static inline float atan2(float n, float m) { return ::atan2f(n, m); };

		static inline double asinh(double n) { return ::asinh(n); };
		static inline float asinh(float n) { return ::asinhf(n); };

		static inline double acosh(double n) { return n < 1 ? 0 : ::acosh(n); };
		static inline float acosh(float n) { return n < 1 ? 0 : ::acoshf(n); };

		static inline double atanh(double n) { return n <= -1 ? -INFINITY : (n >= 1 ? INFINITY : ::atanh(n)); };
		static inline float atanh(float n) { return n <= -1 ? -INFINITY : (n >= 1 ? INFINITY : ::atanhf(n)); };

		static inline double sqrt(double n) { return ::sqrt(n); };
		static inline float sqrt(float n) { return ::sqrtf(n); };

		static inline double fmod(double m, double n) { return ::fmod(m, n); };
		static inline float fmod(float m, float n) { return ::fmodf(m, n); };

		static inline double modf(double m, double* n) { return ::modf(m, n); };
		static inline float modf(float m, float* n) { return ::modff(m, n); };

		static inline double floor(double n) { return ::floor(n); };
		static inline float floor(float n) { return ::floorf(n); };

		static inline double ceil(double n) { return ::ceil(n); };
		static inline float ceil(float n) { return ::ceilf(n); };

		static inline double pow(double m, double n) { return ::pow(m, n); };
		static inline float pow(float m, float n) { return ::powf(m, n); };

		static inline double log(double n) { return ::log(n); };
		static inline float log(float n) { return ::logf(n); };

		static inline double log1p(double n) { return ::log1p(n); };
		static inline float log1p(float n) { return ::log1pf(n); };

		static inline double log2(double n) { return ::log2(n); };
		static inline float log2(float n) { return ::log2f(n); };

		static inline double exp(double n) { return ::exp(n); };
		static inline float exp(float n) { return ::expf(n); };

		static inline double fabs(double n) { return ::fabs(n); };
		static inline float fabs(float n) { return ::fabsf(n); };

	private:
		SMath() {};
		virtual ~SMath() {};
	};
}

#endif