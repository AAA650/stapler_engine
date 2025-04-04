#ifndef S_DLL_CONFIG_H
#define	S_DLL_CONFIG_H

#ifdef S_DLL_LIB //shared lib
#ifdef STAPLER_ENGINE_EXPORTS
#define DLLAPI_SE _declspec(dllexport)
#else
#define DLLAPI_SE _declspec(dllimport)
#endif
#else //static lib
#define DLLAPI_SE
#endif

#include <iostream>
#include <string>

#endif // !S_DLL_CONFIG
