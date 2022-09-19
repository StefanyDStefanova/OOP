#ifndef __MENAGER
#define __MENAGER

#include "Employee.h"

class Menager :public Employee
{
private:
	int mInChargerOf;

public:
	Menager(char* name, int internship, double salary, int inChargerOf);
	Type type();

	int getInChargerOf() const;
	void setInChargerOf(int num);

	void print() const;
};
#endif // !__MENAGER
