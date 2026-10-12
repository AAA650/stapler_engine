///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// base/string.h
/// This file contains implement of string.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_BASE_STRING_H
#define SE_BASE_STRING_H

#include "macro.h"
#include "type.h"
#ifdef SE_BASE_USE_STD_CONTAINER
#include <string>
#endif

namespace stapler_engine {

#ifdef SE_BASE_USE_STD_CONTAINER
typedef std::string String;
typedef std::wstring WString;

#ifdef SE_BASE_USE_UNICODE
typedef WString TString;
typedef WChar TChar;
#define SE_TSTR(str) L##str
#else
typedef String TString;
typedef Char TChar;
#define SE_TSTR(str) str
#endif

#else
// TODO: Make a string container.
#endif
} // namespace stapler_engine

#endif
