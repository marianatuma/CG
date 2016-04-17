#include "displayFile.h"
#include <iostream>

DisplayFile::DisplayFile() {
	this->objectList = new std::list<GraphObj*>();
}

void DisplayFile::add(GraphObj* g) {
	this->objectList->push_front(g);
}

std::list<GraphObj*>* DisplayFile::getObjects() {
	return this->objectList;
}

GraphObj* DisplayFile::getByName(std::string name) {
	GraphObj* g;
	for (std::list<GraphObj*>::const_iterator it = objectList->begin();
    it != objectList->end();
    ++it) {
		g = *it;
		if(g->getName().compare(name) == 0) {
			return g;
		}
	}
	std::cout << "NULL" << "\n";
	return NULL;
}

void DisplayFile::remove(GraphObj *g) {
	objectList->remove(g);
}