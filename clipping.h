#ifndef CLIPPING_H
#define CLIPPING_H

#include "graphObj.h"
#include "window.h"

class Clipping {
public:
	Clipping(Window* window) {
		this->window = window;
	}
	virtual void clip(GraphObj* g) = 0;

protected:
	Window* window;
};
#endif