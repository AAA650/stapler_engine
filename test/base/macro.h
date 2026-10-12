///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// base/macros.h
/// This file contains macros for stapler engine base.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_BASE_MACROS_H
#define SE_BASE_MACROS_H

#include <cassert>

#define SE_BASE_USE_STD_CONTAINER
#define SE_BASE_USE_UNICODE

#if defined(_MSC_VER)
#define SE_FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define SE_FORCE_INLINE inline __attribute__((always_inline))
#else
#define SE_FORCE_INLINE inline
#endif

#endif
