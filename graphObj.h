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

public:
	GraphObj(std::string name, type t);
	type getType();
	std::string getName();
	void changeName(std::string newName);
	virtual std::list<point>* getPoints() = 0;
	virtual point getCenter() = 0;
	void setPoints(std::list<point>* newPoints);
};

#endif