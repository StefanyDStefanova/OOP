#ifndef __ZOOPARK
#define __ZOOPARK

#include <vector>
#include "Animal.h"
#include "ForestAnimal.h"

class Zoo
{
protected:
	std::vector<ForestAnimals*> mAnimals;

	void sortAnimals();

public:
	void addAnimal(ForestAnimals* animals);
	void printTopFive() ;

	~Zoo();
};

#endif // !__ZOOPARK
