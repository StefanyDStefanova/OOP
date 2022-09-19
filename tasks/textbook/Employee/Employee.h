#ifndef __EMPLOYEE
#define __EMPLOYEE

#include <iostream>

enum Type{DEVELOPER=1,MANAGER};

class Employee
{
private:
	char* mName;
	int mInternship;
	double mSalary;

	void copy(char* name, int internship, double salary);

public:
	Employee(char* name, int internship, double salary);
	Employee(const Employee& other);
	Employee& operator= (const Employee& other);

	virtual ~Employee();

	char* getName() const;
	int getInternship() const;
	double getSalary() const;

	virtual Type type() = 0;

	void print() const;
};

#endif // !__EMPLOYEE
