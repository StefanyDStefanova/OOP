#ifndef __PATIENT
#define __PATIENT

#include<cstring>

#include "Date.h"

const int MAX_NAME_SIZE = 25;

class Patient
{
private:
	char patientName[MAX_NAME_SIZE+1];
	Date dateBD;
	int visit;


public:
	Patient();
	Patient(const char* nameP, const Date& dateBDP, const int visitP);
	
	const char* getName() const;
	Date getDateBD() const;
	int getVisit() const;

	/*
	void setName(char* nameP);
	void setDateBD(Date dateBDP);
	void setVisit(int visitP);
	*/
	void print() const;

};

#endif // !__PATIENT
