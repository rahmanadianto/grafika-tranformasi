#include "parachute.hpp"

parachute::parachute(point center) {
	this->radius = 60;
	this->center = center;

	for (int i=0; i<4; i++) {
		// 4 titik di bagian bawah parasut
		point_parachute[i].set_x(center.get_x()-radius+i*(radius/3)*2);
		point_parachute[i].set_y(center.get_y());
	}
	point_parachute[4].set_x(center.get_x());		// titik temu tali parasut
	point_parachute[4].set_y(center.get_y() + 60);
	point_parachute[5].set_x(center.get_x());		// pusat kepala
	point_parachute[5].set_y(center.get_y() + 40);
	point_parachute[6].set_x(center.get_x() - 10);	// kiri atas badan
	point_parachute[6].set_y(center.get_y() + 45);

	// koordinat untuk polygon badan
	people.add_point(5,7);
	people.add_point(17,7);
	people.add_point(22,12);
	people.add_point(22,15);
	people.add_point(17,10);
	people.add_point(17,40);
	people.add_point(14,40);
	people.add_point(14,30);	
	people.add_point(8,30);	
	people.add_point(8,40);
	people.add_point(5,40);
	people.add_point(5,10);
	people.add_point(0,15);
	people.add_point(0,12);
	people.scale(1);
}

void parachute::set_center(int x, int y) {
	center.set_x(x);
	center.set_y(y);
}

void parachute::draw() {

	// Gambar parasut
	circle c(center, radius);
	c.draw_stroke_semi_circle(point_parachute[0], point_parachute[3], 0xffffffff);
	canvas::get_instance()->draw_pixel(point_parachute[0].get_x(), point_parachute[0].get_y(), 0xffff00);
	canvas::get_instance()->draw_pixel(point_parachute[1].get_x(), point_parachute[1].get_y(), 0xffff00);
	canvas::get_instance()->draw_pixel(point_parachute[2].get_x(), point_parachute[2].get_y(), 0xffff00);
	canvas::get_instance()->draw_pixel(point_parachute[3].get_x(), point_parachute[3].get_y(), 0xffff00);

	for (int i=0; i<3; i++) {
		point p((point_parachute[i].get_x() + point_parachute[i+1].get_x())/2, (point_parachute[i].get_y() + point_parachute[i+1].get_y())/2);
		circle c(p, radius/3);
		c.draw_stroke_semi_circle(point_parachute[i], point_parachute[i+1], 0xffffffff);
	}

	// Gambar kepala
	circle head(point_parachute[5], 10);
	head.draw_stroke(0xffffffff);
	head.draw_fill(0xffffffff);

	// Gambar badan
	people.draw_stroke(point_parachute[6].get_x(), point_parachute[6].get_y());
	people.draw_fill(point_parachute[6].get_x()+6, point_parachute[6].get_y()+20);

	// Gambar tali parasut
	for (int i=0; i<4; i++) {
		line l(point_parachute[i], point_parachute[4]);
		l.draw();
	}

}

void parachute::move(int delta_x, int delta_y) {
	center = center.move(delta_x, delta_y);
	for (int i=0; i<7; i++) {
		point_parachute[i] = point_parachute[i].move(delta_x, delta_y);
	}
}

void parachute::rotate(float angle, int x_origin, int y_origin) {
	for (int i=4; i<7; i++) {
		point_parachute[i] = point_parachute[i].rotate(angle, x_origin, y_origin);
	}
}