#pragma once

#include "canvas/pixel.hpp"
#include <ostream>
#include <vector>

namespace rcanvas {
class Canvas {
private:
  uint width_, height_;
  std::vector<Pixel> pixels_;

public:
  Canvas(uint width, uint height)
      : width_(width), height_(height),
        pixels_(std::vector<Pixel>(width * height, Pixel(1, 0, 0))) {}
  inline const Pixel get(uint r, uint c) const;
  inline void set(uint r, uint c, const Pixel &p);
  inline std::ostream &write(std::ostream &os) const;
};

inline const Pixel Canvas::get(uint r, uint c) const {
  return pixels_[r * width_ + c];
}

inline void Canvas::set(uint r, uint c, const Pixel &p) {
  pixels_[r * width_ + c] = p;
}

inline std::ostream &Canvas::write(std::ostream &os) const {
  os << "P3"
     << "\n"
     << width_ << " " << height_ << "\n255\n";
  for (uint r = 0; r < height_; r++) {
    for (uint c = 0; c < width_; c++) {
      os << pixels_[r * width_ + c] << (c == width_ - 1 ? "\n" : " ");
    }
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, const Canvas &c) {
  return c.write(os);
}
} // namespace rcanvas
