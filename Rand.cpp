//Rand.cpp
#include "pch.h"
#include "include/Rand.h"

DLLAPI_SE void RandEng::Reset() {
	std::random_device RandDevice;
	generator = new std::mt19937(RandDevice());
};
DLLAPI_SE void RandEng::Reset(int seed) {
	generator = new std::mt19937(seed);
};
DLLAPI_SE bool RandEng::autoReset() {
	if (AutoResetFreq <= 0) {
		currentFreq = 0;
		return false;
	};
	currentFreq++;
	if (currentFreq >= AutoResetFreq) {
		currentFreq = 0;
		Reset();
		return true;
	};
	return false;
};
DLLAPI_SE int RandEng::UniformInt(int min, int max) {
	autoReset();
	std::uniform_int_distribution<> distribution(min, max);
	return distribution(*generator);
};
DLLAPI_SE double RandEng::UniformReal(double min, double max) {
	autoReset();
	std::uniform_real_distribution<> distribution(min, max);
	return distribution(*generator);
};
DLLAPI_SE int RandEng::UniformIntOdd(int _odd[], const int& _size) {
	if (_size <= 0)
		return -1;
	int sum = 0;
	for (int i = 1; i < _size; i++) {
		if (_odd[i] < 0) {
			throw std::range_error("Cannot below zero");
			return -1;
		};
		sum += _odd[i];
	};
	if (sum < 0) {
		throw std::overflow_error("Overflowed");
		return -1;
	}
	int Num = UniformInt(0, sum - 1);
	for (int i = 0; i < _size; i++) {
		Num -= _odd[i];
		if (Num < 0)
			return i;
	};
	throw std::bad_exception();
	return -1;
};
DLLAPI_SE int RandEng::UniformRealOdd(double _odd[], const int& _size) {
	if (_size <= 0)
		return -1;
	double sum = 0;
	for (int i = 1; i < _size; i++) {
		if (_odd[i] < 0) {
			throw std::range_error("Cannot below zero");
			return -1;
		};
		sum += _odd[i];
	};
	if (sum < 0) {
		throw std::overflow_error("Overflowed");
		return -1;
	}
	int Num = UniformReal(0, sum - 1);
	for (int i = 0; i < _size; i++) {
		Num -= _odd[i];
		if (Num < 0)
			return i;
	};
	throw std::bad_exception();
	return -1;
};