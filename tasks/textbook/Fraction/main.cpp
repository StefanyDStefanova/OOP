#include "Fraction.h"

int main()
{
	int a, b;
	do
	{
		std::cin >> a >> b;
	} while (b == 0);

	Fraction fr(a,b);

	if (isFractin(fr))
	{
		std::cout << a << " not divisible by " << b << std::endl;
	}
	else 
	{
		std::cout << a << " divisible by " << b << std::endl;
	}

	return 0;
}