// vec_4.cpp
#include "../../../lib/stapler_engine/vector/vec_4.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const float_precision Vector4::x_()
	{
		return x;
	}

	DLLAPI_SE void Vector4::x_(float_precision arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const float_precision Vector4::y_()
	{
		return y;
	}

	DLLAPI_SE void Vector4::y_(float_precision arg)
	{
		this->y = arg;
	}

	DLLAPI_SE const float_precision Vector4::z_()
	{
		return z;
	}

	DLLAPI_SE void Vector4::z_(float_precision arg)
	{
		this->z = arg;
	}

	DLLAPI_SE const float_precision Vector4::w_()
	{
		return w;
	}

	DLLAPI_SE void Vector4::w_(float_precision arg)
	{
		this->w = arg;
	}

	DLLAPI_SE Vector4 Vector4::plus_(Vector4& arg)
	{
		return Vector4(this->x + arg.x_(), this->y + arg.y_(), this->z + arg.z_(), this->w + arg.w_());
	}

	DLLAPI_SE Vector4 Vector4::operator+(Vector4& arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::plus_(float_precision arg)
	{
		return Vector4(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE Vector4 Vector4::operator+(float_precision arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::minus_(Vector4& arg)
	{
		return Vector4(this->x - arg.x_(), this->y - arg.y_(), this->z - arg.z_(), this->w - arg.z_());
	}

	DLLAPI_SE Vector4 Vector4::operator-(Vector4& arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::minus_(float_precision arg)
	{
		return Vector4(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE Vector4 Vector4::operator-(float_precision arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::ride_(float_precision arg)
	{
		return Vector4(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE Vector4 Vector4::operator*(float_precision arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE float_precision Vector4::dot_(Vector4& arg)
	{
		return this->x * arg.x_() + this->y * arg.y_() + this->z * arg.z_() + this->w * arg.w_();
	}

	DLLAPI_SE Vector4 Vector4::cross_(Vector4& arg)
	{
		Vector4 ret = Vector4();
		ret.x_(this->y * arg.z_() - this->z * arg.y_());
		ret.y_(this->z * arg.x_() - this->x * arg.z_());
		ret.z_(this->x * arg.y_() - this->y * arg.x_());
		return ret;
	}

	DLLAPI_SE Vector4 Vector4::divide_(float_precision arg)
	{
		return Vector4(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE Vector4 Vector4::operator/(float_precision arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector4::norm_without_radical_()
	{
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void Vector4::operator+=(Vector4& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4::operator+=(float_precision arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4::operator-=(Vector4& arg)
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

	DLLAPI_SE bool Vector4::equal_(Vector4& arg)
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x_()) < EPS) && (fabs(this->y - arg.y_()) < EPS) && (fabs(this->z - arg.z_()) < EPS) && (fabs(this->w - arg.w_()) < EPS);
#else
		return (fabsf(this->x - arg.x_()) < EPS) && (fabsf(this->y - arg.y_()) < EPS) && (fabsf(this->z - arg.z_()) < EPS) && (fabsf(this->w - arg.w_()) < EPS);
#endif
	}

	DLLAPI_SE bool Vector4::operator==(Vector4& arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector4::unequal_(Vector4& arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector4::operator!=(Vector4& arg)
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
