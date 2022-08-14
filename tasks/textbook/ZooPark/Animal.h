#ifndef __ANIMAL
#define __ANIMAL

#include <iostream>
#include <string.h>

class Animals
{
protected:
	char* mTypeFood;
	int mCoef;

public:
	Animals(const char* typeFood = " ");

	virtual~Animals();

	virtual double getCoef() const = 0;
	char* getFood() const;
};

#endif // !__ANIMAL
