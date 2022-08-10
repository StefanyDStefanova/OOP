#include "Doctor.h"


int main()
{
	Doctor d1 ("Petrov");

	int numOfPatients=0;
	do
	{
		std::cout << "Enter the number of patients";
	} while (numOfPatients < 1 || numOfPatients>MAX_PATIENTS);

	for (int i = 0; i < numOfPatients; i++)
	{
		std::cin.ignore();
		std::cout << "Patient name: ";
		char name[MAX_NAME_SIZE];
		std::cin.getline(name, MAX_NAME_SIZE + 1);

		int day, month, year;
		std::cout << "Enter day, month, year: ";
		std::cin >> day >> month >> year;
		Date date(day, month, year);

		int visit;
		std::cout << "Enter the number of examinations per patient: ";
		std::cin >> visit;

		Patient p(name, date, visit);
		d1.registeredPatient(p);
	}

	std::cout << "Average number of doctor visits: " << d1.averageOfVisit() << std::endl;

	if (numOfPatients > 0)
	{
		d1.printUpper(5);
	}

	return 0;
}