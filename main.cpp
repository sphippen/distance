//! main.cpp
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#include <cstdio>

#include "framebuffer.h"

namespace distance {

int main(int argc, char* argv[]) {
  FrameBuffer b(512, 512);
  for (int i = 0; i < 512; ++i) {
    for (int j = 0; j < 512; ++j) {
      b(i, j) = Color(i / 512.0, j / 512.0, 0.0);
    }
  }
  b.writeToFile("test.png");
  return 0;
}

}

int main(int argc, char* argv[]) {
  return distance::main(argc, argv);
}
