// s_random_eng.cpp
// implement of random engine

#include "s_random_eng.h"

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

	DLLAPI_SE int SRandomEng::uniform_int_num(int min, int max) {
		auto_reset();
		std::uniform_int_distribution<> distribution(min, max);
		return distribution(*generator_);
	};

	DLLAPI_SE double SRandomEng::uniform_real_num(double min, double max) {
		auto_reset();
		std::uniform_real_distribution<> distribution(min, max);
		return distribution(*generator_);
	};

	DLLAPI_SE int SRandomEng::uniform_int_odd(int odd[], const int& size) {
		if (size <= 0)
			return -1;
		int sum_num = 0;
		for (int i = 1; i < size; i++) {
			if (odd[i] < 0) {
				throw std::range_error("Cannot below zero");
				return -1;
			};
			sum_num += odd[i];
		};
		if (sum_num < 0) {
			throw std::overflow_error("Overflowed");
			return -1;
		}
		int minus_num = uniform_int_num(0, sum_num - 1);
		for (int i = 0; i < size; i++) {
			minus_num -= odd[i];
			if (minus_num < 0)
				return i;
		};
		throw std::bad_exception();
		return -1;
	};

	DLLAPI_SE int SRandomEng::uniform_real_odd(double odd[], const int& size) {
		if (size <= 0)
			return -1;
		double sum_num = 0;
		for (int i = 1; i < size; i++) {
			if (odd[i] < 0) {
				throw std::range_error("Cannot below zero");
				return -1;
			};
			sum_num += odd[i];
		};
		if (sum_num < 0) {
			throw std::overflow_error("Overflowed");
			return -1;
		}
		double minus_num = uniform_real_num(0, sum_num - 1);
		for (int i = 0; i < size; i++) {
			minus_num -= odd[i];
			if (minus_num < 0)
				return i;
		};
		throw std::bad_exception();
		return -1;
	}

	SRandomEng::~SRandomEng()
	{
		if (generator_ != nullptr)
			delete generator_;
	}
	;
}