// vec_2i.cpp
#include "../../../lib/stapler_engine/vector/vec_2i.h"

namespace stapler_engine::vec 
{
	DLLAPI_SE const int Vector2i::x_()
	{
		return x;
	}

	DLLAPI_SE void Vector2i::x_(int arg)
	{
		this->x = arg;
	}

	DLLAPI_SE const int Vector2i::y_()
	{
		return y;
	}

	DLLAPI_SE void Vector2i::y_(int arg)
	{
		this->y = arg;
	}

	DLLAPI_SE Vector2i Vector2i::plus_(Vector2i arg)
	{
		return Vector2i(this->x + arg.x_(), this->y + arg.y_());
	}

	DLLAPI_SE Vector2i Vector2i::operator+(Vector2i arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::plus_(int arg)
	{
		return Vector2i(this->x + arg, this->y + arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator+(int arg)
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::minus_(Vector2i arg)
	{
		return Vector2i(this->x - arg.x_(), this->y - arg.y_());
	}

	DLLAPI_SE Vector2i Vector2i::operator-(Vector2i arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::minus_(int arg)
	{
		return Vector2i(this->x - arg, this->y - arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator-(int arg)
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::ride_(int arg)
	{
		return Vector2i(this->x * arg, this->y * arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator*(int arg)
	{
		return this->ride_(arg);
	}

	DLLAPI_SE int Vector2i::dot_(Vector2i arg)
	{
		return this->x * arg.x_() + this->y * arg.y_();
	}

	DLLAPI_SE int Vector2i::cross_(Vector2i arg)
	{
		return this->x * arg.y_() - this->y * arg.x_();
	}

	DLLAPI_SE Vector2i Vector2i::divide_(int arg)
	{
		return Vector2i(this->x / arg, this->y / arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator/(int arg)
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int Vector2i::norm_without_radical_()
	{
		return x * x + y * y;
	}

	DLLAPI_SE void Vector2i::operator+=(Vector2i arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2i::operator-=(Vector2i arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2i::operator*=(int arg)
	{
		*this = this->ride_(arg);
	}

	DLLAPI_SE void Vector2i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector2i::equal_(Vector2i arg)
	{
		return this->x == arg.x_() && this->y == arg.y_();
	}

	DLLAPI_SE bool Vector2i::operator==(Vector2i arg)
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector2i::unequal_(Vector2i arg)
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector2i::operator!=(Vector2i arg)
	{
		return this->unequal_(arg);
	}

	Vector2i::Vector2i()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector2i::Vector2i(int arg_x, int arg_y)
	{
		this->x = arg_x;
		this->y = arg_y;
	}
}
