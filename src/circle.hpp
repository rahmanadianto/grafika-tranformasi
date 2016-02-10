#ifndef CIRCLE_H
#define CIRCLE_H

#include "canvas.hpp"
#include "point.hpp"
#include "color.hpp"

class circle {

public:
  circle(point center, int radius);
  void set_center(point new_center);
  void set_radius(int new_radius);
  void draw_stroke(uint32_t color);
	void draw_fill(uint32_t color);

private:
  void draw_fill_rec(int x, int y, uint32_t color);
  void draw(int x, int y, int xC, int yC, uint32_t color);
  point center;
  int radius;
};

#endif
