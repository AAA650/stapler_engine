//SEDefinition.h   Define all things in SE.
#pragma once

#ifndef SEDEFINITION_H
#define SEDEFINITION_H
#endif

#ifdef STAPLERENGINE_EXPORTS
#define DLLAPI_SE _declspec(dllexport)
#else
#define DLLAPI_SE _declspec(dllimport)
#endif

#ifdef UNICODE
#define TSTR wstring
#define COUT wcout
#define CIN wcin
#else  /*ANSI*/
#define TSTR string
#define COUT cout
#define CIN cin
#endif
