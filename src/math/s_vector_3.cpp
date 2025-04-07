// s_vector_3.cpp
//implement of SVector3

#include "s_vector_3.h"

namespace stapler_engine::math
{

	DLLAPI_SE float_precision& SVector3::operator[](int axis_index) {
		return coord_[axis_index];
	}

	DLLAPI_SE SVector3 SVector3::plus(const SVector3& arg) const {
		return SVector3(this->x_ + arg.x_, this->y_ + arg.y_, this->z_ + arg.z_);
	}

	DLLAPI_SE SVector3 SVector3::operator+(const SVector3& arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector3 SVector3::plus(float_precision arg) const {
		return SVector3(this->x_ + arg, this->y_ + arg, this->z_ + arg);
	}

	DLLAPI_SE SVector3 SVector3::operator+(float_precision arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector3 SVector3::minus(const SVector3& arg) const {
		return SVector3(this->x_ - arg.x_, this->y_ - arg.y_, this->z_ - arg.z_);
	}

	DLLAPI_SE SVector3 SVector3::operator-(const SVector3& arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector3 SVector3::minus(float_precision arg) const {
		return SVector3(this->x_ - arg, this->y_ - arg, this->z_ - arg);
	}

	DLLAPI_SE SVector3 SVector3::operator-(float_precision arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector3 SVector3::multiply(float_precision arg) const {
		return SVector3(this->x_ * arg, this->y_ * arg, this->z_ * arg);
	}

	DLLAPI_SE SVector3 SVector3::operator*(float_precision arg) const {
		return this->multiply(arg);
	}

	DLLAPI_SE float_precision SVector3::dot(const SVector3& arg) const {
		return this->x_ * arg.x_ + this->y_ * arg.y_ + this->z_ * arg.z_;
	}

	DLLAPI_SE SVector3 SVector3::cross(const SVector3& arg) const {
		SVector3 ret = SVector3();
		ret.x_ = this->y_ * arg.z_ - this->z_ * arg.y_;
		ret.y_ = this->z_ * arg.x_ - this->x_ * arg.z_;
		ret.z_ = this->x_ * arg.y_ - this->y_ * arg.x_;
		return ret;
	}

	DLLAPI_SE SVector3 SVector3::divide(float_precision arg) const {
		return SVector3(this->x_ / arg, this->y_ / arg, this->z_ / arg);
	}

	DLLAPI_SE SVector3 SVector3::operator/(float_precision arg) const {
		return this->divide(arg);
	}

	DLLAPI_SE float_precision SVector3::length_squared() const {
		return x_ * x_ + y_ * y_ + z_ * z_;
	}

	DLLAPI_SE void SVector3::operator+=(const SVector3& arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector3::operator+=(float_precision arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector3::operator-=(const SVector3& arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector3::operator-=(float_precision arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector3::operator*=(float_precision arg) {
		*this = this->multiply(arg);
	}

	DLLAPI_SE void SVector3::operator/=(float_precision arg) {
		*this = this->divide(arg);
	}

	DLLAPI_SE bool SVector3::equal(const SVector3& arg) const {
		return (math::SMath::fabs(this->x_ - arg.x_) < EPS)
			&& (math::SMath::fabs(this->y_ - arg.y_) < EPS)
			&& (math::SMath::fabs(this->z_ - arg.z_) < EPS);
	}

	DLLAPI_SE bool SVector3::operator==(const SVector3& arg) const {
		return this->equal(arg);
	}

	DLLAPI_SE bool SVector3::unequal(const SVector3& arg) const {
		return !(this->equal(arg));
	}

	DLLAPI_SE bool SVector3::operator!=(const SVector3& arg) const {
		return this->unequal(arg);
	}

	SVector3::SVector3() {
		coord_[0] = 0.0;
		coord_[1] = 0.0;
		coord_[2] = 0.0;
	}

	SVector3::SVector3(float_precision arg_x, float_precision arg_y, float_precision arg_z) {
		coord_[0] = arg_x;
		coord_[1] = arg_y;
		coord_[2] = arg_z;
	}
}
