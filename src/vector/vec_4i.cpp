// vec_4i.cpp
#include "../../include/vector/vec_4i.h"

namespace stapler_engine::vec {

	DLLAPI_SE int& Vector4i::x_() {
		return x;
	}

	DLLAPI_SE int& Vector4i::y_() {
		return y;
	}

	DLLAPI_SE int& Vector4i::z_() {
		return z;
	}

	DLLAPI_SE int& Vector4i::w_() {
		return w;
	}

	DLLAPI_SE int& Vector4i::r_() {
		return x;
	}

	DLLAPI_SE int& Vector4i::g_() {
		return y;
	}

	DLLAPI_SE int& Vector4i::b_() {
		return z;
	}

	DLLAPI_SE int& Vector4i::a_() {
		return w;
	}

	DLLAPI_SE int& Vector4i::operator[](int axis_index) {
		return coord[axis_index];
	}

	DLLAPI_SE Vector4i Vector4i::plus_(const Vector4i& arg) const
	{
		return Vector4i(this->x + arg.x, this->y + arg.y, this->z + arg.z, this->w + arg.w);
	}

	DLLAPI_SE Vector4i Vector4i::operator+(const Vector4i& arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4i Vector4i::plus_(int arg) const
	{
		return Vector4i(this->x + arg, this->y + arg, this->z + arg, this->w + arg);
	}

	DLLAPI_SE Vector4i Vector4i::operator+(int arg) const
	{
		return this->plus_(arg);
	}

	DLLAPI_SE Vector4i Vector4i::minus_(const Vector4i& arg) const
	{
		return Vector4i(this->x - arg.x, this->y - arg.y, this->z - arg.z, this->w - arg.z);
	}

	DLLAPI_SE Vector4i Vector4i::operator-(const Vector4i& arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4i Vector4i::minus_(int arg) const
	{
		return Vector4i(this->x - arg, this->y - arg, this->z - arg, this->w - arg);
	}

	DLLAPI_SE Vector4i Vector4i::operator-(int arg) const
	{
		return this->minus_(arg);
	}

	DLLAPI_SE Vector4i Vector4i::multiply_(int arg) const
	{
		return Vector4i(this->x * arg, this->y * arg, this->z * arg, this->w * arg);
	}

	DLLAPI_SE Vector4i Vector4i::operator*(int arg) const
	{
		return this->multiply_(arg);
	}

	DLLAPI_SE int Vector4i::dot_(const Vector4i& arg) const
	{
		return this->x * arg.x + this->y * arg.y + this->z * arg.z + this->w * arg.w;
	}

	DLLAPI_SE Vector4i Vector4i::cross_(const Vector4i& arg) const
	{
		Vector4i ret = Vector4i();
		ret.x = this->y * arg.z - this->z * arg.y;
		ret.y = this->z * arg.x - this->x * arg.z;
		ret.z = this->x * arg.y - this->y * arg.x;
		return ret;
	}

	DLLAPI_SE Vector4i Vector4i::divide_(int arg) const
	{
		return Vector4i(this->x / arg, this->y / arg, this->z / arg, this->w / arg);
	}

	DLLAPI_SE Vector4i Vector4i::operator/(int arg) const
	{
		return this->divide_(arg);
	}

	DLLAPI_SE int Vector4i::length_squared_() const
	{
		return x * x + y * y + z * z + w * w;
	}

	DLLAPI_SE void Vector4i::operator+=(const Vector4i& arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4i::operator+=(int arg)
	{
		*this = this->plus_(arg);
	}

	DLLAPI_SE void Vector4i::operator-=(const Vector4i& arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector4i::operator-=(int arg)
	{
		*this = this->minus_(arg);
	}

	DLLAPI_SE void Vector4i::operator*=(int arg)
	{
		*this = this->multiply_(arg);
	}

	DLLAPI_SE void Vector4i::operator/=(int arg)
	{
		*this = this->divide_(arg);
	}

	DLLAPI_SE bool Vector4i::equal_(const Vector4i& arg) const
	{
		return (this->x == arg.x) && (this->y == arg.y) && (this->z == arg.z) && (this->w == arg.w);
	}

	DLLAPI_SE bool Vector4i::operator==(const Vector4i& arg) const
	{
		return this->equal_(arg);
	}

	DLLAPI_SE bool Vector4i::unequal_(const Vector4i& arg) const
	{
		return !(this->equal_(arg));
	}

	DLLAPI_SE bool Vector4i::operator!=(const Vector4i& arg) const
	{
		return this->unequal_(arg);
	}

	Vector4i::Vector4i()
	{
		coord[0] = 0;
		coord[1] = 0;
		coord[2] = 0;
		coord[3] = 0;
	}

	Vector4i::Vector4i(int arg_x, int arg_y, int arg_z, int arg_w)
	{
		coord[0] = arg_x;
		coord[1] = arg_y;
		coord[2] = arg_z;
		coord[3] = arg_w;
	}
}
