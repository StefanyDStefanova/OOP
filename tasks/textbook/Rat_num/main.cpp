#include "Rat_num.h"

int main()
{
	int a, b;
	std::cin >> a >> b;
	Rat r(a, b);

	int c, d;
	do
	{
		std::cin >> c >> d;
	} while (c == 0 || d == 0);
	Rat s(c, d);

	Rat sum = r + s;
	Rat sub = r - s;
	Rat mult = r * s;
	Rat div = r / s;

	r.print();
	std::cout << " + ";
	s.print();
	std::cout << " = ";
	sum.print();
	std::cout << std::endl;

	r.print();
	std::cout << " - ";
	s.print();
	std::cout << " = ";
	sub.print();
	std::cout << std::endl;

	r.print();
	std::cout << " * ";
	s.print();
	std::cout << " = ";
	mult.print();
	std::cout << std::endl;

	r.print();
	std::cout << " / ";
	s.print();
	std::cout << " = ";
	div.print();
	std::cout << std::endl;

	return 0;
}