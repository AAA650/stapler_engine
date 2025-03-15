// vec_base.h
// Base class for vectors
#ifndef SE_VECTOR_BASE_H
#define SE_VECTOR_BASE_H

#include "s_math.h"

#include "../object/object.h"

#ifdef USING_DOUBLE_VEC
typedef double float_precision
#define EPS 1e-15
#else
typedef float float_precision;
#define EPS 1e-8f
#endif

#define VEC_2(vec)         (vec).x_(), (vec).y_()
#define T_VEC_2(vec,type)  (type)(vec).x_(), (type)(vec).y_()
#define O_VEC_2(vec)       (vec).y_(), (vec).x_()
#define OT_VEC_2(vec,type) (type)(vec).y_(), (type)(vec).x_()

namespace stapler_engine::vec {
	class Vector : public Object {

	};
}


#endif // !SE_VECTOR_BASE_H
