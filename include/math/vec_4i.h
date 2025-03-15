// vec_4i.h
#ifndef SE_VEC_4I_H
#define SE_VEC_4I_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector4i : public Vector {
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
		//Plus Vector4i
		virtual Vector4i plus_(const Vector4i& vec4i) const;
		virtual Vector4i operator+(const Vector4i& vec4i) const;
		//Plus num
		virtual Vector4i plus_(int num) const;
		virtual Vector4i operator+(int num) const;
		//Minus Vector4i
		virtual Vector4i minus_(const Vector4i& vec4i) const;
		virtual Vector4i operator-(const Vector4i& vec4i) const;
		//Minus num
		virtual Vector4i minus_(int num) const;
		virtual Vector4i operator-(int num) const;
		//Ride num
		virtual Vector4i multiply_(int num) const;
		virtual Vector4i operator*(int num) const;
		//Dot Vector4i
		virtual int dot_(const Vector4i& vec4i) const;
		//Cross Vector4i
		virtual Vector4i cross_(const Vector4i& vec4i) const;
		//Divide num
		virtual Vector4i divide_(int num) const;
		virtual Vector4i operator/(int num) const;
		//Norm without radical
		virtual int length_squared_() const;
		//Self add
		virtual void operator+=(const Vector4i& vec4i);
		virtual void operator+=(int num);
		//Self minus
		virtual void operator-=(const Vector4i& vec4i);
		virtual void operator-=(int num);
		//Self ride
		virtual void operator*=(int num);
		//Self divide
		virtual void operator/=(int num);
		//Is equal
		virtual bool equal_(const Vector4i& vec4i) const;
		virtual bool operator==(const Vector4i& vec4i) const;
		//Is unequal
		virtual bool unequal_(const Vector4i& vec4i) const;
		virtual bool operator!=(const Vector4i& vec4i) const;
		//Init as (0,0,0,0)
		Vector4i();
		//Init as (x,y,z,w)
		Vector4i(int x, int y, int z, int w);
	};
}

#endif