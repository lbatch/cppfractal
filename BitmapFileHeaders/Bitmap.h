// Bitmap.h

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
using namespace std;

namespace fractalproj {

class Bitmap {
private:
  int m_width{0};
  int m_height{0};

public:
  Bitmap(int width, int height);
  bool write(string filename);
  void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
  virtual ~Bitmap();



};

} // namespace

#endif