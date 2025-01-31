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
		virtual inline Vector2i plus_(const Vector2i& vec2i) const;
		virtual inline Vector2i operator+(const Vector2i& vec2i) const;
		//Plus num
		virtual inline Vector2i plus_(int num) const;
		virtual inline Vector2i operator+(int num) const;
		//Minus Vector2i
		virtual inline Vector2i minus_(const Vector2i& vec2i) const;
		virtual inline Vector2i operator-(const Vector2i& vec2i) const;
		//Minus num
		virtual inline Vector2i minus_(int num) const;
		virtual inline Vector2i operator-(int num) const;
		//Ride num
		virtual inline Vector2i ride_(int num) const;
		virtual inline Vector2i operator*(int num) const;
		//Dot Vector2i
		virtual inline int dot_(const Vector2i& vec2i) const;
		//Cross Vector2i
		virtual inline int cross_(const Vector2i& vec2i) const;
		//Divide num
		virtual inline Vector2i divide_(int num) const;
		virtual inline Vector2i operator/(int num) const;
		//Norm without radical
		virtual inline int norm_without_radical_() const;
		//Self add
		virtual inline void operator+=(const Vector2i& vec2i);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(const Vector2i&);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(const Vector2i& vec2i) const;
		virtual inline bool operator==(const Vector2i& vec2i) const;
		//Is unequal
		virtual inline bool unequal_(const Vector2i& vec2i) const;
		virtual inline bool operator!=(const Vector2i& vec2i) const;
		//Init as (0,0)
		Vector2i();
		//Init as (x,y)
		Vector2i(int x, int y);
	};
}

#endif