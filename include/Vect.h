// vec.h
#pragma once

#define VEC_H
#include "SEDefinition.h"
#include <iostream>

#define VEC2(vec) (vec).m_fnx(), (vec).m_fny()
#define VEC3(vec) (vec).m_fnx(), (vec).m_fny(), (vec).m_fnz()
#define TVEC2(vec,type) (type)(vec).m_fnx(), (type)(vec).m_fny()
#define TVEC3(vec,type) (type)(vec).m_fnx(), (type)(vec).m_fny(), (type)(vec).m_fnz()
#define OVEC2(vec) (vec).m_fny(), (vec).m_fnx()
#define OTVEC2(vec,type) (type)(vec).m_fny(), (type)(vec).m_fnx()
// 2D point
class DLLAPI_SE Vec2 {
protected:
	float m_dx, m_dy;
public:
	friend std::ostream& operator<<(std::ostream& out, const Vec2& s) {
		out << s.m_fnx() << "," << s.m_fny();
		return out;
	};
	Vec2 operator+(Vec2);
	Vec2 operator-(Vec2);
	Vec2 operator+=(Vec2);
	Vec2 operator-=(Vec2);
	bool operator==(Vec2);
	bool operator!=(Vec2);
	const float& m_fnx() const;
	const float& m_fny() const;
	void m_fnx(float);
	void m_fny(float);
	Vec2();
	Vec2(float, float);
};

// 3D point
class DLLAPI_SE Vec3 {
protected:
	float m_dx, m_dy, m_dz;
public:
	friend std::ostream& operator<<(std::ostream& out, const Vec3& s) {
		out << s.m_fnx() << "," << s.m_fny() << "," << s.m_fnz();
		return out;
	};
	Vec3 operator+(Vec3);
	Vec3 operator-(Vec3);
	Vec3 operator+=(Vec3);
	Vec3 operator-=(Vec3);
	bool operator==(Vec3);
	bool operator!=(Vec3);
	const float& m_fnx() const;
	const float& m_fny() const;
	const float& m_fnz() const;
	void m_fnx(float);
	void m_fny(float);
	void m_fnz(float);
	Vec3();
	Vec3(float, float, float);
};

// 3D rotate
class DLLAPI_SE dirt {
protected:
	double m_dxy, m_dxz, m_dyz;
public:
	friend std::ostream& operator<<(std::ostream& out, const dirt& s) {
		out << s.m_dxy << "," << s.m_dxz << "," << s.m_dyz;
		return out;
	};
	double m_fnxy() const;
	double m_fnxz() const;
	double m_fnyz() const;
	dirt();
	dirt(double, double, double);
};