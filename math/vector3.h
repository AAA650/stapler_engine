///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// math/vector3.h
/// This file contains the declaration of template Vector3V<Scalar>.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_MATH_VECTOR3_H
#define SE_MATH_VECTOR3_H

#include "math/vector.h"

namespace stapler_engine {
namespace math {

template <typename Scalar> class Vector3V : public Vector<Scalar, 3> {
  using Self = Vector3V<Scalar>;

public:
  Vector3V(std::initializer_list<Scalar> data) : Vector<Scalar, 3>(data) {}

  SE_FORCE_INLINE Scalar &X() noexcept { return this->data_[0]; }
  SE_FORCE_INLINE const Scalar &X() const noexcept { return this->data_[0]; }

  SE_FORCE_INLINE Scalar &Y() noexcept { return this->data_[1]; }
  SE_FORCE_INLINE const Scalar &Y() const noexcept { return this->data_[1]; }

  SE_FORCE_INLINE Scalar &Z() noexcept { return this->data_[2]; }
  SE_FORCE_INLINE const Scalar &Z() const noexcept { return this->data_[2]; }

  inline Self Cross(const Self &rhs) const noexcept {
    return Self{
        {this->data_[1] * rhs.data_[2] - this->data_[2] * rhs.data_[1],
         this->data_[2] * rhs.data_[0] - this->data_[0] * rhs.data_[2],
         this->data_[0] * rhs.data_[1] - this->data_[1] * rhs.data_[0]}};
  }

  inline Self &CrossWith(const Self &rhs) noexcept {
    *this = this->Cross(rhs);
    return *this;
  }
};

typedef Vector3V<Int32> Vector3I;
typedef Vector3V<Float> Vector3;

} // namespace math
} // namespace stapler_engine

#endif
