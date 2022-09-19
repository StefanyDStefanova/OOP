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


	size_t getCapacity()const;				// – връща капациета на вектора
	size_t getSize()const;					// – връща размера на вектора
	bool isEmpty();					// – връща true ако векторът няма елементи и false иначе
	int getAt(const int position); const 
	int getFirst()const;					//– връща първия елемент
	int getLast()const;					//– връща последния елемент
	void assign(const int n,const int x);		//– инициализира вектора с n елемента x
	void pushBack(const int n);				// – слага елемент в края
	void popBack();					//– премахва елемент от края
	void removeAt(const int position);	// – премахва елемент на дадена позиция
	void print()const;
};


#endif 
