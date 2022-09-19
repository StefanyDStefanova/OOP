#include "my_vector.h"

void SVector::del()
{
	delete[] this->array;
	this->array = nullptr;
}

void SVector::copy(const int* array, const size_t capacity, const size_t size)
{
	this->capacity = capacity;

	this->array = new int[this->capacity];

	this->size = size;
	for (int i = 0; i < this->size; i++)
	{
		this->array[i] = array[i];
	}
}

void SVector::resize()
{
	this->capacity = 2 * this->size;
	int* tempArr = new int[this->capacity];
	for (int i = 0; i < this->capacity; i++)
	{
		tempArr[i] = this->array[i];
	}
	del();
	this->array = tempArr;
}

SVector::SVector(const SVector& other)
{
	copy(other.array, other.capacity, other.size);
}

SVector& SVector::operator=(const SVector& other)
{
	if (this != &other)
	{
		del();
		copy(other.array, other.capacity, other.size);
	}
	return *this;
}

SVector::~SVector()
{
	del();
}

size_t SVector::getCapacity()const
{
	return this->capacity;
}
size_t SVector::getSize() const
{
	return this->size;
}

bool SVector::isEmpty()
{
	return this->size == 0;
}

int SVector::getAt(const int position)
{
	if (position + 1 >= size)
	{
		std::cout << "Incorrect position! \n";
		return -1;
	}
	return this->array[position + 1];
}

const int SVector::getFirst() const
{
	if (array == nullptr)
	{
		std::cout << "Error! \n";
		return -1;
	}
	return this->array[0];
}


int SVector::getLast() const
{
	if (array == nullptr)
	{
		std::cout << "Error! \n";
		return -1;
	}
	return this->array[(this->size) - 1];
}

void SVector::assign(const int n, const int x)
{
	if (array == nullptr || n > this->capacity) 
	{
		return;
	}

	if (n > this->size)
	{
			this->size = n;
	}

	for (int i = 0; i < n; i++)
	{
		this->array[i] = x;
	}
}

void SVector::pushBack(const int element)
{
	if (this->capacity==this->size)
	{
		resize();
	}
	this->size ++;
	this->array[size] = element;
}

void SVector::popBack()
{
	if (isEmpty())
	{
		std::cout << "Error. \n";
		return;
	}
	this->size--;
}

void SVector::removeAt(const int position)
{
	if (position < 0 || position >= size) {
		std::cout << "Error!\n";
		return;
	}
	int spos = position - 1;
	for (int i = spos; i < this->size; i++)
	{
		this->array[i] = this->array[i + 1];
	}
	this->size--;
}

void SVector::print() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->array[i]<<"  ";
	}
}
