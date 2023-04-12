#include "Library.h"

void Library::copy(const Library& other)
{
	if (other.mCapacity > mCapacity)
	{
		std::cerr << "Capacity is too big.";
		return;
	}

	//mBooks = new Book[other.mSize];
	for (size_t i = 0; i < other.mCapacity; i++)
	{
		mBooks[i] = other.mBooks[i];
	}
	mSize = other.mSize;
	mCapacity = other.mCapacity;
}

void Library::erase()
{

}

Library::Library(size_t capacity)
{
	//mBooks = new Book[capacity];
	mSize = 0;
	mCapacity = capacity;

}

Library::Library(const Library& other)
{
	copy(other);
}

Library& Library::operator=(const Library& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
