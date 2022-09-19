#ifndef __DATE
#define __DATE

#include <iostream>

class Date
{
private:
	int mDay;
	int mMonth;
	int mYear;

public:
	Date(int day = 1, int month = 1, int year = 1950);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
};
#endif // !__DATE
