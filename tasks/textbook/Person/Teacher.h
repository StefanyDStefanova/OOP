#ifndef __TEACHER
#define __TEACHER

#include"Person.h"
#include <vector>

class Teacher :virtual public Person
{
protected:
	std::vector<std::string> mSubjects;

public:
	Teacher(std::string name,int id, std::vector<std::string> subjects);

	std::vector<std::string> getSubjects() const;
	void setSubjects(std::vector<std::string> subject);
};
#endif // !__TEACHER
