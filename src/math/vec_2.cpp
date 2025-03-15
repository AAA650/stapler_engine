// vec_2.cpp
#include "../../include/math/vec_2.h"

namespace stapler_engine::vec {

	DLLAPI_SE float_precision& Vector2::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE Vector2 Vector2::plus_(const Vector2& arg) const {
		return Vector2(this->x + arg.x, this->y + arg.y);
	}

	DLLAPI_SE Vector2 Vector2::operator+(const Vector2& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::plus_(float_precision arg) const {
		return Vector2(this->x + arg, this->y + arg);
	}

	DLLAPI_SE Vector2 Vector2::operator+(float_precision arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::minus_(const Vector2& arg) const {
		return Vector2(this->x - arg.x, this->y - arg.y);
	}

	DLLAPI_SE Vector2 Vector2::operator-(const Vector2& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::minus_(float_precision arg) const {
		return Vector2(this->x - arg, this->y - arg);
	}

	DLLAPI_SE Vector2 Vector2::operator-(float_precision arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2 Vector2::multiply_(float_precision arg) const {
		return Vector2(this->x * arg, this->y * arg);
	}

	DLLAPI_SE Vector2 Vector2::operator*(float_precision arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE float_precision Vector2::dot_(const Vector2& arg) const {
		return this->x * arg.x + this->y * arg.y;
	}

	DLLAPI_SE float_precision Vector2::cross_(const Vector2& arg) const {
		return this->x * arg.y - this->y * arg.x;
	}

	DLLAPI_SE Vector2 Vector2::divide_(float_precision arg) const {
		return Vector2(this->x / arg, this->y / arg);
	}

	DLLAPI_SE Vector2 Vector2::operator/(float_precision arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector2::length_squared_() const {
		return x * x + y * y;
	}

	DLLAPI_SE void Vector2::operator+=(const Vector2& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2::operator+=(float_precision arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2::operator-=(const Vector2& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2::operator-=(float_precision arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2::operator*=(float_precision arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void Vector2::operator/=(float_precision arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector2::equal_(const Vector2& arg) const {
		return (math::Math::fabs(this->x - arg.x) < EPS)
			&& (math::Math::fabs(this->y - arg.y) < EPS);
	}

	DLLAPI_SE bool Vector2::operator==(const Vector2& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector2::unequal_(const Vector2& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector2::operator!=(const Vector2& arg) const {
		return this->unequal_(arg);
	}

	Vector2::Vector2() {
		coord[0] = 0.0;
		coord[1] = 0.0;
	}

	Vector2::Vector2(float_precision arg_x, float_precision arg_y) {
		coord[0] = arg_x;
		coord[1] = arg_y;
	}
}