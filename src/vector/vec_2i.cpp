// vec_2i.cpp
#include "../../include/vector/vec_2i.h"

namespace stapler_engine::vec {

	DLLAPI_SE int& Vector2i::x_() {
		return x;
	}

	DLLAPI_SE int& Vector2i::y_() {
		return y;
	}

	DLLAPI_SE int& Vector2i::width_() {
		return x;
	}

	DLLAPI_SE int& Vector2i::height_() {
		return y;
	}
	DLLAPI_SE int& Vector2i::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE Vector2i Vector2i::plus_(const Vector2i& arg) const {
		return Vector2i(this->x + arg.x, this->y + arg.y);
	}

	DLLAPI_SE Vector2i Vector2i::operator+(const Vector2i& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::plus_(int arg) const {
		return Vector2i(this->x + arg, this->y + arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator+(int arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::minus_(const Vector2i& arg) const {
		return Vector2i(this->x - arg.x, this->y - arg.y);
	}

	DLLAPI_SE Vector2i Vector2i::operator-(const Vector2i& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::minus_(int arg) const {
		return Vector2i(this->x - arg, this->y - arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator-(int arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector2i Vector2i::multiply_(int arg) const {
		return Vector2i(this->x * arg, this->y * arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator*(int arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE int Vector2i::dot_(const Vector2i& arg) const {
		return this->x * arg.x + this->y * arg.y;
	}

	DLLAPI_SE int Vector2i::cross_(const Vector2i& arg) const {
		return this->x * arg.y - this->y * arg.x;
	}

	DLLAPI_SE Vector2i Vector2i::divide_(int arg) const {
		return Vector2i(this->x / arg, this->y / arg);
	}

	DLLAPI_SE Vector2i Vector2i::operator/(int arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE int Vector2i::length_squared_() const {
		return x * x + y * y;
	}

	DLLAPI_SE void Vector2i::operator+=(const Vector2i& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2i::operator+=(int arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector2i::operator-=(const Vector2i& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2i::operator-=(int arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector2i::operator*=(int arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void Vector2i::operator/=(int arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector2i::equal_(const Vector2i& arg) const {
		return this->x == arg.x && this->y == arg.y;
	}

	DLLAPI_SE bool Vector2i::operator==(const Vector2i& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector2i::unequal_(const Vector2i& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector2i::operator!=(const Vector2i& arg) const {
		return this->unequal_(arg);
	}

	Vector2i::Vector2i() {
		coord[0] = 0;
		coord[1] = 0;
	}

	Vector2i::Vector2i(int arg_x, int arg_y) {
		coord[0] = arg_x;
		coord[1] = arg_y;
	}
}
