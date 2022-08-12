#include "Triangle_hierarchy.h"

int main()
{

	Triangle t1;
	t1.init(2, 3, 4);
	t1.print();

	std::cout << t1.perimeter() << "   " << t1.area()<<std::endl;

	RightTriangle rt1;
	rt1.init(6, 10, 8);
	rt1.print();

	std::cout << rt1.perimeter() << "   " << rt1.area() << std::endl;

	IsoscelesTriangle it1;
	it1.init(5, 4, 5);
	it1.print();

	std::cout << it1.perimeter() << "   " << it1.area() << std::endl;

	return 0;
}