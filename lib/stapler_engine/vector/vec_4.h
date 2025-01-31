// vec_4.h
#ifndef SE_VEC_4_H
#define SE_VEC_4_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector4 : public Vector {
	protected:
		float_precision x, y, z, w;
	public:
		//X axis
		virtual inline float_precision& x_();
		//Y axis
		virtual inline float_precision& y_();
		//Z axis
		virtual inline float_precision& z_();
		//W axis
		virtual inline float_precision& w_();
		//Plus Vector4
		virtual inline Vector4 plus_(const Vector4& vec4) const;
		virtual inline Vector4 operator+(const Vector4& vec4) const;
		//Plus num
		virtual inline Vector4 plus_(float_precision num) const;
		virtual inline Vector4 operator+(float_precision num) const;
		//Minus Vector4
		virtual inline Vector4 minus_(const Vector4& vec4) const;
		virtual inline Vector4 operator-(const Vector4& vec4) const;
		//Minus num
		virtual inline Vector4 minus_(float_precision num) const;
		virtual inline Vector4 operator-(float_precision num) const;
		//Ride num
		virtual inline Vector4 ride_(float_precision num) const;
		virtual inline Vector4 operator*(float_precision num) const;
		//Dot Vector4
		virtual inline float_precision dot_(const Vector4& vec4) const;
		//Cross Vector4
		virtual inline Vector4 cross_(const Vector4& vec4) const;
		//Divide num
		virtual inline Vector4 divide_(float_precision num) const;
		virtual inline Vector4 operator/(float_precision num) const;
		//Norm without radical
		virtual inline float_precision norm_without_radical_() const;
		//Self add
		virtual inline void operator+=(const Vector4& vec4);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(const Vector4& vec4);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(const Vector4& vec4) const;
		virtual inline bool operator==(const Vector4& vec4) const;
		//Is unequal
		virtual inline bool unequal_(const Vector4& vec4) const;
		virtual inline bool operator!=(const Vector4& vec4) const;
		//Init as (0,0,0,0)
		Vector4();
		//Init as (x,y,z,w)
		Vector4(float_precision x, float_precision y, float_precision z, float_precision w);
	};
}

#endif