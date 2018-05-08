#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

using namespace fractalproj;
using namespace std;

int main(){
  
  RGB rgb1(4,5,6);
  RGB rgb2(1,2,3);

  RGB rgb3 = rgb1 - rgb2;

  cout << rgb3.r << ", " << rgb3.g << ", " << rgb3.b << endl;

  FractalCreator fractalCreator(800, 600);

  fractalCreator.addZoom(Zoom(295, 202, 0.1));
  fractalCreator.addZoom(Zoom(312, 304, 0.1));
 
  fractalCreator.run("test.bmp");

  cout << "Finished" << endl;
  return 0;
}
