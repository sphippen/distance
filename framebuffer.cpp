//! framebuffer.cpp
//! Author: Spencer Phippen
//! zlib/libpng licensed (see LICENSE)

#include "framebuffer.h"

#include <cstdio>
#include <cmath>
#include <png.h>

#include "numeric.h"

namespace distance {

FrameBuffer::FrameBuffer(int width, int height) : width_(width), height_(height), data_(width*height) {}

Color& FrameBuffer::operator()(int x, int y) {
  return data_[x*width_ + y];
}

const Color& FrameBuffer::operator()(int x, int y) const {
  return data_[x*width_ + y];
}

bool FrameBuffer::writeToFile(const char* fileName) {
  FILE* outpng = fopen(fileName, "wb");
  if (!outpng)
    return false;

  png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
  if (!png_ptr)
    return false;

  png_infop info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) {
    png_destroy_write_struct(&png_ptr, nullptr);
    fclose(outpng);
    return false;
  }

  if (setjmp(png_jmpbuf(png_ptr))) {
    png_destroy_write_struct(&png_ptr, &info_ptr);
    fclose(outpng);
    return false;
  }

  png_init_io(png_ptr, outpng);

  png_set_IHDR(png_ptr, info_ptr, width_, height_, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
  png_write_info(png_ptr, info_ptr);

  int bytesPerRow = width_ * 3;
  std::vector<uint8_t> rowData(bytesPerRow);
  for (int y = 0; y < height_; ++y) {
    for (int x = 0; x < width_; ++x) {
      Color c = (*this)(x, y);
      c.r = std::pow(c.r, 1/2.2);
      c.g = std::pow(c.g, 1/2.2);
      c.b = std::pow(c.b, 1/2.2);

      uint8_t r = static_cast<uint8_t>(clamp(c.r, 0.0, 1.0) * 255);
      uint8_t g = static_cast<uint8_t>(clamp(c.g, 0.0, 1.0) * 255);
      uint8_t b = static_cast<uint8_t>(clamp(c.b, 0.0, 1.0) * 255);
      rowData[x*3 + 0] = r;
      rowData[x*3 + 1] = g;
      rowData[x*3 + 2] = b;
    }
    png_write_row(png_ptr, rowData.data());
  }
  png_write_end(png_ptr, info_ptr);
  png_destroy_write_struct(&png_ptr, &info_ptr);
  fclose(outpng);
  return true;
}

}
