#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <math.h>
#include <iostream>
#define PI 3.14159265

enum class type {
	LINE,
	POLYGON,
	POINT
};

struct point {
	double x;
	double y;
	double z;
	point(){}
	point(double x1, double y1) {
		x = x1;
		y = y1;
	}	
	point(double x1, double y1, double z1) {
		x = x1;
		y = y1;
		z = z1;
	}
};

class Utils {
public:

	static void indentityMatrix(double matrix[4][4]) {
		int i, j;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (i == j)
					matrix[i][j] = 1.0;
				else
					matrix[i][j] = 0.0;
			}
		}
	}

	static void finishMatrix(double matrix [4][4], double t[4][4], double tMinus[4][4]) {
		double temp[4][4];
		multiply_matrices(temp, tMinus, matrix);

		multiply_matrices(matrix, temp, t);
	}

	static void translationMatrix(double dx, double dy, double dz,
			double t[4][4]) {
		int i, j;

		indentityMatrix(t);
		t[3][0] = dx;
		t[3][1] = dy;
		t[3][2] = dz;
	}

	static void scalingMatrix(double cx, double cy, double factor,
			double s[4][4]) {
		indentityMatrix(s);

		double t[4][4];
		translationMatrix(cx, cy, 0, t);
		double tMinus[4][4];
		translationMatrix(-cx, -cy, 0, tMinus);

		s[0][0] = factor;
		s[1][1] = factor; //modificar para 3d

		finishMatrix(s, t, tMinus);
	}

	static void rotationMatrix(point pos, double angle, double r[4][4]) {
		indentityMatrix(r);

		double t[4][4];
		translationMatrix(pos.x, pos.y, 0, t);

		double tMinus[4][4];
		translationMatrix(-pos.x, -pos.y, 0,tMinus);

		double rad = angle * M_PI / 180;
		
		r[0][0] = cos(rad);
		r[0][1] = -sin(rad);
		r[1][0] = sin(rad);
		r[1][1] = cos(rad);

		finishMatrix(r, t, tMinus);		
	}


	static void multiply_matrices(double ret[4][4], double a[4][4],
			double b[4][4]) {

		int size = 4;
		for (int ia = 0; ia < size; ia++) {
			for (int jb = 0; jb < size; jb++) {
				ret[ia][jb] = 0;
				for (int ja = 0; ja < size; ja++) {
					ret[ia][jb] += a[ia][ja] * b[ja][jb];
				}
			}
		}

	}

	static point transform(point p, double matrix[4][4]) {
		double result[] = { 0, 0, 0, 0 };
		double old[] = { p.x, p.y, p.y, 1 };
		point q;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result[i] += old[j] * matrix[j][i];
			}
		}
		q.x = result[0];
		q.y = result[1];
		q.z = result[2];
		return q;
	}

};

#endif