#include "propeller.hpp"

propeller::propeller(){
}

void propeller::set_center(point c){

}

void propeller::set_size(int s){

}

void propeller::draw(){

  polygon p1,p2,p3;
  point center(300,300);
  set_center(center);
  set_size(1);
  int coef = 6;
  
  circle c(center,7*coef);

  p1.add_point(0*coef, 22*coef);
  p1.add_point(1*coef, 21*coef);
  p1.add_point(5*coef, 21*coef);
  p1.add_point(6*coef, 22*coef);
  p1.add_point(6*coef, 7*coef);
  p1.add_point(5*coef, 6*coef);
  p1.add_point(5*coef, 2*coef);
  p1.add_point(3*coef, 0*coef);
  p1.add_point(1*coef, 2*coef);
  p1.add_point(1*coef, 6*coef);
  p1.add_point(0*coef, 7*coef);
  p1.add_point(0*coef, 22*coef);

  p1.draw_stroke(282 ,120);

  c.draw_stroke(0x99999999);
}