// vec_3i.cpp
#include "../../include/math/vec_3i.h"

namespace stapler_engine::vec {

	DLLAPI_SE int& Vector3i::x_() {
		return x;
	}

	DLLAPI_SE int& Vector3i::y_() {
		return y;
	}

	DLLAPI_SE int& Vector3i::z_() {
		return z;
	}

	DLLAPI_SE int& Vector3i::width_() {
		return x;
	}

	DLLAPI_SE int& Vector3i::height_() {
		return y;
	}

	DLLAPI_SE int& Vector3i::depth_() {
		return z;
	}

	DLLAPI_SE int& Vector3i::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE Vector3i Vector3i::plus_(const Vector3i& arg) const {
		return Vector3i(this->x + arg.x, this->y + arg.y, this->z + arg.z);
	}

	DLLAPI_SE Vector3i Vector3i::operator+(const Vector3i& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::plus_(int arg) const {
		return Vector3i(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator+(int arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::minus_(const Vector3i& arg) const {
		return Vector3i(this->x - arg.x, this->y - arg.y, this->z - arg.z);
	}

	DLLAPI_SE Vector3i Vector3i::operator-(const Vector3i& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::minus_(int arg) const {
		return Vector3i(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator-(int arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3i Vector3i::multiply_(int arg) const {
		return Vector3i(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator*(int arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE int Vector3i::dot_(const Vector3i& arg) const {
		return this->x * arg.x + this->y * arg.y + this->z * arg.z;
	}

	DLLAPI_SE Vector3i Vector3i::cross_(const Vector3i& arg) const {
		Vector3i ret = Vector3i();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector3i Vector3i::divide_(int arg) const {
		return Vector3i(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE Vector3i Vector3i::operator/(int arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE int Vector3i::length_squared_() const {
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void Vector3i::operator+=(const Vector3i& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3i::operator+=(int arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3i::operator-=(const Vector3i& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3i::operator-=(int arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3i::operator*=(int arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void Vector3i::operator/=(int arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector3i::equal_(const Vector3i& arg) const {
		return (this->x == arg.x) && (this->y == arg.y) && (this->z == arg.z);
	}

	DLLAPI_SE bool Vector3i::operator==(const Vector3i& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector3i::unequal_(const Vector3i& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector3i::operator!=(const Vector3i& arg) const {
		return this->unequal_(arg);
	}

	Vector3i::Vector3i() {
		coord[0] = 0;
		coord[1] = 0;
		coord[2] = 0;
	}

	Vector3i::Vector3i(int arg_x, int arg_y, int arg_z) {
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
	}
}
