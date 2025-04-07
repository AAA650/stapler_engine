// s_vector_4.h
// declaration of SVector4

#ifndef S_VECTOR_4_H
#define S_VECTOR_4_H
#include "s_vector_base.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SVector4 : public SVector
	{
	public:
		static const int AXIS_COUNT = 4;
		enum Axis { AX, AY, AZ, AW };

	public:
		union {
			struct {
				float_precision x_;
				float_precision y_;
				float_precision z_;
				float_precision w_;
			};
			float_precision coord_[4];
		};

	public:
		//Find axis by offset
		virtual float_precision& operator[](int axis_index);

		//Plus SVector4
		virtual SVector4 plus(const SVector4& vec4) const;
		virtual SVector4 operator+(const SVector4& vec4) const;

		//Plus num
		virtual SVector4 plus(float_precision num) const;
		virtual SVector4 operator+(float_precision num) const;

		//Minus SVector4
		virtual SVector4 minus(const SVector4& vec4) const;
		virtual SVector4 operator-(const SVector4& vec4) const;

		//Minus num
		virtual SVector4 minus(float_precision num) const;
		virtual SVector4 operator-(float_precision num) const;

		//Ride num
		virtual SVector4 multiply(float_precision num) const;
		virtual SVector4 operator*(float_precision num) const;

		//Dot SVector4
		virtual float_precision dot(const SVector4& vec4) const;

		//Cross SVector4
		virtual SVector4 cross(const SVector4& vec4) const;

		//Divide num
		virtual SVector4 divide(float_precision num) const;
		virtual SVector4 operator/(float_precision num) const;

		//Norm without radical
		virtual float_precision length_squared() const;

		//Self add
		virtual void operator+=(const SVector4& vec4);
		virtual void operator+=(float_precision num);

		//Self minus
		virtual void operator-=(const SVector4& vec4);
		virtual void operator-=(float_precision num);

		//Self ride
		virtual void operator*=(float_precision num);

		//Self divide
		virtual void operator/=(float_precision num);

		//Is equal
		virtual bool equal(const SVector4& vec4) const;
		virtual bool operator==(const SVector4& vec4) const;

		//Is unequal
		virtual bool unequal(const SVector4& vec4) const;
		virtual bool operator!=(const SVector4& vec4) const;

		//Init as (0,0,0,0)
		SVector4();

		//Init as (x,y,z,w)
		SVector4(float_precision x, float_precision y, float_precision z, float_precision w);

	};
}

#endif