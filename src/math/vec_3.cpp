// vec_3.cpp
#include "../../include/math/vec_3.h"

namespace stapler_engine::vec {

	DLLAPI_SE float_precision& Vector3::x_() {
		return x;
	}

	DLLAPI_SE float_precision& Vector3::y_() {
		return y;
	}

	DLLAPI_SE float_precision& Vector3::z_() {
		return z;
	}

	DLLAPI_SE float_precision& Vector3::width_() {
		return x;
	}

	DLLAPI_SE float_precision& Vector3::height_() {
		return y;
	}

	DLLAPI_SE float_precision& Vector3::depth_() {
		return z;
	}

	DLLAPI_SE float_precision& Vector3::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE Vector3 Vector3::plus_(const Vector3& arg) const {
		return Vector3(this->x + arg.x, this->y + arg.y, this->z + arg.z);
	}

	DLLAPI_SE Vector3 Vector3::operator+(const Vector3& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::plus_(float_precision arg) const {
		return Vector3(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE Vector3 Vector3::operator+(float_precision arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::minus_(const Vector3& arg) const {
		return Vector3(this->x - arg.x, this->y - arg.y, this->z - arg.z);
	}

	DLLAPI_SE Vector3 Vector3::operator-(const Vector3& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::minus_(float_precision arg) const {
		return Vector3(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE Vector3 Vector3::operator-(float_precision arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector3 Vector3::multiply_(float_precision arg) const {
		return Vector3(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE Vector3 Vector3::operator*(float_precision arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE float_precision Vector3::dot_(const Vector3& arg) const {
		return this->x * arg.x + this->y * arg.y + this->z * arg.z;
	}

	DLLAPI_SE Vector3 Vector3::cross_(const Vector3& arg) const {
		Vector3 ret = Vector3();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector3 Vector3::divide_(float_precision arg) const {
		return Vector3(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE Vector3 Vector3::operator/(float_precision arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector3::length_squared_() const {
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void Vector3::operator+=(const Vector3& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3::operator+=(float_precision arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector3::operator-=(const Vector3& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3::operator-=(float_precision arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector3::operator*=(float_precision arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void Vector3::operator/=(float_precision arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector3::equal_(const Vector3& arg) const {
		return (math::Math::fabs(this->x - arg.x) < EPS)
			&& (math::Math::fabs(this->y - arg.y) < EPS)
			&& (math::Math::fabs(this->z - arg.z) < EPS);
	}

	DLLAPI_SE bool Vector3::operator==(const Vector3& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector3::unequal_(const Vector3& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector3::operator!=(const Vector3& arg) const {
		return this->unequal_(arg);
	}

	Vector3::Vector3() {
		coord[0] = 0.0;
		coord[1] = 0.0;
		coord[2] = 0.0;
	}

	Vector3::Vector3(float_precision arg_x, float_precision arg_y, float_precision arg_z) {
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
	}
}
