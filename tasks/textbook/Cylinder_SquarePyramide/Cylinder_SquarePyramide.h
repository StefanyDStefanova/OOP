#ifndef __CYLINDER_SQUAREPYRAMIDE
#define __CYLINDER_SQUAREPYRAMIDE

#include <iostream>

class SquarePyramide;

class Cyrlinder
{
private:
	double radians;
	double height;

public:
	Cyrlinder(double radiansP, double heightP);
	
	double getRadians() const;
	double getHeight() const;

	bool isHight(const  SquarePyramide& obj)const;


};

class SquarePyramide
{
private:
	double side;
	double height;

public:
	SquarePyramide(double sideP, double heightP);

	double getSide() const;
	double getHeight() const;

	friend bool Cyrlinder::isHight(const SquarePyramide& obj) const;

};

#endif // !1
