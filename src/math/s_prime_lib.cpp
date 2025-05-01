#include "s_prime_lib.h"


namespace stapler_engine::math
{
	int SPrimeLib::get_size() {
		return prime_nums_.size();
	}

	void SPrimeLib::calculate_nums_to(int end_num) {
		prime_nums_.reserve(end_num / SMath::log((float)end_num));
		for (int num = *(prime_nums_.end() - 1) + 2; num <= end_num; num += 2) {
			bool not_prime = false;
			for (auto it : prime_nums_) {
				if (pow(it, 2) > num)
					break;
				if (num % it == 0) {
					not_prime = true;
					break;
				}
			}
			if (not_prime)
				continue;
			else
				prime_nums_.push_back(num);
		}
	}

	void SPrimeLib::calculate_size_to(int size) {
		prime_nums_.reserve(size);
		for (int num = *(prime_nums_.end() - 1) + 2; prime_nums_.size() < size; num += 2) {
			bool not_prime = false;
			for (auto it : prime_nums_) {
				if (pow(it, 2) > num)
					break;
				if (num % it == 0) {
					not_prime = true;
					break;
				}
			}
			if (not_prime)
				continue;
			else
				prime_nums_.push_back(num);
		}
	}
}
