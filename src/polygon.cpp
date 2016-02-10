#include "polygon.hpp"
#include "line.hpp"
#include <iostream>

polygon::polygon() {
	this->scale_factor = 0;
}

void polygon::add_point(int x, int y) {
	point p(x, y);
	this->points.push_back(p);
}

void polygon::add_point(point p) {
	point p0(p.get_x(), p.get_y());
	this->points.push_back(p0);
}

void polygon::draw_stroke(int x, int y, uint32_t color) {
	for (int i = 0; i < points.size() - 1; i++) {
		line l(points[i].move(x, y).scale(scale_factor), points[i+1].move(x, y).scale(scale_factor));
		l.draw(color);
	}
	line l(points[points.size() - 1].move(x, y).scale(scale_factor), points[0].move(x, y).scale(scale_factor));
	l.draw(color);
}

std::vector<point> polygon::get_points() {
	return points;
}

void polygon::draw_fill(int x, int y, uint32_t color) {
	if (((x > 0) && (x < 1000)) || ((y > 0) && (y < 700))) {
		if (canvas::get_instance()->get_color(x, y) != color) {
			canvas::get_instance()->draw_pixel(x, y, color);
			draw_fill(x+1, y, color);
			draw_fill(x-1, y, color);
			draw_fill(x, y+1, color);
			draw_fill(x, y-1, color);
		}
	}
}

void polygon::scale(float scale, int x_origin, int y_origin) {
	this->scale_factor = scale;
}
