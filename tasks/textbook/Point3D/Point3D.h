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

	void pushArr(int size, Point3D points[]);
	void symmetry(int size, Point3D points[]);

	bool lexic(Point3D p1, Point3D p2);
	void sortPoints(int n, Point3D* p);

	void print() const;
};

#endif // !__POINT_3D
