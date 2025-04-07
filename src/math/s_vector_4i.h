// s_vector_4i.h
// declaration of SVector4i

#ifndef S_VECTOR_4I_H
#define S_VECTOR_4I_H
#include "s_vector_base.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SVector4i : public SVector
	{
	public:
		static const int AXIS_COUNT = 4;
		enum Axis { AX, AY, AZ, AW };

	public:
		union {
			struct {
				union {
					int x_;
					int r_;
				};
				union {
					int y_;
					int g_;
				};
				union {
					int z_;
					int b_;
				};
				union {
					int w_;
					int a_;
				};
			};
			int coord_[4];
		};

	public:
		//Find axis by offset
		virtual int& operator[](int axis_index);

		//Plus SVector4i
		virtual SVector4i plus(const SVector4i& vec4i) const;
		virtual SVector4i operator+(const SVector4i& vec4i) const;

		//Plus num
		virtual SVector4i plus(int num) const;
		virtual SVector4i operator+(int num) const;

		//Minus SVector4i
		virtual SVector4i minus(const SVector4i& vec4i) const;
		virtual SVector4i operator-(const SVector4i& vec4i) const;

		//Minus num
		virtual SVector4i minus(int num) const;
		virtual SVector4i operator-(int num) const;

		//Ride num
		virtual SVector4i multiply(int num) const;
		virtual SVector4i operator*(int num) const;

		//Dot SVector4i
		virtual int dot(const SVector4i& vec4i) const;

		//Cross SVector4i
		virtual SVector4i cross(const SVector4i& vec4i) const;

		//Divide num
		virtual SVector4i divide(int num) const;
		virtual SVector4i operator/(int num) const;

		//Norm without radical
		virtual int length_squared() const;

		//Self add
		virtual void operator+=(const SVector4i& vec4i);
		virtual void operator+=(int num);

		//Self minus
		virtual void operator-=(const SVector4i& vec4i);
		virtual void operator-=(int num);

		//Self ride
		virtual void operator*=(int num);

		//Self divide
		virtual void operator/=(int num);

		//Is equal
		virtual bool equal(const SVector4i& vec4i) const;
		virtual bool operator==(const SVector4i& vec4i) const;

		//Is unequal
		virtual bool unequal(const SVector4i& vec4i) const;
		virtual bool operator!=(const SVector4i& vec4i) const;

		//Init as (0,0,0,0)
		SVector4i();

		//Init as (x,y,z,w)
		SVector4i(int x, int y, int z, int w);

	};
}

#endif