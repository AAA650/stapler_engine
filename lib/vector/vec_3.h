// vec_3.h
#ifndef SE_VEC_3_H
#define SE_VEC_3_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector3 : public Vector {
	public:
		static const int AXIS_COUNT = 3;
		enum Axis { AX, AY, AZ };
	protected:
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
		//X axis
		virtual inline float_precision& x_();
		//Y axis
		virtual inline float_precision& y_();
		//Z axis
		virtual inline float_precision& z_();
		//Vec width
		virtual inline float_precision& width_();
		//Vec height
		virtual inline float_precision& height_();
		//Vec depth
		virtual inline float_precision& depth_();
		//Find axis by offset
		virtual inline float_precision& operator[](int axis_index);
		//Plus Vector3
		virtual inline Vector3 plus_(const Vector3& vec3) const;
		virtual inline Vector3 operator+(const Vector3& vec3) const;
		//Plus num
		virtual inline Vector3 plus_(float_precision num) const;
		virtual inline Vector3 operator+(float_precision num) const;
		//Minus Vector3
		virtual inline Vector3 minus_(const Vector3& vec3) const;
		virtual inline Vector3 operator-(const Vector3& vec3) const;
		//Minus num
		virtual inline Vector3 minus_(float_precision num) const;
		virtual inline Vector3 operator-(float_precision num) const;
		//Ride num
		virtual inline Vector3 multiply_(float_precision num) const;
		virtual inline Vector3 operator*(float_precision num) const;
		//Dot Vector3
		virtual inline float_precision dot_(const Vector3& vec3) const;
		//Cross Vector3
		virtual inline Vector3 cross_(const Vector3& vec3) const;
		//Divide num
		virtual inline Vector3 divide_(float_precision num) const;
		virtual inline Vector3 operator/(float_precision num) const;
		//Norm without radical
		virtual inline float_precision length_squared_() const;
		//Self add
		virtual inline void operator+=(const Vector3& vec3);
		virtual inline void operator+=(float_precision num);
		//Self minus
		virtual inline void operator-=(const Vector3& vec3);
		virtual inline void operator-=(float_precision num);
		//Self ride
		virtual inline void operator*=(float_precision num);
		//Self divide
		virtual inline void operator/=(float_precision num);
		//Is equal
		virtual inline bool equal_(const Vector3& vec3) const;
		virtual inline bool operator==(const Vector3& vec3) const;
		//Is unequal
		virtual inline bool unequal_(const Vector3& vec3) const;
		virtual inline bool operator!=(const Vector3& vec3) const;
		//Init as (0,0,0)
		Vector3();
		//Init as (x,y,z)
		Vector3(float_precision x, float_precision y, float_precision z);
	};
}

#endif