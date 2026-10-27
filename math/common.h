///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// math/common.h
/// This file contains necessary definitions of math.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_MATH_COMMON_H
#define SE_MATH_COMMON_H

#include "base/base.h"
#include <cmath>
#include <initializer_list>
#include <limits>

namespace stapler_engine {

#ifndef SE_MATH_HIGH_PRECISION
typedef Float32 Float;
#else
typedef Float64 Float;
#endif

namespace math {
inline constexpr Float kFloatEpsilon = std::numeric_limits<Float>::epsilon();
inline constexpr Float32 kFloat32Epsilon =
    std::numeric_limits<Float32>::epsilon();
inline constexpr Float64 kFloat64Epsilon =
    std::numeric_limits<Float64>::epsilon();

template <typename T>
SE_FORCE_INLINE Bool IsEqual(const T &lhs, const T &rhs) noexcept {
  return lhs == rhs;
}

template <>
SE_FORCE_INLINE Bool IsEqual<Float32>(const Float32 &lhs,
                                      const Float32 &rhs) noexcept {
  return std::fabs(lhs - rhs) <= kFloat32Epsilon;
}

template <>
SE_FORCE_INLINE Bool IsEqual<Float64>(const Float64 &lhs,
                                      const Float64 &rhs) noexcept {
  return std::fabs(lhs - rhs) <= kFloat64Epsilon;
}

template <typename Scalar> SE_FORCE_INLINE Scalar Zero() noexcept { return 0; }

template <> SE_FORCE_INLINE Float32 Zero<Float32>() noexcept { return 0.0f; }

template <> SE_FORCE_INLINE Float64 Zero<Float64>() noexcept { return 0.0; }

template <typename T> SE_FORCE_INLINE T Sqrt(const T &x) {
  return std::sqrt(x);
}

template <typename FloatType = Float>
inline constexpr FloatType kPiV =
    static_cast<FloatType>(3.14159265358979323846);

template <typename FloatType = Float>
inline constexpr FloatType kInvPiV =
    static_cast<FloatType>(0.31830988618379067154);

template <typename FloatType = Float>
inline constexpr FloatType kEV = static_cast<FloatType>(2.7182818284590452354);

template <typename FloatType = Float>
inline constexpr FloatType kPhiV =
    static_cast<FloatType>(0.61803398874989484820);

template <typename FloatType = Float>
inline constexpr FloatType kSqrt2V =
    static_cast<FloatType>(1.41421356237309504880);

template <typename FloatType = Float>
inline constexpr FloatType kLog2EV =
    static_cast<FloatType>(1.4426950408889634074);

template <typename FloatType = Float>
inline constexpr FloatType kLog10EV =
    static_cast<FloatType>(0.43429448190325182765);

inline constexpr Float kPi = kPiV<Float>;
inline constexpr Float kInvPi = kInvPiV<Float>;
inline constexpr Float kE = kEV<Float>;
inline constexpr Float kPhi = kPhiV<Float>;
inline constexpr Float kSqrt2 = kSqrt2V<Float>;
inline constexpr Float kLog2E = kLog2EV<Float>;
inline constexpr Float kLog10E = kLog10EV<Float>;

} // namespace math
} // namespace stapler_engine

#endif
