#include "Zoopark.h"
#include "Animal.h"
#include "Bear.h"

void Zoo::sortAnimals()
{
	size_t len = mAnimals.size();
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - 1; j++)
		{
			if (mAnimals[j]->getCoef() < mAnimals[j+1]->getCoef())
			{
				ForestAnimals* temp = mAnimals[j];
				mAnimals[j] = mAnimals[j + 1];
				mAnimals[j + 1] = temp;
			}
		}
	}
}

void Zoo::addAnimal(ForestAnimals* animals)
{
	mAnimals.push_back(animals);
}

void Zoo::printTopFive() 
{
	sortAnimals();
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Food: " << mAnimals[i]->getFood()<<" coeff: "<<mAnimals[i]->getCoef()<<std::endl;
	}
}

Zoo::~Zoo()
{
	for (ForestAnimals* animals : mAnimals)
	{
		delete[] animals;
	}
}
