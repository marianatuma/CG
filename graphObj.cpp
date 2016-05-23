#include "graphObj.h"
#include <iostream>

GraphObj::GraphObj(std::string name, type t) {
	this->t = t;
	this->name = name;
	points = new std::list<point>();
	normalizedPoints = new std::list<point>();
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

	//std::cout << clippedPoints->size() << "/" << points->size() << "/" << name <<"\n";
}

std::list<point>* GraphObj::getPoints() {
	return points;
}

std::list<point>* GraphObj::getClippedPoints() {
	return clippedPoints;
}

std::list<point>* GraphObj::getNormalizedPoints() {
	return normalizedPoints;
}

void GraphObj::transform(double matrix[4][4]){
	std::list<point>* transformed = new std::list<point>();
	// TODO genericTransform
	for (std::list<point>::const_iterator it = points->begin();
    it != points->end();
    ++it) {
		transformed->push_back(Utils::transform(*it, matrix));
	}
	this->points->clear();
	this->points = transformed;
}

void GraphObj::transformOnWindowRotation(double matrix[4][4]){
	normalizedPoints = genericTransform(matrix);
}

std::list<point>* GraphObj::genericTransform(double matrix[4][4]){
	point a;
	

	std::list<point>* transformed = new std::list<point>();
	for (std::list<point>::const_iterator it = points->begin();
    it != points->end();
    ++it) {
		a = *it;
		std::cout << "antes:" << a.x << "," << a.y <<"\n";
		a = Utils::transform(a, matrix);
		std::cout << "depois:" << a.x << "," << a.y <<"\n";
		transformed->push_back(a);
	}
	return transformed;
}