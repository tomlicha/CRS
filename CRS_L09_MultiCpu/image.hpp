//----------------------------------------------------------------------------

#ifndef IMAGE_HPP
#define IMAGE_HPP 1

#include "crsUtils.hpp"

struct Pixel
{
uint8_t rgb[3];
const uint8_t & r()                  const noexcept { return rgb[0]; }
      uint8_t & r()                        noexcept { return rgb[0]; }
const uint8_t & g()                  const noexcept { return rgb[1]; }
      uint8_t & g()                        noexcept { return rgb[1]; }
const uint8_t & b()                  const noexcept { return rgb[2]; }
      uint8_t & b()                        noexcept { return rgb[2]; }
const uint8_t & operator[](size_t n) const noexcept { return rgb[n]; }
      uint8_t & operator[](size_t n)       noexcept { return rgb[n]; }
};

Pixel *
loadImage(int &out_width,
          int &out_height,
          const std::string &fileName);

void
saveImage(const Pixel *image,
          int width,
          int height,
          const std::string &fileName);

class ImageSequence
{
public:
  explicit ImageSequence(const std::vector<std::string> &cmdLine,
                         int count) noexcept;

  ImageSequence() =delete;
  ImageSequence(const ImageSequence &) =delete;
  ImageSequence & operator=(const ImageSequence &) =delete;
  ImageSequence(ImageSequence &&) =delete;
  ImageSequence & operator=(ImageSequence &&) =delete;

  ~ImageSequence() =default;

  int current() const noexcept { return _current; }

  Pixel * // image data or nullptr
  next(int &out_width,
       int &out_height) noexcept;

private:
  struct _Info { std::unique_ptr<Pixel[]> image; int width; int height; };
  std::vector<_Info> _loaded{};
  int _count{0};
  int _current{-1};
};

#endif // IMAGE_HPP

//----------------------------------------------------------------------------
