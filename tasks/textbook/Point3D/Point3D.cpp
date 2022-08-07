#include "Point3D.h"

Point3D::Point3D( int _x,  int _y, int _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Point3D::Point3D(const Point3D& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

int Point3D::getX() const
{
	return x;
}

int Point3D::getY() const
{
	return y;
}

int Point3D::getZ() const
{
	return z;
}

void Point3D::setX(int _x)
{
	x = _x;
}

void Point3D::setY(int _y)
{
	y = _y;
}

void Point3D::setZ(int _z)
{
	z = _z;
}

void Point3D::print() const
{
	std::cout << "(" << x << " , " << y << " , " << z << " )\n";
}
