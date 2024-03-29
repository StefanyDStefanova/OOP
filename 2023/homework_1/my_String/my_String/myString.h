#ifndef __MY_STRING
#define __MY_STRING

#include <iostream>
#include <cstring> 
#include <stdexcept>
#include <fstream>

class MyString
{
private:
	size_t mLenght;
	char* mString;

	void copy(const MyString& other);
	void copyHelper(const char* other);
	void erase();

	void resize();

public:
	MyString();
	MyString(const char* other);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();

	char& front(); 
	char& back(); 
	char& operator[](size_t index);

	bool empty() const;
	size_t size() const;
	size_t capacity() const;

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

	void remove()
	{
		erase();
	}
};


#endif // !__MY_STRING