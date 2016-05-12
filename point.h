#ifndef POINT_H
#define POINT_H

#include "graphObj.h"

class Point : public GraphObj {
private:
	point p;
	bool draw;

public:
	Point(std::string name, type t = type::POINT) : GraphObj(name, t), p() {};
	void setPoint(double x, double y);
	point* getPoint();
	virtual point getCenter();
	void setDraw(bool draw);
	bool getDraw();
};

#endif