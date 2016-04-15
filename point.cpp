#include "point.h"

void Point::setPoint(double x, double y) {
	this->p.x = x;
	this->p.y = y;
}

point* Point::getPoint() {
	return &p;
}

std::list<point>* Point::getPoints() {
	std::list<point>* points = new std::list<point>();
	points->push_back(this->p);
	return points;
}

point Point::getCenter() {
	return this->p;
}