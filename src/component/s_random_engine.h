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
		uint16_t auto_reset_freq_ = 0;

	private:
		unsigned int current_freq_ = 0;
		bool auto_reset();

	public:
		int uniform_int_dist(int min, int max);
		double uniform_real_dist(double min, double max);
		//... Other random types
		int discrete_dist(std::initializer_list<double> odd_list);
		//... Other Percentage random types

	public:
		SRandomEng() { reset(); };
		SRandomEng(int seed) { reset(seed); };
		~SRandomEng();
	};
}

#endif