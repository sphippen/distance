//! color.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_COLOR_H_
#define DISTANCE_COLOR_H_

struct Color {
  double r;
  double g;
  double b;

  Color() : r(0.0), g(0.0), b(0.0) {}
  Color(double r, double g, double b) : r(r), g(g), b(b) {}
  explicit Color(double init) : r(init), g(init), b(init) {}

};

inline Color& operator+=(Color& c1, const Color& c2) {
  c1.r += c2.r;
  c1.g += c2.g;
  c1.b += c2.b;
  return c1;
}

inline Color& operator+=(Color& c, double s) {
  c.r += s;
  c.g += s;
  c.b += s;
  return c;
}

inline Color& operator-=(Color& c1, const Color& c2) {
  c1.r -= c2.r;
  c1.g -= c2.g;
  c1.b -= c2.b;
  return c1;
}

inline Color& operator-=(Color& c, double s) {
  c.r -= s;
  c.g -= s;
  c.b -= s;
  return c;
}

inline Color& operator*=(Color& c1, const Color& c2) {
  c1.r *= c2.r;
  c1.g *= c2.g;
  c1.b *= c2.b;
  return c1;
}

inline Color& operator*=(Color& c, double s) {
  c.r *= s;
  c.g *= s;
  c.b *= s;
  return c;
}

inline Color& operator/=(Color& c, double s) {
  c.r /= s;
  c.g /= s;
  c.b /= s;
  return c;
}

inline Color operator+(const Color& c1, const Color& c2) {
  Color copy(c1);
  copy += c2;
  return copy;
}

inline Color operator+(const Color& c1, double s) {
  Color copy(c1);
  copy += s;
  return copy;
}

inline Color operator+(double s, const Color& c1) {
  return operator+(c1, s);
}

inline Color operator-(const Color& c1, const Color& c2) {
  Color copy(c1);
  copy -= c2;
  return copy;
}

inline Color operator-(const Color& c, double s) {
  Color copy(c);
  copy -= s;
  return copy;
}

inline Color operator*(const Color& c, double s) {
  Color copy(c);
  copy *= s;
  return copy;
}

inline Color operator*(double s, const Color& c) {
  return operator*(c, s);
}

inline Color operator/(const Color& c, double s) {
  Color copy(c);
  copy /= s;
  return copy;
}

#endif
