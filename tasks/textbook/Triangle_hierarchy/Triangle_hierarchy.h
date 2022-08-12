#ifndef __TRIANGLE
#define __TRIANGLE

#include <iostream>
#include <stdlib.h>
#include <cmath>

class Triangle
{
protected:
	double a, b, c;

public:
	void init(double x, double y, double z);
	double perimeter() const;
	double area() const;

	void print() const;

};

class RightTriangle :public Triangle
{
public:
	void init(double x, double y, double z);
	double area() const;
};

class IsoscelesTriangle :public Triangle
{
public:
	void init(double x, double y, double z);
	double area() const;
};

#endif // !__TRIANGLE
