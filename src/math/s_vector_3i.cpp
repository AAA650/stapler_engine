// s_vector_3i.cpp
// implement of SVector3i

#include "s_vector_3i.h"

namespace stapler_engine::vector {

	DLLAPI_SE int& SVector3i::operator[](int axis_index) {
		return coord_[axis_index];
	}

	DLLAPI_SE SVector3i SVector3i::plus(const SVector3i& arg) const {
		return SVector3i(this->x_ + arg.x_, this->y_ + arg.y_, this->z_ + arg.z_);
	}

	DLLAPI_SE SVector3i SVector3i::operator+(const SVector3i& arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector3i SVector3i::plus(int arg) const {
		return SVector3i(this->x_ + arg, this->y_ + arg, this->z_ + arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator+(int arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector3i SVector3i::minus(const SVector3i& arg) const {
		return SVector3i(this->x_ - arg.x_, this->y_ - arg.y_, this->z_ - arg.z_);
	}

	DLLAPI_SE SVector3i SVector3i::operator-(const SVector3i& arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector3i SVector3i::minus(int arg) const {
		return SVector3i(this->x_ - arg, this->y_ - arg, this->z_ - arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator-(int arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector3i SVector3i::multiply(int arg) const {
		return SVector3i(this->x_ * arg, this->y_ * arg, this->z_ * arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator*(int arg) const {
		return this->multiply(arg);
	}

	DLLAPI_SE int SVector3i::dot(const SVector3i& arg) const {
		return this->x_ * arg.x_ + this->y_ * arg.y_ + this->z_ * arg.z_;
	}

	DLLAPI_SE SVector3i SVector3i::cross(const SVector3i& arg) const {
		SVector3i ret = SVector3i();
		ret.x_ = this->y_ * arg.z_ - this->z_ * arg.y_;
		ret.y_ = this->z_ * arg.x_ - this->x_ * arg.z_;
		ret.z_ = this->x_ * arg.y_ - this->y_ * arg.x_;
		return ret;
	}

	DLLAPI_SE SVector3i SVector3i::divide(int arg) const {
		return SVector3i(this->x_ / arg, this->y_ / arg, this->z_ / arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator/(int arg) const {
		return this->divide(arg);
	}

	DLLAPI_SE int SVector3i::length_squared() const {
		return x_ * x_ + y_ * y_ + z_ * z_;
	}

	DLLAPI_SE void SVector3i::operator+=(const SVector3i& arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector3i::operator+=(int arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector3i::operator-=(const SVector3i& arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector3i::operator-=(int arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector3i::operator*=(int arg) {
		*this = this->multiply(arg);
	}

	DLLAPI_SE void SVector3i::operator/=(int arg) {
		*this = this->divide(arg);
	}

	DLLAPI_SE bool SVector3i::equal(const SVector3i& arg) const {
		return (this->x_ == arg.x_) && (this->y_ == arg.y_) && (this->z_ == arg.z_);
	}

	DLLAPI_SE bool SVector3i::operator==(const SVector3i& arg) const {
		return this->equal(arg);
	}

	DLLAPI_SE bool SVector3i::unequal(const SVector3i& arg) const {
		return !(this->equal(arg));
	}

	DLLAPI_SE bool SVector3i::operator!=(const SVector3i& arg) const {
		return this->unequal(arg);
	}

	SVector3i::SVector3i() {
		coord_[0] = 0;
		coord_[1] = 0;
		coord_[2] = 0;
	}

	SVector3i::SVector3i(int arg_x, int arg_y, int arg_z) {
		coord_[0] = arg_x;
		coord_[1] = arg_y;
		coord_[2] = arg_z;
	}
}
