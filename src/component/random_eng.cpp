//
#include "../../include/component/random_eng.h"

namespace stapler_engine::component {

	DLLAPI_SE void RandomEng::reset_() {
		std::random_device RandDevice;
		generator_ = new std::mt19937(RandDevice());
	};

	DLLAPI_SE void RandomEng::reset_(int seed) {
		generator_ = new std::mt19937(seed);
	};

	DLLAPI_SE bool RandomEng::auto_reset_() {
		if (auto_reset_freq_ == 0) {
			current_freq_ = 0;
			return false;
		};
		current_freq_++;
		if (current_freq_ >= auto_reset_freq_) {
			current_freq_ = 0;
			reset_();
			return true;
		};
		return false;
	};

	DLLAPI_SE int RandomEng::uniform_int_rand_(int min, int max) {
		auto_reset_();
		std::uniform_int_distribution<> distribution(min, max);
		return distribution(*generator_);
	};

	DLLAPI_SE double RandomEng::uniform_real_rand_(double min, double max) {
		auto_reset_();
		std::uniform_real_distribution<> distribution(min, max);
		return distribution(*generator_);
	};

	DLLAPI_SE int RandomEng::uniform_int_odd_(int odd[], const int& size) {
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
		int minus_num = uniform_int_rand_(0, sum_num - 1);
		for (int i = 0; i < size; i++) {
			minus_num -= odd[i];
			if (minus_num < 0)
				return i;
		};
		throw std::bad_exception();
		return -1;
	};

	DLLAPI_SE int RandomEng::uniform_real_odd_(double odd[], const int& size) {
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
		double minus_num = uniform_real_rand_(0, sum_num - 1);
		for (int i = 0; i < size; i++) {
			minus_num -= odd[i];
			if (minus_num < 0)
				return i;
		};
		throw std::bad_exception();
		return -1;
	};
}