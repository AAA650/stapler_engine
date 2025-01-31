// vec_4i.h
#ifndef SE_VEC_4I_H
#define SE_VEC_4I_H
#include "vec_base.h"

namespace stapler_engine::vector {
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
		virtual inline Vector4i plus_(Vector4i& vec4i);
		virtual inline Vector4i operator+(Vector4i& vec4i);
		//Plus num
		virtual inline Vector4i plus_(int num);
		virtual inline Vector4i operator+(int num);
		//Minus Vector4i
		virtual inline Vector4i minus_(Vector4i& vec4i);
		virtual inline Vector4i operator-(Vector4i& vec4i);
		//Minus num
		virtual inline Vector4i minus_(int num);
		virtual inline Vector4i operator-(int num);
		//Ride num
		virtual inline Vector4i ride_(int num);
		virtual inline Vector4i operator*(int num);
		//Dot Vector4i
		virtual inline int dot_(Vector4i& vec4i);
		//Cross Vector4i
		virtual inline Vector4i cross_(Vector4i& vec4i);
		//Divide num
		virtual inline Vector4i divide_(int num);
		virtual inline Vector4i operator/(int num);
		//Norm without radical
		virtual inline int norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vector4i& vec4i);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(Vector4i& vec4i);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(Vector4i& vec4i);
		virtual inline bool operator==(Vector4i& vec4i);
		//Is unequal
		virtual inline bool unequal_(Vector4i& vec4i);
		virtual inline bool operator!=(Vector4i& vec4i);
		//Init as (0,0,0,0)
		Vector4i();
		//Init as (x,y,z,w)
		Vector4i(int x, int y, int z, int w);
	};
}

#endif