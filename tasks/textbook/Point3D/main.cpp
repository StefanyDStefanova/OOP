#include "Point3D.h"

int main()
{
	Point3D p, p1(1,1,1);
	p.print();
	p1.print();

	Point3D p2 = p1;
	p2.print();
	p2.setX(20);
	p2.setY(2);
	p2.setZ(5);
	p2.print();

	return 0;
}