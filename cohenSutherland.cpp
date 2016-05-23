#include "cohenSutherland.h"
#include <iterator>

bool CohenSutherland::needsClipping(std::list<point>* points) {
	point a, b;
	a = points->back();
	
	for (std::list<point>::const_iterator it = points->begin();
    it != points->end();
    ++it) {
		b = a;
		a = *it;
		if((getQuadrant(a) & getQuadrant(b)) == 0)
			return true;
	}
	return false;
}

void CohenSutherland::clipPolygon(GraphObj* g){
	std::list<point>* points = g->getPoints();
	
	if(needsClipping(points)) {
		std::list<point>* clipped = new std::list<point>();
		
		for (std::list<point>::const_iterator it = points->begin();
    	it != points->end();
    	++it) {
    		// copia, necessario??
    		clipped->push_back(*it);
		}

		std::list<point> temp;
		point a, b, c;
		a = clipped->back();
		bool containsFromPrevious = false;

		//Cortando por borda
		for (int edge = 1; edge <= 8; edge *= 2) {
			temp.clear();

			for (std::list<point>::const_iterator it = clipped->begin();
	    	it != clipped->end();
	    	++it) {
	    		b = a;
				a = *it;

				if ((getQuadrant(a) & edge) == 0) {
					// a esta dentro da area de clipping
					if ((getQuadrant(b) & edge) == 0) {
						temp.push_back(b);
					} else {
						c = calculateIntersection(a, b, edge);
						temp.push_back(c);
					}
				} else if ((getQuadrant(b) & edge) == 0) {
					// a esta fodra da area de cliping mas b esta dentro
					c = calculateIntersection(a, b, edge);
					temp.push_back(c);
					temp.push_back(b);
				}

			}
			
			clipped->clear();
			for (std::list<point>::const_iterator it = temp.begin();
	    	it != temp.end();
	    	++it) {
				clipped->push_back(*it);
			}
		}
		g->setClippedPoints(clipped);
	} else {
	//	g->setClippedPoints(points);
	} 
}

void CohenSutherland::clipPoint(GraphObj* g) {
	Point* p = static_cast<Point*>(g);
	point* o = p->getPoint();
	bool draw = false;
	
	if (this->getQuadrant(*o) == CohenSutherland::INSIDE) {
		draw = true;;
	}

	p->setDraw(draw);
}

void CohenSutherland::clip(GraphObj* g) {
	type t = g->getType();
	switch(t) {
      case type::POLYGON:
        clipPolygon(g);
        break;
      case type::POINT:
        clipPoint(g);
        break;
    }
}

CohenSutherland::Quadrant CohenSutherland::getQuadrant(
		point p) {
	int quadrant = 0;

	if (p.x < window->getXMin()) {
		quadrant += CohenSutherland::LEFT;
	} else if (p.x > window->getXMax()) {
		quadrant += CohenSutherland::RIGHT;
	}

	if (p.y < window->getYMin()) {
		quadrant += CohenSutherland::DOWN;
	} else if (p.y > window->getYMax()) {
		quadrant += CohenSutherland::UP;
	}
	return (CohenSutherland::Quadrant) quadrant;
}

point CohenSutherland::calculateIntersection(point a, point b, int edge) {
	double m = (b.y - a.y) / (b.x - a.x);
	return clipSector(a, m, (CohenSutherland::Quadrant) edge);
}

point CohenSutherland::clipSector(point p, double m, CohenSutherland::Quadrant quadrant) {
	switch (quadrant) {
	case CohenSutherland::INSIDE:
		break;
	case CohenSutherland::LEFT:
		if (m != 0.0) {
			p.y = m * (window->getXMin() - p.x) + p.y;
			p.x =  window->getXMin();
		}
		break;
	case CohenSutherland::RIGHT:
		if (m != 0.0) {
			p.y = m * (window->getXMax() - p.x) + p.y;
			p.x = window->getXMax();
		}
		break;
	case CohenSutherland::UP:
		if (m != 0.0) {
			p.x = p.x + ((1 / m) * (window->getYMax() - p.y));
			p.y = window->getYMax();
		}
		break;
	case CohenSutherland::DOWN:
		if (m != 0.0) {
			p.x = p.x + ((1 / m) * (window->getYMin() - p.y));
			p.y = window->getYMin();
		}
		break;
	case CohenSutherland::UP_LEFT:

		if (m != 0.0) {
			double  tempY = (m * (window->getXMin() - p.x)) + p.y;
			point tempInt(window->getXMin(), tempY);
			if (getQuadrant(tempInt) != CohenSutherland::INSIDE) {
				p.x = (p.x + ((1 / m) * (window->getYMax() - p.y)));
				p.y = window->getYMax();
			} else {
				p.x = window->getXMin();
				p.y = tempY;
			}
		}

		break;

	case CohenSutherland::UP_RIGHT:
		if (m != 0.0) {
			double tempY = (m * (window->getXMax() - p.x)) + p.y;
			point tempInt = point(window->getXMax(), tempY);
			if (getQuadrant(tempInt) != CohenSutherland::INSIDE) {
				p.x = (p.x + ((1 / m) * (window->getYMax() - p.y)));
				p.y = window->getYMax();
			} else {
				p.x = window->getXMax();
				p.y = tempY;
			}
		}

		break;

	case CohenSutherland::DOWN_LEFT:

		if (m != 0.0) {
			double tempY = (m * (window->getXMin() - p.x)) + p.y;
			point tempInt = point(window->getXMin(), tempY);
			if (getQuadrant(tempInt) != CohenSutherland::INSIDE) {
				p.x = (p.x + ((1 / m) * (window->getYMin() - p.y)));
				p.y = window->getYMin();
			} else {
				p.x = window->getXMin();
				p.y = tempY;
			}
		}

		break;

	case CohenSutherland::DOWN_RIGHT:

		if (m != 0.0) {
			double tempY = (m * (window->getXMax() - p.x)) + p.y;
			point tempInt = point(window->getXMax(), tempY);
			if (getQuadrant(tempInt) != CohenSutherland::INSIDE) {
				p.x = (p.x + ((1 / m) * (window->getYMin() - p.y)));
				p.y = window->getYMin();
			} else {
				p.x = window->getXMax();
				p.y = tempY;
			}
		}

		break;
	}
	return p;
}
