// FractalCreator.h

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"

using namespace std;

namespace fractalproj {

class FractalCreator {
private:
  int _width;
  int _height;
  int _total{0};
  unique_ptr<int[]> _histogram;
  unique_ptr<int[]> _fractal;
  Bitmap _bitmap;
  ZoomList _zoomList;
private:
  void calculateIterations();
  void calculateTotalIterations();
  void drawFractal();
  void writeBitmap(string name);
public:
  FractalCreator(int width, int height);
  virtual ~FractalCreator();
  void run(string name);
  void addZoom(const Zoom& zoom);

};


} // namespace fractalproj

#endif
