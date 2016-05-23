#ifndef NOCLIPPING_H
#define NOCLIPPING_H

#include "clipping.h"

class NoClipping : public Clipping{
public:
	NoClipping(Window* window) : Clipping(window){}
	virtual void clip(GraphObj* g);
};

#endif