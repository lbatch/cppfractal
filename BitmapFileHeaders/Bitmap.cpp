// Bitmap.cpp

#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace fractalproj;
using namespace std;

namespace fractalproj {


Bitmap::Bitmap(int width, int height): _width(width), _height(height), _pPixels(new uint8_t[width*height*3]{}) {
  // Code here
}

bool Bitmap::write(string filename){
  BitmapFileHeader bfh;
  BitmapInfoHeader bih;

  bfh.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + _width*_height*3; // file header + info header + number of pixels (width x height x 3 colors info per pixel)
  bfh.dataOffset  = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

  bih.width = _width;
  bih.height = _height;

  ofstream file;
  file.open(filename, ios::out | ios::binary);

  if(!file) {
    return false;
  }

  file.write((char *)&bfh, sizeof(bfh));
  file.write((char *)&bih, sizeof(bih));
  file.write((char *)_pPixels.get(), _width*_height*3);

  file.close();
  
  if(!file) {
    return false;
  }
 
  return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
  uint8_t *pPixel = _pPixels.get();
  
  pPixel += 3*(y*_width + x);
  pPixel[0] = blue;
  pPixel[1] = green;
  pPixel[2] = red; 

}

Bitmap::~Bitmap() {


} // namespace fractalproj


}
