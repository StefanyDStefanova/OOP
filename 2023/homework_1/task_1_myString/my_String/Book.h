#ifndef __BOOK
#define __BOOK

#include "myString.h"

class Book
{
private:
	MyString m_ISBN;
	MyString m_title;
	MyString m_author;
	size_t m_space;

	void copy(const Book& other);
	void erase();

public:
	Book() = delete;
	Book(const char* ISBN, const char* title, const char* author, size_t space);
	Book(const Book& other);
	~Book();

	//const char* ISBN() const;
	const MyString& ISBN() const;
	const MyString& title() const;
	const MyString& author() const;
	size_t space() const;
};



#endif // ! __BOOK
