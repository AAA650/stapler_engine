//Rand.cpp
#include "pch.h"
#include "include/Rand.h"

DLLAPI_SE void RandEng::Reset() {
	std::random_device RandDevice;
	generator = std::mt19937(RandDevice());
};
DLLAPI_SE void RandEng::AutoReset() {
	if (AutoResetFreq <= 0) {
		CurrentFreq = 0;
		return;
	};
	CurrentFreq++;
	if (CurrentFreq >= AutoResetFreq) {
		CurrentFreq = 0;
		Reset();
	};
	return;
};
DLLAPI_SE int RandEng::RandNum(int min, int max) {
	AutoReset();
	std::uniform_int_distribution<> distribution(min, max);
	return distribution(generator);
};
DLLAPI_SE double RandEng::RandNum(double min, double max) {
	AutoReset();
	std::uniform_real_distribution<> distribution(min, max);
	return distribution(generator);
};
DLLAPI_SE int RandEng::RandPer(int odd[], const int& oddc) {
	if (oddc <= 0)
		return -1;
	int sum = 0;
	for (int i = 1; i < oddc; i++) {
		if (odd[i] < 0) {
			throw std::range_error("Cannot below zero");
			return -1;
		};
		sum += odd[i];
	};
	if (sum < 0) {
		throw std::overflow_error("Overflowed");
		return -1;
	}
	int Num = RandNum(0, sum - 1);
	for (int i = 0; i < oddc; i++) {
		Num -= odd[i];
		if (Num < 0)
			return i;
	};
	throw std::bad_exception();
	return -1;
};