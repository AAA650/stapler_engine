// vec_3.cpp
#include "../../../lib/stapler_engine/vector/vec_3.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const float_precision Vec3::x_()
	{
		return x;
	}

	DLLAPI_SE void Vec3::x_(float_precision arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const float_precision Vec3::y_()
	{
		return y;
	}

	DLLAPI_SE void Vec3::y_(float_precision arg)
	{
		this->y = arg;
	}

	DLLAPI_SE const float_precision Vec3::z_()
	{
		return z;
	}

	DLLAPI_SE void Vec3::z_(float_precision arg)
	{
		this->z = arg;
	}

	DLLAPI_SE Vec3 Vec3::plus_(Vec3& arg)
	{
		return Vec3(this->x + arg.x_(), this->y + arg.y_(), this->z + arg.z_());
	}

	DLLAPI_SE Vec3 Vec3::operator+(Vec3& arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec3 Vec3::plus_(float_precision arg)
	{
		return Vec3(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE Vec3 Vec3::operator+(float_precision arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec3 Vec3::minus_(Vec3& arg)
	{
		return Vec3(this->x - arg.x_(), this->y - arg.y_(), this->z - arg.z_());
	}

	DLLAPI_SE Vec3 Vec3::operator-(Vec3& arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec3 Vec3::minus_(float_precision arg)
	{
		return Vec3(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE Vec3 Vec3::operator-(float_precision arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec3 Vec3::ride_(float_precision arg)
	{
		return Vec3(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE Vec3 Vec3::operator*(float_precision arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE float_precision Vec3::dot_(Vec3& arg)
	{
		return this->x * arg.x_() + this->y * arg.y_() + this->z * arg.z_();
	}

	DLLAPI_SE Vec3 Vec3::cross_(Vec3& arg)
	{
		Vec3 ret = Vec3();
		ret.x_(this->y * arg.z_() - this->z * arg.y_());
		ret.y_(this->z * arg.x_() - this->x * arg.z_());
		ret.z_(this->x * arg.y_() - this->y * arg.x_());
		return ret;
	}

	DLLAPI_SE Vec3 Vec3::divide_(float_precision arg)
	{
		return Vec3(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE Vec3 Vec3::operator/(float_precision arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE void Vec3::operator+=(Vec3& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec3::operator+=(float_precision arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec3::operator-=(Vec3& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec3::operator-=(float_precision arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec3::operator*=(float_precision arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vec3::operator/=(float_precision arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vec3::equal_(Vec3& arg)
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x_()) < EPS) && (fabs(this->y - arg.y_()) < EPS) && (fabs(this->z - arg.z_()) < EPS);
#else
		return (fabsf(this->x - arg.x_()) < EPS) && (fabsf(this->y - arg.y_()) < EPS) && (fabsf(this->z - arg.z_()) < EPS);
#endif
	}

	DLLAPI_SE bool Vec3::operator==(Vec3& arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vec3::unequal_(Vec3& arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vec3::operator!=(Vec3& arg)
	{
		return this->unequal_(arg);
	}

	Vec3::Vec3()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}

	Vec3::Vec3(float_precision arg_x, float_precision arg_y, float_precision arg_z)
	{
		this->x = arg_x;
		this->y = arg_y;
		this->z = arg_z;
	}
}
