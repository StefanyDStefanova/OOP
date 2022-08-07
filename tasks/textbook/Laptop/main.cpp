#include "Laptop.h"

int main()
{
	Laptop l1,l2("aa","bb",2000.01,25.0,"lddll jhg jyhf",5,20);
	l1.print();
	l2.print();
	Laptop l3 = l2;
	l3.print();
	std::cout<<l3.operator>(l1);

	return 0;
}