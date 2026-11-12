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
#include "math/vector.h"

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

  static constexpr Self Identity() {
    Self result;
    for (Size i = 0; i < x; i++) {
      for (Size j = 0; j < y; j++) {
        if (i == j)
          result.data_[i][j] = 1;
        else
          result.data_[i][j] = 0;
      }
    }
    return result;
  }

  static constexpr Self Zero() {
    Self result;
    for (Size i = 0; i < x; i++) {
      for (Size j = 0; j < y; j++) {
        result.data_[i][j] = 0;
      }
    }
    return result;
  }

  template <Size row, Size inr, Size col>
  friend Matrix<Scalar, row, col>
  operator*(const Matrix<Scalar, row, inr> &lhs,
            const Matrix<Scalar, inr, col> &rhs) noexcept {
    Matrix<Scalar, row, col> result;
    for (Size r = 0; r < row; r++) {
      for (Size c = 0; c < col; c++) {
        Scalar sum = math::Zero<Scalar>();
        for (int k = 0; k < inr; k++) {
          sum += lhs.data_[r][k] * rhs.data_[k][c];
        }
        result.data_[r][c] = sum;
      }
    }
    return result;
  }

  template <Size row, Size col>
  friend Vector<Scalar, row>
  operator*(const Matrix<Scalar, row, col> &lhs,
            const Vector<Scalar, col> &rhs) noexcept {
    Vector<Scalar, row> result;
    for (Size r = 0; r < row; r++) {
      Scalar sum = math::Zero<Scalar>();
      for (Size c = 0; c < col; c++) {
        sum += lhs.data_[r][c] * rhs[c];
      }
      result.data_[r] = sum;
    }
    return result;
  }

  template <Size s>
  friend Matrix<Scalar, s, s>
  Inverse(Matrix<Scalar, s, s> lhs,
          Matrix<Scalar, s, s> rhs = Matrix<Scalar, s, s>::Identity()) {
    for (Size r = 0; r < s; r++) {
      Size m = r;
      for (Size i = r + 1; i < s; i++) {
        if (std::abs(lhs[i][r]) > std::abs(lhs[m][r]))
          m = i;
      }
      if (lhs[m][r] == 0)
        return math::Zero<Self>();
      if (m != r) {
        Scalar tmp = math::Zero<Scalar>();
        for (Size i = r; i < s; i++) {
          tmp = lhs[m][i];
          lhs[m][i] = lhs[r][i];
          lhs[r][i] = tmp;
        }
        for (Size i = 0; i < s; i++) {
        }
      }
    }
    return lhs;
  }
};

} // namespace math
} // namespace stapler_engine

#endif
