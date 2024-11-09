// vec.h
#pragma once

#define VEC_H
#include "SEDefinition.h"
#include <iostream>

#define VEC2(vec) (vec).x_, (vec).y_
#define VEC3(vec) (vec).x_, (vec).y_, (vec).z_
#define TVEC2(vec,type) (type)(vec).x_, (type)(vec).y_
#define TVEC3(vec,type) (type)(vec).x_, (type)(vec).y_, (type)(vec).z_
#define OVEC2(vec) (vec).y_, (vec).x_
#define OTVEC2(vec,type) (type)(vec).y_, (type)(vec).x_
// 2D point
class DLLAPI_SE Vec2 {
public:
	double x_, y_;
	friend std::ostream& operator<<(std::ostream& out, const Vec2& s) {
		out << s.x_ << "," << s.y_;
		return out;
	};
	Vec2 operator+(Vec2);
	Vec2 operator-(Vec2);
	Vec2 operator+=(Vec2);
	Vec2 operator-=(Vec2);
	bool operator==(Vec2);
	bool operator!=(Vec2);
	Vec2();
	Vec2(double, double);
};

// 3D point
class DLLAPI_SE Vec3 {
public:
	double x_, y_, z_;
	friend std::ostream& operator<<(std::ostream& out, const Vec3& s) {
		out << s.x_ << "," << s.y_ << "," << s.z_;
		return out;
	};
	Vec3 operator+(Vec3);
	Vec3 operator-(Vec3);
	Vec3 operator+=(Vec3);
	Vec3 operator-=(Vec3);
	bool operator==(Vec3);
	bool operator!=(Vec3);
	Vec3();
	Vec3(double, double, double);
};

// 3D rotate
class DLLAPI_SE dirt {
public:
	double x_y_, x_z_, y_z_;
	friend std::ostream& operator<<(std::ostream& out, const dirt& s) {
		out << s.x_y_ << "," << s.x_z_ << "," << s.y_z_;
		return out;
	};
	dirt();
	dirt(double, double, double);
};