// s_vector_3.cpp
//implement of SVector3

#include "s_vector_3.h"

namespace stapler_engine::vector {

	DLLAPI_SE float_precision& SVector3::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE SVector3 SVector3::plus_(const SVector3& arg) const {
		return SVector3(this->x + arg.x, this->y + arg.y, this->z + arg.z);
	}

	DLLAPI_SE SVector3 SVector3::operator+(const SVector3& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector3 SVector3::plus_(float_precision arg) const {
		return SVector3(this->x + arg, this->y + arg, this->z + arg);
	}

	DLLAPI_SE SVector3 SVector3::operator+(float_precision arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector3 SVector3::minus_(const SVector3& arg) const {
		return SVector3(this->x - arg.x, this->y - arg.y, this->z - arg.z);
	}

	DLLAPI_SE SVector3 SVector3::operator-(const SVector3& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector3 SVector3::minus_(float_precision arg) const {
		return SVector3(this->x - arg, this->y - arg, this->z - arg);
	}

	DLLAPI_SE SVector3 SVector3::operator-(float_precision arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector3 SVector3::multiply_(float_precision arg) const {
		return SVector3(this->x * arg, this->y * arg, this->z * arg);
	}

	DLLAPI_SE SVector3 SVector3::operator*(float_precision arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE float_precision SVector3::dot_(const SVector3& arg) const {
		return this->x * arg.x + this->y * arg.y + this->z * arg.z;
	}

	DLLAPI_SE SVector3 SVector3::cross_(const SVector3& arg) const {
		SVector3 ret = SVector3();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE SVector3 SVector3::divide_(float_precision arg) const {
		return SVector3(this->x / arg, this->y / arg, this->z / arg);
	}

	DLLAPI_SE SVector3 SVector3::operator/(float_precision arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision SVector3::length_squared_() const {
		return x * x + y * y + z * z;
	}

	DLLAPI_SE void SVector3::operator+=(const SVector3& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector3::operator+=(float_precision arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector3::operator-=(const SVector3& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector3::operator-=(float_precision arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector3::operator*=(float_precision arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void SVector3::operator/=(float_precision arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool SVector3::equal_(const SVector3& arg) const {
		return (math::SMath::fabs(this->x - arg.x) < EPS)
			&& (math::SMath::fabs(this->y - arg.y) < EPS)
			&& (math::SMath::fabs(this->z - arg.z) < EPS);
	}

	DLLAPI_SE bool SVector3::operator==(const SVector3& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool SVector3::unequal_(const SVector3& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool SVector3::operator!=(const SVector3& arg) const {
		return this->unequal_(arg);
	}

	SVector3::SVector3() {
		coord[0] = 0.0;
		coord[1] = 0.0;
		coord[2] = 0.0;
	}

	SVector3::SVector3(float_precision arg_x, float_precision arg_y, float_precision arg_z) {
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
	}
}
