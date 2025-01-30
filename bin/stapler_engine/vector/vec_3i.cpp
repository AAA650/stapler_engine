// vec_3.cpp
#include "../../../lib/stapler_engine/vector/vec_3i.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const int Vec3i::x_()
	{
		return x;
	}

	DLLAPI_SE void Vec3i::x_(int arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const int Vec3i::y_()
	{
		return y;
	}

	DLLAPI_SE void Vec3i::y_(int arg)
	{
		this->y = arg;
	}

	DLLAPI_SE const int Vec3i::z_()
	{
		return z;
	}

	DLLAPI_SE void Vec3i::z_(int arg)
	{
		this->z = arg;
	}

	DLLAPI_SE Vec3i Vec3i::plus_(Vec3i& arg)
	{
		return Vec3i(this->x + arg.x_(), this->y + arg.y_(), this->z + arg.z_());
	}

	DLLAPI_SE Vec3i Vec3i::operator+(Vec3i& arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec3i Vec3i::plus_(int arg)
	{
		return Vec3i(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE Vec3i Vec3i::operator+(int arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec3i Vec3i::minus_(Vec3i& arg)
	{
		return Vec3i(this->x - arg.x_(), this->y - arg.y_(), this->z - arg.z_());
	}

	DLLAPI_SE Vec3i Vec3i::operator-(Vec3i& arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec3i Vec3i::minus_(int arg)
	{
		return Vec3i(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE Vec3i Vec3i::operator-(int arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec3i Vec3i::ride_(int arg)
	{
		return Vec3i(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE Vec3i Vec3i::operator*(int arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE int Vec3i::dot_(Vec3i& arg)
	{
		return this->x * arg.x_() + this->y * arg.y_() + this->z * arg.z_();
	}

	DLLAPI_SE Vec3i Vec3i::cross_(Vec3i& arg)
	{
		Vec3i ret = Vec3i();
		ret.x_(this->y * arg.z_() - this->z * arg.y_());
		ret.y_(this->z * arg.x_() - this->x * arg.z_());
		ret.z_(this->x * arg.y_() - this->y * arg.x_());
		return ret;
	}

	DLLAPI_SE Vec3i Vec3i::divide_(int arg)
	{
		return Vec3i(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE Vec3i Vec3i::operator/(int arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int Vec3i::norm_without_radical_()
	{
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void Vec3i::operator+=(Vec3i& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec3i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec3i::operator-=(Vec3i& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec3i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec3i::operator*=(int arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vec3i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vec3i::equal_(Vec3i& arg)
	{
		return (this->x == arg.x_()) && (this->y == arg.y_()) && (this->z == arg.z_());
	}

	DLLAPI_SE bool Vec3i::operator==(Vec3i& arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vec3i::unequal_(Vec3i& arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vec3i::operator!=(Vec3i& arg)
	{
		return this->unequal_(arg);
	}

	Vec3i::Vec3i()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vec3i::Vec3i(int arg_x, int arg_y, int arg_z)
	{
		this->x = arg_x;
		this->y = arg_y;
		this->z = arg_z;
	}
}
