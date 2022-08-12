#include <iostream>
#include <stdlib.h>

const int MAX_SIZE = 100;

template<class T>
class Array
{
private:
	T* mArr;
	int mSize;

	void del();

public:

	Array(int size);
	Array(const Array& other);
	Array& operator=(const Array& other);

	~Array();

	int getSize() const;
	T& operator[](int index);

};

template<class T>
inline void Array<T>::del()
{
	delete[] this->mArr;
}

template<class T>
Array<T>::Array(int size)
{
	if (size > MAX_SIZE)
	{
		throw std::exception("Upper then max size");
		exit(1);
	}

	this->mSize = size;
	this->mArr = new T[size];
}

template<class T>
Array<T>::Array(const Array<T>& other) :mSize(other.mSize)
{
	this->mSize = other.mSize;
	this->mArr = new T[this->mSize + 1];

	for (int i = 0; i < mSize; i++)
	{
		this->mArr[i] = other.mArr[i];
	}
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		del();
		this->mSize = other.mSize;
		this->mArr = new T[mSize + 1];

		for (int i = 0; i < mSize; i++)
		{
			this->mArr[i] = other.mArr[i];
		}
	}

	return *this;
}

template<class T>
Array<T>::~Array()
{
	del();
}

template<class T>
int Array<T>::getSize() const
{
	return this->mSize;
}

template<class T>
T& Array<T>::operator[](int index)
{
	return this->mArr[index];
}

int main()
{
	int size;
	std::cin >> size;

	int num = 9;

	Array<int> a(size);
	for (int i = 0; i < size; i++)
	{
		a[i] = num+1;
		num++;
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << "\n------------------------------------------------------\n";

	Array<char> c(size);
	for (int i = 0; i < size; i++)
	{
		c[i] = (char)(i + 65);
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << c[i] << " ";
	}

	return 0;
}
