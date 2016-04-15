#ifndef LINE_H
#define LINE_H

#include "graphObj.h"

class Line : public GraphObj {
private:
	point start;
	point end;

public:
	Line(std::string name, type t = type::LINE) : GraphObj(name, t) , start(),end() {};
	void setStart(double x, double y);
	void setEnd(double x, double y);
	point* getStart();
	point* getEnd();
	virtual point getCenter();
	virtual std::list<point>* getPoints();
};

#endif