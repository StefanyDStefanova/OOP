#include "my_vector.h"


int main() 
{
	SVector a1;
	a1.isEmpty();
	a1.pushBack(3);
	a1.pushBack(7);
	a1.print();
	a1.getSize();
	a1.popBack();
	a1.print();

	SVector v;// (8);
		std::cout << v.isEmpty() << "\n";
		v.pushBack(1);
		v.pushBack(2);
		v.pushBack(3);

		std::cout << v.getFirst();
		std::cout << v.getLast();
		std::cout << v.isEmpty() << "\n";
		v.assign(7, 21);

		v.print();
		std::cout << "\n";
		v.pushBack(-21);
		v.pushBack(-31);

		SVector v3(std::move(v));


		v.print();
		std::cout << "\n";
		std::cout << v.getCapacity();

	

	return 0;
}