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
		//Get x axis
		virtual inline const float_precision x_();
		//Set x axis
		virtual inline void x_(float_precision num);
		//Get y axis
		virtual inline const float_precision y_();
		//Set y axis
		virtual inline void y_(float_precision num);
		//Plus Vector2
		virtual inline Vector2 plus_(Vector2 vec2);
		virtual inline Vector2 operator+(Vector2 vec2);
		//Plus num
		virtual inline Vector2 plus_(float_precision num);
		virtual inline Vector2 operator+(float_precision num);
		//Minus Vector2
		virtual inline Vector2 minus_(Vector2 vec2);
		virtual inline Vector2 operator-(Vector2 vec2);
		//Minus num
		virtual inline Vector2 minus_(float_precision num);
		virtual inline Vector2 operator-(float_precision num);
		//Ride num
		virtual inline Vector2 ride_(float_precision num);
		virtual inline Vector2 operator*(float_precision num);
		//Dot Vector2
		virtual inline float_precision dot_(Vector2 vec2);
		//Cross Vector2
		virtual inline float_precision cross_(Vector2 vec2);
		//Divide num
		virtual inline Vector2 divide_(float_precision num);
		virtual inline Vector2 operator/(float_precision num);
		//Norm without radical
		virtual inline float_precision norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vector2 vec2);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(Vector2);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(Vector2 vec2);
		virtual inline bool operator==(Vector2 vec2);
		//Is unequal
		virtual inline bool unequal_(Vector2 vec2);
		virtual inline bool operator!=(Vector2 vec2);
		//Init as (0,0)
		Vector2();
		//Init as (x,y)
		Vector2(float_precision x, float_precision y);
	};
}

#endif