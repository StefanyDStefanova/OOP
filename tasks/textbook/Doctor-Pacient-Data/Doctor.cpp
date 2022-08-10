#include "Doctor.h"

#include<cstring>

Doctor::Doctor(char* doctorNameP)
{
	strcpy(doctorName, doctorNameP);
	this->patientRegistered = 0;
}

const char* Doctor::getDoctorName() const
{
	return this->doctorName;
}

const Patient* Doctor::getPatients() const
{
	return this->patientsList;
}

int Doctor::getPatientRegistered() const
{
	return patientRegistered;
}

void Doctor::registeredPatient(const Patient& patients)
{
	this->patientsList[this->patientRegistered] = patients;
	this->patientRegistered++;
}

double Doctor::averageOfVisit() const
{
	int totalVisited = 0;
	for (int i = 0; i < patientRegistered; i++)
	{
		totalVisited += patientsList[i].getVisit();
	}
	if (patientRegistered != 0)
	{
		return (double(totalVisited) / patientRegistered);
	}
	return 0;
}

Patient Doctor::printUpper(int limit) const
{
	for (int i = 0; i < patientRegistered; i++)
	{
		if (patientsList[i].getVisit() > limit)
		{
			//std::cout << "Patient " << patientsList[i].getName() << " have mor then limit visits." << std::endl;
			patientsList[i].print();
		}
	}
}

