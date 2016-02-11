#include "propeller.hpp"

propeller::propeller(){
}

void propeller::set_center(point c){

}

void propeller::set_size(int s){

}

void propeller::draw(point n_center, float n_size){

  set_center(n_center);
  set_size(n_size);

  polygon p1,p2,p3;
  float coef = n_size;
  
  circle c(n_center,7*coef);
  c.draw_stroke(0xffffffff);

  p1.add_point(0*coef, 0*coef);
  p1.add_point(0*coef, -9*coef);
  p1.add_point(2*coef, -9*coef);
  p1.add_point(3*coef, -8*coef);
  p1.add_point(3*coef, -23*coef);
  p1.add_point(2*coef, -24*coef);
  p1.add_point(2*coef, -28*coef);
  p1.add_point(0*coef, -30*coef);
  p1.add_point(-2*coef, -28*coef);
  p1.add_point(-2*coef, -24*coef);
  p1.add_point(-3*coef, -23*coef);
  p1.add_point(-3*coef, -8*coef);
  p1.add_point(-2*coef, -9*coef);
  p1.add_point(0*coef, -9*coef);
  p1.add_point(0*coef, 0*coef);

  p1.draw_stroke(n_center.get_x() ,n_center.get_y());

  p2 = p1;
  p2.rotate(90);
  p2.draw_stroke(n_center.get_x() ,n_center.get_y());

  p3 = p1;
  p3.rotate(-90);
  p3.draw_stroke(n_center.get_x() ,n_center.get_y());

}

void propeller::rotate(float rotate){

}