// vec_base.h
// basic declaration for vectors
// declaration of SVector

#ifndef S_VECTOR_BASE_H
#define S_VECTOR_BASE_H

#include "../s_object.h"

#include "s_math_func.h"

#define VEC_2(vec)         (vec).x_(), (vec).y_()
#define T_VEC_2(vec,type)  (type)(vec).x_(), (type)(vec).y_()
#define O_VEC_2(vec)       (vec).y_(), (vec).x_()
#define OT_VEC_2(vec,type) (type)(vec).y_(), (type)(vec).x_()

namespace stapler_engine::vector
{
	class DLLAPI_SE SVector : public SObject
	{

	};
}


#endif // !S_VECTOR_BASE_H
