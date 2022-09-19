#ifndef __DATE_TIME
#define __DATE_TIME

#include "Date.h"
#include "Time.h"
#include <string.h>
#include <stdlib.h>

class DateTime :public Date, public Time
{
private:
	char mDateTimeString[20];

public:
	DateTime(int day, int month, int year, int minutes, int hour, char dateTimeString);

	void print()const;
};
#endif // !__DATE_TIME
