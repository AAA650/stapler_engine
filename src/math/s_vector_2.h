// s_vector_2.h
// declaration of SVector2

#ifndef S_VECTOR_2_H
#define S_VECTOR_2_H
#include "s_vector_base.h"

namespace stapler_engine::vector
{
	class DLLAPI_SE SVector2 : public SVector
	{
	public:
		static const int AXIS_COUNT = 2;
		enum Axis { AX, AY };

	public:
		union {
			struct {
				union {
					float_precision x_;
					float_precision width_;
				};
				union {
					float_precision y_;
					float_precision height_;
				};
			};
			float_precision coord_[2];
		};

	public:
		//Find axis by offset
		virtual float_precision& operator[](int axis_index);

		//Plus SVector2
		virtual SVector2 plus(const SVector2& vec2) const;
		virtual SVector2 operator+(const SVector2& vec2) const;

		//Plus num
		virtual SVector2 plus(float_precision num) const;
		virtual SVector2 operator+(float_precision num) const;

		//Minus SVector2
		virtual SVector2 minus(const SVector2& vec2) const;
		virtual SVector2 operator-(const SVector2& vec2) const;

		//Minus num
		virtual SVector2 minus(float_precision num) const;
		virtual SVector2 operator-(float_precision num) const;

		//Ride num
		virtual SVector2 multiply(float_precision num) const;
		virtual SVector2 operator*(float_precision num) const;

		//Dot SVector2
		virtual float_precision dot(const SVector2& vec2) const;

		//Cross SVector2
		virtual float_precision cross(const SVector2& vec2) const;

		//Divide num
		virtual SVector2 divide(float_precision num) const;
		virtual SVector2 operator/(float_precision num) const;

		//Norm without radical
		virtual float_precision length_squared() const;

		//Self add
		virtual void operator+=(const SVector2& vec2);
		virtual void operator+=(float_precision num);

		//Self minus
		virtual void operator-=(const SVector2& vec2);
		virtual void operator-=(float_precision num);

		//Self ride
		virtual void operator*=(float_precision num);

		//Self divide
		virtual void operator/=(float_precision num);

		//Is equal
		virtual bool equal(const SVector2& vec2) const;
		virtual bool operator==(const SVector2& vec2) const;

		//Is unequal
		virtual bool unequal(const SVector2& vec2) const;
		virtual bool operator!=(const SVector2& vec2) const;

		//Init as (0,0)
		SVector2();

		//Init as (x,y)
		SVector2(float_precision x, float_precision y);

	};

	typedef SVector2 Point2;
	typedef SVector2 Size2;
}

#endif