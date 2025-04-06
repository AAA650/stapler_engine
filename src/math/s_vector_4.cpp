// s_vector_4.cpp
//implement of SVector4

#include "s_vector_4.h"

namespace stapler_engine::vector {

	DLLAPI_SE float_precision& SVector4::operator[](int axis_index) {
		return coord_[axis_index];
	}

	DLLAPI_SE SVector4 SVector4::plus(const SVector4& arg) const {
		return SVector4(this->x_ + arg.x_, this->y_ + arg.y_, this->z_ + arg.z_, this->w_ + arg.w_);
	}

	DLLAPI_SE SVector4 SVector4::operator+(const SVector4& arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector4 SVector4::plus(float_precision arg) const {
		return SVector4(this->x_ + arg, this->y_ + arg, this->z_ + arg, this->w_ + arg);
	}

	DLLAPI_SE SVector4 SVector4::operator+(float_precision arg) const {
		return this->plus(arg);
	}

	DLLAPI_SE SVector4 SVector4::minus(const SVector4& arg) const {
		return SVector4(this->x_ - arg.x_, this->y_ - arg.y_, this->z_ - arg.z_, this->w_ - arg.z_);
	}

	DLLAPI_SE SVector4 SVector4::operator-(const SVector4& arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector4 SVector4::minus(float_precision arg) const {
		return SVector4(this->x_ - arg, this->y_ - arg, this->z_ - arg, this->w_ - arg);
	}

	DLLAPI_SE SVector4 SVector4::operator-(float_precision arg) const {
		return this->minus(arg);
	}

	DLLAPI_SE SVector4 SVector4::multiply(float_precision arg) const {
		return SVector4(this->x_ * arg, this->y_ * arg, this->z_ * arg, this->w_ * arg);
	}

	DLLAPI_SE SVector4 SVector4::operator*(float_precision arg) const {
		return this->multiply(arg);
	}

	DLLAPI_SE float_precision SVector4::dot(const SVector4& arg) const {
		return this->x_ * arg.x_ + this->y_ * arg.y_ + this->z_ * arg.z_ + this->w_ * arg.w_;
	}

	DLLAPI_SE SVector4 SVector4::cross(const SVector4& arg) const {
		SVector4 ret = SVector4();
		ret.x_ = this->y_ * arg.z_ - this->z_ * arg.y_;
		ret.y_ = this->z_ * arg.x_ - this->x_ * arg.z_;
		ret.z_ = this->x_ * arg.y_ - this->y_ * arg.x_;
		return ret;
	}

	DLLAPI_SE SVector4 SVector4::divide(float_precision arg) const {
		return SVector4(this->x_ / arg, this->y_ / arg, this->z_ / arg, this->w_ / arg);
	}

	DLLAPI_SE SVector4 SVector4::operator/(float_precision arg) const {
		return this->divide(arg);
	}

	DLLAPI_SE float_precision SVector4::length_squared() const {
		return x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_;
	}

	DLLAPI_SE void SVector4::operator+=(const SVector4& arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector4::operator+=(float_precision arg) {
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector4::operator-=(const SVector4& arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector4::operator-=(float_precision arg) {
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector4::operator*=(float_precision arg) {
		*this = this->multiply(arg);
	}

	DLLAPI_SE void SVector4::operator/=(float_precision arg) {
		*this = this->divide(arg);
	}

	DLLAPI_SE bool SVector4::equal(const SVector4& arg) const {
		return (math::SMath::fabs(this->x_ - arg.x_) < EPS)
			&& (math::SMath::fabs(this->y_ - arg.y_) < EPS)
			&& (math::SMath::fabs(this->z_ - arg.z_) < EPS)
			&& (math::SMath::fabs(this->w_ - arg.w_) < EPS);
	}

	DLLAPI_SE bool SVector4::operator==(const SVector4& arg) const {
		return this->equal(arg);
	}

	DLLAPI_SE bool SVector4::unequal(const SVector4& arg) const {
		return !(this->equal(arg));
	}

	DLLAPI_SE bool SVector4::operator!=(const SVector4& arg) const {
		return this->unequal(arg);
	}

	SVector4::SVector4() {
		coord_[0] = 0.0;
		coord_[1] = 0.0;
		coord_[2] = 0.0;
		coord_[3] = 0.0;
	}

	SVector4::SVector4(float_precision arg_x, float_precision arg_y, float_precision arg_z, float_precision arg_w) {
		coord_[0] = arg_x;
		coord_[1] = arg_y;
		coord_[2] = arg_z;
		coord_[3] = arg_w;
	}
}
