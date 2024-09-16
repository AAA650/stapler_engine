//Rand.cpp
#include "pch.h"
#include "include/Rand.h"

DLLAPI_SE int RandEng::GetRandNum() {
	return distribution(generator);
};
DLLAPI_SE void RandEng::Reset(int min, int max) {
	MinNum = min; MaxNum = max;
	std::random_device RandDevice;
	generator = std::mt19937(RandDevice());
	distribution = std::uniform_int_distribution<>(min, max);

};
DLLAPI_SE void RandEng::Reset() {
	Reset(MinNum, MaxNum);
};
RandEng::RandEng(int min, int max) {
	Reset(min, max);
};