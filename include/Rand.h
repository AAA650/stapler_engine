//Rand.h
#pragma once
#include <random>
#include "SEDefinition.h"
#ifndef RAND_H
#define RAND_H
#endif

class DLLAPI_SE Rand {
protected:
	std::mt19937 generator;
	std::uniform_int_distribution<> distribution;
public:
	Rand(int, int);
	int GetNum();
};