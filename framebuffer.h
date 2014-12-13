//! framebuffer.h
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#ifndef DISTANCE_IMAGE_H_
#define DISTANCE_IMAGE_H_

#include <cstdint>
#include <vector>

#include "color.h"

namespace distance {

class FrameBuffer {
 public:
  FrameBuffer(int width, int height);

  Color& operator()(int x, int y);
  const Color& operator()(int x, int y) const;

  bool writeToFile(const char* fileName);

 private:
  int width_;
  int height_;
  std::vector<Color> data_;
};

}

#endif
