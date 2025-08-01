#include "s_prime_lib.h"


namespace stapler_engine::math
{
	size_t SPrimeLib::get_size() {
		return prime_nums_->size();
	}

	void SPrimeLib::calculate_nums_to(unsigned int end_num) {
		if (end_num <= *(prime_nums_->end() - 1))
			return;
		prime_nums_->reserve((size_t)(end_num / SMath::log((float)end_num)));
		for (unsigned int num = *(prime_nums_->end() - 1) + 2; num <= end_num; num += 2) {
			bool not_prime = false;
			for (auto it : *prime_nums_) {
				if (pow(it, 2) > num)
					break;
				if (num % it == 0) {
					not_prime = true;
					break;
				}
			}
			if (!not_prime)
				prime_nums_->push_back(num);
		}
	}

	void SPrimeLib::calculate_size_to(size_t size) {
		if (size <= prime_nums_->size())
			return;
		prime_nums_->reserve(size);
		for (unsigned int num = *(prime_nums_->end() - 1) + 2; prime_nums_->size() < size; num += 2) {
			bool not_prime = false;
			for (auto it : *prime_nums_) {
				if (pow(it, 2) > num)
					break;
				if (num % it == 0) {
					not_prime = true;
					break;
				}
			}
			if (!not_prime)
				prime_nums_->push_back(num);
		}
	}

	SPrimeLib::SPrimeLib() {
		prime_nums_ = new std::vector<unsigned int>;
	}

	SPrimeLib::~SPrimeLib() {
		delete prime_nums_;
	}

}
