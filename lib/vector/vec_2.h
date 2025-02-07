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
	protected:
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
		//X axis
		virtual inline float_precision& x_();
		//Y axis
		virtual inline float_precision& y_();
		//Vec width
		virtual inline float_precision& width_();
		//Vec height
		virtual inline float_precision& height_();
		//Find axis by offset
		virtual inline float_precision& operator[](int axis_index);
		//Plus Vector2
		virtual inline Vector2 plus_(const Vector2& vec2) const;
		virtual inline Vector2 operator+(const Vector2& vec2) const;
		//Plus num
		virtual inline Vector2 plus_(float_precision num) const;
		virtual inline Vector2 operator+(float_precision num) const;
		//Minus Vector2
		virtual inline Vector2 minus_(const Vector2& vec2) const;
		virtual inline Vector2 operator-(const Vector2& vec2) const;
		//Minus num
		virtual inline Vector2 minus_(float_precision num) const;
		virtual inline Vector2 operator-(float_precision num) const;
		//Ride num
		virtual inline Vector2 multiply_(float_precision num) const;
		virtual inline Vector2 operator*(float_precision num) const;
		//Dot Vector2
		virtual inline float_precision dot_(const Vector2& vec2) const;
		//Cross Vector2
		virtual inline float_precision cross_(const Vector2& vec2) const;
		//Divide num
		virtual inline Vector2 divide_(float_precision num) const;
		virtual inline Vector2 operator/(float_precision num) const;
		//Norm without radical
		virtual inline float_precision length_squared_() const;
		//Self add
		virtual inline void operator+=(const Vector2& vec2);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(const Vector2& vec2);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(const Vector2& vec2) const;
		virtual inline bool operator==(const Vector2& vec2) const;
		//Is unequal
		virtual inline bool unequal_(const Vector2& vec2) const;
		virtual inline bool operator!=(const Vector2& vec2) const;
		//Init as (0,0)
		Vector2();
		//Init as (x,y)
		Vector2(float_precision x, float_precision y);
	};
}

#endif