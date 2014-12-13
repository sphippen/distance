//! scene.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_SCENE_H_
#define DISTANCE_SCENE_H_

#include <vector>
#include <memory>

#include "vec.h"
#include "objects.h"

namespace distance {

struct Camera {
  Vec3 pos;
  Vec3 lookAt;
  Vec3 up;
  double vFOV;
  double aspectRatio;
};

class Scene {
 public:
  Scene();
  bool renderScene(const char* fileName);
 private:
  int width_;
  int height_;
  Camera camera_;
  std::vector<std::unique_ptr<Object>> objs_;
};

}

#endif
