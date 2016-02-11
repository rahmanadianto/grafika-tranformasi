#include <iostream>
#include "gl.hpp"
using namespace std;

int main() {

  cout << "Grafika Wow" << endl;
  polygon p;

  p.add_point(0, 0);
  p.add_point(100, 0);
  p.add_point(100, 100);
  p.add_point(0, 100);

  p.draw_stroke(590, 500);

  line l(100, 100, 500, 500);

  l.draw();

  canvas::get_instance()->render();
  return 0;
}
