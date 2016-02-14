#include "gl.hpp"
#include "plane.hpp"

int main() {
	plane p(point(1000,600), 10);
	parachute pr(point(600, 500));
	int i = 0;
	while(i < 140) {
		int delta_x = -i * 0.06;;
		int delta_y = -i * 0.04;
		p.rotate_propeller(i*0.05);
		p.set_size(10 + i * 0.3);
		p.move(delta_x, delta_y);
		if (i > 100) {
			p.crash();
			pr.move(-2, 4);
			pr.draw();
		}
		p.draw(0xffffffff);
		canvas::get_instance()->render();
		canvas::get_instance()->clear();
		usleep(10000);	
		i++;
	}
	
	return 0;
}