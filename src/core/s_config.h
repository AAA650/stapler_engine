#ifndef S_DLL_CONFIG_H
#define	S_DLL_CONFIG_H

// shared lib
#ifdef S_DLL_LIB
// exporting dll
#ifdef STAPLER_ENGINE_EXPORTS
// using msvc
#ifdef _MSC_VER
#define DLLAPI_SE _declspec(dllexport)
// using gnu complier
#elif __GNUC__
#define DLLAPI_SE
#endif
// importing dll
#else
#define DLLAPI_SE _declspec(dllimport)
#endif
//static lib
#else
#define DLLAPI_SE
#endif

/*
#ifndef STAPLER_ENGINE_EXPORTS
#pragma comment(lib,"stapler_engine.lib")
#endif
*/

#include <iostream>
#include <cstring>
#include <vector>

#include "s_type_def.h"

#endif // !S_DLL_CONFIG
