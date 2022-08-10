#include "Date.h"

Date::Date(int dayP, int monthP, int yearP)
{
	this->day = dayP;
	this->month = monthP;
	this->year = yearP;
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->month;
}

void Date::setDay(int dayP)
{
	this->day = dayP;
}

void Date::setMonth(int monthP)
{
	this->month = monthP;
}

void Date::setYear(int yearP)
{
	this->year = yearP;
}

void Date::printDate() const
{
	std::cout << year << " - " << month << " - " << day << std::endl;
}
