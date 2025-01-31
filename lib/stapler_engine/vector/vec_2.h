// vec_2.h
#ifndef SE_VEC_2_H
#define SE_VEC_2_H
#include "vec_base.h"

namespace stapler_engine::vec 
{
	class DLLAPI_SE Vector2 : public Vector {
	protected:
		float_precision x, y;
	public:
		//X axis
		virtual inline float_precision& x_();
		//Y axis
		virtual inline float_precision& y_();
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
		virtual inline Vector2 ride_(float_precision num) const;
		virtual inline Vector2 operator*(float_precision num) const;
		//Dot Vector2
		virtual inline float_precision dot_(const Vector2& vec2) const;
		//Cross Vector2
		virtual inline float_precision cross_(const Vector2& vec2) const;
		//Divide num
		virtual inline Vector2 divide_(float_precision num) const;
		virtual inline Vector2 operator/(float_precision num) const;
		//Norm without radical
		virtual inline float_precision norm_without_radical_() const;
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