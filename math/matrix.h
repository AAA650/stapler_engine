///===-------------------------------------------------------------------------------===//
///
/// Part of Stapler Engine Project(aka. SE), under Apache License V2.0 .
/// See the LICENSE.md file for more information.
/// Copyright (c) 2026 AAA650. All Rights Reserved.
///
///===-------------------------------------------------------------------------------===//
///
/// math/matrix.h
/// This file contains the declaration of template Matrix<Scalar, Size>.
///
///===-------------------------------------------------------------------------------===//

#ifndef SE_MATH_MATRIX_H
#define SE_MATH_MATRIX_H

#include "math/common.h"

namespace stapler_engine {
namespace math {

template <typename Scalar, Size x, Size y> class Matrix {
  using Self = Matrix<Scalar, x, y>;
  static_assert(x > 0 && y > 0);

protected:
  Scalar data_[x][y];

public:
  inline Self &operator+=(const Self &rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        this->data_[i][j] += rhs.data_[i][j];
      }
    }
    return *this;
  }

  inline Self &operator+=(Scalar rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        this->data_[i][j] += rhs;
      }
    }
    return *this;
  }

  inline Self &operator-=(const Self &rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        this->data_[i][j] -= rhs.data_[i][j];
      }
    }
    return *this;
  }

  inline Self &operator-=(Scalar rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        this->data_[i][j] -= rhs;
      }
    }
    return *this;
  }

  inline Self &operator*=(Scalar rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        this->data_[i][j] *= rhs;
      }
    }
    return *this;
  }

  inline Self &operator/=(Scalar rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        this->data_[i][j] /= rhs;
      }
    }
    return *this;
  }

  inline Bool operator==(const Self &rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        if (this->data_[i][j] != rhs.data_[i][j])
          return false;
      }
    }
    return true;
  }

  inline Bool operator!=(const Self &rhs) {
    for (Size i = 0; i < x; ++i) {
      for (Size j = 0; j < y; ++j) {
        if (this->data_[i][j] != rhs.data_[i][j])
          return true;
      }
    }
    return false;
  }

  template <Size R, Size K, Size C>
  friend Matrix<Scalar, R, C>
  operator*(const Matrix<Scalar, R, K> &lhs,
            const Matrix<Scalar, K, C> &rhs) noexcept {
    Matrix<Scalar, R, C> result;
    for (Size r = 0; r < R; ++r) {
      for (Size c = 0; c < C; ++c) {
        Scalar sum = static_cast<Scalar>(0.0);
        for (int k = 0; k < K; ++k) {
          sum += lhs.data_[k][c] * rhs.data_[r][k];
        }
        result.data_[r][c] = sum;
      }
    }
    return result;
  }
};
} // namespace math
} // namespace stapler_engine

#endif
