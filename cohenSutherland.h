#ifndef COHENSUTHERLAND_HPP
#define COHENSUTHERLAND_HPP

#include "graphObj.h"
#include "window.h"
#include "polygon.h"
#include "point.h"

class CohenSutherland {
public:
	CohenSutherland (Window* w);
	void clip(GraphObj* g);

private:
	Window *window;
	void clipPolygon(GraphObj*);
	Point* clipPoint(GraphObj*);
	bool isInside(point a, point b, point c);
	point intersection(point a, point b, point p, point q);
};

#endif