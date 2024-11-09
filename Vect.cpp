// vec.cpp methods in vec.h
#include "pch.h"
#include "include/Vect.h"

// class Vec2 methods
DLLAPI_SE Vec2 Vec2::operator+(Vec2 Input) {
	Vec2 out;
	out.x_ = x_ + Input.x_;
	out.y_ = y_ + Input.y_;
	return out;
};
DLLAPI_SE Vec2 Vec2::operator-(Vec2 Input) {
	Vec2 out;
	out.x_ = x_ - Input.x_;
	out.y_ = y_ - Input.y_;
	return out;
};
DLLAPI_SE Vec2 Vec2::operator+=(Vec2 Input) {
	x_ += Input.x_;
	y_ += Input.y_;
	return *this;
};
DLLAPI_SE Vec2 Vec2::operator-=(Vec2 Input) {
	x_ -= Input.x_;
	y_ -= Input.y_;
	return *this;
};
DLLAPI_SE bool Vec2::operator==(Vec2 Input) {
	return x_ == Input.x_ && y_ == Input.y_;
};
DLLAPI_SE bool Vec2::operator!=(Vec2 Input) {
	return x_ != Input.x_ || y_ != Input.y_;
};

Vec2::Vec2() { x_ = 0; y_ = 0; };
Vec2::Vec2(double dInx, double dIny) {
	x_ = dInx;
	y_ = dIny;
};

// class Vec3 methods
DLLAPI_SE Vec3 Vec3::operator+(Vec3 Input) {
	Vec3 out;
	out.x_ = x_ + Input.x_;
	out.y_ = y_ + Input.y_;
	out.z_ = z_ + Input.z_;
	return out;
};
DLLAPI_SE Vec3 Vec3::operator-(Vec3 Input) {
	Vec3 out;
	out.x_ = x_ - Input.x_;
	out.y_ = y_ - Input.y_;
	out.z_ = z_ - Input.z_;
	return out;
};
DLLAPI_SE Vec3 Vec3::operator+=(Vec3 Input) {
	x_ += Input.x_;
	y_ += Input.y_;
	z_ += Input.z_;
	return *this;
};
DLLAPI_SE Vec3 Vec3::operator-=(Vec3 Input) {
	x_ -= Input.x_;
	y_ -= Input.y_;
	z_ -= Input.z_;
	return *this;
};
DLLAPI_SE bool Vec3::operator==(Vec3 Input) {
	return x_ == Input.x_ && y_ == Input.y_ && z_ == Input.z_;
};
DLLAPI_SE bool Vec3::operator!=(Vec3 Input) {
	return x_ != Input.x_ || y_ != Input.y_ || z_ != Input.z_;
};

Vec3::Vec3() { x_ = 0; y_ = 0; z_ = 0; };
Vec3::Vec3(double dInx, double dIny, double dInz) {
	x_ = dInx;
	y_ = dIny;
	z_ = dInz;
};

// class dirt methods
dirt::dirt() { x_y_ = 0; y_z_ = 0; x_z_ = 0; };
dirt::dirt(double dInxy, double dInxz, double dInyz) {
	x_y_ = dInxy;
	x_z_ = dInxz;
	y_z_ = dInyz;
};