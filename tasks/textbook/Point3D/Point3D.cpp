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

void Point3D::pushArr(int size, Point3D points[])
{
	for (int i = 0; i < size; i++)
	{
		int p;
		std::cout << "x= ";
		std::cin >> p;
		points[i].setX(p);

		std::cout << "y=" ;
		std::cin >> p;
		points[i].setY(p);

		std::cout << "z= ";
		std::cin >> p;
		points[i].setZ(p);
	}
}

void Point3D::symmetry(int size, Point3D points[])
{
	for (int i = 0; i < size; i++)
	{
		points[i].setX(-points[i].getX());
		points[i].setY(-points[i].getY());
		points[i].setZ(-points[i].getZ());
	}
}

bool Point3D::lexic(Point3D p1, Point3D p2)
{
	return p1.getX()<p2.getX() ||p1.getX()==p2.getX()&&p1.getY()<p2.getY()||p1.getX()==p2.getX()&&p1.getY()==p2.getY()&&p1.getZ()<p2.getZ();
}

void Point3D::sortPoints(int n, Point3D* p)
{
	for (int i = 0; i < n-1; i++)
	{
		int k = i;
		Point3D min = p[i];
		for (int j = i + 1; j < n; j++)
		{
			if (lexic(p[j], min))
			{
				min = p[j];
				k = j;
			}
			p[k] = p[i];
			p[i] = min;
		}
	}
}

void Point3D::print() const
{
	std::cout << "(" << x << " , " << y << " , " << z << " )\n";
}
