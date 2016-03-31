#ifndef OBJECT_H
#define OBJECT_H

#include <list>
#include <string>

enum class type {
	LINE
};

struct point {
	double x;
	double y;	
};

class GraphObj {
private:
	type t;
	std::string name;

public:
	GraphObj(type t, std::string name);
	type getType();
	std::string getName();
};

#endif