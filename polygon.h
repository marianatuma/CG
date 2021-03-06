#ifndef POLYGON_H
#define POLYGON_H

#include "graphObj.h"
#include <list>

class Polygon : public GraphObj {
public:
	Polygon(std::string name, type t = type::POLYGON) : GraphObj(name, t) {};
	void addPoint(double x, double y);
	void setClippedPoints(std::list<point>* clipped);
	virtual point getCenter();
};

#endif