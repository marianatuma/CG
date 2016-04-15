#ifndef POLYGON_H
#define POLYGON_H

#include "graphObj.h"
#include <list>

class Polygon : public GraphObj {
private:
	std::list<point>* points;

public:
	Polygon(std::string name, type t = type::POLYGON) : GraphObj(name, t) {
		points = new std::list<point>();
	};
	void addPoint(double x, double y);
	virtual std::list<point>* getPoints();
	virtual point getCenter();
};

#endif