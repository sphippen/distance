//! numeric.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_NUMERIC_H_
#define DISTANCE_NUMERIC_H_

#include <algorithm>

namespace distance {

template <typename T>
T clamp(T x, T a, T b) {
  return std::min(std::max(x, a), b);
}

}

#endif
