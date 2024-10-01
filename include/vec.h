// vec.h
#pragma once

#define VEC_H
#include "SEDefinition.h"
#include <iostream>

#define VECD(vec) (vec).m_fnx(), (vec).m_fny()
#define VECT(vec) (vec).m_fnx(), (vec).m_fny(), (vec).m_fnz()
#define TVECD(vec,type) (type)(vec).m_fnx(), (type)(vec).m_fny()
#define TVECT(vec,type) (type)(vec).m_fnx(), (type)(vec).m_fny(), (type)(vec).m_fnz()
#define OVECD(vec) (vec).m_fny(), (vec).m_fnx()
#define OTVECD(vec,type) (type)(vec).m_fny(), (type)(vec).m_fnx()
// 2D point
class DLLAPI_SE vecd {
protected:
	float m_dx, m_dy;
public:
	friend std::ostream& operator<<(std::ostream& out, const vecd& s) {
		out << s.m_fnx() << "," << s.m_fny();
		return out;
	};
	vecd operator+(vecd);
	vecd operator-(vecd);
	vecd operator+=(vecd);
	vecd operator-=(vecd);
	bool operator==(vecd);
	bool operator!=(vecd);
	const float& m_fnx() const;
	const float& m_fny() const;
	void m_fnx(float);
	void m_fny(float);
	vecd();
	vecd(float, float);
};

// 3D point
class DLLAPI_SE vect {
protected:
	float m_dx, m_dy, m_dz;
public:
	friend std::ostream& operator<<(std::ostream& out, const vect& s) {
		out << s.m_fnx() << "," << s.m_fny() << "," << s.m_fnz();
		return out;
	};
	vect operator+(vect);
	vect operator-(vect);
	vect operator+=(vect);
	vect operator-=(vect);
	bool operator==(vect);
	bool operator!=(vect);
	const float& m_fnx() const;
	const float& m_fny() const;
	const float& m_fnz() const;
	void m_fnx(float);
	void m_fny(float);
	void m_fnz(float);
	vect();
	vect(float, float, float);
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