#include "myString.h"

void MyString::copy(const MyString& other)
{
	size_t len = 0;
	while (other.str[len] != '\0')
		len++;
	
	str = new char[len + 1];

	for (int i = 0; i < len; i++)
	{
		str[i] = other.str[i];
	}

	str[len] = '\0';

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

	str[len] = '\0';
}

MyString::MyString()
{
	str = new char[1];
	str[0] = '\0';
	lenght++;
}

MyString::MyString(const MyString& other)
{
	copy(other);
}

MyString::MyString(const char* other)
{
	copyHelper(other);
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
		throw std::runtime_error("String is empty.");

	return str[0];
}

char& MyString::back()
{
	if(empty())
		throw std::runtime_error("String is empty.");

	return str[lenght - 1];
}

char& MyString::operator[](std::size_t index)
{
	if (empty())
		throw std::runtime_error("String is empty.");

	if(index>=lenght)
		throw std::runtime_error("String does not have that many elements.");

	return str[index];

}

bool MyString::empty() const
{
	return lenght == 1;
}

std::size_t MyString::size() const
{
	return lenght - 1;
}


void MyString::clear()
{
	erase();

	str = new char[1];
	str[0] = '\0';

	lenght = 1;
}

void MyString::pop_back()
{
	lenght--;
	str[lenght] = '\0';
}

