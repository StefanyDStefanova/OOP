#include "Employee.h"

void Employee::copy(char* name, int internship, double salary)
{
	this->mName = new char[strlen(name) + 1];
	strcpy_s(this->mName, strlen(name) + 1, name);

	this->mInternship = internship;
	this->mSalary = salary;
}

Employee::Employee(char* name, int internship, double salary) :mInternship(internship),mSalary(salary)
{
	this->mName = new char[strlen(name) + 1];
	strcpy_s(this->mName, strlen(name) + 1, name);
}

Employee::Employee(const Employee& other)
{
	copy(other.mName, other.mInternship, other.mSalary);
}

Employee& Employee::operator=(const Employee& other)
{
	if(this != &other)
	{
		delete[] this->mName;
		copy(other.mName, other.mInternship, other.mSalary);
	}
	return *this;
}

Employee::~Employee()
{
	delete[] mName;
}

char* Employee::getName() const
{
	return this->mName;
}

int Employee::getInternship() const
{
	return this->mInternship;
}

double Employee::getSalary() const
{
	return this->mSalary;
}

void Employee::print() const
{
	std::cout << "-------------------------\n";
	std::cout << "Name: " << mName << std::endl;
	std::cout << "Internship: " << mInternship << std::endl;
	std::cout << "Salary: " << mSalary << std::endl;
	std::cout << "-------------------------\n";

}

