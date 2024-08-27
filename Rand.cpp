//Rand.cpp
#include "pch.h"
#include "include/Rand.h"

DLLAPI_SE int Rand::GetRandNum() {
	return distribution(generator);
};
DLLAPI_SE void Rand::Reset(int min, int max) {
	MinNum = min; MaxNum = max;
	std::random_device RandDevice;
	generator = std::mt19937(RandDevice());
	distribution = std::uniform_int_distribution<>(min, max);

};
DLLAPI_SE void Rand::Reset() {
	Reset(MinNum, MaxNum);
};
Rand::Rand(int min, int max) {
	Reset(min, max);
};