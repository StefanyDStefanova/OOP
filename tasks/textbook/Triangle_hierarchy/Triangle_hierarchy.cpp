#include "Triangle_hierarchy.h"

void Triangle::init(double x, double y, double z)
{
	if (x > 0 && y > 0 && z > 0 && x + y > z && x + z > y && y + z > x)
	{
		a = x;
		b = y;
		c = z;
	}
	else
	{
		throw std::exception("You have incorrect enter");
	}
}

double Triangle::perimeter() const
{
	return a+b+c;
}

double Triangle::area() const
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::print() const
{
	std::cout << a << " " << b << " " << c << std::endl;
}

void RightTriangle::init(double x, double y, double z)
{
	if (fabs(x * x + y * y - z * z) > 1.0e-14 && fabs(x * x + z * z - y * y) > 1.0e-14 && fabs(y * y + z * z - x * x) > 1.0e-14)
	{
		throw std::exception("The triangle is not right triangle");
	}
}

double RightTriangle::area() const
{
	if (fabs(a * a + b * b - c * c) <= 1e-14)
	{
		return a * b / 2;
	}
	return b * c / 2;
}

void IsoscelesTriangle::init(double x, double y, double z)
{
	if (fabs(x - y) > 1.0e-14 && fabs(x - z) > 1.0e-14 && fabs(y - z) > 1.0e-14)
	{
		throw std::exception("The triangle is not isosceles triangle.");
	}

}

double IsoscelesTriangle::area() const
{
	if(fabs(a - b) <= 1.0e-14 )
	{
		return sqrt(a * a - c * c / 4) * c / 2;
	}
	if (fabs(a - c) <= 1.0e-14)
	{
		return sqrt(a * a - b * b) / 4 * b / 2;
	}
	return sqrt(b * b - a * a / 4) * a / 2;
}
