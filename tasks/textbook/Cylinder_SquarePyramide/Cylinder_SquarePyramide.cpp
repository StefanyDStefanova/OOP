#include "Cylinder_SquarePyramide.h"

Cyrlinder::Cyrlinder(double radiansP, double heightP)
{
	this->radians = radiansP;
	this->height = heightP;
}

double Cyrlinder::getRadians() const
{
	return this->radians;
}

double Cyrlinder::getHeight() const
{
	return this->height;
}

bool Cyrlinder::isHight(const SquarePyramide& obj) const
{
	return this->height > obj.height;
}

SquarePyramide::SquarePyramide(double sideP, double heightP)
{
	this->side = sideP;
	this->height = heightP;
}

double SquarePyramide::getSide() const
{
	return this->side;
}

double SquarePyramide::getHeight() const
{
	return this->height;
}
