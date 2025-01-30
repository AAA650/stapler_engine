//
#ifndef SE_VEC_3_H
#define SE_VEC_3_H
#include "vec_base.h"

namespace stapler_engine::vector {
	class DLLAPI_SE Vec3 : public Vec {
	protected:
		float_precision x, y, z;
	public:
		//Get x axis
		virtual const float_precision& x_();
		//Get y axis
		virtual const float_precision& y_();
		//Get z axis
		virtual const float_precision& z_();
		//Plus and return value
		virtual Vec3 operator+(Vec3&);
		//Minus and return value
		virtual Vec3 operator-(Vec3&);
		//
		virtual Vec3 operator*(Vec3&);
		virtual Vec3 operator/(Vec3&);
		virtual void operator+=(Vec3&);
		virtual void operator-=(Vec3&);
		virtual void operator*=(Vec3&);
		virtual void operator/=(Vec3&);
		virtual bool operator==(Vec3&);
		virtual bool operator!=(Vec3&);
		Vec3();
		Vec3(float_precision, float_precision, float_precision);
	};
}

#endif