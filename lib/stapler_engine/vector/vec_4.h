// vec_4.h
#ifndef SE_VEC_4_H
#define SE_VEC_4_H
#include "vec_base.h"

namespace stapler_engine::vector {
	class DLLAPI_SE Vector4 : public Vector {
	protected:
		float_precision x, y, z, w;
	public:
		//Get x axis
		virtual inline const float_precision x_();
		//Set x axis
		virtual inline void x_(float_precision num);
		//Get y axis
		virtual inline const float_precision y_();
		//Set y axis
		virtual inline void y_(float_precision num);
		//Get z axis
		virtual inline const float_precision z_();
		//Set z axis
		virtual inline void z_(float_precision num);
		//Get z axis
		virtual inline const float_precision w_();
		//Set z axi
		virtual inline void w_(float_precision num);
		//Plus Vector4
		virtual inline Vector4 plus_(Vector4 vec4);
		virtual inline Vector4 operator+(Vector4 vec4);
		//Plus num
		virtual inline Vector4 plus_(float_precision num);
		virtual inline Vector4 operator+(float_precision num);
		//Minus Vector4
		virtual inline Vector4 minus_(Vector4 vec4);
		virtual inline Vector4 operator-(Vector4 vec4);
		//Minus num
		virtual inline Vector4 minus_(float_precision num);
		virtual inline Vector4 operator-(float_precision num);
		//Ride num
		virtual inline Vector4 ride_(float_precision num);
		virtual inline Vector4 operator*(float_precision num);
		//Dot Vector4
		virtual inline float_precision dot_(Vector4 vec4);
		//Cross Vector4
		virtual inline Vector4 cross_(Vector4 vec4);
		//Divide num
		virtual inline Vector4 divide_(float_precision num);
		virtual inline Vector4 operator/(float_precision num);
		//Norm without radical
		virtual inline float_precision norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vector4 vec4);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(Vector4 vec4);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(Vector4 vec4);
		virtual inline bool operator==(Vector4 vec4);
		//Is unequal
		virtual inline bool unequal_(Vector4 vec4);
		virtual inline bool operator!=(Vector4 vec4);
		//Init as (0,0,0,0)
		Vector4();
		//Init as (x,y,z,w)
		Vector4(float_precision x, float_precision y, float_precision z, float_precision w);
	};
}

#endif