#ifndef __PREDATOR_ANIMAL
#define __PREDATOR_ANIMAL

#include "Animal.h"


class PredatorsAnimals :virtual public Animals
{
protected:
	double mBiteForce;
	int mRunningSpeed;

public:
	PredatorsAnimals(const char* typeFood = " ", const double biteForce = 0.0, const int& runningSpeed = 0);
};


#endif // !__PREDATOR_ANIMAL
