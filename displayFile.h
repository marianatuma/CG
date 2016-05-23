#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <list>
#include <string>
#include "graphObj.h"
#include "utils.hpp"

class DisplayFile {
private:
	std::list<GraphObj*>* objectList;	
public:
	DisplayFile();
	void add(GraphObj* g);
	void remove(GraphObj *g);
	std::list<GraphObj*>* getObjects();
	GraphObj* getByName(std::string name);
	void rotateAll(double angle, point center);
};

#endif