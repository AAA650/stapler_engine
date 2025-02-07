// vec_3i.h
#ifndef SE_VEC_3I_H
#define SE_VEC_3I_H
#include "vec_base.h"

namespace stapler_engine::vec {
	class DLLAPI_SE Vector3i : public Vector {
	public:
		static const int AXIS_COUNT = 3;
		enum Axis { AX, AY, AZ };
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
				union {
					int z;
					int depth;
				};
			};
			int coord[3];
		};
	public:
		//X axis
		virtual inline int& x_();
		//Y axis
		virtual inline int& y_();
		//Z axis
		virtual inline int& z_();
		//Vec width
		virtual inline int& width_();
		//Vec height
		virtual inline int& height_();
		//Vec depth
		virtual inline int& depth_();
		//Find axis by offset
		virtual inline int& operator[](int axis_index);
		//Plus Vector3i
		virtual inline Vector3i plus_(const Vector3i& vec3) const;
		virtual inline Vector3i operator+(const Vector3i& vec3) const;
		//Plus num
		virtual inline Vector3i plus_(int num) const;
		virtual inline Vector3i operator+(int num) const;
		//Minus Vector3i
		virtual inline Vector3i minus_(const Vector3i& vec3) const;
		virtual inline Vector3i operator-(const Vector3i& vec3) const;
		//Minus num
		virtual inline Vector3i minus_(int num) const;
		virtual inline Vector3i operator-(int num) const;
		//Ride num
		virtual inline Vector3i multiply_(int num) const;
		virtual inline Vector3i operator*(int num) const;
		//Dot Vector3i
		virtual inline int dot_(const Vector3i& vec3) const;
		//Cross Vector3i
		virtual inline Vector3i cross_(const Vector3i& vec3) const;
		//Divide num
		virtual inline Vector3i divide_(int num) const;
		virtual inline Vector3i operator/(int num) const;
		//Norm without radical
		virtual inline int length_squared_() const;
		//Self add
		virtual inline void operator+=(const Vector3i& vec3);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(const Vector3i& vec3);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(const Vector3i& vec3) const;
		virtual inline bool operator==(const Vector3i& vec3) const;
		//Is unequal
		virtual inline bool unequal_(const Vector3i& vec3) const;
		virtual inline bool operator!=(const Vector3i& vec3) const;
		//Init as (0,0,0)
		Vector3i();
		//Init as (x,y,z)
		Vector3i(int x, int y, int z);
	};
}

#endif