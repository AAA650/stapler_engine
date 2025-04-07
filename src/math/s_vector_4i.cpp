// s_vector_4i.cpp
// implement of SVector4i

#include "s_vector_4i.h"

namespace stapler_engine::math {

	DLLAPI_SE int& SVector4i::operator[](int axis_index) {
		return coord_[axis_index];
	}

	DLLAPI_SE SVector4i SVector4i::plus(const SVector4i& arg) const
	{
		return SVector4i(this->x_ + arg.x_, this->y_ + arg.y_, this->z_ + arg.z_, this->w_ + arg.w_);
	}

	DLLAPI_SE SVector4i SVector4i::operator+(const SVector4i& arg) const
	{
		return this->plus(arg);
	}

	DLLAPI_SE SVector4i SVector4i::plus(int arg) const
	{
		return SVector4i(this->x_ + arg, this->y_ + arg, this->z_ + arg, this->w_ + arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator+(int arg) const
	{
		return this->plus(arg);
	}

	DLLAPI_SE SVector4i SVector4i::minus(const SVector4i& arg) const
	{
		return SVector4i(this->x_ - arg.x_, this->y_ - arg.y_, this->z_ - arg.z_, this->w_ - arg.z_);
	}

	DLLAPI_SE SVector4i SVector4i::operator-(const SVector4i& arg) const
	{
		return this->minus(arg);
	}

	DLLAPI_SE SVector4i SVector4i::minus(int arg) const
	{
		return SVector4i(this->x_ - arg, this->y_ - arg, this->z_ - arg, this->w_ - arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator-(int arg) const
	{
		return this->minus(arg);
	}

	DLLAPI_SE SVector4i SVector4i::multiply(int arg) const
	{
		return SVector4i(this->x_ * arg, this->y_ * arg, this->z_ * arg, this->w_ * arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator*(int arg) const
	{
		return this->multiply(arg);
	}

	DLLAPI_SE int SVector4i::dot(const SVector4i& arg) const
	{
		return this->x_ * arg.x_ + this->y_ * arg.y_ + this->z_ * arg.z_ + this->w_ * arg.w_;
	}

	DLLAPI_SE SVector4i SVector4i::cross(const SVector4i& arg) const
	{
		SVector4i ret = SVector4i();
		ret.x_ = this->y_ * arg.z_ - this->z_ * arg.y_;
		ret.y_ = this->z_ * arg.x_ - this->x_ * arg.z_;
		ret.z_ = this->x_ * arg.y_ - this->y_ * arg.x_;
		return ret;
	}

	DLLAPI_SE SVector4i SVector4i::divide(int arg) const
	{
		return SVector4i(this->x_ / arg, this->y_ / arg, this->z_ / arg, this->w_ / arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator/(int arg) const
	{
		return this->divide(arg);
	}

	DLLAPI_SE int SVector4i::length_squared() const
	{
		return x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_;
	}

	DLLAPI_SE void SVector4i::operator+=(const SVector4i& arg)
	{
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector4i::operator+=(int arg)
	{
		*this = this->plus(arg);
	}

	DLLAPI_SE void SVector4i::operator-=(const SVector4i& arg)
	{
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector4i::operator-=(int arg)
	{
		*this = this->minus(arg);
	}

	DLLAPI_SE void SVector4i::operator*=(int arg)
	{
		*this = this->multiply(arg);
	}

	DLLAPI_SE void SVector4i::operator/=(int arg)
	{
		*this = this->divide(arg);
	}

	DLLAPI_SE bool SVector4i::equal(const SVector4i& arg) const
	{
		return (this->x_ == arg.x_) && (this->y_ == arg.y_) && (this->z_ == arg.z_) && (this->w_ == arg.w_);
	}

	DLLAPI_SE bool SVector4i::operator==(const SVector4i& arg) const
	{
		return this->equal(arg);
	}

	DLLAPI_SE bool SVector4i::unequal(const SVector4i& arg) const
	{
		return !(this->equal(arg));
	}

	DLLAPI_SE bool SVector4i::operator!=(const SVector4i& arg) const
	{
		return this->unequal(arg);
	}

	SVector4i::SVector4i()
	{
		coord_[0] = 0;
		coord_[1] = 0;
		coord_[2] = 0;
		coord_[3] = 0;
	}

	SVector4i::SVector4i(int arg_x, int arg_y, int arg_z, int arg_w)
	{
		coord_[0] = arg_x;
		coord_[1] = arg_y;
		coord_[2] = arg_z;
		coord_[3] = arg_w;
	}
}
