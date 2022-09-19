#ifndef __TIME
#define __TIME

#include <iostream>

class Time
{
private:
	int mMinutes;
	int mHour;

public:
	Time(int minutes = 0, int hour = 0);

	int getMinutes() const;
	int getHour() const;

	void setMinutes(int minutes);
	void setHours(int hour);
};

#endif // !__TIME
