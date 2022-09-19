#include "Student.h"



Student::Student(std::string name, int id, int fn, int numOfSubjects):Person(name,id),mNumOfSubjects(numOfSubjects)
{
	if (fn < 10000 || fn>99999)
	{
		throw std::exception("Invalid facultyNum. ");
	}
	this->mFn = fn;
}

int Student::getFn() const
{
	return this->mFn;
}

int Student::getNumOfSubjects() const
{
	return this->mNumOfSubjects;
}

void Student::setFn(const int fn)
{
	if (fn < 10000 || fn>99999)
	{
		throw std::exception("Invalid facultyNum. ");
	}
	this->mFn = fn;
}

void Student::setNumOfSubjects(const int numOfSubjects)
{
	this->mNumOfSubjects = numOfSubjects;
}
