// s_vector_4i.h
#ifndef S_VECTOR_4I_H
#define S_VECTOR_4I_H
#include "s_vector_base.h"

namespace stapler_engine::vector
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
					int x;
					int r;
				};
				union {
					int y;
					int g;
				};
				union {
					int z;
					int b;
				};
				union {
					int w;
					int a;
				};
			};
			int coord[4];
		};

	public:
		//Find axis by offset
		virtual int& operator[](int axis_index);

		//Plus SVector4i
		virtual SVector4i plus_(const SVector4i& vec4i) const;
		virtual SVector4i operator+(const SVector4i& vec4i) const;

		//Plus num
		virtual SVector4i plus_(int num) const;
		virtual SVector4i operator+(int num) const;

		//Minus SVector4i
		virtual SVector4i minus_(const SVector4i& vec4i) const;
		virtual SVector4i operator-(const SVector4i& vec4i) const;

		//Minus num
		virtual SVector4i minus_(int num) const;
		virtual SVector4i operator-(int num) const;

		//Ride num
		virtual SVector4i multiply_(int num) const;
		virtual SVector4i operator*(int num) const;

		//Dot SVector4i
		virtual int dot_(const SVector4i& vec4i) const;

		//Cross SVector4i
		virtual SVector4i cross_(const SVector4i& vec4i) const;

		//Divide num
		virtual SVector4i divide_(int num) const;
		virtual SVector4i operator/(int num) const;

		//Norm without radical
		virtual int length_squared_() const;

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
		virtual bool equal_(const SVector4i& vec4i) const;
		virtual bool operator==(const SVector4i& vec4i) const;

		//Is unequal
		virtual bool unequal_(const SVector4i& vec4i) const;
		virtual bool operator!=(const SVector4i& vec4i) const;

		//Init as (0,0,0,0)
		SVector4i();

		//Init as (x,y,z,w)
		SVector4i(int x, int y, int z, int w);

	};
}

#endif