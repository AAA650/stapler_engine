// vec_2.cpp
#include "../../../lib/stapler_engine/vector/vec_2.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const float_precision Vec2::x_()
	{
		return x;
	}

	DLLAPI_SE void Vec2::x_(float_precision arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const float_precision Vec2::y_()
	{
		return y;
	}

	DLLAPI_SE void Vec2::y_(float_precision arg)
	{
		this->y = arg;
	}

	DLLAPI_SE Vec2 Vec2::plus_(Vec2& arg)
	{
		return Vec2(this->x + arg.x_(), this->y + arg.y_());
	}

	DLLAPI_SE Vec2 Vec2::operator+(Vec2& arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec2 Vec2::plus_(float_precision arg)
	{
		return Vec2(this->x + arg, this->y + arg);
	}

	DLLAPI_SE Vec2 Vec2::operator+(float_precision arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec2 Vec2::minus_(Vec2& arg)
	{
		return Vec2(this->x - arg.x_(), this->y - arg.y_());
	}

	DLLAPI_SE Vec2 Vec2::operator-(Vec2& arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec2 Vec2::minus_(float_precision arg)
	{
		return Vec2(this->x - arg, this->y - arg);
	}

	DLLAPI_SE Vec2 Vec2::operator-(float_precision arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec2 Vec2::ride_(float_precision arg)
	{
		return Vec2(this->x * arg, this->y * arg);
	}

	DLLAPI_SE Vec2 Vec2::operator*(float_precision arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE float_precision Vec2::dot_(Vec2& arg)
	{
		return this->x * arg.x_() + this->y * arg.y_();
	}

	DLLAPI_SE float_precision Vec2::cross_(Vec2& arg)
	{
		return this->x * arg.y_() - this->y * arg.x_();
	}

	DLLAPI_SE Vec2 Vec2::divide_(float_precision arg)
	{
		return Vec2(this->x / arg, this->y / arg);
	}

	DLLAPI_SE Vec2 Vec2::operator/(float_precision arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE void Vec2::operator+=(Vec2& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec2::operator+=(float_precision arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec2::operator-=(Vec2& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec2::operator-=(float_precision arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec2::operator*=(float_precision arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vec2::operator/=(float_precision arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vec2::equal_(Vec2& arg)
	{
#ifdef USING_DOUBLE_VEC
		return (fabs(this->x - arg.x_()) < EPS) && (fabs(this->y - arg.y_()) < EPS);
#else
		return (fabsf(this->x - arg.x_()) < EPS) && (fabsf(this->y - arg.y_()) < EPS);
#endif
	}

	DLLAPI_SE bool Vec2::operator==(Vec2& arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vec2::unequal_(Vec2& arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vec2::operator!=(Vec2& arg)
	{
		return this->unequal_(arg);
	}

	Vec2::Vec2()
	{
		this->x = 0.0;
		this->y = 0.0;
	}

	Vec2::Vec2(float_precision arg_x, float_precision arg_y)
	{
		this->x = arg_x;
		this->y = arg_y;
	}
}