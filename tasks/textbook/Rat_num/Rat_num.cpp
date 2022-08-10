#include "Rat_num.h"

Rat::Rat(int numeratorP, int denominatorP)
{
	if (denominatorP == 0)
	{
		std::cout << "improper denominator. It is replaced by 1.";	
		this->numerator = numeratorP;
		this->denominator = 1;
	}
	else
	{
		if (numeratorP == 0)
		{
			this->numerator = 0;
			this->denominator = 1;
		}
		else
		{
			int g = gcd(abs(numeratorP), abs(denominatorP));
			if (numeratorP > 0 && denominatorP > 0 || numeratorP < 0 && denominatorP < 0)
			{
				this->numerator = abs(numeratorP) / g;
				this->denominator = abs(denominatorP) / g;
			}
			else
			{
				this->numerator = -abs(numeratorP);
				this->denominator = abs(denominatorP);
			}
		}
	}
}

Rat::Rat(const Rat& other)
{
	this->numerator = other.numerator;
	this->denominator = other.denominator;
}

Rat Rat::sum(const Rat& other) const
{
	return Rat(this->numerator * other.denominator + this->denominator * other.numerator
		, this->denominator * other.denominator);
}

Rat Rat::mult(const Rat& other)const
{
	return Rat(this->numerator * other.numerator, this->denominator * other.denominator);
}

Rat Rat::sub(const Rat& other) const
{
	return Rat(this->numerator * other.denominator - this->denominator * other.numerator
		, this->denominator * other.denominator);
}

Rat Rat::div(const Rat& other) const
{
	return Rat(this->numerator * other.denominator, this->denominator * other.numerator);
}

void Rat::print() const
{
	std::cout << numerator << std::endl << " -- " << denominator << std::endl;
}

int Rat::getNumerator() const
{
	return this->numerator;
}

int Rat::getDenominator() const
{
	return this->denominator;
}

void Rat::setNumerator(int numeratorP)
{
	this->numerator = numeratorP;
}

void Rat::setDenominator(int denominatorP)
{
	if (denominatorP != 0)
	{
		this->denominator = denominatorP;
	}
	else 
	{
		std::cout << "improper denominator. It is replaced by 1.";
		this->denominator = 1;
	}
}

Rat operator+(const Rat& obj1, const Rat& obj2)
{
	return obj1.sum(obj2);
}

Rat operator*(const Rat& obj1, const Rat& obj2)
{
	return obj1.mult(obj2);
}

Rat operator-(const Rat& obj1, const Rat& obj2)
{
	return obj1.sub(obj2);
}

Rat operator/(const Rat& obj1, const Rat& obj2)
{
	return obj1.div(obj2);
}
