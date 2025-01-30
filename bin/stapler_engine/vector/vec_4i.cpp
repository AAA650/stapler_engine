// vec_4i.cpp
#include "../../../lib/stapler_engine/vector/vec_4i.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const int Vec4i::x_()
	{
		return x;
	}

	DLLAPI_SE void Vec4i::x_(int arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const int Vec4i::y_()
	{
		return y;
	}

	DLLAPI_SE void Vec4i::y_(int arg)
	{
		this->y = arg;
	}

	DLLAPI_SE const int Vec4i::z_()
	{
		return z;
	}

	DLLAPI_SE void Vec4i::z_(int arg)
	{
		this->z = arg;
	}

	DLLAPI_SE const int Vec4i::w_()
	{
		return w;
	}

	DLLAPI_SE void Vec4i::w_(int arg)
	{
		this->w = arg;
	}

	DLLAPI_SE Vec4i Vec4i::plus_(Vec4i& arg)
	{
		return Vec4i(this->x + arg.x_(), this->y + arg.y_(), this->z + arg.z_(), this->w + arg.w_());
	}

	DLLAPI_SE Vec4i Vec4i::operator+(Vec4i& arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec4i Vec4i::plus_(int arg)
	{
		return Vec4i(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE Vec4i Vec4i::operator+(int arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec4i Vec4i::minus_(Vec4i& arg)
	{
		return Vec4i(this->x - arg.x_(), this->y - arg.y_(), this->z - arg.z_(), this->w - arg.z_());
	}

	DLLAPI_SE Vec4i Vec4i::operator-(Vec4i& arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec4i Vec4i::minus_(int arg)
	{
		return Vec4i(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE Vec4i Vec4i::operator-(int arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec4i Vec4i::ride_(int arg)
	{
		return Vec4i(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE Vec4i Vec4i::operator*(int arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE int Vec4i::dot_(Vec4i& arg)
	{
		return this->x * arg.x_() + this->y * arg.y_() + this->z * arg.z_() + this->w * arg.w_();
	}

	DLLAPI_SE Vec4i Vec4i::cross_(Vec4i& arg)
	{
		Vec4i ret = Vec4i();
		ret.x_(this->y * arg.z_() - this->z * arg.y_());
		ret.y_(this->z * arg.x_() - this->x * arg.z_());
		ret.z_(this->x * arg.y_() - this->y * arg.x_());
		return ret;
	}

	DLLAPI_SE Vec4i Vec4i::divide_(int arg)
	{
		return Vec4i(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE Vec4i Vec4i::operator/(int arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int Vec4i::norm_without_radical_()
	{
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void Vec4i::operator+=(Vec4i& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec4i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec4i::operator-=(Vec4i& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec4i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec4i::operator*=(int arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vec4i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vec4i::equal_(Vec4i& arg)
	{
		return (this->x == arg.x_()) && (this->y == arg.y_()) && (this->z == arg.z_()) && (this->w == arg.w_());
	}

	DLLAPI_SE bool Vec4i::operator==(Vec4i& arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vec4i::unequal_(Vec4i& arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vec4i::operator!=(Vec4i& arg)
	{
		return this->unequal_(arg);
	}

	Vec4i::Vec4i()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}

	Vec4i::Vec4i(int arg_x, int arg_y, int arg_z, int arg_w)
	{
		this->x = arg_x;
		this->y = arg_y;
		this->z = arg_z;
		this->w = arg_w;
	}
}
