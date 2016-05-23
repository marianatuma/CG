#include "noClipping.h"
#include "point.h"

void NoClipping::clip(GraphObj* g){
	type t = g->getType();
	switch(t) {
      case type::POLYGON:
		    g->setClippedPoints(g->getPoints());        
        break;
      case type::POINT:
        Point* p = static_cast<Point*>(g);
        p->setDraw(true);
        break;
    }
}