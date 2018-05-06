// Mandelbrot.h

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fractalproj {

class Mandelbrot {
public:
  static const int MAX_ITERATIONS = 1000;
  Mandelbrot();
  virtual ~Mandelbrot();

  static int getIterations(double x, double y);
};

} // namespace fractalproj

#endif // Mandelbrot.h
