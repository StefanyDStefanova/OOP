#ifndef __DATE
#define __DATE

#include <iostream>

class Date 
{
private:
	int day;
	int month;
	int year;

public:
	Date(int dayP = 1, int monthP = 1, int yearP = 1960);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int dayP);
	void setMonth(int monthP);
	void setYear(int yearP);

	void printDate() const;

};

#endif // !__DATE
