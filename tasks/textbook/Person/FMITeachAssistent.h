#ifndef __FMI_TEACH_ASSISTENT
#define __FMI_TEACH_ASSISTENT

#include "Student.h"
#include "Teacher.h"
#include "Advisor.h"

class FmiTeachAssistent :public Teacher, public Student,public Advisor
{
private:
	size_t mNumOfStudySubject;

public:
	FmiTeachAssistent(std::string name, int id, std::vector<std::string> subjects, int fn, int sumOfSubject, std::string Aname, std::vector<std::string>Asubjects,size_t numOfStudySubject);

	size_t getNumOfStudySubject() const;

	void printInfo() const override;
};
#endif // !__FMI_TEACH_ASSISTENT
