// s_vector_2.cpp
// implement of SVector2

#include "s_vector_2.h"

namespace stapler_engine::vector {

	DLLAPI_SE float_precision& SVector2::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE SVector2 SVector2::plus_(const SVector2& arg) const {
		return SVector2(this->x + arg.x, this->y + arg.y);
	}

	DLLAPI_SE SVector2 SVector2::operator+(const SVector2& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector2 SVector2::plus_(float_precision arg) const {
		return SVector2(this->x + arg, this->y + arg);
	}

	DLLAPI_SE SVector2 SVector2::operator+(float_precision arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector2 SVector2::minus_(const SVector2& arg) const {
		return SVector2(this->x - arg.x, this->y - arg.y);
	}

	DLLAPI_SE SVector2 SVector2::operator-(const SVector2& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector2 SVector2::minus_(float_precision arg) const {
		return SVector2(this->x - arg, this->y - arg);
	}

	DLLAPI_SE SVector2 SVector2::operator-(float_precision arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector2 SVector2::multiply_(float_precision arg) const {
		return SVector2(this->x * arg, this->y * arg);
	}

	DLLAPI_SE SVector2 SVector2::operator*(float_precision arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE float_precision SVector2::dot_(const SVector2& arg) const {
		return this->x * arg.x + this->y * arg.y;
	}

	DLLAPI_SE float_precision SVector2::cross_(const SVector2& arg) const {
		return this->x * arg.y - this->y * arg.x;
	}

	DLLAPI_SE SVector2 SVector2::divide_(float_precision arg) const {
		return SVector2(this->x / arg, this->y / arg);
	}

	DLLAPI_SE SVector2 SVector2::operator/(float_precision arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision SVector2::length_squared_() const {
		return x * x + y * y;
	}

	DLLAPI_SE void SVector2::operator+=(const SVector2& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector2::operator+=(float_precision arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector2::operator-=(const SVector2& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector2::operator-=(float_precision arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector2::operator*=(float_precision arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void SVector2::operator/=(float_precision arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool SVector2::equal_(const SVector2& arg) const {
		return (math::SMath::fabs(this->x - arg.x) < EPS)
			&& (math::SMath::fabs(this->y - arg.y) < EPS);
	}

	DLLAPI_SE bool SVector2::operator==(const SVector2& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool SVector2::unequal_(const SVector2& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool SVector2::operator!=(const SVector2& arg) const {
		return this->unequal_(arg);
	}

	SVector2::SVector2() {
		coord[0] = 0.0;
		coord[1] = 0.0;
	}

	SVector2::SVector2(float_precision arg_x, float_precision arg_y) {
		coord[0] = arg_x;
		coord[1] = arg_y;
	}
}