#ifndef __FOREST_ANIMAL
#define __FOREST_ANIMAL

#include "Animal.h"

class ForestAnimals :virtual public Animals
{
protected:
	int mSeaLevel;

public:
	ForestAnimals(const char* typeFood = " ", const int seaLevel = 0);

};
#endif // !__FOREST_ANIMAL
