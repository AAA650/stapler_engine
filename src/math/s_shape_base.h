// s_shape_base.h
// declaration of SShape

#ifndef S_SHAPE_BASE_H
#define S_SHAPE_BASE_H

#include "s_math_func.h"
#include "s_vector.h"

namespace stapler_engine::math
{
	class DLLAPI_SE SShape : public SObject
	{
	public:
		virtual float_precision get_square_measure() = 0;
	};
}

#endif