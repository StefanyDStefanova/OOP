#ifndef __MATRIX
#define __MATRIX

#include <iostream>

class Matrix
{
private:
	int** matrix;
	size_t size;

	int** allocateMemory(size_t size)const;
	void del();
	void copy(const Matrix&);
	void copyValue(int**);

public:
	Matrix();
	Matrix(const int**, size_t );
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& otrer);

	~Matrix();

	int** getMatrix() const;
	size_t getSize() const;

	int getAt(size_t, size_t) const;
	Matrix add(const Matrix&) const;

	void print() const;
};

#endif // !__MATRIX
