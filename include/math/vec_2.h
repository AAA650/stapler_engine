// vec_2.h
#ifndef SE_VEC_2_H
#define SE_VEC_2_H
#include "vec_base.h"

namespace stapler_engine::vec 
{
	class DLLAPI_SE Vector2 : public Vector {
	public:
		static const int AXIS_COUNT = 2;
		enum Axis { AX, AY };
	public:
		union {
			struct {
				union {
					float_precision x;
					float_precision width;
				};
				union {
					float_precision y;
					float_precision height;
				};
			};
			float_precision coord[2];
		};
	public:
		//Find axis by offset
		virtual float_precision& operator[](int axis_index);
		//Plus Vector2
		virtual Vector2 plus_(const Vector2& vec2) const;
		virtual Vector2 operator+(const Vector2& vec2) const;
		//Plus num
		virtual Vector2 plus_(float_precision num) const;
		virtual Vector2 operator+(float_precision num) const;
		//Minus Vector2
		virtual Vector2 minus_(const Vector2& vec2) const;
		virtual Vector2 operator-(const Vector2& vec2) const;
		//Minus num
		virtual Vector2 minus_(float_precision num) const;
		virtual Vector2 operator-(float_precision num) const;
		//Ride num
		virtual Vector2 multiply_(float_precision num) const;
		virtual Vector2 operator*(float_precision num) const;
		//Dot Vector2
		virtual float_precision dot_(const Vector2& vec2) const;
		//Cross Vector2
		virtual float_precision cross_(const Vector2& vec2) const;
		//Divide num
		virtual Vector2 divide_(float_precision num) const;
		virtual Vector2 operator/(float_precision num) const;
		//Norm without radical
		virtual float_precision length_squared_() const;
		//Self add
		virtual void operator+=(const Vector2& vec2);
		virtual void operator+=(float_precision num);
		//Self minus
		virtual void operator-=(const Vector2& vec2);
		virtual void operator-=(float_precision num);
		//Self ride
		virtual void operator*=(float_precision num);
		//Self divide
		virtual void operator/=(float_precision num);
		//Is equal
		virtual bool equal_(const Vector2& vec2) const;
		virtual bool operator==(const Vector2& vec2) const;
		//Is unequal
		virtual bool unequal_(const Vector2& vec2) const;
		virtual bool operator!=(const Vector2& vec2) const;
		//Init as (0,0)
		Vector2();
		//Init as (x,y)
		Vector2(float_precision x, float_precision y);
	};

	typedef Vector2 Point2;
	typedef Vector2 Size2;
}

#endif