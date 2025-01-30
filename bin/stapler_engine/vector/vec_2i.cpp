// vec_2i.cpp
#include "../../../lib/stapler_engine/vector/vec_2i.h"

namespace stapler_engine::vector 
{
	DLLAPI_SE const int Vec2i::x_()
	{
		return x;
	}

	DLLAPI_SE void Vec2i::x_(int arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const int Vec2i::y_()
	{
		return y;
	}

	DLLAPI_SE void Vec2i::y_(int arg)
	{
		this->y = arg;
	}

	DLLAPI_SE Vec2i Vec2i::plus_(Vec2i& arg)
	{
		return Vec2i(this->x + arg.x_(), this->y + arg.y_());
	}

	DLLAPI_SE Vec2i Vec2i::operator+(Vec2i& arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec2i Vec2i::plus_(int arg)
	{
		return Vec2i(this->x + arg, this->y + arg);
	}

	DLLAPI_SE Vec2i Vec2i::operator+(int arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vec2i Vec2i::minus_(Vec2i& arg)
	{
		return Vec2i(this->x - arg.x_(), this->y - arg.y_());
	}

	DLLAPI_SE Vec2i Vec2i::operator-(Vec2i& arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec2i Vec2i::minus_(int arg)
	{
		return Vec2i(this->x - arg, this->y - arg);
	}

	DLLAPI_SE Vec2i Vec2i::operator-(int arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vec2i Vec2i::ride_(int arg)
	{
		return Vec2i(this->x * arg, this->y * arg);
	}

	DLLAPI_SE Vec2i Vec2i::operator*(int arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE int Vec2i::dot_(Vec2i& arg)
	{
		return this->x * arg.x_() + this->y * arg.y_();
	}

	DLLAPI_SE int Vec2i::cross_(Vec2i& arg)
	{
		return this->x * arg.y_() - this->y * arg.x_();
	}

	DLLAPI_SE Vec2i Vec2i::divide_(int arg)
	{
		return Vec2i(this->x / arg, this->y / arg);
	}

	DLLAPI_SE Vec2i Vec2i::operator/(int arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int Vec2i::norm_without_radical_()
	{
		return x * x + y * y;
	}

	DLLAPI_SE void Vec2i::operator+=(Vec2i& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec2i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vec2i::operator-=(Vec2i& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec2i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vec2i::operator*=(int arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vec2i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vec2i::equal_(Vec2i& arg)
	{
		return this->x == arg.x_() && this->y == arg.y_();
	}

	DLLAPI_SE bool Vec2i::operator==(Vec2i& arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vec2i::unequal_(Vec2i& arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vec2i::operator!=(Vec2i& arg)
	{
		return this->unequal_(arg);
	}

	Vec2i::Vec2i()
	{
		this->x = 0;
		this->y = 0;
	}

	Vec2i::Vec2i(int arg_x, int arg_y)
	{
		this->x = arg_x;
		this->y = arg_y;
	}
}
