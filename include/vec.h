// vec.h
#pragma once

#define VEC_H
#include "defse.h"
#include <iostream>

#define POSVECD(vec) vec.m_fnx(), vec.m_fny()
#define POSVECT(vec) vec.m_fnx(), vec.m_fny(), vec.m_fnz()

// 2D point
class DLLAPI_SE vecd {
protected:
	double m_dx, m_dy;
public:
	friend std::ostream& operator<<(std::ostream&, const vecd&);
	vecd operator+(vecd);
	vecd operator-(vecd);
	vecd operator+=(vecd);
	vecd operator-=(vecd);
	bool operator==(vecd);
	bool operator!=(vecd);
	const double& m_fnx() const;
	const double& m_fny() const;
	void m_fnx(double);
	void m_fny(double);
	vecd();
	vecd(double, double);
};

// 3D point
class DLLAPI_SE vect {
protected:
	double m_dx, m_dy, m_dz;
public:
	friend std::ostream& operator<<(std::ostream&, const vect&);
	vect operator+(vect);
	vect operator-(vect);
	vect operator+=(vect);
	vect operator-=(vect);
	bool operator==(vect);
	bool operator!=(vect);
	const double& m_fnx() const;
	const double& m_fny() const;
	const double& m_fnz() const;
	void m_fnx(double);
	void m_fny(double);
	void m_fnz(double);
	vect();
	vect(double, double, double);
};

// 3D rotate
class DLLAPI_SE dirt {
protected:
	double m_dxy, m_dxz, m_dyz;
public:
	friend std::ostream& operator<<(std::ostream&, const dirt&);
	double m_fnxy() const;
	double m_fnxz() const;
	double m_fnyz() const;
	dirt();
	dirt(double, double, double);
};