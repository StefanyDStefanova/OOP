#include <iostream>

const int sizeMax = 20;

struct Person
{
	char firstName[25];
	char lastName[25];
};

struct Client
{
	Person name;
	double banckAccount;
};

void initPerson(Person p)
{
	std::cout << "First name: ";
	std::cin >> p.firstName;
	std::cout << "Last name: ";
	std::cin>> p.firstName;
}

void initClient(Client c)
{
	std::cout << "Name: ";
	initPerson(c.name);
	std::cin >> c.banckAccount;
}

void printInfoPerson(const Person& namePerson)
{
	std::cout << "First name is: " << namePerson.firstName << " and second: " << namePerson.lastName;
}

void printInfoClient(const Client& banckAcc)
{
	std::cout << "You ";
	printInfoPerson(banckAcc.name);
	std::cout << " have: " << banckAcc.banckAccount;
}

int main() 
{
	int n;
	std::cin >> n;

	Client a[sizeMax];

	for (int i = 0; i < n; i++)
	{
		initClient(a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		printInfoClient(a[i]);
	}

	double obligations=0;

	for (int i = 0; i < n; i++)
	{
		obligations += a[i].banckAccount;
	}
	return 0;
}