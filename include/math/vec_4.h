// vec_4.h
#ifndef SE_VEC_4_H
#define SE_VEC_4_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector4 : public Vector {
	protected:
	public:
		static const int AXIS_COUNT = 4;
		enum Axis { AX, AY, AZ, AW };
	public:
		union {
			struct {
				float_precision x;
				float_precision y;
				float_precision z;
				float_precision w;
			};
			float_precision coord[4];
		};
	public:
		//Find axis by offset
		virtual float_precision& operator[](int axis_index);
		//Plus Vector4
		virtual Vector4 plus_(const Vector4& vec4) const;
		virtual Vector4 operator+(const Vector4& vec4) const;
		//Plus num
		virtual Vector4 plus_(float_precision num) const;
		virtual Vector4 operator+(float_precision num) const;
		//Minus Vector4
		virtual Vector4 minus_(const Vector4& vec4) const;
		virtual Vector4 operator-(const Vector4& vec4) const;
		//Minus num
		virtual Vector4 minus_(float_precision num) const;
		virtual Vector4 operator-(float_precision num) const;
		//Ride num
		virtual Vector4 multiply_(float_precision num) const;
		virtual Vector4 operator*(float_precision num) const;
		//Dot Vector4
		virtual float_precision dot_(const Vector4& vec4) const;
		//Cross Vector4
		virtual Vector4 cross_(const Vector4& vec4) const;
		//Divide num
		virtual Vector4 divide_(float_precision num) const;
		virtual Vector4 operator/(float_precision num) const;
		//Norm without radical
		virtual float_precision length_squared_() const;
		//Self add
		virtual void operator+=(const Vector4& vec4);
		virtual void operator+=(float_precision num);
		//Self minus
		virtual void operator-=(const Vector4& vec4);
		virtual void operator-=(float_precision num);
		//Self ride
		virtual void operator*=(float_precision num);
		//Self divide
		virtual void operator/=(float_precision num);
		//Is equal
		virtual bool equal_(const Vector4& vec4) const;
		virtual bool operator==(const Vector4& vec4) const;
		//Is unequal
		virtual bool unequal_(const Vector4& vec4) const;
		virtual bool operator!=(const Vector4& vec4) const;
		//Init as (0,0,0,0)
		Vector4();
		//Init as (x,y,z,w)
		Vector4(float_precision x, float_precision y, float_precision z, float_precision w);
	};
}

#endif