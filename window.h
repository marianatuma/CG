#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
	double xMax, yMax, xMin, yMin;
public:
	Window(double xMax, double yMax,  double xMin = 0, double yMin = 0);
	~Window();
	double getXMin();
	double getYMin();
	double getXMax();
	double getYMax();
	void zoom(double delta);
	void moveX(double delta);
	void moveY(double delta);
	void zoomIn(double delta);
	void zoomOut(double delta);
};

#endif