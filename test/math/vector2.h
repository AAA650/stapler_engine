///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// math/vector2.h
/// This file contains the declaration of template Vector2V<Scalar>.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_MATH_VECTOR2_H
#define SE_MATH_VECTOR2_H

#include "math/vector.h"
#include <initializer_list>

namespace stapler_engine {
namespace math {

template <typename Scalar> class Vector2V : public Vector<Scalar, 2> {
  using Self = Vector2V<Scalar>;

public:
  Vector2V(std::initializer_list<Scalar> data) : Vector<Scalar, 2>(data) {}

  SE_FORCE_INLINE Scalar &X() noexcept { return this->data_[0]; }
  SE_FORCE_INLINE const Scalar &X() const noexcept { return this->data_[0]; }

  SE_FORCE_INLINE Scalar &Y() noexcept { return this->data_[1]; }
  SE_FORCE_INLINE const Scalar &Y() const noexcept { return this->data_[1]; }

  inline Scalar Cross(const Self &other) noexcept {
    return this->data_[0] * other.data_[1] - this->data_[1] * other.data_[0];
  }
};

typedef Vector2V<Int32> Vector2I;
typedef Vector2V<Float> Vector2;

} // namespace math
} // namespace stapler_engine

#endif
