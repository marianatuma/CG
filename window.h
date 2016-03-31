#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
	double xMax, yMax;
public:
	Window(double xMax, double yMAx);
	double getXMAx();
	double getYMAx();
	void zoom(double delta);
	void moveX(double delta);
	void moveY(double delta);
};

#endif