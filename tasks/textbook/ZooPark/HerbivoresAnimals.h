#ifndef __HERBIVORES_ANIMALS
#define __HERBIVORES_ANIMALS

#include "Animal.h"

class HerbivoresAnimals :virtual public Animals
{
protected:
	int mTypesOfGrass;

public:
	HerbivoresAnimals(const char* typeFood = " ", const int typesOfGrass=0);
};
#endif // !__HERBIVORES_ANIMALS
