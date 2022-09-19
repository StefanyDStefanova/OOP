#include "Date.h"

Date::Date(int day, int month, int year):mDay(day),mMonth(month),mYear(year)
{
}

int Date::getDay() const
{
	return this->mDay;
}

int Date::getMonth() const
{
	return this->mMonth;
}

int Date::getYear() const
{
	return this->mYear;
}

void Date::setDay(int day)
{
	if (day < 1 || day>31)
	{
		throw "Invalid day";
	}
	this->mDay = day;
}

void Date::setMonth(int month)
{
	if (month < 1 || month>12)
	{
		throw "Invalid month";
	}
	this->mMonth = month;
}

void Date::setYear(int year)
{
	if (year < 1950 )
	{
		throw "Invalid year";
	}
	this->mYear = year;
}
