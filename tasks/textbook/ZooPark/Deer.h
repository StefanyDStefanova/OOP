#ifndef __DEER
#define __DEER

#include "ForestAnimal.h"
#include "HerbivoresAnimals.h"

class Deer : public HerbivoresAnimals, public ForestAnimals
{
public:
	Deer(const char* typeFood=" ", const int seaLevel=0, const int typeOfGrass=0);
	double getCoef()const override;

};
#endif // !__DEEP
