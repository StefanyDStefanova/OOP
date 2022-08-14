#ifndef __STUDENT
#define __STUDENT

#include "Person.h"

class Student :virtual public Person
{
private:
	int mFn;
	int mNumOfSubjects;

public:
	Student(std::string name, int id, int fn, int numOfSubjects);

	int getFn() const;
	int getNumOfSubjects() const;

	void setFn( int fn);
	void setNumOfSubjects( int numOfSubjects);
};
#endif // !__STUDENT
