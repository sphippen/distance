//! 
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

}

#endif
