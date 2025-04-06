// s_vector_2i.cpp
// implement of SVector2i

#include "s_vector_2i.h"

namespace stapler_engine::vector
{

	DLLAPI_SE int& SVector2i::operator[](int axis_index) {
		return coord_[axis_index];
	}

	DLLAPI_SE SVector2i SVector2i::plus(const SVector2i& arg) const {
		return SVector2i(this->x_ + arg.x_, this->y_ + arg.y_);
	}

	DLLAPI_SE SVector2i SVector2i::operator+(const SVector2i& arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector2i SVector2i::plus(int arg) const {
		return SVector2i(this->x_ + arg, this->y_ + arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator+(int arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector2i SVector2i::minus(const SVector2i& arg) const {
		return SVector2i(this->x_ - arg.x_, this->y_ - arg.y_);
	}

	DLLAPI_SE SVector2i SVector2i::operator-(const SVector2i& arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector2i SVector2i::minus(int arg) const {
		return SVector2i(this->x_ - arg, this->y_ - arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator-(int arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector2i SVector2i::multiply(int arg) const {
		return SVector2i(this->x_ * arg, this->y_ * arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator*(int arg) const {
		return this->multiply(arg);
	}

	DLLAPI_SE int SVector2i::dot(const SVector2i& arg) const {
		return this->x_ * arg.x_ + this->y_ * arg.y_;
	}

	DLLAPI_SE int SVector2i::cross(const SVector2i& arg) const {
		return this->x_ * arg.y_ - this->y_ * arg.x_;
	}

	DLLAPI_SE SVector2i SVector2i::divide(int arg) const {
		return SVector2i(this->x_ / arg, this->y_ / arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator/(int arg) const {
		return this->divide(arg);
	}

	DLLAPI_SE int SVector2i::length_squared() const {
		return x_ * x_ + y_ * y_;
	}

	DLLAPI_SE void SVector2i::operator+=(const SVector2i& arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector2i::operator+=(int arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector2i::operator-=(const SVector2i& arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector2i::operator-=(int arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector2i::operator*=(int arg) {
		*this = this->multiply(arg);
	}

	DLLAPI_SE void SVector2i::operator/=(int arg) {
		*this = this->divide(arg);
	}

	DLLAPI_SE bool SVector2i::equal(const SVector2i& arg) const {
		return this->x_ == arg.x_ && this->y_ == arg.y_;
	}

	DLLAPI_SE bool SVector2i::operator==(const SVector2i& arg) const {
		return this->equal(arg);
	}

	DLLAPI_SE bool SVector2i::unequal(const SVector2i& arg) const {
		return !(this->equal(arg));
	}

	DLLAPI_SE bool SVector2i::operator!=(const SVector2i& arg) const {
		return this->unequal(arg);
	}

	SVector2i::SVector2i() {
		coord_[0] = 0;
		coord_[1] = 0;
	}

	SVector2i::SVector2i(int arg_x, int arg_y) {
		coord_[0] = arg_x;
		coord_[1] = arg_y;
	}
}
