// s_vector_3i.cpp
// implement of SVector3i

#include "s_vector_3i.h"

namespace stapler_engine::vector {

	DLLAPI_SE int& SVector3i::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE SVector3i SVector3i::plus_(const SVector3i& arg) const {
		return SVector3i(this->x + arg.x, this->y + arg.y, this->z + arg.z);
	}

	DLLAPI_SE SVector3i SVector3i::operator+(const SVector3i& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector3i SVector3i::plus_(int arg) const {
		return SVector3i(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator+(int arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector3i SVector3i::minus_(const SVector3i& arg) const {
		return SVector3i(this->x - arg.x, this->y - arg.y, this->z - arg.z);
	}

	DLLAPI_SE SVector3i SVector3i::operator-(const SVector3i& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector3i SVector3i::minus_(int arg) const {
		return SVector3i(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator-(int arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector3i SVector3i::multiply_(int arg) const {
		return SVector3i(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator*(int arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE int SVector3i::dot_(const SVector3i& arg) const {
		return this->x * arg.x + this->y * arg.y + this->z * arg.z;
	}

	DLLAPI_SE SVector3i SVector3i::cross_(const SVector3i& arg) const {
		SVector3i ret = SVector3i();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE SVector3i SVector3i::divide_(int arg) const {
		return SVector3i(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE SVector3i SVector3i::operator/(int arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE int SVector3i::length_squared_() const {
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void SVector3i::operator+=(const SVector3i& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector3i::operator+=(int arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector3i::operator-=(const SVector3i& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector3i::operator-=(int arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector3i::operator*=(int arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void SVector3i::operator/=(int arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool SVector3i::equal_(const SVector3i& arg) const {
		return (this->x == arg.x) && (this->y == arg.y) && (this->z == arg.z);
	}

	DLLAPI_SE bool SVector3i::operator==(const SVector3i& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool SVector3i::unequal_(const SVector3i& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool SVector3i::operator!=(const SVector3i& arg) const {
		return this->unequal_(arg);
	}

	SVector3i::SVector3i() {
		coord[0] = 0;
		coord[1] = 0;
		coord[2] = 0;
	}

	SVector3i::SVector3i(int arg_x, int arg_y, int arg_z) {
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
	}
}
