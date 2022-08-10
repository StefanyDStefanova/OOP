#ifndef __MY_STRING
#define __MY_STRING

#define DEFAULT_CAPACITY 8

#include <iostream>
#include <cstring>


class String
{
private:
	char* mData; // ��������� ���
	size_t mCapacity; // ���������� �� ����(������)

	char* dynCopy(const char* other, size_t capacity) const;
	void resize(size_t capacity);

public:
	String();
	String(const char* other);
	String(const String& other);
	String& operator=(const String& other);

	~String();

	bool isEmpty()const;	 // ��������� ���� ���� � ������(�.�.���� ��� ������� 0)

	void erase();	 // �������� ���� � ������ �������� �� ���������� �� � ���� �� ������������(���� �� � 8 �������)
	void swap(String& other); // ������� ������������ �� ������� ��� � ���� other

	size_t getCapacity() const;
	size_t getsize() const; //����� ��������� �� ����

	void setData(const char*);
	void setCapasity(const size_t);

	String& append(const String& other); // ����������� ������� ��� � ���� other
	String& append(const char* other); // ������ ���� ������� �����
	void pushBack(char c); // ������ ������ 'c' � ���� �� ����

	String* substr(size_t start, size_t end) const; // ����� ������������ ����� ��� ���������� ������� �� ������� ���, �������� �� ������� start � ��������� �� ������� end - 1
	
	String& operator+(const String& other)const; // -����� ��� ���, ����� ������������ ������������ �� ������� � ���� other
	String& operator+=(const String& other); // -����� ��������� ��� ������� ���, ���� ����� ���� ����� ������������ � ���� other
	char operator[](size_t index)const; // -����� ����� �� �������� �� ������� index
	char& operator[](size_t index); // -����� ��������� ��� �������� �� ������� index
	bool operator==(const String& other)const; // -��������� �������������� ���� ����� ���� �� �������
	bool operator!=(const String& other)const; // -��������� �������������� ���� ����� ���� �� ��������

	friend std::ostream& operator << (std::ostream& out, const String& str);// -���������� �������, ����� ������� ���� � �����
	friend std::istream& operator >> (std::istream& in, const String& str);

	void print() const;

};

#endif // !__MY_STRING
