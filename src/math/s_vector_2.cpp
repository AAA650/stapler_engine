// s_vector_2.cpp
// implement of SVector2

#include "s_vector_2.h"

namespace stapler_engine::math
{

	DLLAPI_SE float_precision& SVector2::operator[](int axis_index) {
		return coord_[axis_index];
	}

	DLLAPI_SE SVector2 SVector2::plus(const SVector2& arg) const {
		return SVector2(this->x_ + arg.x_, this->y_ + arg.y_);
	}

	DLLAPI_SE SVector2 SVector2::operator+(const SVector2& arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector2 SVector2::plus(float_precision arg) const {
		return SVector2(this->x_ + arg, this->y_ + arg);
	}

	DLLAPI_SE SVector2 SVector2::operator+(float_precision arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector2 SVector2::minus(const SVector2& arg) const {
		return SVector2(this->x_ - arg.x_, this->y_ - arg.y_);
	}

	DLLAPI_SE SVector2 SVector2::operator-(const SVector2& arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector2 SVector2::minus(float_precision arg) const {
		return SVector2(this->x_ - arg, this->y_ - arg);
	}

	DLLAPI_SE SVector2 SVector2::operator-(float_precision arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector2 SVector2::multiply(float_precision arg) const {
		return SVector2(this->x_ * arg, this->y_ * arg);
	}

	DLLAPI_SE SVector2 SVector2::operator*(float_precision arg) const {
		return this->multiply(arg);
	}

	DLLAPI_SE float_precision SVector2::dot(const SVector2& arg) const {
		return this->x_ * arg.x_ + this->y_ * arg.y_;
	}

	DLLAPI_SE float_precision SVector2::cross(const SVector2& arg) const {
		return this->x_ * arg.y_ - this->y_ * arg.x_;
	}

	DLLAPI_SE SVector2 SVector2::divide(float_precision arg) const {
		return SVector2(this->x_ / arg, this->y_ / arg);
	}

	DLLAPI_SE SVector2 SVector2::operator/(float_precision arg) const {
		return this->divide(arg);
	}

	DLLAPI_SE float_precision SVector2::length_squared() const {
		return x_ * x_ + y_ * y_;
	}

	DLLAPI_SE void SVector2::operator+=(const SVector2& arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector2::operator+=(float_precision arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector2::operator-=(const SVector2& arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector2::operator-=(float_precision arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector2::operator*=(float_precision arg) {
		*this = this->multiply(arg);
	}

	DLLAPI_SE void SVector2::operator/=(float_precision arg) {
		*this = this->divide(arg);
	}

	DLLAPI_SE bool SVector2::equal(const SVector2& arg) const {
		return (math::SMath::fabs(this->x_ - arg.x_) < EPS)
			&& (math::SMath::fabs(this->y_ - arg.y_) < EPS);
	}

	DLLAPI_SE bool SVector2::operator==(const SVector2& arg) const {
		return this->equal(arg);
	}

	DLLAPI_SE bool SVector2::unequal(const SVector2& arg) const {
		return !(this->equal(arg));
	}

	DLLAPI_SE bool SVector2::operator!=(const SVector2& arg) const {
		return this->unequal(arg);
	}

	SVector2::SVector2() {
		coord_[0] = 0.0;
		coord_[1] = 0.0;
	}

	SVector2::SVector2(float_precision arg_x, float_precision arg_y) {
		coord_[0] = arg_x;
		coord_[1] = arg_y;
	}
}