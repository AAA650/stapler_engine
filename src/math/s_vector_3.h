// s_vector_3.h
// declaration of SVector3

#ifndef S_VECTOR_3_H
#define S_VECTOR_3_H
#include "s_vector_base.h"

namespace stapler_engine::vector
{
	class DLLAPI_SE SVector3 : public SVector
	{
	public:
		static const int AXIS_COUNT = 3;
		enum Axis { AX, AY, AZ };

	public:
		union {
			struct {
				union {
					float_precision x;
					float_precision width;
				};
				union {
					float_precision y;
					float_precision height;
				};
				union {
					float_precision z;
					float_precision depth;
				};
			};
			float_precision coord[3];
		};

	public:
		//Find axis by offset
		virtual float_precision& operator[](int axis_index);

		//Plus SVector3
		virtual SVector3 plus_(const SVector3& vec3) const;
		virtual SVector3 operator+(const SVector3& vec3) const;

		//Plus num
		virtual SVector3 plus_(float_precision num) const;
		virtual SVector3 operator+(float_precision num) const;

		//Minus SVector3
		virtual SVector3 minus_(const SVector3& vec3) const;
		virtual SVector3 operator-(const SVector3& vec3) const;

		//Minus num
		virtual SVector3 minus_(float_precision num) const;
		virtual SVector3 operator-(float_precision num) const;

		//Ride num
		virtual SVector3 multiply_(float_precision num) const;
		virtual SVector3 operator*(float_precision num) const;

		//Dot SVector3
		virtual float_precision dot_(const SVector3& vec3) const;

		//Cross SVector3
		virtual SVector3 cross_(const SVector3& vec3) const;

		//Divide num
		virtual SVector3 divide_(float_precision num) const;
		virtual SVector3 operator/(float_precision num) const;

		//Norm without radical
		virtual float_precision length_squared_() const;

		//Self add
		virtual void operator+=(const SVector3& vec3);
		virtual void operator+=(float_precision num);

		//Self minus
		virtual void operator-=(const SVector3& vec3);
		virtual void operator-=(float_precision num);

		//Self ride
		virtual void operator*=(float_precision num);

		//Self divide
		virtual void operator/=(float_precision num);

		//Is equal
		virtual bool equal_(const SVector3& vec3) const;
		virtual bool operator==(const SVector3& vec3) const;

		//Is unequal
		virtual bool unequal_(const SVector3& vec3) const;
		virtual bool operator!=(const SVector3& vec3) const;

		//Init as (0,0,0)
		SVector3();

		//Init as (x,y,z)
		SVector3(float_precision x, float_precision y, float_precision z);

	};

	typedef SVector3 Point3;
	typedef SVector3 Size3;
}

#endif