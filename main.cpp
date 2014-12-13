//! main.cpp
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#include <cstdio>

#include "scene.h"

namespace distance {

int main(int argc, char* argv[]) {
  const char* filename = "out.png";
  if (argc == 2)
    filename = argv[1];

  Scene s;
  if (s.renderScene(filename))
    std::printf("File written to \"%s\"\n", filename);
  else
    std::printf("File \"%s\" couldn't be written...\n", filename);

  return 0;
}

}

int main(int argc, char* argv[]) {
  return distance::main(argc, argv);
}
