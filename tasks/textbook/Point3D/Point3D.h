#ifndef __POINT_3D
#define __POINT_3D

#include <iostream>

class Point3D
{
private:
	int x;
	int y;
	int z;
	
public:
	Point3D(int = 0.0, int = 0.0, int = 0.0);
	Point3D(const Point3D& other);

	int getX() const;
	int getY() const;
	int getZ() const;

	void setX(int);
	void setY(int);
	void setZ(int);

	void print() const;
};

#endif // !__POINT_3D
