#include "point.h"

void Point::setPoint(double x, double y) {
	this->p.x = x;
	this->p.y = y;
	points = new std::list<point>();
	this->points->push_back(p);
}

point* Point::getPoint() {
	return &p;
}

point Point::getCenter() {
	return this->p;
}

void Point::setDraw(bool draw) {
	this->draw = draw;
}

bool Point::getDraw() {
	return draw;
}