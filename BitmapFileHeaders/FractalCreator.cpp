// FractalCreator.cpp

#include "FractalCreator.h"

namespace fractalproj {

void FractalCreator::run(string name) {
  addZoom(Zoom(295, _height-202, 0.1));
  addZoom(Zoom(312, _height-304, 0.1));
  calculateIterations();
  calculateTotalIterations();
  drawFractal();
  writeBitmap(name);
}

FractalCreator::FractalCreator(int width, int height): _width(width), _height(height), _histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}), _fractal(new int[_width * _height]{0}), _bitmap(_width, _height), _zoomList(_width, _height) {
  _zoomList.add(Zoom(_width/2, _height/2, 4.0/_width));
}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calculateIterations() {
  for(int y = 0; y < _height; y++)
  {
    for(int x = 0; x < _width; x++)
    {
      pair<double, double> coords = _zoomList.doZoom(x, y);      

      int iterations = Mandelbrot::getIterations(coords.first, coords.second);
    
      _fractal[y*_width + x] = iterations;  
 
      if(iterations != Mandelbrot::MAX_ITERATIONS)
      { 
        _histogram[iterations]++; 
      }
    }
  }


}

void FractalCreator::calculateTotalIterations() {

  for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++)
  {
    _total += _histogram[i];
  }

}

void FractalCreator::drawFractal() {
  
  RGB startColor(0, 0, 0);
  RGB endColor(0, 255, 0);
  RGB colorDiff = endColor - startColor;

  for(int y = 0; y < _height; y++)
  {
    for(int x = 0; x < _width; x++)
    {
      uint8_t red = 0;
      uint8_t green = 0;
      uint8_t blue = 0;

      int iterations = _fractal[y*_width + x];

      if(iterations != Mandelbrot::MAX_ITERATIONS)
      {
        double hue = 0.0;

        for(int i = 0; i <= iterations; i++)
        {
          hue += ((double)_histogram[i])/_total;
        }
        
        red = startColor.r + colorDiff.r*hue;
        green = startColor.g + colorDiff.g*hue;
        blue = startColor.b + colorDiff.b*hue;
      
      }
       
      _bitmap.setPixel(x, y, red, green, blue);
     
    }
  }
} 



void FractalCreator::addZoom(const Zoom& zoom) {
  _zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name) {
  _bitmap.write(name);
}



} // namespace fractalproj
