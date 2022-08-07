#ifndef __LAPTOP
#define __LAPTOP

#include <iostream>
#include <string.h>

class Laptop
{
private:
	char* brand;
	char* model;
	double price;
	double screen;
	char* processor;
	int RAM;
	int battery;

	void del();
	void copy(const char* brandC,const char* modelC,const double priceC,const double screenC,const char* processorC,const int RAMC,const int batteryC);

public:
	Laptop(const char* = " ", const char* = " ", double = 0.0, double = 0.0, const char* = " ", int = 0, int = 0);
	Laptop(const Laptop& other);
	Laptop& operator=(const Laptop& other);

	bool operator>(const Laptop& laptop)const ;
	bool operator<=(const Laptop& laptop)const ;
	bool operator==(const Laptop& laptop)const ;
	bool operator!=(const Laptop& laptop)const ;

	~Laptop();

	void print() const;
};

#endif // !__LAPTOP
