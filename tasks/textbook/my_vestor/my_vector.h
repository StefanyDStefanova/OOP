#ifndef __MY_VECTOR
#define __MY_VECTOR

#include <iostream>
#include <cstring>


class SVector
{
private:
	int* array;
	size_t capacity;
	size_t size;

	void del();
	void copy(const int* array, const size_t capacity, const size_t size);
	void resize();

public:

	SVector() {};
	SVector(const SVector& other);
	SVector& operator=(const SVector& other);
	~SVector();

	/*Vector(const int capacity);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	Vector(Vector && other);
	Vector& operator=(Vector&& other) noexcept;*/


	size_t getCapacity()const;				// � ����� ��������� �� �������
	size_t getSize()const;					// � ����� ������� �� �������
	bool isEmpty();					// � ����� true ��� �������� ���� �������� � false �����
	int getAt(const int position); const 
	int getFirst()const;					//� ����� ������ �������
	int getLast()const;					//� ����� ��������� �������
	void assign(const int n,const int x);		//� ������������ ������� � n �������� x
	void pushBack(const int n);				// � ����� ������� � ����
	void popBack();					//� �������� ������� �� ����
	void removeAt(const int position);	// � �������� ������� �� ������ �������
	void print()const;
};


#endif 
