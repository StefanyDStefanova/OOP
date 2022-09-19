#include "Budget.h"

Budget::Budget()
{
	this->mFacultyBudget = 0.0;
}

double Budget::getUniBudget() const
{
	return this->mUniBudget;
}

double Budget::getFcultyBudget() const
{
	return this->mFacultyBudget;
}

void Budget::addBudget(double money)
{
	this->mFacultyBudget = money;
	this->mUniBudget += this->mFacultyBudget;
}

void Budget::print() const
{
	std::cout << "UNI BUDGET IS: " << mUniBudget;

}
