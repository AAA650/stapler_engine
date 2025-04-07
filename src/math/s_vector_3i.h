// s_vector_3i.h
// declaration of SVector3i

#ifndef S_VECTOR_3I_H
#define S_VECTOR_3I_H
#include "s_vector_base.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SVector3i : public SVector
	{
	public:
		static const int AXIS_COUNT = 3;
		enum Axis { AX, AY, AZ };

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
				union {
					int z_;
					int depth_;
				};
			};
			int coord_[3];
		};

	public:
		//Find axis by offset
		virtual int& operator[](int axis_index);

		//Plus SVector3i
		virtual SVector3i plus(const SVector3i& vec3) const;
		virtual SVector3i operator+(const SVector3i& vec3) const;

		//Plus num
		virtual SVector3i plus(int num) const;
		virtual SVector3i operator+(int num) const;

		//Minus SVector3i
		virtual SVector3i minus(const SVector3i& vec3) const;
		virtual SVector3i operator-(const SVector3i& vec3) const;

		//Minus num
		virtual SVector3i minus(int num) const;
		virtual SVector3i operator-(int num) const;

		//Ride num
		virtual SVector3i multiply(int num) const;
		virtual SVector3i operator*(int num) const;

		//Dot SVector3i
		virtual int dot(const SVector3i& vec3) const;

		//Cross SVector3i
		virtual SVector3i cross(const SVector3i& vec3) const;

		//Divide num
		virtual SVector3i divide(int num) const;
		virtual SVector3i operator/(int num) const;

		//Norm without radical
		virtual int length_squared() const;

		//Self add
		virtual void operator+=(const SVector3i& vec3);
		virtual void operator+=(int num);

		//Self minus
		virtual void operator-=(const SVector3i& vec3);
		virtual void operator-=(int num);

		//Self ride
		virtual void operator*=(int num);

		//Self divide
		virtual void operator/=(int num);

		//Is equal
		virtual bool equal(const SVector3i& vec3) const;
		virtual bool operator==(const SVector3i& vec3) const;

		//Is unequal
		virtual bool unequal(const SVector3i& vec3) const;
		virtual bool operator!=(const SVector3i& vec3) const;

		//Init as (0,0,0)
		SVector3i();

		//Init as (x,y,z)
		SVector3i(int x, int y, int z);

	};

	typedef SVector3i Point3i;
	typedef SVector3i Size3i;
}

#endif