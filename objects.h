//! objects.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_OBJECTS_H_
#define DISTANCE_OBJECTS_H_

#include "vec.h"

namespace distance {

class Object {
  virtual double minDistance(Vec3 p) = 0;
};

class Sphere : public Object {
 public:
  Vec3 center;
  double radius;

  Sphere() : center(0.0), radius(1.0) {}
  Sphere(Vec3 center, double radius) : center(center), radius(radius) {}
  virtual double minDistance(Vec3 p) override {
    return (p-center).length();
  }
};

}

#endif
