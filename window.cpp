#include "window.h"

Window::Window(double xMax, double yMax, double xMin, double yMin) {
	this->xMax = xMax;
	this->yMax = yMax;
	this->xMin = xMin;
	this->yMin = yMin;
	vup.x = 0.0;
	vup.y = 1.0;
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

point Window::getCenter(){
	point center;
	center.x = (xMax-xMin)/2;
	center.y = (yMax-yMin)/2;
	return center;
}

void Window::rotate(double angle){
  double rMatrix[4][4];
  Utils::rotationMatrix(getCenter(), angle, rMatrix);
  point origin(xMin, yMin);
  point antiorigin(xMax, yMax);
  
  origin = Utils::transform(origin, rMatrix);
  antiorigin = Utils::transform(antiorigin, rMatrix);
  
  xMin = origin.x;
  yMin = origin.y;

  xMax = antiorigin.x;
  yMax = antiorigin.y;

  vup = Utils::transform(vup, rMatrix);
}

double Window::getAngle() {
	point base(0,1);
	return Utils::angle(vup, base);
}

