//Colour.cpp
#include "pch.h"
#include "include/Colour.h"

DLLAPI_SE colour RGBA(int r, int g, int b, int a) {
	if ((r >> 8) != 0 || (g >> 8) != 0 || (b >> 8) != 0 || (a >> 8) != 0)
		return 0;
	return (r << 24) + (g << 16) + (b << 8) + a;
};