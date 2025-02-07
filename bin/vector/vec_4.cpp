// vec_4.cpp
#include "../../lib/vector/vec_4.h"

namespace stapler_engine::vec {

	DLLAPI_SE float_precision& Vector4::x_() {
		return x;
	}

	DLLAPI_SE float_precision& Vector4::y_() {
		return y;
	}

	DLLAPI_SE float_precision& Vector4::z_() {
		return z;
	}

	DLLAPI_SE float_precision& Vector4::w_() {
		return w;
	}

	DLLAPI_SE float_precision& Vector4::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE Vector4 Vector4::plus_(const Vector4& arg) const {
		return Vector4(this->x + arg.x, this->y + arg.y, this->z + arg.z, this->w + arg.w);
	}

	DLLAPI_SE Vector4 Vector4::operator+(const Vector4& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::plus_(float_precision arg) const {
		return Vector4(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE Vector4 Vector4::operator+(float_precision arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::minus_(const Vector4& arg) const {
		return Vector4(this->x - arg.x, this->y - arg.y, this->z - arg.z, this->w - arg.z);
	}

	DLLAPI_SE Vector4 Vector4::operator-(const Vector4& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::minus_(float_precision arg) const {
		return Vector4(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE Vector4 Vector4::operator-(float_precision arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4 Vector4::multiply_(float_precision arg) const {
		return Vector4(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE Vector4 Vector4::operator*(float_precision arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE float_precision Vector4::dot_(const Vector4& arg) const {
		return this->x * arg.x + this->y * arg.y + this->z * arg.z + this->w * arg.w;
	}

	DLLAPI_SE Vector4 Vector4::cross_(const Vector4& arg) const {
		Vector4 ret = Vector4();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector4 Vector4::divide_(float_precision arg) const {
		return Vector4(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE Vector4 Vector4::operator/(float_precision arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision Vector4::length_squared_() const {
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void Vector4::operator+=(const Vector4& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4::operator+=(float_precision arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4::operator-=(const Vector4& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector4::operator-=(float_precision arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector4::operator*=(float_precision arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void Vector4::operator/=(float_precision arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector4::equal_(const Vector4& arg) const {
		return (math::Math::fabs(this->x - arg.x) < EPS)
			&& (math::Math::fabs(this->y - arg.y) < EPS)
			&& (math::Math::fabs(this->z - arg.z) < EPS)
			&& (math::Math::fabs(this->w - arg.w) < EPS);
	}

	DLLAPI_SE bool Vector4::operator==(const Vector4& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector4::unequal_(const Vector4& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector4::operator!=(const Vector4& arg) const {
		return this->unequal_(arg);
	}

	Vector4::Vector4() {
		coord[0] = 0.0;
		coord[1] = 0.0;
		coord[2] = 0.0;
		coord[3] = 0.0;
	}

	Vector4::Vector4(float_precision arg_x, float_precision arg_y, float_precision arg_z, float_precision arg_w) {
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
		coord[3] = arg_w;
	}
}
