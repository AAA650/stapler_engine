// vec_3.cpp
#include "../../../lib/stapler_engine/vector/vec_3.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const float_precision& Vec3::x_()
	{
		return x;
	}

	DLLAPI_SE const float_precision& Vec3::y_()
	{
		return y;
	}

	DLLAPI_SE const float_precision& Vec3::z_()
	{
		return z;
	}

	DLLAPI_SE Vec3 Vec3::operator+(Vec3& arg)
	{
		return Vec3(this->x + arg.x_(), this->y + arg.y_(), this->z + arg.z_());
	}

	DLLAPI_SE Vec3 Vec3::operator-(Vec3& arg)
	{
		return Vec3(this->x - arg.x_(), this->y - arg.y_(), this->z - arg.z_());
	}

	DLLAPI_SE Vec3 Vec3::operator*(Vec3& arg)
	{
		return Vec3(this->x * arg.x_(), this->y * arg.y_(), this->z * arg.z_());
	}

	DLLAPI_SE Vec3 Vec3::operator/(Vec3& arg)
	{
		return Vec3(this->x / arg.x_(), this->y / arg.y_(), this->z / arg.z_());
	}

	DLLAPI_SE void Vec3::operator+=(Vec3& arg)
	{
		this->x += arg.x_();
		this->y += arg.y_();
		this->z += arg.z_();
	}

	DLLAPI_SE void Vec3::operator-=(Vec3& arg)
	{
		this->x -= arg.x_();
		this->y -= arg.y_();
		this->z -= arg.z_();
	}

	DLLAPI_SE void Vec3::operator*=(Vec3& arg)
	{
		this->x *= arg.x_();
		this->y *= arg.y_();
		this->z *= arg.z_();
	}

	DLLAPI_SE void Vec3::operator/=(Vec3& arg)
	{
		this->x /= arg.x_();
		this->y /= arg.y_();
		this->z /= arg.z_();
	}

	DLLAPI_SE bool Vec3::operator==(Vec3& arg)
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x_()) < EPS) && (fabs(this->y - arg.y_()) < EPS) && (fabs(this->z - arg.z_()) < EPS);
#else
		return (fabsf(this->x - arg.x_()) < EPS) && (fabsf(this->y - arg.y_()) < EPS) && (fabsf(this->z - arg.z_() < EPS));
#endif
	}

	DLLAPI_SE bool Vec3::operator!=(Vec3& arg)
	{
		return !(*this == arg);
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
