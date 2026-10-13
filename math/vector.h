///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// math/vector.h
/// This file contains the declaration of template Vector<Scalar, Size>.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_MATH_VECTOR_H
#define SE_MATH_VECTOR_H

#include "math/common.h"

namespace stapler_engine {
namespace math {

template <typename Scalar, Size size> class Vector {
  using Self = Vector<Scalar, size>;
  static_assert(size > 0);

protected:
  Scalar data_[size];

public:
  Vector(std::initializer_list<Scalar> data) {
    assert(data.size() == size);
    Size i = 0;
    for (Scalar v : data)
      this->data_[i++] = v;
  }

public:
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
};

} // namespace math
} // namespace stapler_engine

#endif
