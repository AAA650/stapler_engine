// vec_3.cpp
#include "../../lib/vector/vec_3i.h"

namespace stapler_engine::vec 
{
	DLLAPI_SE int& Vector3i::x_()
	{
		return x;
	}

	DLLAPI_SE int& Vector3i::y_()
	{
		return y;
	}

	DLLAPI_SE int& Vector3i::z_()
	{
		return z;
	}

	DLLAPI_SE Vector3i Vector3i::plus_(const Vector3i& arg) const
	{
		return Vector3i(this->x + arg.x, this->y + arg.y, this->z + arg.z);
	}

	DLLAPI_SE Vector3i Vector3i::operator+(const Vector3i& arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::plus_(int arg) const
	{
		return Vector3i(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator+(int arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::minus_(const Vector3i& arg) const
	{
		return Vector3i(this->x - arg.x, this->y - arg.y, this->z - arg.z);
	}

	DLLAPI_SE Vector3i Vector3i::operator-(const Vector3i& arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::minus_(int arg) const
	{
		return Vector3i(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator-(int arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::ride_(int arg) const
	{
		return Vector3i(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator*(int arg) const
	{
		return this->ride_(arg);
	}

	DLLAPI_SE int Vector3i::dot_(const Vector3i& arg) const
	{
		return this->x * arg.x + this->y * arg.y + this->z * arg.z;
	}

	DLLAPI_SE Vector3i Vector3i::cross_(const Vector3i& arg) const
	{
		Vector3i ret = Vector3i();
		ret.x_() = this->y * arg.z - this->z * arg.y;
		ret.y_() = this->z * arg.x - this->x * arg.z;
		ret.z_() = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector3i Vector3i::divide_(int arg) const
	{
		return Vector3i(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator/(int arg) const
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int Vector3i::norm_without_radical_() const
	{
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void Vector3i::operator+=(const Vector3i& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3i::operator-=(const Vector3i& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3i::operator*=(int arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vector3i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector3i::equal_(const Vector3i& arg) const
	{
		return (this->x == arg.x) && (this->y == arg.y) && (this->z == arg.z);
	}

	DLLAPI_SE bool Vector3i::operator==(const Vector3i& arg) const
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector3i::unequal_(const Vector3i& arg) const
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector3i::operator!=(const Vector3i& arg) const
	{
		return this->unequal_(arg);
	}

	Vector3i::Vector3i()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vector3i::Vector3i(int arg_x, int arg_y, int arg_z)
	{
		this->x = arg_x;
		this->y = arg_y;
		this->z = arg_z;
	}
}
