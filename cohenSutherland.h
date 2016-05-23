#ifndef COHENSUTHERLAND_H
#define COHENSUTHERLAND_H

#include "point.h"
#include "clipping.h"

class CohenSutherland : public Clipping{
protected:
	enum Quadrant {
		INSIDE = 0x0,
		LEFT = 0x1,
		RIGHT = 0x2,
		DOWN = 0x4,
		UP = 0x8,
		UP_LEFT = UP | LEFT,
		UP_RIGHT = UP | RIGHT,
		DOWN_LEFT = DOWN | LEFT,
		DOWN_RIGHT = DOWN | RIGHT
	};

private:
	Quadrant getQuadrant(point p);
	point calculateIntersection(point a, point b, int edge);
	double calculateM(point a, point b);
	point clipSector(point p, double m, CohenSutherland::Quadrant quadrant);
	void clipPolygon(GraphObj* g);
	void clipPoint(GraphObj* g);
	bool needsClipping(std::list<point>* points);

public:
	CohenSutherland(Window* window) : Clipping(window){}
	virtual void clip (GraphObj* g);
};

#endif