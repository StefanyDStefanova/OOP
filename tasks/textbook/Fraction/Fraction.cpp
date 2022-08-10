#include "Fraction.h"

Fraction::Fraction(int nP, int dP)
{
    n = nP;
    d = dP;
}

int Fraction::getN() const
{
    return n;
}

int Fraction::getD() const
{
    return d;
}

bool isFractin(const Fraction& obj)
{
    return obj.n % obj.d != 0;
}
