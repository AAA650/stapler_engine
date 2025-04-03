#ifndef SE_TYPE_DEF_H
#define SE_TYPE_DEF_H

#ifdef UNICODE //UNICODE
#define TSTR wstring
#define COUT wcout
#define CIN wcin
#else  //ASCII
#define TSTR string
#define COUT cout
#define CIN cin
#endif

#endif