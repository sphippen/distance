//! ray.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_RAY_H_
#define DISTANCE_RAY_H_

#include "vec.h"

namespace distance {

struct Ray {
  Vec3 p;
  Vec3 dir;
  Ray() {}
  Ray(Vec3 p, Vec3 dir) : p(p), dir(dir) {}
};

}

#endif
