#ifndef SE_DLL_CONFIG_H
#define	SE_DLL_CONFIG_H

#ifdef SE_DLL_LIB //shared lib
#ifdef STAPLER_ENGINE_EXPORTS
#define DLLAPI_SE _declspec(dllexport)
#else
#define DLLAPI_SE _declspec(dllimport)
#endif
#else //static lib
#define DLLAPI_SE
#endif

#include <stdlib.h>
#include <iostream>
#include <string>

#endif // !SE_DLL_CONFIG
