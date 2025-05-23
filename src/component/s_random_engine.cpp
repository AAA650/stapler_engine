// s_random_eng.cpp
// implement of random engine

#include "s_random_engine.h"

namespace stapler_engine::component {

	DLLAPI_SE void SRandomEng::reset() {
		//get a rand_device to get seed
		std::random_device rand_device;
		if (generator_ != nullptr)
			delete generator_;
		generator_ = new std::mt19937(rand_device());
	};

	DLLAPI_SE void SRandomEng::reset(int seed) {
		if (generator_ != nullptr)
			delete generator_;
		generator_ = new std::mt19937(seed);
	};

	DLLAPI_SE bool SRandomEng::auto_reset() {
		if (auto_reset_freq_ == 0) {
			current_freq_ = 0;
			return false;
		};
		current_freq_++;
		if (current_freq_ >= auto_reset_freq_) {
			current_freq_ = 0;
			reset();
			return true;
		};
		return false;
	};

	DLLAPI_SE int SRandomEng::uniform_int_dist(int min, int max) {
		auto_reset();
		std::uniform_int_distribution<> distribution(min, max);
		return distribution(*generator_);
	};

	DLLAPI_SE double SRandomEng::uniform_real_dist(double min, double max) {
		auto_reset();
		std::uniform_real_distribution<> distribution(min, max);
		return distribution(*generator_);
	};

	DLLAPI_SE int SRandomEng::discrete_dist(std::initializer_list<double> odd_list) {
		auto_reset();
		std::discrete_distribution<> distribution(odd_list);
		return distribution(*generator_);

	};

	SRandomEng::~SRandomEng()
	{
		if (generator_ != nullptr)
			delete generator_;
	}
	;
}