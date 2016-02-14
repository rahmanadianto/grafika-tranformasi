#include "polygon.hpp"
#include "line.hpp"
#include <iostream>

polygon::polygon() {
	this->scale_factor = 1;
	this->rotate_factor = 0;
}

void polygon::add_point(int x, int y) {
	point p(x, y);
	this->points.push_back(p);
}

void polygon::add_point(point p) {
	point p0(p.get_x(), p.get_y());
	this->points.push_back(p0);
}

void polygon::set_point(int index, point new_value) {
	points[index] = new_value;
}

void polygon::draw_stroke(int x, int y, uint32_t color) {
	int x_origin = points[0].get_x() + x;
	int y_origin = points[0].get_y() + y;

	for (int i = 0; i < points.size() -1; i++) {
		point p1 = points[i].move(x, y).scale(scale_factor, x_origin, y_origin).rotate(rotate_factor, x_origin, y_origin);
		point p2 = points[i+1].move(x, y).scale(scale_factor, x_origin, y_origin).rotate(rotate_factor, x_origin, y_origin);

		line l(p1, p2);
		l.draw(color);
	}

	point p1 = points[points.size() - 1].move(x, y).scale(scale_factor, x_origin, y_origin).rotate(rotate_factor, x_origin, y_origin);
	point p2 = points[0].move(x, y).scale(scale_factor, x_origin, y_origin).rotate(rotate_factor, x_origin, y_origin);

	line l(p1, p2);
	l.draw(color);
}

std::vector<point> polygon::get_points() {
	return points;
}

void polygon::reset() {
	points.clear();
}

void polygon::resize(int n_points) {
	points.resize(n_points);
}

void polygon::draw_fill(int x, int y, uint32_t color) {
	if (((x > 0) && (x < (int) canvas::get_instance()->get_var_info().xres)) ||
      ((y > 0) && (y < (int) canvas::get_instance()->get_var_info().yres))) {
		if (canvas::get_instance()->get_color(x, y) != color) {
			canvas::get_instance()->draw_pixel(x, y, color);
			draw_fill(x+1, y, color);
			draw_fill(x-1, y, color);
			draw_fill(x, y+1, color);
			draw_fill(x, y-1, color);
		}
	}
}

void polygon::scale(float scale) {
	this->scale_factor = scale;
}

void polygon::rotate(float rotate) {
	this->rotate_factor = rotate;
}
