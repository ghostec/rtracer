#pragma once

#include "math/float64.hpp"
#include "math/vec3.hpp"
#include <ostream>

namespace rcanvas {
class Pixel {
private:
  vec3 v_;

public:
  Pixel() : v_(0) {}
  Pixel(float64 a) : v_(a) {}
  Pixel(float64 r, float64 g, float64 b) : v_(r, g, b) {}
  inline std::ostream &write(std::ostream &os) const;
};

int toRGB(float64 a) { return int(255.99 * a); }

inline std::ostream &Pixel::write(std::ostream &os) const {
  os << toRGB(v_.x) << " " << toRGB(v_.y) << " " << toRGB(v_.z);
  return os;
}

inline std::ostream &operator<<(std::ostream &os, const Pixel &p) {
  return p.write(os);
}
} // namespace rcanvas
