//Rand.cpp
#include "pch.h"
#include "include/Rand.h"

template<class Type>
Rand<Type>::Rand(Type min, Type max) {
	std::random_device RandDevice;
	generator = std::mt19937(RandDevice());
	distribution = std::uniform_int_distribution<Type>(min, max);
};
template<class Type>
DLLAPI_SE Type Rand<Type>::GetNum() {
	return distribution(generator);
};