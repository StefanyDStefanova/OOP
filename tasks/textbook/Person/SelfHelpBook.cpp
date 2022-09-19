#include "SelfHelpBook.h"

SelfHelpBook::SelfHelpBook(std::string name, std::vector<std::string> subjects, int serialNum, std::string autor):Advisor(name,subjects),Book(serialNum),mAutor(autor)
{
}

std::string SelfHelpBook::getAutor() const
{
	return mAutor;
}

void SelfHelpBook::setAutor(std::string autor)
{
	mAutor = autor;
}

void SelfHelpBook::printInfo() const
{
	std::cout << "-----------------------------------\n";
	std::cout << "Id: " << Book::getSerialNum() << std::endl;
	std::cout << "Advisor's name: " << Advisor::getName() << std::endl;
	std::cout << "Advisor's subject: " << Advisor::getSubject().size() << std::endl;
	for (std::string str : Advisor::getSubject())
	{
		std::cout << str << " ";
	}
	std::cout << std::endl;
	std::cout << "Autor: " << getAutor() << std::endl;
	std::cout << "-----------------------------------\n";


}
