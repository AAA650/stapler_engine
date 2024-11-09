//StaplerEngine.h Include all things.
//StaplerEngine Copyright 2022-2024 TEAH Technology Co. Ltd.
//
#ifndef STAPLERENGINE_H
#define STAPLERENGINE_H

#define SE_VER "0.3.0"

#include "include/SEDefinition.h"

#if (!defined STAPLERENGINE_EXPORTS) && (!defined STAPLERENGINE_COMMENT)
	#define STAPLERENGINE_COMMENT
	#pragma comment(lib,"StaplerEngine.lib")
#endif

#include "include/Object.h"
#include "include/Colour.h"
#include "include/Rand.h"

#endif