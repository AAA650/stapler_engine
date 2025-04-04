// random_eng.h
// A random engine
#ifndef S_RANDOM_ENG_H
#define S_RANDOM_ENG_H

#include "s_component_base.h"
#include <random>

namespace stapler_engine::component {
	class DLLAPI_SE RandomEng :public Component {
	protected:
		std::mt19937* generator_;
	public:
		void reset_();
		void reset_(int);
		unsigned int auto_reset_freq_ = NULL;
	private:
		unsigned int current_freq_ = NULL;
		bool auto_reset_();
	public:
		int uniform_int_rand_(int, int);
		double uniform_real_rand_(double, double);
		//... Other random types
		int uniform_int_odd_(int[], const int&);
		int uniform_real_odd_(double[], const int&);
		//... Other Percentage random types

		RandomEng() { reset_(); };
		RandomEng(int seed) { reset_(seed); };
		~RandomEng() { delete generator_; };
	};
}

#endif