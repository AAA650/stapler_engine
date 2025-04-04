// s_vector_2i.cpp
// implement of SVector2i

#include "s_vector_2i.h"

namespace stapler_engine::vector {

	DLLAPI_SE int& SVector2i::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE SVector2i SVector2i::plus_(const SVector2i& arg) const {
		return SVector2i(this->x + arg.x, this->y + arg.y);
	}

	DLLAPI_SE SVector2i SVector2i::operator+(const SVector2i& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector2i SVector2i::plus_(int arg) const {
		return SVector2i(this->x + arg, this->y + arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator+(int arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector2i SVector2i::minus_(const SVector2i& arg) const {
		return SVector2i(this->x - arg.x, this->y - arg.y);
	}

	DLLAPI_SE SVector2i SVector2i::operator-(const SVector2i& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector2i SVector2i::minus_(int arg) const {
		return SVector2i(this->x - arg, this->y - arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator-(int arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector2i SVector2i::multiply_(int arg) const {
		return SVector2i(this->x * arg, this->y * arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator*(int arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE int SVector2i::dot_(const SVector2i& arg) const {
		return this->x * arg.x + this->y * arg.y;
	}

	DLLAPI_SE int SVector2i::cross_(const SVector2i& arg) const {
		return this->x * arg.y - this->y * arg.x;
	}

	DLLAPI_SE SVector2i SVector2i::divide_(int arg) const {
		return SVector2i(this->x / arg, this->y / arg);
	}

	DLLAPI_SE SVector2i SVector2i::operator/(int arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE int SVector2i::length_squared_() const {
		return x * x + y * y;
	}

	DLLAPI_SE void SVector2i::operator+=(const SVector2i& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector2i::operator+=(int arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector2i::operator-=(const SVector2i& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector2i::operator-=(int arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector2i::operator*=(int arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void SVector2i::operator/=(int arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool SVector2i::equal_(const SVector2i& arg) const {
		return this->x == arg.x && this->y == arg.y;
	}

	DLLAPI_SE bool SVector2i::operator==(const SVector2i& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool SVector2i::unequal_(const SVector2i& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool SVector2i::operator!=(const SVector2i& arg) const {
		return this->unequal_(arg);
	}

	SVector2i::SVector2i() {
		coord[0] = 0;
		coord[1] = 0;
	}

	SVector2i::SVector2i(int arg_x, int arg_y) {
		coord[0] = arg_x;
		coord[1] = arg_y;
	}
}
