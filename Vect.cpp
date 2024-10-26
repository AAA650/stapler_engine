// vec.cpp methods in vec.h
#include "pch.h"
#include "include/Vect.h"

// class Vec2 methods
DLLAPI_SE Vec2 Vec2::operator+(Vec2 Input) {
	Vec2 out;
	out.m_dx = m_dx + Input.m_dx;
	out.m_dy = m_dy + Input.m_dy;
	return out;
};
DLLAPI_SE Vec2 Vec2::operator-(Vec2 Input) {
	Vec2 out;
	out.m_dx = m_dx - Input.m_dx;
	out.m_dy = m_dy - Input.m_dy;
	return out;
};
DLLAPI_SE Vec2 Vec2::operator+=(Vec2 Input) {
	m_dx += Input.m_dx;
	m_dy += Input.m_dy;
	return *this;
};
DLLAPI_SE Vec2 Vec2::operator-=(Vec2 Input) {
	m_dx -= Input.m_dx;
	m_dy -= Input.m_dy;
	return *this;
};
DLLAPI_SE bool Vec2::operator==(Vec2 Input) {
	return m_dx == Input.m_dx && m_dy == Input.m_dy;
};
DLLAPI_SE bool Vec2::operator!=(Vec2 Input) {
	return m_dx != Input.m_dx || m_dy != Input.m_dy;
};
DLLAPI_SE const float& Vec2::m_fnx() const {
	return m_dx;
};
DLLAPI_SE const float& Vec2::m_fny() const {
	return m_dy;
};
DLLAPI_SE void Vec2::m_fnx(float dInx) {
	m_dx = dInx;
};
DLLAPI_SE void Vec2::m_fny(float dIny) {
	m_dy = dIny;
};
Vec2::Vec2() { m_dx = 0; m_dy = 0; };
Vec2::Vec2(float dInx, float dIny) {
	m_dx = dInx;
	m_dy = dIny;
};

// class Vec3 methods
DLLAPI_SE Vec3 Vec3::operator+(Vec3 Input) {
	Vec3 out;
	out.m_dx = m_dx + Input.m_dx;
	out.m_dy = m_dy + Input.m_dy;
	out.m_dz = m_dz + Input.m_dz;
	return out;
};
DLLAPI_SE Vec3 Vec3::operator-(Vec3 Input) {
	Vec3 out;
	out.m_dx = m_dx - Input.m_dx;
	out.m_dy = m_dy - Input.m_dy;
	out.m_dz = m_dz - Input.m_dz;
	return out;
};
DLLAPI_SE Vec3 Vec3::operator+=(Vec3 Input) {
	m_dx += Input.m_dx;
	m_dy += Input.m_dy;
	m_dz += Input.m_dz;
	return *this;
};
DLLAPI_SE Vec3 Vec3::operator-=(Vec3 Input) {
	m_dx -= Input.m_dx;
	m_dy -= Input.m_dy;
	m_dz -= Input.m_dz;
	return *this;
};
DLLAPI_SE bool Vec3::operator==(Vec3 Input) {
	return m_dx == Input.m_dx && m_dy == Input.m_dy && m_dz == Input.m_dz;
};
DLLAPI_SE bool Vec3::operator!=(Vec3 Input) {
	return m_dx != Input.m_dx || m_dy != Input.m_dy || m_dz != Input.m_dz;
};
DLLAPI_SE const float& Vec3::m_fnx() const {
	return m_dx;
};
DLLAPI_SE const float& Vec3::m_fny() const {
	return m_dy;
};
DLLAPI_SE const float& Vec3::m_fnz() const {
	return m_dz;
};
DLLAPI_SE void Vec3::m_fnx(float dInx) {
	m_dx = dInx;
};
DLLAPI_SE void Vec3::m_fny(float dIny) {
	m_dy = dIny;
};
DLLAPI_SE void Vec3::m_fnz(float dInz) {
	m_dz = dInz;
};
Vec3::Vec3() { m_dx = 0; m_dy = 0; m_dz = 0; };
Vec3::Vec3(float dInx, float dIny, float dInz) {
	m_dx = dInx;
	m_dy = dIny;
	m_dz = dInz;
};

// class dirt methods
DLLAPI_SE double dirt::m_fnxy() const {
	return m_dxy;
};
DLLAPI_SE double dirt::m_fnxz() const {
	return m_dxz;
};
DLLAPI_SE double dirt::m_fnyz() const {
	return m_dyz;
};
dirt::dirt() { m_dxy = 0; m_dyz = 0; m_dxz = 0; };
dirt::dirt(double dInxy, double dInxz, double dInyz) {
	m_dxy = dInxy;
	m_dxz = dInxz;
	m_dyz = dInyz;
};