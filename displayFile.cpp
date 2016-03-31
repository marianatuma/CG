#include "displayFile.h"

DisplayFile::DisplayFile() {
	this->objectList = new std::list<GraphObj*>();
}

void DisplayFile::add(GraphObj* g) {
	this->objectList->push_front(g);
}

std::list<GraphObj*>* DisplayFile::getObjects() {
	return this->objectList;
}