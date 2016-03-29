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