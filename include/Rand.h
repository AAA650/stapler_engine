//Rand.h
#pragma once
#include <random>
#include "SEDefinition.h"
#ifndef RAND_H
#define RAND_H
#endif

class DLLAPI_SE RandEng {
protected:
	std::mt19937* generator_;
public:
	void reset_();
	void reset_(int);
	unsigned int auto_reset_freq_ = NULL;
private:
	unsigned int current_freq_ = NULL;
	bool auto_reset_();
public:
	int uniform_int_rand_(int, int);
	double uniform_real_rand_(double, double);
	//... Other random types
	int uniform_intodd(int[], const int&);
	int uniform_realodd(double[], const int&);
	//... Other Percentage random types

	RandEng() { reset_(); };
	RandEng(int seed) { reset_(seed); };
};