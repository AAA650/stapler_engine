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

template <typename Scalar> class Vector<Scalar, 3> {
  using Self = Vector<Scalar, 3>;
  static const Size size = 3;

protected:
  Scalar data_[size];

public:
  Vector(std::initializer_list<Scalar> data) : Vector<Scalar, 3>(data) {}

  SE_FORCE_INLINE Scalar &X() noexcept { return this->data_[0]; }
  SE_FORCE_INLINE const Scalar &X() const noexcept { return this->data_[0]; }

  SE_FORCE_INLINE Scalar &Y() noexcept { return this->data_[1]; }
  SE_FORCE_INLINE const Scalar &Y() const noexcept { return this->data_[1]; }

  SE_FORCE_INLINE Scalar &Z() noexcept { return this->data_[2]; }
  SE_FORCE_INLINE const Scalar &Z() const noexcept { return this->data_[2]; }

  SE_FORCE_INLINE Scalar &operator[](Size index) noexcept {
    return this->data_[index];
  }
  SE_FORCE_INLINE const Scalar &operator[](Size index) const noexcept {
    return this->data_[index];
  }

  inline Scalar &At(Index index) noexcept {
    assert(index >= -size && index < size);
    return this->data_[index % size];
  }

  inline const Scalar &At(Index index) const noexcept {
    assert(index >= -size && index < size);
    return this->data_[index % size];
  }

  inline Scalar LengthPow2() const noexcept {
    Scalar result = static_cast<Scalar>(0.0);
    for (Size i = 0; i < size; i++) {
      result += this->data_[i] * this->data_[i];
    }
    return result;
  }

  inline Scalar Length() const noexcept { return Sqrt(LengthPow2()); }

  inline Self &Normalize() const noexcept {
    Scalar factor = 1 / Length();
    for (Size i = 0; i < size; i++) {
      this->data_[i] *= factor;
    }
    return &this;
  }

  inline Self &operator+=(const Self &rhs) noexcept {
    for (Size i = 0; i < size; i++)
      this->data_[i] += rhs.data_[i];
    return *this;
  }

  inline Self &operator+=(Scalar rhs) noexcept {
    for (Size i = 0; i < size; i++)
      this->data_[i] += rhs;
    return *this;
  }

  inline Self &operator-=(const Self &rhs) noexcept {
    for (Size i = 0; i < size; i++)
      this->data_[i] -= rhs.data_[i];
    return *this;
  }

  inline Self &operator-=(Scalar rhs) noexcept {
    for (Size i = 0; i < size; i++)
      this->data_[i] -= rhs;
    return *this;
  }

  inline Self &operator*=(Scalar rhs) noexcept {
    for (Size i = 0; i < size; i++)
      this->data_[i] *= rhs;
    return *this;
  }

  inline Self &operator/=(Scalar rhs) noexcept {
    assert(rhs != 0);
    for (Size i = 0; i < size; i++)
      this->data_[i] /= rhs;
    return *this;
  }

  friend inline Bool operator==(const Self &lhs, const Self &rhs) noexcept {
    for (Size i = 0; i < size; i++)
      if (!IsEqual(lhs.data_[i], rhs.data_[i]))
        return false;
    return true;
  }

  friend inline Bool operator!=(const Self &lhs, const Self &rhs) noexcept {
    for (Size i = 0; i < size; i++)
      if (!IsEqual(lhs.data_[i], rhs.data_[i]))
        return true;
    return false;
  }

  friend inline Self operator+(Self lhs, const Self &rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  friend inline Self operator+(Self lhs, const Scalar &rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  friend inline Self operator-(Self lhs, const Self &rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  friend inline Self operator-(Self lhs, const Scalar &rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  friend inline Scalar operator*(const Self &lhs, const Self &rhs) noexcept {
    Scalar result = static_cast<Scalar>(0.0);
    for (Size i = 0; i < size; i++) {
      result += lhs.data_[i] * rhs.data_[i];
    }
    return result;
  }

  friend inline Self operator*(Self lhs, const Scalar &rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  friend inline Self operator/(Self lhs, const Scalar &rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }

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

typedef Vector<Int32, 3> Vector3I;
typedef Vector<Float, 3> Vector3;

} // namespace math
} // namespace stapler_engine

#endif
