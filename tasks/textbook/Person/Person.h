#ifndef __PERSON
#define __PERSON

#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>

class Person
{
private:
	std::string mName;
	int mId;

public:
	Person(std::string name,int id);

	std::string getName() const;
	int getId() const;

	void setName( std::string name);
	void setId( int id);

};
#endif // !__PERSON
