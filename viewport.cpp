#include "viewport.h"

Viewport::Viewport(double x, double y, double width, double height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

}

Viewport::~Viewport() {
	// TODO Auto-generated destructor stub
}

double Viewport::getXMax() {
	return x + width;
}

double Viewport::getYMax() {
	return y + height;
}

double Viewport::getX() {
	return this->x;
}
double Viewport::getY() {
	return this->y;
}
double Viewport::getHeight() {
	return this->height;
}
double Viewport::getWidth() {
	return this->width;
}

void Viewport::setX(double x) {
	this->x = x;
}

void Viewport::setY(double y) {
	this->y = y;
}

void Viewport::setHeight(double height) {
	this->height = height;
}

void Viewport::setWidth(double width) {
	this->width = width;
}

void Viewport::keepAspectRatio(double aspect) {
	double futureHeight = width * (1 / aspect);
	if (height < futureHeight)
		width = height * aspect;
	else
		height = futureHeight;
}

