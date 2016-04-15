#include "line.h"

void Line::setStart(double x, double y) {
	start.x = x;
	start.y = y;
}

void Line::setEnd(double x, double y) {
	end.x = x;
	end.y = y;
}


point* Line::getStart() {
	return &start;
}

point* Line::getEnd() {
	return &end;
}

point Line::getCenter() {
	point center;
	center.x = (start.x+end.x)/2;
	center.y = (start.y+end.y)/2;
	return center;
}

std::list<point>* Line::getPoints() {
	points->clear();
	points->push_back(this->start);
	points->push_back(this->end);
	return points;
}