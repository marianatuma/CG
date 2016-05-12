#ifndef COHENSUTHERLAND_HPP
#define COHENSUTHERLAND_HPP

#include "graphObj.h"
#include "window.h"
#include "polygon.h"
#include "point.h"

class SutherlandHodgeman {
public:
	SutherlandHodgeman (Window* w);
	void clip(GraphObj* g);

private:
	Window *window;
	bool isInside(point a, point b, point c);
	point intersection(point a, point b, point p, point q);
	void clipPoint(GraphObj* g, point w[]);
	void clipPolygon(GraphObj* g, point w[]);
};

#endif