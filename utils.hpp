#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <math.h>

enum class type {
	LINE,
	POLYGON,
	POINT
};

struct point {
	double x;
	double y;	
};

class Utils {
public:
	static double distance(point a, point b) {
		double dist = sqrt( pow((a.x - b.x),2) + pow((a.y - b.y), 2));
		return dist;
	}

	static point translatePoint(point p, double dist) {
		point newPoint;
		newPoint.x = p.x + dist;
		newPoint.y = p.y + dist;
		return newPoint;
	}

	
};

#endif