#include "point.hpp"
#include <math.h>

/*
 * 
 * Constructor
 *
 */
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

/*
 * 
 * Setter and Getter
 *
 */

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

void point::set_coord(int x, int y) {
	this->x = x;
	this->y = y;
}

/*
 * 
 * Transformation
 *
 */

point point::scale(float scale, int x_origin, int y_origin) {
	this->x = floor((this->x - x_origin) * scale + x_origin);
	this->y = floor((this->y - y_origin) * scale + y_origin);

	return *this;
}

point point::rotate(float angle, int x_origin, int y_origin) {
	float s = sin(angle);
	float c = cos(angle);

	int x = this->x;
	int y = this->y;

	this->x = floor( c * (x - x_origin) + s * (y - y_origin)) + x_origin;
	this->y = floor( c * (y - y_origin) - s * (x - x_origin)) + y_origin;

	return *this;
}

point point::move(int delta_x, int delta_y) {
	point p(this->get_x() + delta_x, this->get_y() + delta_y);

	return p;
}

/*
 * 
 * Comparator function
 *
 */

bool point::cmp_x(const point& p1, const point& p2) {
	return p1.get_x() < p2.get_x();
}

bool point::cmp_y(const point& p1, const point& p2) {
	return p1.get_y() < p2.get_y();
}
