#ifndef COHENSUTHERLAND_HPP
#define COHENSUTHERLAND_HPP

#include "polygon.h"
#include "point.h"
#include "clipping.h"

class SutherlandHodgeman : public Clipping{
public:
	SutherlandHodgeman (Window* w) : Clipping(w){}
	virtual void clip(GraphObj* g);

private:
	bool isInside(point a, point b, point c);
	point intersection(point a, point b, point p, point q);
	void clipPoint(GraphObj* g, point w[]);
	void clipPolygon(GraphObj* g, point w[]);
};

#endif