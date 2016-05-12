#ifndef OBJECT_H
#define OBJECT_H

#include <list>
#include <string>
#include "utils.hpp"

class GraphObj {
private:
	type t;
	std::string name;

protected:
	std::list<point>* points;
	std::list<point>* clippedPoints;

public:
	GraphObj(std::string name, type t);
	type getType();
	std::string getName();
	void changeName(std::string newName);
	std::list<point>* getPoints();
	std::list<point>* getClippedPoints();
	virtual point getCenter() = 0;
	void setPoints(std::list<point>* newPoints);
	void setClippedPoints(std::list<point>* clipped);
	void transform(double matrix[4][4]);
};

#endif