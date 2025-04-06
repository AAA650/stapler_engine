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
					int x_;
					int width_;
				};
				union {
					int y_;
					int height_;
				};
			};
			int coord_[2];
		};

	public:
		//Find axis by offset
		virtual int& operator[](int axis_index);

		//Plus SVector2i
		virtual SVector2i plus(const SVector2i& vec2i) const;
		virtual SVector2i operator+(const SVector2i& vec2i) const;

		//Plus num
		virtual SVector2i plus(int num) const;
		virtual SVector2i operator+(int num) const;

		//Minus SVector2i
		virtual SVector2i minus(const SVector2i& vec2i) const;
		virtual SVector2i operator-(const SVector2i& vec2i) const;

		//Minus num
		virtual SVector2i minus(int num) const;
		virtual SVector2i operator-(int num) const;

		//Ride num
		virtual SVector2i multiply(int num) const;
		virtual SVector2i operator*(int num) const;

		//Dot SVector2i
		virtual int dot(const SVector2i& vec2i) const;

		//Cross SVector2i
		virtual int cross(const SVector2i& vec2i) const;

		//Divide num
		virtual SVector2i divide(int num) const;
		virtual SVector2i operator/(int num) const;

		//Norm without radical
		virtual int length_squared() const;

		//Self add
		virtual void operator+=(const SVector2i& vec2i);
		virtual void operator+=(int num);

		//Self minus
		virtual void operator-=(const SVector2i& vec2i);
		virtual void operator-=(int num);

		//Self ride
		virtual void operator*=(int num);

		//Self divide
		virtual void operator/=(int num);

		//Is equal
		virtual bool equal(const SVector2i& vec2i) const;
		virtual bool operator==(const SVector2i& vec2i) const;

		//Is unequal
		virtual bool unequal(const SVector2i& vec2i) const;
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