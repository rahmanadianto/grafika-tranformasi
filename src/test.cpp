#include <iostream>
#include "gl.hpp"
using namespace std;

int main() {

  cout << "Grafika Wow" << endl;
  propeller p;

  point center(800,500);
  float size = 2;
  float rotation = 0;

  p.draw(center,size,rotation);

  canvas::get_instance() ->render();
  canvas::get_instance()->clear();  

  point n_center(800,500);
  float n_size = size;
  float n_rotation = rotation;  

  for (int i = 0; i < 100; i++) {

    n_center.set_x(center.get_x()-i);
    n_center.set_y(center.get_y()-i);
    n_size = 2+(i*0.05);
    n_rotation = 0+(i);

    p.draw(n_center,n_size,n_rotation);
    canvas::get_instance()->render();
    canvas::get_instance()->clear();  
    usleep(100000);
  }

  return 0;
}
