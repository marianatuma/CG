#include "graphObj.h"

GraphObj::GraphObj(type t, std::string name) {
	this->t = t;
	this->name = name;	
}

type GraphObj::getType() {
	return this->t;
}

std::string GraphObj::getName() {
	return this->name;
}