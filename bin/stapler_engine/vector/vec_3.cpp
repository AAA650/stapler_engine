// vec_3.cpp
#include "../../../lib/stapler_engine/vector/vec_3.h"

namespace stapler_engine::vec 
{
	DLLAPI_SE float_precision& Vector3::x_()
	{
		return x;
	}

	DLLAPI_SE float_precision& Vector3::y_()
	{
		return y;
	}

	DLLAPI_SE float_precision& Vector3::z_()
	{
		return z;
	}

	DLLAPI_SE Vector3 Vector3::plus_(const Vector3& arg) const
	{
		return Vector3(this->x + arg.x, this->y + arg.y, this->z + arg.z);
	}

	DLLAPI_SE Vector3 Vector3::operator+(const Vector3& arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::plus_(float_precision arg) const
	{
		return Vector3(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE Vector3 Vector3::operator+(float_precision arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::minus_(const Vector3& arg) const
	{
		return Vector3(this->x - arg.x, this->y - arg.y, this->z - arg.z);
	}

	DLLAPI_SE Vector3 Vector3::operator-(const Vector3& arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::minus_(float_precision arg) const
	{
		return Vector3(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE Vector3 Vector3::operator-(float_precision arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::ride_(float_precision arg) const
	{
		return Vector3(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE Vector3 Vector3::operator*(float_precision arg) const
	{
		return this->ride_(arg);
	}

	DLLAPI_SE float_precision Vector3::dot_(const Vector3& arg) const
	{
		return this->x * arg.x + this->y * arg.y + this->z * arg.z;
	}

	DLLAPI_SE Vector3 Vector3::cross_(const Vector3& arg) const
	{
		Vector3 ret = Vector3();
		ret.x_() = this->y * arg.z - this->z * arg.y;
		ret.y_() = this->z * arg.x - this->x * arg.z;
		ret.z_() = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector3 Vector3::divide_(float_precision arg) const
	{
		return Vector3(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE Vector3 Vector3::operator/(float_precision arg) const
	{
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector3::norm_without_radical_() const
	{
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void Vector3::operator+=(const Vector3& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3::operator+=(float_precision arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3::operator-=(const Vector3& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3::operator-=(float_precision arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3::operator*=(float_precision arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vector3::operator/=(float_precision arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector3::equal_(const Vector3& arg) const
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x) < EPS) && (fabs(this->y - arg.y) < EPS) && (fabs(this->z - arg.z) < EPS);
#else
		return (fabsf(this->x - arg.x) < EPS) && (fabsf(this->y - arg.y) < EPS) && (fabsf(this->z - arg.z) < EPS);
#endif
	}

	DLLAPI_SE bool Vector3::operator==(const Vector3& arg) const
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector3::unequal_(const Vector3& arg) const
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector3::operator!=(const Vector3& arg) const
	{
		return this->unequal_(arg);
	}

	Vector3::Vector3()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
	}

	Vector3::Vector3(float_precision arg_x, float_precision arg_y, float_precision arg_z)
	{
		this->x = arg_x;
		this->y = arg_y;
		this->z = arg_z;
	}
}
