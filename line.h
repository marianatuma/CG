#ifndef LINE_H
#define LINE_H

#include "graphObj.h"

class Line : public GraphObj {
private:
	point start;
	point end;

public:
	Line(type t, std::string name) : GraphObj(t, name) , start(),end() {};
	void setStart(double x, double y);
	void setEnd(double x, double y);
	point* getStart();
	point* getEnd();
};

#endif