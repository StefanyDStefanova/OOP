#include <iostream>
#include "myString.h"
#include "Book.h"

int main()
{
	MyString first;

	/*MyString second("aa");

	std::cout << "Second string is: " << second << std::endl;

	std::cout << "First is empty: " << first.empty() << std::endl;

	first.push_back('a');

	std::cout << "First is empty after add elem: " << first.empty() << std::endl;

	first.pop_back();

	std::cout << "First is empty after pop elem: " << first.empty() << std::endl;

	second.push_back('b');
	second.push_back('c');
	second.push_back('d');

	std::cout << "Second front elem: " << second.front() << "Second back elem: " << second.back() << std::endl;

	std::cout << "Size: " << second.size() << " Capacity: " << second.capacity() << std::endl;

	std::cout << "Function c_str: " << second.c_str() << std::endl;

	first.push_back('a');
	first.push_back('a');
	first.push_back('b');
	first.push_back('c');
	first.push_back('d');

	std::cout << "== " << (first == second) << std::endl;
	std::cout << "< " << (first < second) << std::endl;
	first.pop_back();
	std::cout << "> " << (first > second) << std::endl;
	std::cout << "<= " << (first <= second) << std::endl;
	std::cout << ">= " << (first >= second) << std::endl;*/

	Book b("neshto","zaglavie","avtor",5);

	return 0;
}