#ifndef GRAPHOBJECT_H
#define GRAPHOBJECT_H

#include <list>
#include <string>
#include "utils.hpp"

class GraphObj {
private:
	type t;
	std::string name;
	std::list<point>* genericTransform(double matrix[4][4]);

protected:
	std::list<point>* points;
	std::list<point>* clippedPoints;// encontrados com base nos points por enquanto, mudar pra se basear nos normalized points
	std::list<point>* normalizedPoints;

public:
	GraphObj(std::string name, type t);
	type getType();
	std::string getName();
	void changeName(std::string newName);
	std::list<point>* getPoints();
	std::list<point>* getClippedPoints();
	std::list<point>* getNormalizedPoints();
	virtual point getCenter() = 0;
	void setPoints(std::list<point>* newPoints);
	void setClippedPoints(std::list<point>* clipped);
	void transform(double matrix[4][4]);
	void transformOnWindowRotation(double matrix[4][4]);
};

#endif