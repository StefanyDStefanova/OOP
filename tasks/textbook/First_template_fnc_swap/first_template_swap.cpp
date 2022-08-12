#include <iostream>

template <class T>
void swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

int main()
{
	std::cout << "INT: " << std::endl;
	int a, b;
	std::cin >> a >> b;
	std::cout << a << " " << b << " SWAP-> ";
	swap(a, b);
	std::cout << a << " " << b << std::endl;


	std::cout << "DOUBLE: " << std::endl;
	double c, d;
	std::cin >> c >> d;
	std::cout << c << " " << d << " SWAP-> ";
	swap(c, d);
	std::cout << c << " " << d << std::endl;


	std::cout << "CHAR: " << std::endl;
	char e, f;
	std::cin >> e >> f;
	std::cout << e <<" " << f << " SWAP-> ";
	swap(e, f);
	std::cout << e << " " << f << std::endl;

	return 0;
}