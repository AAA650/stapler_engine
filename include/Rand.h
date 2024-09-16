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
	std::uniform_int_distribution<> distribution;
	int MinNum, MaxNum;
public:
	int GetRandNum();
	void Reset(int, int);
	void Reset();
	RandEng(int, int);
};