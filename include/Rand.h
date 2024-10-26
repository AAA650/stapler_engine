//Rand.h
#pragma once
#include <random>
#include "SEDefinition.h"
#ifndef RAND_H
#define RAND_H
#endif

class DLLAPI_SE RandEng {
protected:
	std::mt19937* generator;
public:
	void Reset();
	void Reset(int);
	unsigned int AutoResetFreq = NULL;
private:
	unsigned int currentFreq = NULL;
	bool autoReset();
public:
	int UniformInt(int, int);
	double UniformReal(double, double);
	//... Other random types
	int UniformIntOdd(int[], const int&);
	int UniformRealOdd(double[], const int&);
	//... Other Percentage random types

	RandEng() { Reset(); };
	RandEng(int seed) { Reset(seed); };
};