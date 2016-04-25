#ifndef POLYGON_H
#define POLYGON_H

#include "graphObj.h"
#include <list>

class Polygon : public GraphObj {
public:
	Polygon(std::string name, type t = type::POLYGON) : GraphObj(name, t) {
		points = new std::list<point>();
	};
	void addPoint(double x, double y);
	virtual std::list<point>* getPoints();
	std::list<point>* getClippedPoints();
	void setClippedPoints(std::list<point>* clipped);
	virtual point getCenter();
};

#endif