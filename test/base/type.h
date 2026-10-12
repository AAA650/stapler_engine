///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// base/types.h
/// This file contains basic types and consts in stapler engine.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_BASE_TYPES_H
#define SE_BASE_TYPES_H

#include <cstddef>
#include <cstdint>

namespace stapler_engine {

// Ints
typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;
typedef int64_t Int64;

// Unsigned Ints
typedef uint8_t UInt8;
typedef uint16_t UInt16;
typedef uint32_t UInt32;
typedef uint64_t UInt64;

// Floats
typedef float Float32;
typedef double Float64;

// Bool
typedef bool Bool;
inline constexpr Bool kTrue = true;
inline constexpr Bool kFalse = false;

// Char
typedef char Char;
typedef wchar_t WChar;

// Size and Index
typedef size_t Size;
typedef ptrdiff_t Index;

} // namespace stapler_engine

#endif
