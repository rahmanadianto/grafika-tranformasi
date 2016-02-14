#include "line.hpp"

line::line(int x1, int y1, int x2, int y2) : p1(x1, y1), p2(x2, y2) {}

line::line(point _p1, point _p2) : p1(_p1.get_x(), _p1.get_y()), p2(_p2.get_x(), _p2.get_y()) {}

void line::set_point(int x1, int y1, int x2, int y2) {
	p1.set_coord(x1, y1);
	p2.set_coord(x2, y2);	
}

void line::set_point(point p1, point p2) {
	this->p1.set_x(p1.get_x());
	this->p1.set_y(p1.get_y());
	
	this->p2.set_x(p2.get_x());
	this->p2.set_y(p2.get_y());
}

void line::draw(uint32_t color) {
	int x1 = this->p1.get_x();
	int y1 = this->p1.get_y();

	int x2 = this->p2.get_x();
	int y2 = this->p2.get_y();

	const bool steep = fabs(y2 - y1) > fabs(x2 - x1); // octants 1,2,5,6
	
	if (steep) {
		std::swap(x1, y1);
		std::swap(x2, y2);
	}
	if (x1 > x2) {
		std::swap(x1, x2);
		std::swap(y1, y2);
	}

	const float dx = x2 - x1;
	const float dy = fabs(y2 - y1);
	float err = dx / 2.0f;
	const int yinc = (y2 > y1) ? 1 : -1;
	int y = y1;
	
	for (int x = x1; x < x2; x++) {
		if (steep) {
			canvas::get_instance()->draw_pixel(y, x, color);
		} else {
			canvas::get_instance()->draw_pixel(x, y, color);
		}
		err -= dy;
		if (err < 0) {
			y += yinc;
			err += dx;
		}
	}
}

void line::move(int x, int y) {
	this->p1 = this->p1.move(x,y);
	this->p2 = this->p2.move(x,y);
}

void line::scale(int scale) {
	int dx, dy;
	
	dx = abs(this->p1.get_x() - this->p2.get_x());
	dy = abs(this->p1.get_y() - this->p2.get_y());

	if (p1.get_x() > p2.get_x()) {
		this->p1 = this->p1.move(dx, 0);
		this->p2 = this->p2.move(-dx, 0);
	} else {
		this->p1 = this->p1.move(-dx, 0);
		this->p2 = this->p2.move(dx, 0);
	}

	if (p1.get_y() > p2.get_y()) {
		this->p1 = this->p1.move(0, dy);
		this->p2 = this->p2.move(0, -dy);
	} else {
		this->p1 = this->p1.move(0, -dy);
		this->p2 = this->p2.move(0, dy);
	}
}