// s_type_def.h
// defined some useful types

#ifndef S_TYPE_DEF_H
#define S_TYPE_DEF_H

namespace stapler_engine {

#ifdef UNICODE
	typedef std::wstring tstring;
	typedef wchar_t tchar;

#	define tcout std::wcout
#	define tcin std::wcin
#	define tstrcmp wcscmp

#else //UNICODE
	typedef std::string tstring;
	typedef char tchar;

#	define tcout std::cout
#	define tcin std::cin
#	define tstrcmp strcmp

#endif //ASCII
}

#endif