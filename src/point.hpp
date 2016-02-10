#ifndef _POIN_H
#define _POIN_H


class point {
public:
	point(int x, int y);
	int get_x() const;
	int get_y() const;
	static bool cmp_x(const point& p1, const point& p2);
	static bool cmp_y(const point& p1, const point& p2);
	void set_x(int x);
	void set_y(int y);
	point scale(float scale);
	void set_coord(int x, int y);
	point move(int delta_x = 0, int delta_y = 0);
private:
	int x;
	int y;
};

#endif