#include "Patient.h"

Patient::Patient()
{
	this->visit = 0;
}

Patient::Patient(const char* nameP, const Date& dateBDP, const int visitP)
{
	strcpy_s(this->patientName, MAX_NAME_SIZE + 1, nameP);
	this->dateBD = dateBDP;
	this->visit = visitP;
}

const char* Patient::getName() const
{
	return this->patientName;
}

Date Patient::getDateBD() const
{
	return this->dateBD;
}

int Patient::getVisit() const
{
	return this->visit;
}

void Patient::print() const
{
	std::cout << "Name: " << patientName << std::endl;

	std::cout << "Date of birthday: ";
	dateBD.printDate();
	std::cout<< std::endl;

	std::cout << "Visited: " << visit << std::endl;
}
