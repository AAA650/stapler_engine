// s_vector_4.cpp
//implement of SVector4

#include "s_vector_4.h"

namespace stapler_engine::vector {

	DLLAPI_SE float_precision& SVector4::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE SVector4 SVector4::plus_(const SVector4& arg) const {
		return SVector4(this->x + arg.x, this->y + arg.y, this->z + arg.z, this->w + arg.w);
	}

	DLLAPI_SE SVector4 SVector4::operator+(const SVector4& arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector4 SVector4::plus_(float_precision arg) const {
		return SVector4(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE SVector4 SVector4::operator+(float_precision arg) const {
		return this->plus_(arg);
	}

	DLLAPI_SE SVector4 SVector4::minus_(const SVector4& arg) const {
		return SVector4(this->x - arg.x, this->y - arg.y, this->z - arg.z, this->w - arg.z);
	}

	DLLAPI_SE SVector4 SVector4::operator-(const SVector4& arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector4 SVector4::minus_(float_precision arg) const {
		return SVector4(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE SVector4 SVector4::operator-(float_precision arg) const {
		return this->minus_(arg);
	}

	DLLAPI_SE SVector4 SVector4::multiply_(float_precision arg) const {
		return SVector4(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE SVector4 SVector4::operator*(float_precision arg) const {
		return this->multiply_(arg);
	}

	DLLAPI_SE float_precision SVector4::dot_(const SVector4& arg) const {
		return this->x * arg.x + this->y * arg.y + this->z * arg.z + this->w * arg.w;
	}

	DLLAPI_SE SVector4 SVector4::cross_(const SVector4& arg) const {
		SVector4 ret = SVector4();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE SVector4 SVector4::divide_(float_precision arg) const {
		return SVector4(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE SVector4 SVector4::operator/(float_precision arg) const {
		return this->divide_(arg);
	}

	DLLAPI_SE float_precision SVector4::length_squared_() const {
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void SVector4::operator+=(const SVector4& arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector4::operator+=(float_precision arg) {
		*this = this->plus_(arg);
	}

	DLLAPI_SE void SVector4::operator-=(const SVector4& arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector4::operator-=(float_precision arg) {
		*this = this->minus_(arg);
	}

	DLLAPI_SE void SVector4::operator*=(float_precision arg) {
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void SVector4::operator/=(float_precision arg) {
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool SVector4::equal_(const SVector4& arg) const {
		return (math::SMath::fabs(this->x - arg.x) < EPS)
			&& (math::SMath::fabs(this->y - arg.y) < EPS)
			&& (math::SMath::fabs(this->z - arg.z) < EPS)
			&& (math::SMath::fabs(this->w - arg.w) < EPS);
	}

	DLLAPI_SE bool SVector4::operator==(const SVector4& arg) const {
		return this->equal_(arg);
	}

	DLLAPI_SE bool SVector4::unequal_(const SVector4& arg) const {
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool SVector4::operator!=(const SVector4& arg) const {
		return this->unequal_(arg);
	}

	SVector4::SVector4() {
		coord[0] = 0.0;
		coord[1] = 0.0;
		coord[2] = 0.0;
		coord[3] = 0.0;
	}

	SVector4::SVector4(float_precision arg_x, float_precision arg_y, float_precision arg_z, float_precision arg_w) {
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
		coord[3] = arg_w;
	}
}
