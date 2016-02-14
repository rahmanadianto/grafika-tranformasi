#include "propeller.hpp"

propeller::propeller(){
}

void propeller::draw(point n_center, float n_size, float n_rotation){

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

  p1.rotate(n_rotation+0);
  p1.draw_stroke(n_center.get_x() ,n_center.get_y());

  p2 = p1;
  p2.rotate(n_rotation+90);
  p2.draw_stroke(n_center.get_x() ,n_center.get_y());

  p3 = p1;
  p3.rotate(n_rotation-90);
  p3.draw_stroke(n_center.get_x() ,n_center.get_y());




}