//! scene.cpp
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#include "scene.h"

#include <cstdio>
#include "numeric.h"
#include "framebuffer.h"
#include "ray.h"

namespace distance {

Scene::Scene() : width_(800), height_(600) {
  camera_.pos = Vec3(0.0, 0.0, 10.0);
  camera_.lookAt = Vec3(0.0, 0.0, 0.0);
  camera_.up = Vec3(0.0, 1.0, 0.0);
  camera_.vFOV = radFromDeg(60);
  camera_.aspectRatio = static_cast<double>(width_) / height_;
}

bool Scene::renderScene(const char* fileName) {
  FrameBuffer fb(width_, height_);

  // Calc camera stuff
  Vec3 forward = camera_.lookAt - camera_.pos;
  forward.normalize();
  Vec3 right = forward.cross(camera_.up);
  Vec3 up = right.cross(forward);

  double imgPlaneH = 2.0 * std::tan(camera_.vFOV / 2.0);
  double imgPlaneW = imgPlaneH * camera_.aspectRatio;

  Vec3 imgPlaneTopLeft = camera_.pos + forward - (imgPlaneW/2.0)*right + (imgPlaneH/2.0)*up;

  for (int y = 0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {
      Vec3 imgPlanePos = imgPlaneTopLeft + (x+0.5)*(imgPlaneW/width_)*right - (y+0.5)*(imgPlaneH/height_)*up;
      Ray r(camera_.pos, imgPlanePos - camera_.pos);
      r.dir.normalize();

      fb(x, y) = (Color(r.dir.x, r.dir.y, r.dir.z)+1.0) / 2.0;
      // TODO: generate color from ray
    }
  }

  return fb.writeToFile(fileName);
}

};
