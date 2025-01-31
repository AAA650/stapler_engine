// vec_4.cpp
#include "../../../lib/stapler_engine/vector/vec_4.h"

namespace stapler_engine::vec 
{
	DLLAPI_SE float_precision& Vector4::x_()
	{
		return x;
	}

	DLLAPI_SE float_precision& Vector4::y_()
	{
		return y;
	}

	DLLAPI_SE float_precision& Vector4::z_()
	{
		return z;
	}

	DLLAPI_SE float_precision& Vector4::w_()
	{
		return w;
	}

	DLLAPI_SE Vector4 Vector4::plus_(const Vector4& arg) const
	{
		return Vector4(this->x + arg.x, this->y + arg.y, this->z + arg.z, this->w + arg.w);
	}

	DLLAPI_SE Vector4 Vector4::operator+(const Vector4& arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::plus_(float_precision arg) const
	{
		return Vector4(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE Vector4 Vector4::operator+(float_precision arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::minus_(const Vector4& arg) const
	{
		return Vector4(this->x - arg.x, this->y - arg.y, this->z - arg.z, this->w - arg.z);
	}

	DLLAPI_SE Vector4 Vector4::operator-(const Vector4& arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::minus_(float_precision arg) const
	{
		return Vector4(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE Vector4 Vector4::operator-(float_precision arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::ride_(float_precision arg) const
	{
		return Vector4(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE Vector4 Vector4::operator*(float_precision arg) const
	{
		return this->ride_(arg);
	}

	DLLAPI_SE float_precision Vector4::dot_(const Vector4& arg) const
	{
		return this->x * arg.x + this->y * arg.y + this->z * arg.z + this->w * arg.w;
	}

	DLLAPI_SE Vector4 Vector4::cross_(const Vector4& arg) const
	{
		Vector4 ret = Vector4();
		ret.x_() = this->y * arg.z - this->z * arg.y;
		ret.y_() = this->z * arg.x - this->x * arg.z;
		ret.z_() = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector4 Vector4::divide_(float_precision arg) const
	{
		return Vector4(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE Vector4 Vector4::operator/(float_precision arg) const
	{
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector4::norm_without_radical_() const
	{
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void Vector4::operator+=(const Vector4& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4::operator+=(float_precision arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4::operator-=(const Vector4& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector4::operator-=(float_precision arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector4::operator*=(float_precision arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vector4::operator/=(float_precision arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector4::equal_(const Vector4& arg) const
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x) < EPS) && (fabs(this->y - arg.y) < EPS) && (fabs(this->z - arg.z) < EPS) && (fabs(this->w - arg.w) < EPS);
#else
		return (fabsf(this->x - arg.x) < EPS) && (fabsf(this->y - arg.y) < EPS) && (fabsf(this->z - arg.z) < EPS) && (fabsf(this->w - arg.w) < EPS);
#endif
	}

	DLLAPI_SE bool Vector4::operator==(const Vector4& arg) const
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector4::unequal_(const Vector4& arg) const
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector4::operator!=(const Vector4& arg) const
	{
		return this->unequal_(arg);
	}

	Vector4::Vector4()
	{
		this->x = 0.0;
		this->y = 0.0;
		this->z = 0.0;
		this->w = 0.0;
	}

	Vector4::Vector4(float_precision arg_x, float_precision arg_y, float_precision arg_z, float_precision arg_w)
	{
		this->x = arg_x;
		this->y = arg_y;
		this->z = arg_z;
		this->w = arg_w;
	}
}
