#ifndef S_DLL_CONFIG_H
#define	S_DLL_CONFIG_H

// shared lib
#ifdef S_DLL_LIB
	// Using msvc compiler
#	ifdef _MSC_VER
#		ifdef STAPLER_ENGINE_EXPORTS
#			define DLLAPI_SE _declspec(dllexport)
#		else
#			define DLLAPI_SE _declspec(dllimport)
#		endif
	// Using GNU Compiler
#	elif __GNUC__
#		define DLLAPI_SE
#	endif

//static lib
#else
#	define DLLAPI_SE
#endif

/*
#ifndef STAPLER_ENGINE_EXPORTS
#	pragma comment(lib,"stapler_engine.lib")
#endif
*/

#include <iostream>
#include <stdint.h>
#include <cstring>
#include <vector>

#include "s_type_def.h"

#endif // !S_DLL_CONFIG
