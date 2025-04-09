// s_random_eng.h
// a random engine

#ifndef S_RANDOM_ENG_H
#define S_RANDOM_ENG_H

#include "s_component_base.h"
#include <random>

namespace stapler_engine::component
{
	class DLLAPI_SE SRandomEng :public SComponent
	{
	protected:
		std::mt19937* generator_;

	public:
		void reset();
		void reset(int);
		unsigned int auto_reset_freq_ = NULL;

	private:
		unsigned int current_freq_ = NULL;
		bool auto_reset();

	public:
		int uniform_int_num(int, int);
		double uniform_real_num(double, double);
		//... Other random types
		int uniform_int_odd(int[], const int&);
		int uniform_real_odd(double[], const int&);
		//... Other Percentage random types

	public:
		SRandomEng() { reset(); };
		SRandomEng(int seed) { reset(seed); };
		~SRandomEng() { delete generator_; };
	};
}

#endif