#include "Time.h"

Time::Time(int minutes, int hour):mMinutes(minutes),mHour(hour)
{
}

int Time::getMinutes() const
{
	return this->mMinutes;
}

int Time::getHour() const
{
	return this->mHour;
}

void Time::setMinutes(int minutes)
{
	if (minutes < 0 || minutes>60)
	{
		throw "Minutes is not valid.";
	}
	this->mMinutes = minutes;
}

void Time::setHours(int hour)
{
	if (hour < 0 || hour>24)
	{
		throw "Hour is not valid.";
	}
	this->mHour = hour;
}
