#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <math.h>
#define PI 3.14159265

enum class type {
	LINE,
	POLYGON,
	POINT
};

struct point {
	double x;
	double y;
	point(){}
	point(double x1, double y1) {
		x = x1;
		y = y1;
	}	
};

class Utils {
public:
	static point translationVector(point a, point b) {
		point vector;
		vector.x = b.x - a.x;
		vector.y = b.y - a.y;
		return vector;
	}

	static point translatePoint(point p, point vector) {
		point newPoint;
		newPoint.x = p.x + vector.x;
		newPoint.y = p.y + vector.y;
		return newPoint;
	}

	static point scalePoint(point p, double factor, point vectorToOrigin, point vectorToCenter){
		point translated = translatePoint(p, vectorToOrigin);
		translated.x = translated.x * factor;
		translated.y = translated.y * factor;
		translated = translatePoint(translated, vectorToCenter);
		return translated;
	}

	static point rotatePoint(point p, double angle, point vectorToOrigin, point vectorToCenter){
		point translated = translatePoint(p, vectorToOrigin);
		double sine = sin(angle*PI/180);
		double cosine = cos(angle*PI/180);
		translated.x = translated.x * cosine - translated.y * sine;
		translated.y = translated.x * sine + translated.y * cosine;
		translated = translatePoint(translated, vectorToCenter);
		return translated;
	}
	
};

#endif