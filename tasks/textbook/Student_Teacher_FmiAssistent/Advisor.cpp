#include "Advisor.h"

Advisor::Advisor(std::string name, std::vector<std::string> subjects):mName(name),mSubjects(subjects)
{
}

std::string Advisor::getName() const
{
	return mName;
}

std::vector<std::string> Advisor::getSubject() const
{
	return mSubjects;
}

void Advisor::setName(std::string name)
{
	mName = name;
}

void Advisor::setSubject(std::vector<std::string> subject)
{
	mSubjects = subject;
}
