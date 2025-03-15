// node_2d.h
#ifndef SE_NODE_2D_H
#define SE_NODE_2D_H

#include "node_base.h"
#include "../vector/vec_2.h"
#include "../vector/vec_2i.h"

namespace stapler_engine::node {
	class DLLAPI_SE Node2D : public Node {
	public:
		vec::Vector2 position;

	};
}

#endif