#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <list>
#include <string>
#include "graphObj.h"

class DisplayFile {
private:
	std::list<GraphObj*>* objectList;	
public:
	DisplayFile();
	void add(GraphObj* g);
	void remove(GraphObj *g);
	std::list<GraphObj*>* getObjects();
	GraphObj* getByName(std::string name);
};

#endif