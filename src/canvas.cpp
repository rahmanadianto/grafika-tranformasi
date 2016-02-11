#include "canvas.hpp"

canvas* canvas::instance;

canvas::canvas() {
	int fbfd = open("/dev/fb0", O_RDWR);

	ioctl(fbfd, FBIOGET_FSCREENINFO, &(this->finfo));
	ioctl(fbfd, FBIOGET_VSCREENINFO, &(this->vinfo));

	long int screensize = this->vinfo.xres * this->vinfo.yres * this->vinfo.bits_per_pixel / 8;

	this->fb_ptr = (uint8_t*)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
	this->canvas_ptr = (uint8_t*)malloc(screensize);
	memset(canvas_ptr, 0, screensize);
}

void canvas::draw_pixel(int x, int y, uint32_t color) {
	if (x < this->vinfo.xres && y < this->vinfo.yres) {
		long int location = (x + this->vinfo.xoffset) * (this->vinfo.bits_per_pixel/8) +
               				(y + this->vinfo.yoffset) * (this->finfo.line_length);
        *((uint32_t*)(this->canvas_ptr + location)) = color;
	}
}

uint32_t canvas::get_color(int x, int y) {
	if (x < this->vinfo.xres && y < this->vinfo.yres) {
		long int location = (x + this->vinfo.xoffset) * (this->vinfo.bits_per_pixel/8) +
               				(y + this->vinfo.yoffset) * (this->finfo.line_length);
        return *((uint32_t*)(this->canvas_ptr + location));
	}
	return 0x00000000;
}

fb_var_screeninfo canvas::get_var_info() {
	return vinfo;
}

void canvas::render() {
	long int screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	memcpy(this->fb_ptr, this->canvas_ptr, screensize);
	usleep(10000);
}

void canvas::clear() {
	long int screensize = this->vinfo.xres * this->vinfo.yres * this->vinfo.bits_per_pixel / 8;
	memset(canvas_ptr, 0, screensize);
}

canvas* canvas::get_instance() {
	if (canvas::instance) {
		return canvas::instance;
	}

	return canvas::instance = new canvas();
}
