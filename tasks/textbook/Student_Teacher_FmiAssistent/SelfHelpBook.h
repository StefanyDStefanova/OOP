#ifndef __SELF_HELP_BOOK
#define __SELF_HELP_BOOK

#include "Advisor.h"
#include "Book.h"

class SelfHelpBook :public Advisor, public Book
{
private:
	std::string mAutor;

public:
	SelfHelpBook(std::string name, std::vector<std::string>subjects, int serialNum, std::string autor);

	std::string getAutor() const;
	void setAutor(std::string autor);

	void printInfo() const;
};
#endif // !__SELF_HELP_BOOK
