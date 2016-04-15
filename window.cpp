#include "window.h"

Window::Window(double xMax, double yMax, double xMin, double yMin) {
	this->xMax = xMax;
	this->yMax = yMax;
	this->xMin = xMin;
	this->yMin = yMin;
}

double Window::getXMin() {
	return this->xMin;
}

double Window::getYMin() {
	return this->yMin;
}

double Window::getXMax() {
	return this->xMax;
}

double Window::getYMax() {
	return this->yMax;
}

void Window::moveX(double delta) {
	this->xMin += delta;
	this->xMax += delta;
}

void Window::moveY(double delta) {
	this->yMin += delta;
	this->yMax += delta;
}

void Window::zoomIn(double delta) {
	this->yMin = this->yMin/delta;
	this->yMax = this->yMax/delta;
	this->xMin = this->xMin/delta;
	this->xMax = this->xMax/delta;	
}


void Window::zoomOut(double delta) {
	this->yMin = this->yMin*delta;
	this->yMax = this->yMax*delta;
	this->xMin = this->xMin*delta;
	this->xMax = this->xMax*delta;
}