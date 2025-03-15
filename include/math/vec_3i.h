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
		virtual int& x_();
		//Y axis
		virtual int& y_();
		//Z axis
		virtual int& z_();
		//Vec width
		virtual int& width_();
		//Vec height
		virtual int& height_();
		//Vec depth
		virtual int& depth_();
		//Find axis by offset
		virtual int& operator[](int axis_index);
		//Plus Vector3i
		virtual Vector3i plus_(const Vector3i& vec3) const;
		virtual Vector3i operator+(const Vector3i& vec3) const;
		//Plus num
		virtual Vector3i plus_(int num) const;
		virtual Vector3i operator+(int num) const;
		//Minus Vector3i
		virtual Vector3i minus_(const Vector3i& vec3) const;
		virtual Vector3i operator-(const Vector3i& vec3) const;
		//Minus num
		virtual Vector3i minus_(int num) const;
		virtual Vector3i operator-(int num) const;
		//Ride num
		virtual Vector3i multiply_(int num) const;
		virtual Vector3i operator*(int num) const;
		//Dot Vector3i
		virtual int dot_(const Vector3i& vec3) const;
		//Cross Vector3i
		virtual Vector3i cross_(const Vector3i& vec3) const;
		//Divide num
		virtual Vector3i divide_(int num) const;
		virtual Vector3i operator/(int num) const;
		//Norm without radical
		virtual int length_squared_() const;
		//Self add
		virtual void operator+=(const Vector3i& vec3);
		virtual void operator+=(int num);
		//Self minus
		virtual void operator-=(const Vector3i& vec3);
		virtual void operator-=(int num);
		//Self ride
		virtual void operator*=(int num);
		//Self divide
		virtual void operator/=(int num);
		//Is equal
		virtual bool equal_(const Vector3i& vec3) const;
		virtual bool operator==(const Vector3i& vec3) const;
		//Is unequal
		virtual bool unequal_(const Vector3i& vec3) const;
		virtual bool operator!=(const Vector3i& vec3) const;
		//Init as (0,0,0)
		Vector3i();
		//Init as (x,y,z)
		Vector3i(int x, int y, int z);
	};

	typedef Vector3i Point3i;
	typedef Vector3i Size3i;
}

#endif