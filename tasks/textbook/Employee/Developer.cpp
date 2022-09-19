#include "Developer.h"

Developer::Developer(char* name, int internship, double salary,bool knowCpp,bool knowCs):Employee(name,internship,salary),mKnowCpp(knowCpp),mKnowCs(knowCs)
{
}

Type Developer::type()
{
	return DEVELOPER;
}

bool Developer::getKnowCpp() const
{
	return this->mKnowCpp;
}

bool Developer::getKnowCs() const
{
	return this->mKnowCs;
}

void Developer::setKnowCpp(bool know)
{
	this->mKnowCpp = know;
}

void Developer::setKnowCs(bool know)
{
	this->mKnowCs = know;
}

void Developer::print() const
{
	std::cout << "Know C++: " << (mKnowCpp ? "yes" : "no") << std::endl;
	std::cout << "Know C#: " << (mKnowCs ? "yes" : "no") << std::endl;
}
