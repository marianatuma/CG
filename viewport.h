#ifndef VIEWPORT_HPP_
#define VIEWPORT_HPP_

class Viewport {
public:
	Viewport(double x = 0, double y = 0, double width = 200, double height = 200);
	virtual ~Viewport();
	double getXMax();
	double getYMax();
	double getX();
	double getY();
	double getHeight();
	double getWidth();
	void setX(double x);
	void setY(double y);
	void setHeight(double height);
	void setWidth(double width);
	void keepAspectRatio(double aspect);

private:
	double x;
	double y;
	double width;
	double height;
};

#endif