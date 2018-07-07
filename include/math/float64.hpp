#pragma once

#include <cmath>

namespace rcanvas {
using float64 = double;

inline bool equals(const float64 a, const float64 b) {
  const float64 epsilon = (a + b) / 1e14;
  return std::fabs(a - b) <=
         ((std::fabs(a) < std::fabs(b) ? std::fabs(b) : std::fabs(a)) *
          epsilon);
}
} // namespace rcanvas
