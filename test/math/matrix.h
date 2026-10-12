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
};
} // namespace math
} // namespace stapler_engine

#endif
