#ifndef _CANVAS_H
#define _CANVAS_H

#include "include.hpp"

class canvas {
public:
	static canvas* get_instance();
	void draw_pixel(int x, int y, uint32_t color = 0xffffffff);
	uint32_t get_color(int x, int y);
	void render();
	void clear();
	fb_var_screeninfo get_var_info();

private:
	canvas();
	uint8_t* fb_ptr;
	uint8_t* canvas_ptr;
	static canvas* instance;
	struct fb_fix_screeninfo finfo;
	struct fb_var_screeninfo vinfo;
};
#endif
