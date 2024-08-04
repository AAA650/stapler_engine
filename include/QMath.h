#include <math.h>

float Q_SqrtNum(float const& num) {
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = num * 0.5F;
	i = *(long*)&num;//deep dark ×ª»»Ğ¡¼¼ÇÉ
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return y;
 }
