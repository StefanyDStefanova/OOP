#include "FMITeachAssistent.h"
#include "SelfHelpBook.h"

int main()
{
	std::string name("Georgi");
	std::string name2("Georgi2");


	std::vector<std::string> subjectsHeTeaches;
	subjectsHeTeaches.push_back("OOP");
	subjectsHeTeaches.push_back("SDP");

	std::vector<std::string> subjectsHeAdvisor;
	subjectsHeAdvisor.push_back("EAI");
	subjectsHeAdvisor.push_back("DSTR");


	FmiTeachAssistent Georgi(name, 12345678, subjectsHeTeaches, 98755, name2, subjectsHeAdvisor, 5);

	Georgi.printInfo();
	return 0;
}