#ifndef __RAT
#define __RAT

#include <iostream>
#include <math.h>

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(a, a % b);
}

class Rat
{
private:
	int numerator;
	int denominator;

public:
	Rat(int numeratorP = 0, int denominatorP = 1);
	Rat(const Rat& other);

	Rat sum(const Rat& other)const;
	Rat mult(const Rat& other)const;
	Rat sub(const Rat& other)const;
	Rat div(const Rat& other)const;

	void print() const;

	int getNumerator() const;
	int getDenominator() const;

	void setNumerator(int numeratorP);
	void setDenominator(int denominatorP);

};

Rat operator+(const Rat& obj1, const Rat& obj2);
Rat operator*(const Rat& obj1, const Rat& obj2);
Rat operator-(const Rat& obj1, const Rat& obj2);
Rat operator/(const Rat& obj1, const Rat& obj2);

#endif // !__RAT
