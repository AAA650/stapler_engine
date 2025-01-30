// Vec2ii.h
#ifndef SE_VEC_2I_H
#define SE_VEC_2I_H
#include "vec_base.h"

namespace stapler_engine::vector {
	class DLLAPI_SE Vec2i : public Vec 
	{
	protected:
		int x, y;
	public:
		//Get x axis
		virtual inline const int x_();
		//Set x axis
		virtual inline void x_(int num);
		//Get y axis
		virtual inline const int y_();
		//Set y axis
		virtual inline void y_(int num);
		//Plus Vec2i
		virtual inline Vec2i plus_(Vec2i& Vec2i);
		virtual inline Vec2i operator+(Vec2i& Vec2i);
		//Plus num
		virtual inline Vec2i plus_(int num);
		virtual inline Vec2i operator+(int num);
		//Minus Vec2i
		virtual inline Vec2i minus_(Vec2i& Vec2i);
		virtual inline Vec2i operator-(Vec2i& Vec2i);
		//Minus num
		virtual inline Vec2i minus_(int num);
		virtual inline Vec2i operator-(int num);
		//Ride num
		virtual inline Vec2i ride_(int num);
		virtual inline Vec2i operator*(int num);
		//Dot Vec2i
		virtual inline int dot_(Vec2i& Vec2i);
		//Cross Vec2i
		virtual inline int cross_(Vec2i& Vec2i);
		//Divide num
		virtual inline Vec2i divide_(int num);
		virtual inline Vec2i operator/(int num);
		//Self add
		virtual inline void operator+=(Vec2i& Vec2i);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(Vec2i&);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(Vec2i& Vec2i);
		virtual inline bool operator==(Vec2i& Vec2i);
		//Is unequal
		virtual inline bool unequal_(Vec2i& Vec2i);
		virtual inline bool operator!=(Vec2i& Vec2i);
		//Init as (0,0)
		Vec2i();
		//Init as (x,y)
		Vec2i(int x, int y);
	};
}

#endif