//! numeric.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_NUMERIC_H_
#define DISTANCE_NUMERIC_H_

#include <algorithm>

namespace distance {

const static double kPi = 3.14159265358979323846264338327950288419716;

template <typename T>
T clamp(T x, T a, T b) {
  return std::min(std::max(x, a), b);
}

inline double radFromDeg(double deg) {
  return deg * kPi / 180.0;
}

inline double degFromRad(double rad) {
  return rad * 180.0 / kPi;
}

}

#endif
