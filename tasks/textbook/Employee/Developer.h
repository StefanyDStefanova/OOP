#ifndef __DEVELOPER
#define __DEVELOPER

#include "Employee.h"

class Developer:public Employee
{
private:
	bool mKnowCpp, mKnowCs;

public:
	Developer(char* name, int internship, double salary, bool knowCpp, bool knowCs);
	Type type();

	bool getKnowCpp() const;
	bool getKnowCs() const;

	void setKnowCpp(bool know);
	void setKnowCs(bool know);

	void print() const;
};
#endif // !__DEVELOPER
