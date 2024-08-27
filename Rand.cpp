//Rand.cpp
#include "pch.h"
#include "include/Rand.h"

Rand::Rand(int min, int max) {
	std::random_device RandDevice;
	generator = std::mt19937(RandDevice());
	distribution = std::uniform_int_distribution<>(min, max);
};
DLLAPI_SE int Rand::GetNum() {
	return distribution(generator);
};