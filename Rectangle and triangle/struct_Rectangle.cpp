#include <iostream>

struct Rectangle
{
	int length;
	int width;
};

void initRectangle(Rectangle& r)
{
	std::cin >> r.length;
	std::cin >> r.width;
}

Rectangle initRectangless()
{
	Rectangle r;
	do
	{
		std::cin >> r.length;
		std::cin >> r.width;
	} while (r.length <= 0 || r.width <= 0);
	return r;		
}

void printRectangle (Rectangle r) 
{
	std::cout << r.length << " and " << r.width << std::endl;
}

//------------------- zad 3 --------------------------
//--------------- struct Triangle --------------------

struct Triangle
{
	double pointA;
	double pointB;
	double pointC;
};

void createTriangle(Triangle t) 
{
	bool triangleIsCorect;
	do
	{
		std::cin >> t.pointA;
		std::cin >> t.pointB;
		std::cin >> t.pointC;

		triangleIsCorect =
			(t.pointA > 0) && (t.pointB > 0) && (t.pointC > 0)
			(t.pointA + t.pointB > t.pointC) &&
			(t.pointA + t.pointC > t.pointB) &&
			(t.pointC + t.pointB > t.pointA);
	} while (!triangleIsCorect);
}

double perimTriangle(Triangle t)
{
	return t.pointA + t.pointB + t.pointC;
}

double areaTriangle(Triangle t)
{
	double p = perimTriangle(t) / 2;
	return sqrt(p * (p - t.pointA) * (p - t.pointB) * (p - t.pointC));
	return sqrt(p * (p - t.pointA) * (p - t.pointB) * (p - t.pointC));
}

void printTriangle(Triangle t)
{
	std::cout << t.pointA << "," << t.pointB << "," << t.pointC << std::endl;
}

int main() 
{
	return 0;
}