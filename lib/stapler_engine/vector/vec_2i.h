// vec2_i.h
#ifndef SE_VEC_2I_H
#define SE_VEC_2I_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector2i : public Vector 
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
		//Plus Vector2i
		virtual inline Vector2i plus_(Vector2i vec2i);
		virtual inline Vector2i operator+(Vector2i vec2i);
		//Plus num
		virtual inline Vector2i plus_(int num);
		virtual inline Vector2i operator+(int num);
		//Minus Vector2i
		virtual inline Vector2i minus_(Vector2i vec2i);
		virtual inline Vector2i operator-(Vector2i vec2i);
		//Minus num
		virtual inline Vector2i minus_(int num);
		virtual inline Vector2i operator-(int num);
		//Ride num
		virtual inline Vector2i ride_(int num);
		virtual inline Vector2i operator*(int num);
		//Dot Vector2i
		virtual inline int dot_(Vector2i vec2i);
		//Cross Vector2i
		virtual inline int cross_(Vector2i vec2i);
		//Divide num
		virtual inline Vector2i divide_(int num);
		virtual inline Vector2i operator/(int num);
		//Norm without radical
		virtual inline int norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vector2i vec2i);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(Vector2i);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(Vector2i vec2i);
		virtual inline bool operator==(Vector2i vec2i);
		//Is unequal
		virtual inline bool unequal_(Vector2i vec2i);
		virtual inline bool operator!=(Vector2i vec2i);
		//Init as (0,0)
		Vector2i();
		//Init as (x,y)
		Vector2i(int x, int y);
	};
}

#endif