#include "MyString.h"

void MyString::copy(const MyString& other)
{
	this->copyHelper( other.c_str() );
}

void MyString::copyHelper(const char* other)
{
	size_t len = strlen(other);
	mString = new char[len + 1];

	strcpy(mString, other);
	mLenght = len;

	mString[len] = '\0';
}

void MyString::erase()
{
	delete[] mString;
	mString = nullptr;
	mLenght = 0;
}

void MyString::resize()
{
	char* tmp = new char[mLenght];
	strcpy(tmp, mString);
	
	if (mLenght == capacity())
		mLenght *= 2;
	if (mLenght > capacity())
		mLenght /= 2;

	delete[]mString;
	mString = new char[mLenght];
	strcpy(mString, tmp);

	delete[]tmp;

}

MyString::MyString()
{
	mString = new char[1];
	mString[0] = '\0';
	mLenght = 0;
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


bool MyString::empty() const
{
	return mLenght == 0;
}


const char* MyString::c_str() const
{
	return mString;
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t otherLenght = strlen(other.mString);
	size_t newLenght = mLenght + otherLenght;

	char* tmp = new char[newLenght + 1];

	strcpy(tmp, mString);
	for (size_t i = mLenght; i < newLenght; i++)
	{
		tmp[i] = other.mString[i];
	}

	tmp[newLenght] = '\0';

	delete[] mString;
	mString = tmp;

	return *this; 
}

MyString MyString::operator+(const MyString& other) const
{
	size_t otherLenght = strlen(other.mString);
	size_t newLenght = mLenght + otherLenght;

	char* tmp = new char[newLenght + 1];

	strcpy(tmp, mString);
	for (size_t i = mLenght; i < newLenght; i++)
	{
		tmp[i] = other.mString[i];
	}

	tmp[newLenght] = '\0';

	delete[] mString;
	strcpy(mString, tmp);
	
	return MyString();
}

bool MyString::operator==(const MyString& other) const
{
	return strcmp(mString, other.mString);
}

bool MyString::operator<(const MyString& other) const
{
	/*
	size_t size = mStringlen(word);

		size_t minSize = std::min(mSize, size);

		for (size_t i = 0; i < minSize; i++)
		{
			if (mWord[i] >= word[i])
			{
				return false;
			}
		}
		return true;
	*/
	return strcmp(mString, other.mString);
}

bool MyString::operator>(const MyString& other) const
{
	return strcmp(mString, other.mString);
}

bool MyString::operator<=(const MyString& other) const
{
	return !(*this > other.mString);
}

bool MyString::operator>=(const MyString& other) const
{
	return !(*this < other.mString);
}


char& MyString::front()
{
	if (empty())
		std::cerr << ("mStringing is empty.");

	return mString[0];
}

char& MyString::back()
{
	if(empty())
		std::cerr << ("mStringing is empty.");

	return mString[mLenght - 1];
}

char& MyString::operator[](std::size_t index)
{
	if (empty())
		std::cerr << ("mStringing is empty.");

	if(index>= mLenght)
		std::cerr << ("mStringing does not have that many elements.");

	return mString[index];

}

size_t MyString::size() const
{
	if (empty())
		return 0;

	return mLenght;
}

size_t MyString::capacity() const
{
	size_t cap = 0;
	while (mString[cap] != '\0')
		cap++;

	return cap;
}


void MyString::pop_back()
{
	if (empty())
	{
		std::cerr << "mStringing is empty";
		return;
	}

	mLenght--;
	mString[mLenght] = '\0';

	if (mLenght / 3 > capacity())
		resize();
}

void MyString::push_back(char ch)
{
	
	if (mLenght == capacity())
	{
		resize();
	}

	mString[mLenght++] = ch;
	mString[mLenght] = '\0';
}


std::ostream& operator<<(std::ostream& os, const MyString& mStringing) {
	os << mStringing.c_str();
	return os;
}

std::istream& operator>>(std::istream& out, MyString& mStringing) {
	char tmp;
	char* buffer = new char[255];

	int i = 0;

	while (out.get(tmp))
		buffer[i++] = tmp;

	buffer[i] = '\0';

	mStringing.erase();
	mStringing.copyHelper(buffer);
	delete[] buffer;

	return out;
}



