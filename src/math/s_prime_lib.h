// s_prime_lib.h
// calculating prime nums

#ifndef S_PRIME_LIB_H
#define S_PRIME_LIB_H

#include "../core/s_core.h"
#include "s_math_func.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SPrimeLib :public SObject
	{
	public:
		std::vector<int> prime_nums_;

	public:
		virtual int get_size();

		virtual void calculate_nums_to(int end_num);

		virtual void calculate_size_to(int size);
	};
}

#endif
