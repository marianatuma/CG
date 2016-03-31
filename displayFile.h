#ifndef DISPLAYFILE_H
#define DISPLAYFILE_H

#include <list>
#include "graphObj.h"

class DisplayFile {
private:
	std::list<GraphObj*>* objectList;	
public:
	DisplayFile();
	void add(GraphObj* g);
	std::list<GraphObj*>* getObjects();
};

#endif