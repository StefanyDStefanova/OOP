#include "Menager.h"

Menager::Menager(char* name, int internship, double salary, int inChargerOf):Employee(name,internship,salary),mInChargerOf(inChargerOf)
{
}

Type Menager::type()
{
	return MANAGER;
}

int Menager::getInChargerOf() const
{
	return this->mInChargerOf;
}

void Menager::setInChargerOf(int num)
{
	this->mInChargerOf = num;
}

void Menager::print() const
{
	std::cout << "In Charget of: " << mInChargerOf << std::endl;
}
