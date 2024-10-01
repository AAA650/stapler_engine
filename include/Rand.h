//Rand.h
#pragma once
#include <random>
#include "SEDefinition.h"
#ifndef RAND_H
#define RAND_H
#endif

class DLLAPI_SE RandEng {
protected:
	std::mt19937 generator;
public:
	unsigned int AutoResetFreq = NULL;
private:
	unsigned int CurrentFreq = NULL;
	void AutoReset();
public:
	void Reset();
	int RandNum(int, int);
	double RandNum(double, double);
	int RandPer(int[], const int&);
	RandEng() { Reset(); };
};