#ifndef SE_DLL_CONFIG
#define	SE_DLL_CONFIG

#ifdef STAPLER_ENGINE_EXPORTS
#define DLLAPI_SE _declspec(dllexport)
#else
#define DLLAPI_SE _declspec(dllimport)
#endif

#ifdef UNICODE //UNICODE
#define TSTR wstring
#define COUT wcout
#define CIN wcin
#else  //ASCII
#define TSTR string
#define COUT cout
#define CIN cin
#endif

#include <stdlib.h>
#include <typeinfo>

#endif // !SE_DLL_CONFIG
