// vec_3i.h
#ifndef SE_VEC_3I_H
#define SE_VEC_3I_H
#include "vec_base.h"

namespace stapler_engine::vector {
	class DLLAPI_SE Vector3i : public Vector {
	protected:
		int x, y, z;
	public:
		//Get x axis
		virtual inline const int x_();
		//Set x axis
		virtual inline void x_(int num);
		//Get y axis
		virtual inline const int y_();
		//Set y axis
		virtual inline void y_(int num);
		//Get z axis
		virtual inline const int z_();
		//Set z axis
		virtual inline void z_(int num);
		//Plus Vector3i
		virtual inline Vector3i plus_(Vector3i vec3);
		virtual inline Vector3i operator+(Vector3i vec3);
		//Plus num
		virtual inline Vector3i plus_(int num);
		virtual inline Vector3i operator+(int num);
		//Minus Vector3i
		virtual inline Vector3i minus_(Vector3i vec3);
		virtual inline Vector3i operator-(Vector3i vec3);
		//Minus num
		virtual inline Vector3i minus_(int num);
		virtual inline Vector3i operator-(int num);
		//Ride num
		virtual inline Vector3i ride_(int num);
		virtual inline Vector3i operator*(int num);
		//Dot Vector3i
		virtual inline int dot_(Vector3i vec3);
		//Cross Vector3i
		virtual inline Vector3i cross_(Vector3i vec3);
		//Divide num
		virtual inline Vector3i divide_(int num);
		virtual inline Vector3i operator/(int num);
		//Norm without radical
		virtual inline int norm_without_radical_();
		//Self add
		virtual inline void operator+=(Vector3i vec3);
		virtual inline void operator+=(int num);
		//Self minus
		virtual inline void operator-=(Vector3i vec3);
		virtual inline void operator-=(int num);
		//Self ride
		virtual inline void operator*=(int num);
		//Self divide
		virtual inline void operator/=(int num);
		//Is equal
		virtual inline bool equal_(Vector3i vec3);
		virtual inline bool operator==(Vector3i vec3);
		//Is unequal
		virtual inline bool unequal_(Vector3i vec3);
		virtual inline bool operator!=(Vector3i vec3);
		//Init as (0,0,0)
		Vector3i();
		//Init as (x,y,z)
		Vector3i(int x, int y, int z);
	};
}

#endif