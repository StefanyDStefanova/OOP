#ifndef __FRACTION
#define __FRACTION

#include <iostream>
class Fraction
{
private:
	int n;
	int d;

public:
	Fraction(int nP = 0, int dP = 0);

	int getN() const;
	int getD() const;

	friend bool isFractin(const Fraction& obj);

}

#endif // !__FRACTION