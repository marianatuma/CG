#include "displayFile.h"

DisplayFile::DisplayFile() {
	this->objectList = new std::list<GraphObj*>();
	this->it = objectList->begin();
	this->size = 0;
}

void DisplayFile::add(GraphObj* g) {
	std::list<GraphObj*>::iterator tempIt;
	tempIt = objectList->begin();
	this->objectList->insert(tempIt, g);
	this->size++;
}

GraphObj* DisplayFile::getNextObject() {
	return *++it;
}

void DisplayFile::resetIterator() {
	it = objectList->begin();
}

int DisplayFile::getSize() {
	return size;
}