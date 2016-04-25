#include "graphObj.h"

GraphObj::GraphObj(std::string name, type t) {
	this->t = t;
	this->name = name;
}

type GraphObj::getType() {
	return this->t;
}

std::string GraphObj::getName() {
	return this->name;
}

void GraphObj::changeName(std::string newName) {
	this->name = newName;
}

void GraphObj::setPoints(std::list<point>* newPoints){
	this->points = newPoints;
}

void GraphObj::setClippedPoints(std::list<point>* clipped) {
	clippedPoints = clipped;
}