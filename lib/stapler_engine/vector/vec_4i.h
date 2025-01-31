// vec_4i.h
#ifndef SE_VEC_4I_H
#define SE_VEC_4I_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector4i : public Vector {
	protected:
		int x, y, z, w;
	public:
		//Get x axis
		virtual inline const int x_();
		//Set x axis
		virtual inline void x_(int num);
		//Get y axis
		virtual inline const int y_();
		//Set y axis
		virtual inline void y_(int num);
		//Get z axis
		virtual inline const int z_();
		//Set z axis
		virtual inline void z_(int num);
		//Get z axis
		virtual inline const int w_();
		//Set z axi
		virtual inline void w_(int num);
		//Plus Vector4i
		virtual inline Vector4i plus_(const Vector4i& vec4i) const;
		virtual inline Vector4i operator+(const Vector4i& vec4i) const;
		//Plus num
		virtual inline Vector4i plus_(int num) const;
		virtual inline Vector4i operator+(int num) const;
		//Minus Vector4i
		virtual inline Vector4i minus_(const Vector4i& vec4i) const;
		virtual inline Vector4i operator-(const Vector4i& vec4i) const;
		//Minus num
		virtual inline Vector4i minus_(int num) const;
		virtual inline Vector4i operator-(int num) const;
		//Ride num
		virtual inline Vector4i ride_(int num) const;
		virtual inline Vector4i operator*(int num) const;
		//Dot Vector4i
		virtual inline int dot_(const Vector4i& vec4i) const;
		//Cross Vector4i
		virtual inline Vector4i cross_(const Vector4i& vec4i) const;
		//Divide num
		virtual inline Vector4i divide_(int num) const;
		virtual inline Vector4i operator/(int num) const;
		//Norm without radical
		virtual inline int norm_without_radical_() const;
		//Self add
		virtual inline void operator+=(const Vector4i& vec4i);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(const Vector4i& vec4i);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(const Vector4i& vec4i) const;
		virtual inline bool operator==(const Vector4i& vec4i) const;
		//Is unequal
		virtual inline bool unequal_(const Vector4i& vec4i) const;
		virtual inline bool operator!=(const Vector4i& vec4i) const;
		//Init as (0,0,0,0)
		Vector4i();
		//Init as (x,y,z,w)
		Vector4i(int x, int y, int z, int w);
	};
}

#endif