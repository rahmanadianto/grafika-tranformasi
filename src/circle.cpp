#include "circle.hpp"

circle::circle() {
  this->center = point(100, 100);
  this->radius = 100;
}

circle::circle(point center, int radius) {
  this->center = center;
  this->radius = radius;
}

point circle::get_center() {
  return center;
}

void circle::set_center(point new_center) {
  this->center = new_center;
}

void circle::set_radius(int new_radius) {
  this->radius = new_radius;
}

void circle::draw_stroke(uint32_t color) {
  int P;
  int x, y;
  P = 1 - radius;
  x = 0;
  y = radius;

  draw(x, y, center.get_x(), center.get_y(), color);
  while (x <= y) {
    x++;
    if (P<0) {
      P += 2 * x + 1;
    }
    else {
      P += 2 * (x - y) + 1;
      y--;
    }
    draw(x, y, center.get_x(), center.get_y(), color);
  }
}

void circle::draw_fill(uint32_t color) {
  draw_fill_rec(center.get_x(), center.get_y(), color);
}

void circle::draw_stroke_semi_circle(point start, point end, uint32_t color) {
  int P;
  int x, y;
  P = 1 - radius;
  x = 0;
  y = radius;

  if (start.get_y()>end.get_y()) {
    // Kasus 1
    draw_arc1(start, end, x, y, center.get_x(), center.get_y(), color);
  }
  else {
    // Kasus 2
    draw_arc2(start, end, x, y, center.get_x(), center.get_y(), color);
  }
  while (x <= y) {
    x++;
    if (P<0) {
      P += 2 * x + 1;
    }
    else {
      P += 2 * (x - y) + 1;
      y--;
    }
    if (start.get_y()>end.get_y()) {
      // Kasus 1
      draw_arc1(start, end, x, y, center.get_x(), center.get_y(), color);
    }
    else {
      // Kasus 2
      draw_arc2(start, end, x, y, center.get_x(), center.get_y(), color);
    }
  }
}

void circle::draw_fill_rec(int x, int y, uint32_t color) {
  if (((x > 0) && (x < 1000)) || ((y > 0) && (y < 700))) {
		if (canvas::get_instance()->get_color(x, y) != color) {
			canvas::get_instance()->draw_pixel(x, y, color);
			draw_fill_rec(x+1, y, color);
			draw_fill_rec(x-1, y, color);
			draw_fill_rec(x, y+1, color);
			draw_fill_rec(x, y-1, color);
		}
	}
}

void circle::draw(int x, int y, int xC, int yC, uint32_t color) {
  canvas::get_instance()->draw_pixel(xC + x, yC + y, color);
  canvas::get_instance()->draw_pixel(xC + x, yC - y, color);
  canvas::get_instance()->draw_pixel(xC - x, yC + y, color);
  canvas::get_instance()->draw_pixel(xC - x, yC - y, color);
  canvas::get_instance()->draw_pixel(xC + y, yC + x, color);
  canvas::get_instance()->draw_pixel(xC - y, yC + x, color);
  canvas::get_instance()->draw_pixel(xC + y, yC - x, color);
  canvas::get_instance()->draw_pixel(xC - y, yC - x, color);
}

void circle::draw_arc1(point start, point end, int x, int y, int xC, int yC, uint32_t color) {
  if ((xC+x)<end.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + x, yC + y, color);
  if ((xC+x)<end.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + x, yC - y, color);
  if ((xC-x)<end.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - x, yC + y, color);
  if ((xC-x)<end.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - x, yC - y, color);
  if ((xC+x)<end.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + y, yC + x, color);
  if ((xC-x)<end.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - y, yC + x, color);
  if ((xC+x)<end.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + y, yC - x, color);
  if ((xC-x)<end.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - y, yC - x, color);
}

void circle::draw_arc2(point start, point end, int x, int y, int xC, int yC, uint32_t color) {
  if ((xC+x)>start.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + x, yC + y, color);
  if ((xC+x)>start.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + x, yC - y, color);
  if ((xC-x)>start.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - x, yC + y, color);
  if ((xC-x)>start.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - x, yC - y, color);
  if ((xC+x)>start.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + y, yC + x, color);
  if ((xC-x)>start.get_x() && (yC+y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - y, yC + x, color);
  if ((xC+x)>start.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC + y, yC - x, color);
  if ((xC-x)>start.get_x() && (yC-y)<end.get_y()) canvas::get_instance()->draw_pixel(xC - y, yC - x, color);
}
