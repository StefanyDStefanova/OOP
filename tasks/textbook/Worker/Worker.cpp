#include "Worker.h"

Worker::Worker(const char* name, const double salary)
{
	this->mName = new char [strlen(name)+1];
	strcat_s(this->mName, (strlen(name) + 1), name);

	this->mSalary = salary;
}

Worker::Worker(const Worker& other):mSalary(other.mSalary)
{
	this->mName = new char[strlen(other.mName) + 1];
	strcat_s(this->mName, (strlen(other.mName) + 1), other.mName);
}

Worker& Worker::operator=(const Worker& other)
{
	if (this != &other)
	{
		delete[] this->mName;

		this->mName = new char[strlen(other.mName) + 1];
		strcat_s(this->mName, (strlen(other.mName) + 1), other.mName);

		this->mSalary = other.mSalary;
	}

	return *this;
}

Worker::~Worker()
{
	delete[] this->mName;
}

double Worker::getSalary() const
{
	return this->mSalary;
}

void Worker::print() const
{
	std::cout << "Name: " << mName << " salary: " << mSalary;
}

HourlyWorker::HourlyWorker(const char* name, const double salary, const char* kindWork, const int hours):Worker(name,salary)
{
	this->mKindWork = new char[strlen(kindWork) + 1];
	strcpy_s(this->mKindWork, strlen(kindWork) + 1, kindWork);

	this->mHours = hours;
}

HourlyWorker::HourlyWorker(const HourlyWorker& other):Worker(other.mName,other.mSalary),mHours(other.mHours)
{
	this->mKindWork = new char[strlen(other.mKindWork)+1];
	strcpy_s(this->mKindWork, strlen(other.mKindWork) + 1, other.mKindWork);
}

HourlyWorker& HourlyWorker::operator=(const HourlyWorker& other)
{
	if (this != &other)
	{
		Worker::operator=(other);
		delete[] mKindWork;

		this->mKindWork = new char[strlen(other.mKindWork) + 1];
		strcpy_s(this->mKindWork, strlen(other.mKindWork) + 1, other.mKindWork);

		this->mHours = other.mHours;
	}
	return *this;
}

HourlyWorker::~HourlyWorker()
{
	delete[] mKindWork;
}

double HourlyWorker::WeekSalary() const
{
	if (mHours>41 && mHours<60)
	{
		return 40 * mSalary + (mHours - 40) * 1.5 * mSalary;
	}
	else if (mHours > 60)
	{
		return 40 * mSalary + 20 * 1.5 * mSalary + (mHours - 60) * 2 * mSalary;
	}
	return mHours * mSalary;
}

void HourlyWorker::print() const
{
	std::cout << "Kint of work: " << mKindWork << " hours: " << mHours;
}

SalariedWorker::SalariedWorker(const char* name, const double salary, const char* work, const int hours):Worker(name,salary),mHours(hours)
{
	this->mWork = new char[strlen(work)+1];
	strcpy_s(this->mWork, strlen(work) + 1, work);
}

SalariedWorker::SalariedWorker(const SalariedWorker& other):Worker(other.mName,other.mSalary),mHours(other.mHours)
{
	this->mWork = new char[strlen(other.mWork) + 1];
	strcpy_s(this->mWork, strlen(other.mWork) + 1, other.mWork);
}

SalariedWorker& SalariedWorker::operator=(const SalariedWorker& other)
{
	if (this != &other)
	{
		Worker::operator=(other);

		delete[] this->mWork;
		this->mWork = new char[strlen(other.mWork) + 1];
		strcpy_s(this->mWork, strlen(other.mWork) + 1, other.mWork);

		this->mHours = other.mHours;
	}
	return *this;
}

SalariedWorker::~SalariedWorker()
{
	delete[] mWork;
}

double SalariedWorker::weekSalary() const
{
	return 40*mSalary;
}

void SalariedWorker::print() const
{
	std::cout << "Wokr: " << mWork << " hours: " << mHours;
}

void createHourlyWorkerArray(int m, HourlyWorker**& arr)
{
	arr = new HourlyWorker * [m];
	for (int i = 0; i < m; i++)
	{
		char n[MAX_SIZE];

		std::cout << "Name: ";
		std::cin.getline(n, MAX_SIZE);

		double s;
		std::cout << " hourly wage: ";
		std::cin >> s;

		std::cin.ignore();
		char w[MAX_SIZE];

		std::cout << "\n type of work done: ";
		std::cin.getline(w, MAX_SIZE);

		int h;
		std::cout << "\n Number of hours to work: ";
		std::cin >> h;
		std::cin.ignore();

		arr[i] = new HourlyWorker(n, s, w, h);

	}
}

void printHourlyWorkerArray(int n, HourlyWorker** arr)
{
	std::cout << "List of hourly workers: ";
	for (int i = 0; i < n; i++)
	{
		arr[i]->print();
	}
}

void deleteHourlyWorkerArray(int n, HourlyWorker** arr)
{
	for (int i = 0; i < n; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void createSalariedWorkerArray(int m, SalariedWorker**& arr)
{
	std::cout << "Array of workers: ";

	arr = new SalariedWorker*[m];

	for (int i = 0; i < m; i++)
	{
		char n[MAX_SIZE];
		std::cout << "Name: ";
		std::cin.getline(n, MAX_SIZE);

		double s;
		std::cout << "\n Hourly payment: ";
		std::cin >> s;
		std::cin.ignore();

		char w[MAX_SIZE];
		std::cout << "\n Type of work: ";
		std::cin.getline(w, MAX_SIZE);

		int h;
		std::cout << "\n Hours: ";
		std::cin >> h;
		std::cin.ignore();

		arr[i] = new SalariedWorker(n, s, w, h);
	}
	

}

void printSalariedWorkerArray(int m, SalariedWorker** arr)
{
	std::cout << "\n Array of workers: ";
	for (int i = 0; i < m; i++)
	{
		arr[i]->print();
	}

}

void sortSalariedWorkerArray(int m, SalariedWorker** arr)
{
	for (int i = 0; i < m - 1; i++)
	{
		int l=i; 
		double max = arr[i]->weekSalary();
		for (int j = i + 1; j < m; j++)
		{
			if (arr[j]->weekSalary() > max)
			{
				max = arr[j]->weekSalary();
				l = j;
			}
			SalariedWorker* ptr = arr[i];
			arr[i] = arr[l];
			arr[l] = ptr;
		}
	}
}

void deleteSalariedWorkerArray(int m, SalariedWorker** arr)
{
	for (int i = 0; i < m; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}

void sortHourlyWorkerArray(int n, HourlyWorker** arr)
{
	for (int i = 0; i < n-1; i++)
	{
		int k = i;
		double max = arr[i]->WeekSalary();

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j]->WeekSalary() > max)
			{
				max = arr[j]->WeekSalary();
				k = j;
			}
			HourlyWorker* ptr = arr[i];
			arr[i] = arr[k];
			arr[k] = ptr;
		}
	}
}
