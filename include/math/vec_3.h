// vec_3.h
#ifndef SE_VEC_3_H
#define SE_VEC_3_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector3 : public Vector {
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
		//Plus Vector3
		virtual Vector3 plus_(const Vector3& vec3) const;
		virtual Vector3 operator+(const Vector3& vec3) const;
		//Plus num
		virtual Vector3 plus_(float_precision num) const;
		virtual Vector3 operator+(float_precision num) const;
		//Minus Vector3
		virtual Vector3 minus_(const Vector3& vec3) const;
		virtual Vector3 operator-(const Vector3& vec3) const;
		//Minus num
		virtual Vector3 minus_(float_precision num) const;
		virtual Vector3 operator-(float_precision num) const;
		//Ride num
		virtual Vector3 multiply_(float_precision num) const;
		virtual Vector3 operator*(float_precision num) const;
		//Dot Vector3
		virtual float_precision dot_(const Vector3& vec3) const;
		//Cross Vector3
		virtual Vector3 cross_(const Vector3& vec3) const;
		//Divide num
		virtual Vector3 divide_(float_precision num) const;
		virtual Vector3 operator/(float_precision num) const;
		//Norm without radical
		virtual float_precision length_squared_() const;
		//Self add
		virtual void operator+=(const Vector3& vec3);
		virtual void operator+=(float_precision num);
		//Self minus
		virtual void operator-=(const Vector3& vec3);
		virtual void operator-=(float_precision num);
		//Self ride
		virtual void operator*=(float_precision num);
		//Self divide
		virtual void operator/=(float_precision num);
		//Is equal
		virtual bool equal_(const Vector3& vec3) const;
		virtual bool operator==(const Vector3& vec3) const;
		//Is unequal
		virtual bool unequal_(const Vector3& vec3) const;
		virtual bool operator!=(const Vector3& vec3) const;
		//Init as (0,0,0)
		Vector3();
		//Init as (x,y,z)
		Vector3(float_precision x, float_precision y, float_precision z);
	};

	typedef Vector3 Point3;
	typedef Vector3 Size3;
}

#endif