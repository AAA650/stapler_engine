// s_vector_2i.h
// declaration of SVector2i

#ifndef S_VECTOR_2I_H
#define S_VECTOR_2I_H
#include "s_vector_base.h"

namespace stapler_engine::vector
{
	class DLLAPI_SE SVector2i : public SVector
	{
	public:
		static const int AXIS_COUNT = 2;
		enum Axis { AX, AY };

	public:
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
		//Find axis by offset
		virtual int& operator[](int axis_index);

		//Plus SVector2i
		virtual SVector2i plus_(const SVector2i& vec2i) const;
		virtual SVector2i operator+(const SVector2i& vec2i) const;

		//Plus num
		virtual SVector2i plus_(int num) const;
		virtual SVector2i operator+(int num) const;

		//Minus SVector2i
		virtual SVector2i minus_(const SVector2i& vec2i) const;
		virtual SVector2i operator-(const SVector2i& vec2i) const;

		//Minus num
		virtual SVector2i minus_(int num) const;
		virtual SVector2i operator-(int num) const;

		//Ride num
		virtual SVector2i multiply_(int num) const;
		virtual SVector2i operator*(int num) const;

		//Dot SVector2i
		virtual int dot_(const SVector2i& vec2i) const;

		//Cross SVector2i
		virtual int cross_(const SVector2i& vec2i) const;

		//Divide num
		virtual SVector2i divide_(int num) const;
		virtual SVector2i operator/(int num) const;

		//Norm without radical
		virtual int length_squared_() const;

		//Self add
		virtual void operator+=(const SVector2i& vec2i);
		virtual void operator+=(int num);

		//Self minus
		virtual void operator-=(const SVector2i&);
		virtual void operator-=(int num);

		//Self ride
		virtual void operator*=(int num);

		//Self divide
		virtual void operator/=(int num);

		//Is equal
		virtual bool equal_(const SVector2i& vec2i) const;
		virtual bool operator==(const SVector2i& vec2i) const;

		//Is unequal
		virtual bool unequal_(const SVector2i& vec2i) const;
		virtual bool operator!=(const SVector2i& vec2i) const;

		//Init as (0,0)
		SVector2i();

		//Init as (x,y)
		SVector2i(int x, int y);

	};

	typedef SVector2i Point2i;
	typedef SVector2i Size2i;
}

#endif