#include "Bear.h"

Bear::Bear(const char* typeFood, const int seaLevel, const double power, const int speed):Animals(typeFood),PredatorsAnimals(typeFood,power,speed),ForestAnimals(typeFood,seaLevel)
{
	mCoef = (double)((mBiteForce * mRunningSpeed)/ mSeaLevel);
}

double Bear::getCoef()const
{
	return mCoef;

}
