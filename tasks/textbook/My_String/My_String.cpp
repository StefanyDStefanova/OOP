#include "My_String.h"

char* String::dynCopy(const char* other, size_t capacity) const
{
	char* result = new char[capacity + 1];
	strcpy_s(result,capacity+1, mData);
	return result;
}

void String::resize(size_t capacity)
{
	char* result = mData;
	mData = new char[capacity + 1];
	strcpy_s(mData,capacity+1, result);
	delete[] result;
}

String::String()
{
	this->mCapacity = DEFAULT_CAPACITY;
	this->mData = new char[mCapacity+1];
	this->mData[0] = 0;
}

String::String(const char* other):mCapacity(DEFAULT_CAPACITY)
{
	size_t strSize = strlen(other);

	while ((mCapacity * 3) / 4 < strSize)
	{
		mCapacity *= 2;
	}
	mData = dynCopy(other, mCapacity);
}

String::String(const String& other)
{
	this->mCapacity = other.mCapacity;
	this->mData = dynCopy(other.mData, other.mCapacity);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		delete[]mData;
		this->mCapacity = other.mCapacity;
		this->mData = dynCopy(other.mData, other.mCapacity);
	}
	return *this;
}

String::~String()
{
	delete[]mData;
}

bool String::isEmpty() const
{
	//return strlen(mData)==0;
	return getsize() == 0;
}

void String::erase()
{
	if (this->mCapacity != DEFAULT_CAPACITY)
	{
		delete[]mData;
		this->mCapacity = DEFAULT_CAPACITY;
		this->mData = new char[this->mCapacity + 1];
	}
	else
	{
		this->mData[0] = 0;
	}
}

void String::swap(String& other)
{
	std::swap(this->mCapacity, other.mCapacity);
	char* temp = this->mData;
	this->mData = other.mData;
	other.mData = temp;
}

size_t String::getCapacity() const
{
	return this->mCapacity;
}

size_t String::getsize() const
{
	return strlen(this->mData);
}

void String::setData(const char* other)
{
	this->mData = dynCopy(other, mCapacity);
}

void String::setCapasity(const size_t other)
{
	this->mCapacity = other;
}

String* String::substr(size_t start, size_t end) const
{
	String* result = new String();
	size_t size = end - start;
	while ((result->mCapacity * 3) / 4 < size)
	{
		result->mCapacity *= 2;
	}

	size_t index = 0;
	for (size_t i = start; i < end; i++)
	{
		result->mData[index++] = this->mData[i];
	}
	result->mData[index] = 0;

	return result;
}

String& String::operator+(const String& other) const
{
	String* result = new String(*this);
	return result->append(other);
}

String& String::operator+=(const String& other)
{
	return this->append(other);
}

char String::operator[](size_t index) const
{
	if (index > this->getsize())
	{
		throw "Index out of bounds";
	}
	return this->mData[index];
}

char& String::operator[](size_t index)
{
	if (index >= this->getsize())
	{
		throw "Index out of bounds";
	}

	return this->mData[index];
}

bool String::operator==(const String& other) const
{
	return this->mCapacity == other.mCapacity && strcmp(this->mData, other.mData);
}

bool String::operator!=(const String& other) const
{
	return !operator==(other);
}

void String::print() const
{
	std::cout << this->mCapacity << " " << mData << std::endl;

}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.mCapacity << ' ' << str.mData;
	return out;
}

std::istream& operator>>(std::istream& in, const String& str)
{
	in >> str.mData;
	return in;
}
