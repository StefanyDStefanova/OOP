#ifndef __LIBRARY
#define __LIBRARY

#include "Book.h"

class Library
{
private:
	Book* m_books;
	size_t m_size;
	size_t m_capacity;

	void copy(const Library& other);
	void erase();

public:
	Library() = delete;
	Library(size_t capacity);
	Library(const Library& other);
	~Library();

	bool empty();
	size_t size() const;

	const Book& operator[](std::size_t index) const;

	bool addNewBook(Book& book);
	void removeBook(const char* ISBN);
	const Book* find(const char* ISBN) const;


};

#endif // !__LIBRARY
