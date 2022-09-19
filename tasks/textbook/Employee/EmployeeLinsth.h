#ifndef __EMPLOYEE_LIST
#define __EMPLOYEE_LIST

#include "Developer.h"
#include "Menager.h"

class EmployeeList 
{
private:
	Employee** employees;
	int size;
	int capacity;

	bool resize();

public:
	EmployeeList();
	bool insert(Employee* newEmployee);

};
#endif // !__EMPLOYEE_LIST
