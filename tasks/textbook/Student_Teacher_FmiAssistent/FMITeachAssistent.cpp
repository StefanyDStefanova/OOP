#include "FMITeachAssistent.h"

FmiTeachAssistent::FmiTeachAssistent(std::string name, int id, std::vector<std::string> subjects, int fn, int sumOfSubject, std::string Aname, std::vector<std::string>Asubjects, size_t numOfStudySubject):Person(name,id),Teacher(name,id,subjects),Student(name,id,fn,sumOfSubject),Advisor(Aname,Asubjects)
{
	mNumOfStudySubject = Student::getNumOfSubjects() + Teacher::getSubjects().size() + Advisor::getSubject().size();
}

size_t FmiTeachAssistent::getNumOfStudySubject() const
{
	return mNumOfStudySubject;
}

void FmiTeachAssistent::printInfo() const
{
	std::cout << "---------------------------------------\n";
	std::cout << "Name: " << Person::getName() << std::endl;
	std::cout << "Id: " << Person::getId() << std::endl;

	std::cout << "Fn: " << Student::getFn() << std::endl;
	std::cout << "Student Subject: " << Student::getNumOfSubjects() << std::endl;
	std::cout << "Teacher Subject: " << Teacher::getSubjects().size() << std::endl;
	for (std::string str : Teacher::getSubjects())
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;
	std::cout << "Advisor's name: " << Advisor::getName() << std::endl;
	std::cout << "Advisor's subject: " << Advisor::getSubject().size() << std::endl;
	for (std::string str : Advisor::getSubject())
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;
	std::cout << "---------------------------------------\n";

}
