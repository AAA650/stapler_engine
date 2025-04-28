// stapler_engine.h
// stapler_engine_3, aka SE, copyright 2025 AAA650
// thanks for using SE, hope U can use it to build a wonderful project.
//

#ifndef STAPLER_ENGINE_H
#define STAPLER_ENGINE_H

#include "core/s_core.h"
#include "math/s_math.h"
#include "component/s_component.h"
#include "node/s_node.h"

namespace se = stapler_engine;
namespace se_math = stapler_engine::math;
namespace se_comp = stapler_engine::component;
namespace se_node = stapler_engine::node;

namespace stapler_engine 
{
	//Stapler engine main function
	int se_main(int argc, char* argv[]);
}

#endif // !STAPLER_ENGINE_H
