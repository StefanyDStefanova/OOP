#ifndef __BOOK
#define __BOOK

#include "myString.h"

class Book
{
private:
	MyString mISBN;
	MyString mTitle;
	MyString mAuthor;
	size_t mSpace;

	void copy(const Book& other);
	void clear();

public:
	Book() = delete;
	Book(const char* ISBN, const char* title, const char* author, size_t space);
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	const char* ISBN() const;
	const char* title() const;
	const char* author() const;
	size_t space() const;

	void clearBook()
	{
		clear();
	}

	const MyString getISNB() const;
	const MyString getTitle() const;
	const MyString getAuthor() const;
	const size_t getSpace() const;

	MyString setISNB(const MyString& newISNB);
	MyString setTitle(const MyString& newTitle);
	MyString setAuthor(const MyString& newAuthor);
	size_t setSpace(const size_t newSpace);

	void print() const;
};



#endif // ! __BOOK
