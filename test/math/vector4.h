///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// math/vector4.h
/// This file contains the declaration of template Vector4V<Scalar>.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_MATH_VECTOR4_H
#define SE_MATH_VECTOR4_H

#include "math/vector.h"

namespace stapler_engine {
namespace math {

template <typename Scalar> class Vector4V : public Vector<Scalar, 4> {
  using Self = Vector4V<Scalar>;

public:
  Vector4V(std::initializer_list<Scalar> data) : Vector<Scalar, 4>(data) {}

  SE_FORCE_INLINE Scalar &X() noexcept { return this->data_[0]; }
  SE_FORCE_INLINE const Scalar &X() const noexcept { return this->data_[0]; }

  SE_FORCE_INLINE Scalar &Y() noexcept { return this->data_[1]; }
  SE_FORCE_INLINE const Scalar &Y() const noexcept { return this->data_[1]; }

  SE_FORCE_INLINE Scalar &Z() noexcept { return this->data_[2]; }
  SE_FORCE_INLINE const Scalar &Z() const noexcept { return this->data_[2]; }

  SE_FORCE_INLINE Scalar &W() noexcept { return this->data_[3]; }
  SE_FORCE_INLINE const Scalar &W() const noexcept { return this->data_[3]; }

  inline Self Cross(const Self &other) const noexcept {
    return Self{
        {this->data_[1] * other.data_[2] - this->data_[2] * other.data_[1],
         this->data_[2] * other.data_[0] - this->data_[0] * other.data_[2],
         this->data_[0] * other.data_[1] - this->data_[1] * other.data_[0]}};
  }

  inline Self CrossWith(const Self &other) noexcept {
    *this = this->Cross(other);
  }
};

typedef Vector4V<Int32> Vector4I;
typedef Vector4V<Float> Vector4;

} // namespace math
} // namespace stapler_engine

#endif
