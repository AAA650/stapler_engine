// vec.cpp methods in vec.h
#include "pch.h"
#include "include/vec.h"

// class vecd methods
DLLAPI_SE vecd vecd::operator+(vecd Input) {
	vecd out;
	out.m_dx = m_dx + Input.m_dx;
	out.m_dy = m_dy + Input.m_dy;
	return out;
};
DLLAPI_SE vecd vecd::operator-(vecd Input) {
	vecd out;
	out.m_dx = m_dx - Input.m_dx;
	out.m_dy = m_dy - Input.m_dy;
	return out;
};
DLLAPI_SE vecd vecd::operator+=(vecd Input) {
	m_dx += Input.m_dx;
	m_dy += Input.m_dy;
	return *this;
};
DLLAPI_SE vecd vecd::operator-=(vecd Input) {
	m_dx -= Input.m_dx;
	m_dy -= Input.m_dy;
	return *this;
};
DLLAPI_SE bool vecd::operator==(vecd Input) {
	return m_dx == Input.m_dx && m_dy == Input.m_dy;
};
DLLAPI_SE bool vecd::operator!=(vecd Input) {
	return m_dx != Input.m_dx || m_dy != Input.m_dy;
};
DLLAPI_SE const float& vecd::m_fnx() const {
	return m_dx;
};
DLLAPI_SE const float& vecd::m_fny() const {
	return m_dy;
};
DLLAPI_SE void vecd::m_fnx(float dInx) {
	m_dx = dInx;
};
DLLAPI_SE void vecd::m_fny(float dIny) {
	m_dy = dIny;
};
vecd::vecd() { m_dx = 0; m_dy = 0; };
vecd::vecd(float dInx, float dIny) {
	m_dx = dInx;
	m_dy = dIny;
};

// class vect methods
DLLAPI_SE vect vect::operator+(vect Input) {
	vect out;
	out.m_dx = m_dx + Input.m_dx;
	out.m_dy = m_dy + Input.m_dy;
	out.m_dz = m_dz + Input.m_dz;
	return out;
};
DLLAPI_SE vect vect::operator-(vect Input) {
	vect out;
	out.m_dx = m_dx - Input.m_dx;
	out.m_dy = m_dy - Input.m_dy;
	out.m_dz = m_dz - Input.m_dz;
	return out;
};
DLLAPI_SE vect vect::operator+=(vect Input) {
	m_dx += Input.m_dx;
	m_dy += Input.m_dy;
	m_dz += Input.m_dz;
	return *this;
};
DLLAPI_SE vect vect::operator-=(vect Input) {
	m_dx -= Input.m_dx;
	m_dy -= Input.m_dy;
	m_dz -= Input.m_dz;
	return *this;
};
DLLAPI_SE bool vect::operator==(vect Input) {
	return m_dx == Input.m_dx && m_dy == Input.m_dy && m_dz == Input.m_dz;
};
DLLAPI_SE bool vect::operator!=(vect Input) {
	return m_dx != Input.m_dx || m_dy != Input.m_dy || m_dz != Input.m_dz;
};
DLLAPI_SE const float& vect::m_fnx() const {
	return m_dx;
};
DLLAPI_SE const float& vect::m_fny() const {
	return m_dy;
};
DLLAPI_SE const float& vect::m_fnz() const {
	return m_dz;
};
DLLAPI_SE void vect::m_fnx(float dInx) {
	m_dx = dInx;
};
DLLAPI_SE void vect::m_fny(float dIny) {
	m_dy = dIny;
};
DLLAPI_SE void vect::m_fnz(float dInz) {
	m_dz = dInz;
};
vect::vect() { m_dx = 0; m_dy = 0; m_dz = 0; };
vect::vect(float dInx, float dIny, float dInz) {
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