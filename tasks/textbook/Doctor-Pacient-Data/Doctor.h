#ifndef __DOCTOR
#define __DOCTOR

#include "Patient.h"

const int MAX_PATIENTS = 200;

class Doctor
{
private:
	char doctorName[MAX_NAME_SIZE];
	Patient patientsList[MAX_PATIENTS];
	int patientRegistered;

public:
	Doctor( char* doctorNameP=nullptr);
	
	const char* getDoctorName() const;
	const Patient* getPatients() const;
	int getPatientRegistered() const;

	//void setDoctorName(char* doctorNameP);
	//void setPatients(Patient* patientsP);
	//void setPatientRegistered(int patientRegisteredP);

	void registeredPatient(const Patient& patients);

	double averageOfVisit() const;
	Patient printUpper(int num)const;


};

#endif // !__DOCTOR
