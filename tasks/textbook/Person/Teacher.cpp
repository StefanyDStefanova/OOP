#include "Teacher.h"

Teacher::Teacher(std::string name, int id, std::vector<std::string> subjects):Person(name,id)
{
	setSubjects(subjects);
}

std::vector<std::string> Teacher::getSubjects() const
{
	return mSubjects;
}

void Teacher::setSubjects(std::vector<std::string> subject)
{
	mSubjects = subject;
}
