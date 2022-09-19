#include "DateTime.h"

DateTime::DateTime(int day, int month, int year, int minutes, int hour, char dateTimeString):Date(day,month,year),Time(minutes,hour)
{
	char temp[90];
	strcpy(mDateTimeString, itoa(getMonth(), temp, 10));
	strcat(mDateTimeString, "/ ");
	strcat(mDateTimeString, itoa(getDay(), temp, 10));
	strcat(mDateTimeString, "/ ");
	strcat(mDateTimeString, itoa(getDay(), temp, 10));
	strcat(mDateTimeString, "/ ");
	strcat(mDateTimeString, "  ");
	strcat(mDateTimeString, itoa(getHour(), temp, 10));
	strcat(mDateTimeString, " : ");
	strcat(mDateTimeString, itoa(getMinutes(), temp, 10));

}

void DateTime::print() const
{
	std::cout << mDateTimeString;
}


