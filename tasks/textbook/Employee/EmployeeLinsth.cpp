#include "EmployeeLinsth.h"

bool EmployeeList::resize()
{
	Employee** newArr = new Employee * [capacity * 2];
	if (newArr == NULL)
	{
		return false;
	}
	for (int i = 0; i < capacity; i++)
	{
		newArr[i] = employees[i];
	}
	Employee** tmp = employees;
	employees = newArr;
	delete tmp;
	capacity *= 2;
	return true;
}

EmployeeList::EmployeeList()
{
	capacity = 3;
	size = 0;
	employees = new Employee * [capacity];
}

bool EmployeeList::insert(Employee* newEmployee)
{
	if (size == capacity && !resize())
	{
		return false;
	}
	employees[size++] = newEmployee; 
	return true;
}
