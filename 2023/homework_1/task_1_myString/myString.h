#ifndef __MY_STRING
#define __MY_STRING

#include <iostream>
#include <cstring> 
#include <stdexcept>
#include <fstream>

class MyString
{
private:
	size_t lenght;
	char* str;

	void copy(const MyString& other);
	void copyHelper(const char* other);
	void erase();

public:
	MyString();
	MyString(const MyString& other);
	MyString(const char* other);
	MyString& operator=(const MyString& other);
	~MyString();

	char& front(); 
	char& back(); 
	char& operator[](std::size_t index);

	bool empty() const;
	std::size_t size() const;
	std::size_t capacity() const;

	void clear();
	void pop_back();
	void push_back(char ch);

	const char* c_str() const;

	MyString& operator+=(const MyString& other);
	MyString operator+(const MyString& other) const;
	bool operator==(const MyString& other) const;
	bool operator<(const MyString& other) const;
	bool operator>(const MyString& other) const;
	bool operator<=(const MyString& other) const;
	bool operator>=(const MyString& other) const;

	friend std::ostream& operator<<(std::ostream& out, const MyString& string);
	friend std::istream& operator>>(std::istream& out, MyString& string);
};


std::ostream& operator<<(std::ostream& os, const MyString& string) {
	os << string.c_str();
	return os;
}

std::istream& operator>>(std::istream& out, MyString& string) {
	char tmp;
	char* buffer = new char[255];
	int i = 0;
	while (out.get(tmp) && !isspace(tmp))
		buffer[i++] = tmp;

	buffer[i] = '\0';

	string = MyString(buffer);

	delete[] buffer;

	return out;
}


#endif // !__MY_STRING
