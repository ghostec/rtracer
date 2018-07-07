#pragma once

#include "math/float64.hpp"
#include <cmath>
#include <istream>
#include <ostream>

namespace rcanvas {
class vec3 {
public:
  float64 x, y, z;
  vec3(float64 a) : x(a), y(a), z(a) {}
  vec3(float64 x, float64 y, float64 z) : x(x), y(y), z(z) {}
  inline vec3 operator+() const;
  inline vec3 operator-() const;
  inline vec3 &operator+=(const vec3 &v);
  inline vec3 &operator-=(const vec3 &v);
  inline vec3 &operator*=(const vec3 &v);
  inline vec3 &operator*=(const float64 t);
  inline vec3 &operator/=(const float64 t);
  inline float64 squaredLength() const;
  inline float64 length() const;
  inline vec3 unit() const;
  inline void makeUnit();
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2) { return v1 + (-v2); }

inline vec3 operator*(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

inline vec3 operator*(const float64 t, const vec3 &v) {
  return vec3(t * v.x, t * v.y, t * v.z);
}

inline vec3 operator*(const vec3 &v, const float64 t) { return t * v; }

inline vec3 operator/(const vec3 &v, const float64 t) {
  const float64 inv_t = 1.0 / t;
  return v * inv_t;
}

inline float64 dot(const vec3 &v1, const vec3 &v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
  return vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
              v1.x * v2.y - v1.y * v2.x);
}

inline vec3 vec3::operator+() const { return *this; }

inline vec3 vec3::operator-() const { return vec3(-x, -y, -z); }

inline vec3 &vec3::operator+=(const vec3 &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

inline vec3 &vec3::operator-=(const vec3 &v) {
  *this += -v;
  return *this;
}

inline vec3 &vec3::operator*=(const vec3 &v) {
  x *= v.x;
  y *= v.y;
  z *= v.z;
  return *this;
}

inline vec3 &vec3::operator*=(const float64 t) {
  x *= t;
  y *= t;
  z *= t;
  return *this;
}

inline vec3 &vec3::operator/=(const float64 t) {
  const float64 inv_t = 1.0 / t;
  *this *= inv_t;
  return *this;
}

inline float64 vec3::squaredLength() const { return x * x + y * y + z * z; }

inline float64 vec3::length() const { return std::sqrt(squaredLength()); }

inline vec3 vec3::unit() const { return *this / length(); }

inline void vec3::makeUnit() { *this = *this / length(); }

inline std::istream &operator>>(std::istream &is, vec3 &v) {
  is >> v.x >> v.y >> v.z;
  return is;
}

inline std::ostream &operator<<(std::ostream &os, const vec3 &v) {
  os << v.x << " " << v.y << " " << v.z;
  return os;
}
} // namespace rcanvas
