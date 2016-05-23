#include "sutherlandHodgeman.h"
#include <vector>
#include <iterator>

void SutherlandHodgeman::clip(GraphObj* g) {
	point w[] = {point(window->getXMin(), window->getYMin()), 
		point(window->getXMax(), window->getYMin()), 
		point(window->getXMax(), window->getYMax()), 
		point(window->getXMin(), window->getYMax())};

	type t = g->getType();
	switch(t) {
      case type::POLYGON:
        clipPolygon(g, w);
        break;
      case type::POINT:
        clipPoint(g, w);
        break;
    }
}

void SutherlandHodgeman::clipPolygon(GraphObj* g, point w[]){
std::list<point>* points = g->getPoints();
	std::list<point>* clipped = new std::list<point>();
	

	for (std::list<point>::const_iterator it = points->begin();
    it != points->end(); ++it) {
		clipped->push_back(*it);
	}

	int len = 4;
	for (int i = 0; i < len; i++) {
		int size = clipped->size();
		
		std::vector<point> input;
		for (std::list<point>::const_iterator it = clipped->begin();
		    it != clipped->end(); ++it) {
			input.push_back(*it);
		}

		clipped = new std::list<point>();

		point a = w[(i + len - 1) % len];
		point b = w[i];

		for (int j = 0; j < size; j++) {

			point p = input[(j + size - 1) % size];
			point q = input[j];

			if (isInside(a, b, q)) {
				if (!isInside(a, b, p)) {
					clipped->push_back(intersection(a, b, p, q));
				}
				clipped->push_back(q);
			} else if (isInside(a, b, p)) {
				clipped->push_back(intersection(a, b, p, q));
			}
		}
	}

	g->setClippedPoints(clipped);
}

void SutherlandHodgeman::clipPoint(GraphObj* g, point w[]){
	Point* p = static_cast<Point*>(g);
	point* o = p->getPoint();
	int len = 4;
	bool draw = true;

	for (int i = 0; i < len; i++) {
		point a = w[(i + len - 1) % len];
		point b = w[i];

		if(!isInside(a, b, *o)) 
			draw = false;
	} 
	p->setDraw(draw);
}

bool SutherlandHodgeman::isInside(point a, point b, point c) {
	return (a.x - c.x) * (b.y - c.y) > (a.y - c.y) * (b.x - c.x);
}

point SutherlandHodgeman::intersection(point a, point b, point p,
		point q) {
	point res;
	double A1 = b.y - a.y;
	double B1 = a.x - b.x;
	double C1 = A1 * a.x + B1 * a.y;

	double A2 = q.y - p.y;
	double B2 = p.x - q.x;
	double C2 = A2 * p.x + B2 * p.y;

	double det = A1 * B2 - A2 * B1;
	res.x = (B2 * C1 - B1 * C2) / det;
	res.y = (A1 * C2 - A2 * C1) / det;

	return res;
}