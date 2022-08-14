#ifndef __BEAR
#define __BEAR

#include "ForestAnimal.h"
#include "PredatorsAnimals.h"


class Bear : public PredatorsAnimals, public ForestAnimals
{
public:
	Bear(const char* typeFood = " ", const int seaLevel=0, const double power=0.0, const int speed=0);
	double getCoef()const override;
};

#endif // !__BEAR
