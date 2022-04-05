#include <iostream>
#include <cmath>

const double PI = 3.14;

struct Polat
{
	double lengthPolat;
	double angle;
};

struct Rect
{
	double x, y;
};

void initPolat(Polat p)
{

}

void initRect(Rect r)
{

}

Rect polarToRect(const Polat& p)
{
	const double deg = PI / 180;
	Rect r;
	r.x = p.lengthPolat * cos(p.angle*deg);
	r.y = p.lengthPolat * sin(p.angle*deg);
	return r;
}

Polat rectToPolar(const Rect& r)
{
	Polat p;
	p.lengthPolat = sqrt(r.x * r.x + r.y * r.y);
	p.angle = atan2(r.y , r.x);
	return p;
}

void printRect(Rect r)
{
	std::cout << "X: " << r.x << "Y: " << r.y;
}

void printPolar(Polat p)
{
	const double rad = 180 / PI;
	std::cout << "Length: " << p.lengthPolat;
	std::cout << "Angle: " << p.angle*rad;
}

int main()
{
	Rect r;
	Polat p;

	char kind;
	std::cout << "Chouse the kind: ";
	do 
	{
		std::cin >> kind;
	} while (kind == 'r' || kind == 'p');

	switch (kind)
	{
		case('r'):
			while (std::cin >> r.x >> r.y)
			{
				p = rectToPolar(r);
				printPolar(p);
				std::cout << "Next";
			}
			break;
		case('p'):
			while (std::cin >> p.lengthPolat >> p.angle)
			{
				r = polarToRect(p);
				printRect(r);
				std::cout << "Next";
			}
			break;
	}

	return 0;
}