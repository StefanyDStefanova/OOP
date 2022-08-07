#include "Laptop.h"
#include <string.h>

void Laptop::del()
{
	delete[] this->brand;
	this->brand = nullptr;

	delete[] this->model;
	this->model = nullptr;

	delete[] this->processor;
	this->processor = nullptr;

}

void Laptop::copy(const char* brandC, const char* modelC, const double priceC, const double screenC, const char* processorC , const int RAMC, const int batteryC)
{
	brand = new char[strlen(brandC)+1];
	strcpy_s(this->brand,  strlen(brandC)+1,brandC);
	model = new char[strlen(modelC) + 1];
	strcpy_s(this->model,  strlen(modelC)+1,modelC);

	price = priceC;
	screen = screenC;
	processor = new char[strlen(processorC) + 1];
	strcpy_s(this->processor,  strlen(processorC)+1,processorC );

	RAM = RAMC;
	battery = batteryC;

}

Laptop::Laptop(const char* brandP, const char* modelP, double priceP, double screenP, const char* processorP, int RAMP, int batteryP)
{
	brand = new char[strlen(brandP) + 1];
	strcpy_s(brand,  strlen(brandP) + 1,brandP);
	model = new char[strlen(modelP) + 1];
	strcpy_s(model,  strlen(modelP) + 1,modelP);
	price = priceP;
	screen = screenP;
	processor = new char[strlen(processorP) + 1];
	strcpy_s(this->processor, strlen(processorP) + 1, processorP);
	RAM = RAMP;
	battery = batteryP;
}

Laptop::Laptop(const Laptop& other)
{
	del();
	copy(other.brand, other.model, other.price, other.screen, other.processor, other.RAM, other.battery);
}

Laptop& Laptop::operator=(const Laptop& other)
{
	if (this != &other)
	{
		del();
		copy(other.brand, other.model, other.price, other.screen, other.processor, other.RAM, other.battery);
	}
	return *this;
}

bool Laptop::operator>(const Laptop& laptop) const
{
	return this->screen>laptop.screen;
}

bool Laptop::operator<=(const Laptop& laptop)const
{
	return !operator>(laptop);
}

bool Laptop::operator==(const Laptop& laptop) const
{
	return this->screen==laptop.screen;
}

bool Laptop::operator!=(const Laptop& laptop) const
{
	return !operator==(laptop);
}

Laptop::~Laptop()
{
	del();
}

void Laptop::print() const
{
	std::cout << "Brand: " << brand << "\n";
	std::cout << "Model: " << model << "\n";
	std::cout << "Price: " << price << "\n";
	std::cout << "Screen: " << screen << "\n";
	std::cout << "Processor: " << processor << "\n";
	std::cout << "RAM: " << RAM << "\n";
	std::cout << "Battery: " << battery << "\n";
}
