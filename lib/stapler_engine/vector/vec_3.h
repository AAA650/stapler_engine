// vec_3.h
#ifndef SE_VEC_3_H
#define SE_VEC_3_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector3 : public Vector {
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
		//Plus Vector3
		virtual inline Vector3 plus_(const Vector3& vec3) const;
		virtual inline Vector3 operator+(const Vector3& vec3) const;
		//Plus num
		virtual inline Vector3 plus_(float_precision num) const;
		virtual inline Vector3 operator+(float_precision num) const;
		//Minus Vector3
		virtual inline Vector3 minus_(const Vector3& vec3) const;
		virtual inline Vector3 operator-(const Vector3& vec3) const;
		//Minus num
		virtual inline Vector3 minus_(float_precision num) const;
		virtual inline Vector3 operator-(float_precision num) const;
		//Ride num
		virtual inline Vector3 ride_(float_precision num) const;
		virtual inline Vector3 operator*(float_precision num) const;
		//Dot Vector3
		virtual inline float_precision dot_(const Vector3& vec3) const;
		//Cross Vector3
		virtual inline Vector3 cross_(const Vector3& vec3) const;
		//Divide num
		virtual inline Vector3 divide_(float_precision num) const;
		virtual inline Vector3 operator/(float_precision num) const;
		//Norm without radical
		virtual inline float_precision norm_without_radical_() const;
		//Self add
		virtual inline void operator+=(const Vector3& vec3);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(const Vector3& vec3);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(const Vector3& vec3) const;
		virtual inline bool operator==(const Vector3& vec3) const;
		//Is unequal
		virtual inline bool unequal_(const Vector3& vec3) const;
		virtual inline bool operator!=(const Vector3& vec3) const;
		//Init as (0,0,0)
		Vector3();
		//Init as (x,y,z)
		Vector3(float_precision x, float_precision y, float_precision z);
	};
}

#endif