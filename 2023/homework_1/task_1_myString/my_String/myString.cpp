#include "myString.h"

void MyString::copy(const MyString& other)
{
	this->copyHelper( other.c_str() );
}

void MyString::copyHelper(const char* other)
{
	size_t len = 0;
	while (other[len] != '\0')
		len++;

	str = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		str[i] = other[i];
	}
	lenght = len;
	str[len] = '\0';
}

void MyString::erase()
{
	delete[] str;
	str = nullptr;
	lenght = 0;
}

void MyString::resize()
{
}

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	lenght = 0;
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString::MyString(const char* other)
{
	copyHelper(other);
}

const char* MyString::c_str() const
{
	return str;
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}

	return *this;
}

MyString::~MyString()
{
	erase();
}

char& MyString::front()
{
	if (empty())
		std::cerr << ("String is empty.");

	return str[0];
}

char& MyString::back()
{
	if(empty())
		std::cerr << ("String is empty.");

	return str[lenght - 1];
}

char& MyString::operator[](std::size_t index)
{
	if (empty())
		std::cerr << ("String is empty.");

	if(index>=lenght)
		std::cerr << ("String does not have that many elements.");

	return str[index];

}

bool MyString::empty() const
{
	return lenght == 0;
}

std::size_t MyString::size() const
{
	if (empty())
		return 0;

	return lenght;
}

std::size_t MyString::capacity() const
{

	return std::size_t();
}


void MyString::pop_back()
{
	if (empty())
	{
		std::cerr << "String is empty";
		return;
	}

	/*char* tmp = new char[lenght - 1];


	for (int i = 0; i < lenght - 1; i++)
	{
		tmp[i] = str[i];
	}

	lenght--;

	tmp[lenght] = '\0';
	delete[] str;
	str = tmp;
	*/

	lenght--;
	str[lenght] = '\0';
}

void MyString::push_back(char ch)
{
	/*
	char* tmp = new char[lenght + 2];
	

	for (int i = 0; i < lenght; i++)
	{
		tmp[i] = str[i];
	}
	
	tmp[lenght++] = ch;
	tmp[lenght] = '\0';
	delete[] str;
	str = tmp;*/

	if (lenght == capacity())
	{
		resize();
	}

	str[lenght++] = ch;
	str[lenght] = '\0';
}


std::ostream& operator<<(std::ostream& os, const MyString& string) {
	os << string.c_str();
	return os;
}

std::istream& operator>>(std::istream& out, MyString& string) {
	char tmp;
	char* buffer = new char[255];

	int i = 0;

	while (out.get(tmp))
		buffer[i++] = tmp;

	buffer[i] = '\0';

	string.erase();
	string.copyHelper(buffer);
	delete[] buffer;

	return out;
}

