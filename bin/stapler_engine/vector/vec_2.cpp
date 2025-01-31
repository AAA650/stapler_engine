// vec_2.cpp
#include "../../../lib/stapler_engine/vector/vec_2.h"

namespace stapler_engine::vec 
{
	DLLAPI_SE float_precision& Vector2::x_()
	{
		return x;
	}

	DLLAPI_SE float_precision& Vector2::y_()
	{
		return y;
	}

	DLLAPI_SE Vector2 Vector2::plus_(const Vector2& arg) const
	{
		return Vector2(this->x + arg.x, this->y + arg.y);
	}

	DLLAPI_SE Vector2 Vector2::operator+(const Vector2& arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::plus_(float_precision arg) const
	{
		return Vector2(this->x + arg, this->y + arg);
	}

	DLLAPI_SE Vector2 Vector2::operator+(float_precision arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::minus_(const Vector2& arg) const
	{
		return Vector2(this->x - arg.x, this->y - arg.y);
	}

	DLLAPI_SE Vector2 Vector2::operator-(const Vector2& arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::minus_(float_precision arg) const
	{
		return Vector2(this->x - arg, this->y - arg);
	}

	DLLAPI_SE Vector2 Vector2::operator-(float_precision arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::ride_(float_precision arg) const
	{
		return Vector2(this->x * arg, this->y * arg);
	}

	DLLAPI_SE Vector2 Vector2::operator*(float_precision arg) const
	{
		return this->ride_(arg);
	}

	DLLAPI_SE float_precision Vector2::dot_(const Vector2& arg) const
	{
		return this->x * arg.x + this->y * arg.y;
	}

	DLLAPI_SE float_precision Vector2::cross_(const Vector2& arg) const
	{
		return this->x * arg.y - this->y * arg.x;
	}

	DLLAPI_SE Vector2 Vector2::divide_(float_precision arg) const
	{
		return Vector2(this->x / arg, this->y / arg);
	}

	DLLAPI_SE Vector2 Vector2::operator/(float_precision arg) const
	{
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector2::norm_without_radical_() const
	{
		return x * x + y * y;
	}

	DLLAPI_SE void Vector2::operator+=(const Vector2& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2::operator+=(float_precision arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2::operator-=(const Vector2& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2::operator-=(float_precision arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2::operator*=(float_precision arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vector2::operator/=(float_precision arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector2::equal_(const Vector2& arg) const
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x) < EPS) && (fabs(this->y - arg.y) < EPS);
#else
		return (fabsf(this->x - arg.x) < EPS) && (fabsf(this->y - arg.y) < EPS);
#endif
	}

	DLLAPI_SE bool Vector2::operator==(const Vector2& arg) const
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector2::unequal_(const Vector2& arg) const
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector2::operator!=(const Vector2& arg) const
	{
		return this->unequal_(arg);
	}

	Vector2::Vector2()
	{
		this->x = 0.0;
		this->y = 0.0;
	}

	Vector2::Vector2(float_precision arg_x, float_precision arg_y)
	{
		this->x = arg_x;
		this->y = arg_y;
	}
}