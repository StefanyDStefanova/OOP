#include "Deer.h"

Deer::Deer(const char* typeFood, const int seaLevel, const int typeOfGrass):Animals(typeFood),ForestAnimals(typeFood,seaLevel),HerbivoresAnimals(typeFood,typeOfGrass)
{
	mCoef = (double)(mSeaLevel / mTypesOfGrass);
}

double Deer::getCoef()const
{
	return mCoef;
}
