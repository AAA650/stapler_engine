// vec2_i.h
#ifndef SE_VEC_2I_H
#define SE_VEC_2I_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector2i : public Vector {
	public:
		static const int AXIS_COUNT = 2;
		enum Axis { AX, AY };
	protected:
		union {
			struct {
				union {
					int x;
					int width;
				};
				union {
					int y;
					int height;
				};
			};
			int coord[2];
		};
	public:
		//X axis
		virtual inline int& x_();
		//Y axis
		virtual inline int& y_();
		//Vec width
		virtual inline int& width_();
		//Vec height
		virtual inline int& height_();
		//Find axis by offset
		virtual inline int& operator[](int axis_index);
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
		virtual inline Vector2i multiply_(int num) const;
		virtual inline Vector2i operator*(int num) const;
		//Dot Vector2i
		virtual inline int dot_(const Vector2i& vec2i) const;
		//Cross Vector2i
		virtual inline int cross_(const Vector2i& vec2i) const;
		//Divide num
		virtual inline Vector2i divide_(int num) const;
		virtual inline Vector2i operator/(int num) const;
		//Norm without radical
		virtual inline int length_squared_() const;
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