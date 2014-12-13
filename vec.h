//! vec.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_VEC_H_
#define DISTANCE_VEC_H_

#include <cmath>

namespace distance {

// Templated size vec
template <int n>
struct Vec {
  double data[n];

  Vec() {
    for (int i = 0; i < n; ++i)
      data[i] = 0.0;
  }

  explicit Vec(double init) {
    for (int i = 0; i < n; ++i)
      data[i] = init;
  }

  double lengthSquared() const {
    double accum = 0.0;
    for (int i = 0; i < n; ++i)
      accum += data[i]*data[i];
    return accum;
  }

  double length() const {
    return std::sqrt(lengthSquared());
  }

  void normalize() {
    double factor = 1.0 / length();
    for (int i = 0; i < n; ++i)
      data[i] *= factor;
  }

  double normalized() const {
    Vec<n> v(*this);
    v.normalize();
    return v;
  }

  double dot(const Vec<n>& v) const {
    double accum = 0.0;
    for (int i = 0; i < n; ++i)
      accum += data[i] * v.data[i];
  }
};

template <int n>
Vec<n>& operator+=(Vec<n>& v1, const Vec<n>& v2) {
  for (int i = 0; i < n; ++i)
    v1.data[i] += v2.data[i];
  return v1;
}

template <int n>
Vec<n>& operator-=(Vec<n>& v1, const Vec<n>& v2) {
  for (int i = 0; i < n; ++i)
    v1.data[i] -= v2.data[i];
  return v1;
}

template <int n>
Vec<n>& operator*=(Vec<n>& v, double r) {
  for (int i = 0; i < n; ++i)
    v.data[i] *= r;
  return v;
}

template <int n>
Vec<n> operator*(const Vec<n>& v, double r) {
  Vec<n> copy(v);
  copy *= r;
  return copy;
}

template <int n>
Vec<n>& operator*(double r, const Vec<n>& v) {
  return operator*(v, r);
}

template <int n>
Vec<n> operator-(Vec<n>& v) {
  Vec<n> copy(v);
  for (int i = 0; i < n; ++i)
    copy.data[i] *= -1.0;
  return copy;
}

// Specializations

template <>
struct Vec<2> {
  union {
    double data[2];
    struct {
      double x;
      double y;
    };
  };

  Vec() : x(0.0), y(0.0) {}
  Vec(double x, double y) : x(x), y(y) {}
  explicit Vec(double init) : x(init), y(init) {}

  double lengthSquared() const {
    return x*x + y*y;
  }

  double length() const {
    return std::sqrt(lengthSquared());
  }

  void normalize() {
    double factor = 1.0 / length();
    x /= factor;
    y /= factor;
  }

  Vec<2> normalized() const {
    Vec<2> v(*this);
    v.normalize();
    return v;
  }

  double dot(const Vec<2>& v) const {
    return x*v.x + y*v.y;
  }

};
typedef Vec<2> Vec2;

template <>
struct Vec<3> {
  union {
    double data[3];
    struct {
      double x;
      double y;
      double z;
    };
  };

  Vec() : x(0.0), y(0.0), z(0.0) {}
  Vec(double x, double y, double z) : x(x), y(y), z(z) {}
  explicit Vec(double init) : x(init), y(init), z(init) {}

  double lengthSquared() const {
    return x*x + y*y + z*z;
  }

  double length() const {
    return std::sqrt(lengthSquared());
  }

  void normalize() {
    double factor = 1.0 / length();
    x /= factor;
    y /= factor;
    z /= factor;
  }

  Vec<3> normalized() const {
    Vec<3> v(*this);
    v.normalize();
    return v;
  }

  double dot(const Vec<3>& v) const {
    return x*v.x + y*v.y + z*v.z;
  }

  Vec<3> cross(const Vec<3>& v) const {
    return Vec<3>(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
  }
};
typedef Vec<3> Vec3;

template <>
struct Vec<4> {
  union {
    double data[4];
    struct {
      union {
        struct {
          double x;
          double y;
          double z;
        };
        Vec<3> xyz;
      };
      double w;
    };
  };

  Vec() : x(0.0), y(0.0), z(0.0), w(0.0) {}
  Vec(double x, double y, double z, double w) : x(x), y(y), z(z), w(w) {}
  explicit Vec(double init) : x(init), y(init), z(init), w(init) {}

  double lengthSquared() const {
    return x*x + y*y + z*z + w*w;
  }

  double length() const {
    return std::sqrt(lengthSquared());
  }

  void normalize() {
    double factor = 1.0 / length();
    x /= factor;
    y /= factor;
    z /= factor;
    w /= factor;
  }

  Vec<4> normalized() const {
    Vec<4> v(*this);
    v.normalize();
    return v;
  }

  double dot(const Vec<4>& v) const {
    return x*v.x + y*v.y + z*v.z + w*v.w;
  }

};
typedef Vec<4> Vec4;

}

#endif
