// vec_4i.h
#ifndef SE_VEC_4I_H
#define SE_VEC_4I_H
#include "vec_base.h"

namespace stapler_engine::vector {
	class DLLAPI_SE Vec4i : public Vec {
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
		//Plus Vec4i
		virtual inline Vec4i plus_(Vec4i& vec4i);
		virtual inline Vec4i operator+(Vec4i& vec4i);
		//Plus num
		virtual inline Vec4i plus_(int num);
		virtual inline Vec4i operator+(int num);
		//Minus Vec4i
		virtual inline Vec4i minus_(Vec4i& vec4i);
		virtual inline Vec4i operator-(Vec4i& vec4i);
		//Minus num
		virtual inline Vec4i minus_(int num);
		virtual inline Vec4i operator-(int num);
		//Ride num
		virtual inline Vec4i ride_(int num);
		virtual inline Vec4i operator*(int num);
		//Dot Vec4i
		virtual inline int dot_(Vec4i& vec4i);
		//Cross Vec4i
		virtual inline Vec4i cross_(Vec4i& vec4i);
		//Divide num
		virtual inline Vec4i divide_(int num);
		virtual inline Vec4i operator/(int num);
		//Norm without radical
		virtual inline int norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vec4i& vec4i);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(Vec4i& vec4i);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(Vec4i& vec4i);
		virtual inline bool operator==(Vec4i& vec4i);
		//Is unequal
		virtual inline bool unequal_(Vec4i& vec4i);
		virtual inline bool operator!=(Vec4i& vec4i);
		//Init as (0,0,0,0)
		Vec4i();
		//Init as (x,y,z,w)
		Vec4i(int x, int y, int z, int w);
	};
}

#endif