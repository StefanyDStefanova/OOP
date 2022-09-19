#ifndef __WORKER
#define __WORKER

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>


const int MAX_SIZE=25;

class Worker
{
protected:
	char* mName;
	double mSalary;


public:
	Worker(const char* name= " ", const double salary=0.0);
	Worker(const Worker& other);
	Worker& operator=(const Worker& other);

	~Worker();

	double getSalary() const;

	void print() const;
};

class HourlyWorker :public Worker
{
private:
	int mHours;
	char* mKindWork;

public:
	HourlyWorker(const char* name = " ", const double salary = 0.0, const char* kindWork = " ",const int hours=0);
	HourlyWorker(const HourlyWorker& other);
	HourlyWorker& operator=(const HourlyWorker& other);

	~HourlyWorker();

	double WeekSalary()const;

	void print() const;
};

class SalariedWorker:public Worker
{
private:
	char* mWork;
	int mHours;

public:
	SalariedWorker(const char* name = " ", const double salary = 0.0, const char* work = " ", const int hours = 0);
	SalariedWorker(const SalariedWorker& other);
	SalariedWorker& operator= (const SalariedWorker & other);

	~SalariedWorker();

	double weekSalary() const;

	void print() const;
};

void createHourlyWorkerArray(int m, HourlyWorker**& arr);
void printHourlyWorkerArray(int n, HourlyWorker** arr);
void sortHourlyWorkerArray(int n, HourlyWorker** arr);
void deleteHourlyWorkerArray(int n, HourlyWorker** arr);


void createSalariedWorkerArray(int m, SalariedWorker**& arr);
void printSalariedWorkerArray(int m, SalariedWorker** arr);
void sortSalariedWorkerArray(int m, SalariedWorker** arr);
void deleteSalariedWorkerArray(int m, SalariedWorker** arr);


#endif // !__WORKER
