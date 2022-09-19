#ifndef __ADVISOR
#define __ADVISOR

#include <iostream>
#include <string>
#include<vector>

class Advisor
{
private: 
	std::string mName;
	std::vector<std::string> mSubjects;

public:
	Advisor(std::string name, std::vector<std::string>subjects);

	std::string getName() const;
	std::vector<std::string> getSubject() const;

	void setName(std::string name);
	void setSubject(std::vector<std::string> subject);

	virtual void printInfo() const = 0;
};
#endif // !__ADVISOR
