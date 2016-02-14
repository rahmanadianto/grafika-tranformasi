#include <iostream>
#include "gl.hpp"

using namespace std;

int main() {

  polygon p;
  p.scale(4);
  p.add_point(0, 0);
  p.add_point(100, 0);
  p.add_point(100, 100);
  p.add_point(0, 100);
  p.draw_stroke(500, 500);

  for (int i = 0; i < 1000; i++) {
    p.rotate(i*0.05);
    p.scale(i*0.05);
    p.draw_stroke(500, 500);
    canvas::get_instance()->render();
    canvas::get_instance()->clear();  
    usleep(100000);
  }

  return 0;
}
