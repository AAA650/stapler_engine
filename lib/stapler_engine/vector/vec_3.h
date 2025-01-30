// vec_3.h
#ifndef SE_VEC_3_H
#define SE_VEC_3_H
#include "vec_base.h"

namespace stapler_engine::vector {
	class DLLAPI_SE Vec3 : public Vec {
	protected:
		float_precision x, y, z;
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
		//Plus Vec3
		virtual inline Vec3 plus_(Vec3& vec3);
		virtual inline Vec3 operator+(Vec3& vec3);
		//Plus num
		virtual inline Vec3 plus_(float_precision num);
		virtual inline Vec3 operator+(float_precision num);
		//Minus Vec3
		virtual inline Vec3 minus_(Vec3& vec3);
		virtual inline Vec3 operator-(Vec3& vec3);
		//Minus num
		virtual inline Vec3 minus_(float_precision num);
		virtual inline Vec3 operator-(float_precision num);
		//Ride num
		virtual inline Vec3 ride_(float_precision num);
		virtual inline Vec3 operator*(float_precision num);
		//Dot Vec3
		virtual inline float_precision dot_(Vec3& vec3);
		//Cross Vec3
		virtual inline Vec3 cross_(Vec3& vec3);
		//Divide num
		virtual inline Vec3 divide_(float_precision num);
		virtual inline Vec3 operator/(float_precision num);
		//Norm without radical
		virtual inline float_precision norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vec3& vec3);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(Vec3& vec3);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(Vec3& vec3);
		virtual inline bool operator==(Vec3& vec3);
		//Is unequal
		virtual inline bool unequal_(Vec3& vec3);
		virtual inline bool operator!=(Vec3& vec3);
		//Init as (0,0,0)
		Vec3();
		//Init as (x,y,z)
		Vec3(float_precision x, float_precision y, float_precision z);
	};
}

#endif