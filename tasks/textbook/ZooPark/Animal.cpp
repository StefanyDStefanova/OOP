#include "Animal.h"

Animals::Animals(const char* typeFood)
{
	this->mTypeFood = new char[strlen(typeFood) + 1];
	strcpy_s(this->mTypeFood, strlen(typeFood) + 1, typeFood);
}

Animals::~Animals()
{
	delete[] this->mTypeFood;
}

char* Animals::getFood() const
{
	return this->mTypeFood;
}
