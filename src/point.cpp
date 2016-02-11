#include "point.hpp"
#include <math.h>

point::point() {
	this->x = 0;
	this->y = 0;
}

point::point(int x, int y) {
	this->x = x;
	this->y = y;
}

point::point(const point& p) {
	this->x = p.get_x();
	this->y = p.get_y();
}

int point::get_x() const {
	return this->x;
}

int point::get_y() const {
	return this->y;
}

void point::set_x(int x) {
	this->x = x;
}

void point::set_y(int y) {
	this->y = y;
}
point point::scale(float scale) {
	this->x = floor((this->x - 200) * scale + 200);
	this->y = floor((this->y - 200) * scale + 200);

	return *this;
}

void point::set_coord(int x, int y) {
	this->x = x;
	this->y = y;
}

bool point::cmp_x(const point& p1, const point& p2) {
	return p1.get_x() < p2.get_x();
}

bool point::cmp_y(const point& p1, const point& p2) {
	return p1.get_y() < p2.get_y();
}

point point::move(int delta_x, int delta_y) {
	point p(this->get_x() + delta_x, this->get_y() + delta_y);

	return p;
}
