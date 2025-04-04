// s_vector_4i.cpp
// implement of SVector4i

#include "s_vector_4i.h"

namespace stapler_engine::vector {

	DLLAPI_SE int& SVector4i::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE SVector4i SVector4i::plus_(const SVector4i& arg) const
	{
		return SVector4i(this->x + arg.x, this->y + arg.y, this->z + arg.z, this->w + arg.w);
	}

	DLLAPI_SE SVector4i SVector4i::operator+(const SVector4i& arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE SVector4i SVector4i::plus_(int arg) const
	{
		return SVector4i(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator+(int arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE SVector4i SVector4i::minus_(const SVector4i& arg) const
	{
		return SVector4i(this->x - arg.x, this->y - arg.y, this->z - arg.z, this->w - arg.z);
	}

	DLLAPI_SE SVector4i SVector4i::operator-(const SVector4i& arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE SVector4i SVector4i::minus_(int arg) const
	{
		return SVector4i(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator-(int arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE SVector4i SVector4i::multiply_(int arg) const
	{
		return SVector4i(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator*(int arg) const
	{
		return this->multiply_(arg);
	}

	DLLAPI_SE int SVector4i::dot_(const SVector4i& arg) const
	{
		return this->x * arg.x + this->y * arg.y + this->z * arg.z + this->w * arg.w;
	}

	DLLAPI_SE SVector4i SVector4i::cross_(const SVector4i& arg) const
	{
		SVector4i ret = SVector4i();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE SVector4i SVector4i::divide_(int arg) const
	{
		return SVector4i(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE SVector4i SVector4i::operator/(int arg) const
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int SVector4i::length_squared_() const
	{
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void SVector4i::operator+=(const SVector4i& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector4i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector4i::operator-=(const SVector4i& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector4i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector4i::operator*=(int arg)
	{
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void SVector4i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool SVector4i::equal_(const SVector4i& arg) const
	{
		return (this->x == arg.x) && (this->y == arg.y) && (this->z == arg.z) && (this->w == arg.w);
	}

	DLLAPI_SE bool SVector4i::operator==(const SVector4i& arg) const
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool SVector4i::unequal_(const SVector4i& arg) const
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool SVector4i::operator!=(const SVector4i& arg) const
	{
		return this->unequal_(arg);
	}

	SVector4i::SVector4i()
	{
		coord[0] = 0;
		coord[1] = 0;
		coord[2] = 0;
		coord[3] = 0;
	}

	SVector4i::SVector4i(int arg_x, int arg_y, int arg_z, int arg_w)
	{
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
		coord[3] = arg_w;
	}
}
