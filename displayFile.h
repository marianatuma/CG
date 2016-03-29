#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <list>
#include "graphObj.h"

class DisplayFile {
private:
	std::list<GraphObj*>* objectList;	
	std::list<GraphObj*>::iterator it;
	int size;
public:
	DisplayFile();
	void add(GraphObj* g);
	GraphObj* getNextObject();
	void resetIterator();
	int getSize();
};

#endif