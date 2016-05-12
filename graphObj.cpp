#include "graphObj.h"
#include <iostream>

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

	for (std::list<point>::const_iterator it = clipped->begin();
    	it != clipped->end();
    	++it) {
			point p = *it;
			std::cout << p.x << "," << p.y << "\n";
	}
}

std::list<point>* GraphObj::getPoints() {
	return points;
}

std::list<point>* GraphObj::getClippedPoints() {
	return clippedPoints;
}

void GraphObj::transform(double matrix[4][4]){
	std::list<point>* translated = new std::list<point>();
	for (std::list<point>::const_iterator it = points->begin();
    it != points->end();
    ++it) {
		translated->push_back(Utils::transform(*it, matrix));
	}
	this->points->clear();
	this->points = translated;
}