// FractalCreator.h

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H

#include <string>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
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
  
  vector<int> _ranges;
  vector<RGB> _colors;
  vector<int> _rangeTotals;
  bool _bGotFirstRange{false};
private:
  void calculateIterations();
  void calculateTotalIterations();
  void drawFractal();
  void writeBitmap(string name);
  void calculateRangeTotals();
  int getRange(int iterations) const;
public:
  FractalCreator(int width, int height);
  virtual ~FractalCreator();
  void run(string name);
  void addZoom(const Zoom& zoom);
  void addRange(double rangeEnd, const RGB& rgb);
};


} // namespace fractalproj

#endif
