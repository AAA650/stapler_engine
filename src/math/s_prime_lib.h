// s_prime_lib.h
// calculating prime nums

#ifndef S_PRIME_LIB_H
#define S_PRIME_LIB_H

#include "s_math_func.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SPrimeLib :public SObject
	{
	public:
		std::vector<unsigned int>* prime_nums_;

	public:
		virtual size_t get_size();

		virtual void calculate_nums_to(unsigned int end_num);

		virtual void calculate_size_to(size_t size);

		SPrimeLib();

		~SPrimeLib();
	};
}

#endif
