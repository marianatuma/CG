#include "polygon.h"

void Polygon::addPoint(double x, double y){
	point newPoint;
	newPoint.x = x;
	newPoint.y = y;
	points->push_back(newPoint);
}

std::list<point>* Polygon::getPoints() {
	return points;
}

std::list<point>* Polygon::getClippedPoints() {
	return clippedPoints;
}

point Polygon::getCenter() {
	double sumX, sumY = 0;
	point center;

	for (std::list<point>::const_iterator it = points->begin();
	  it != points->end();
	  ++it) {
	    point p = *it;
	    sumX += p.x;
	    sumY += p.y;
	}

	center.x = sumX/points->size();
	center.y = sumY/points->size();

	return center;
}