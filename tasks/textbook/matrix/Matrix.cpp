#include "Matrix.h"

int** Matrix::allocateMemory(size_t size) const
{
	int** matrix = new int* [size];
	for (int i = 0; i < size; i++)
	{
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			matrix[i][j]=0;
		}
	}
	return matrix;
}

void Matrix::del()
{
	for (int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::copy(const Matrix& other)
{
	this->size = other.size;
	this->matrix = allocateMemory(other.size);
	copyValue(other.matrix);
}

void Matrix::copyValue(int** matrixP)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			this->matrix[i][j] = matrixP[i][j];
		}
	}
}

Matrix::Matrix()
{
	this->size = 3;
	this->matrix = allocateMemory(size);
}

Matrix::Matrix(const int** matrixP, size_t sizeP)
{ 
	this->size = sizeP;
	this->matrix = allocateMemory(size);
	copyValue(matrix);
	
}

Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

Matrix::~Matrix()
{
	del();
}

int** Matrix::getMatrix() const
{
	return matrix;
}

size_t Matrix::getSize() const
{
	return size;
}

int Matrix::getAt(size_t i, size_t j) const
{
	if (i >= size || j >= size || i < 0 || j < 0)
	{
		throw "Invalid index!";
	}
	return matrix[i][j];
}

Matrix Matrix::add(const Matrix& other) const
{
	if (this->size != other.size)
	{
		throw "Invalid matrix addition";
	}
	size_t sumSize = other.size;
	int** sumMatrix = allocateMemory(sumSize);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sumMatrix[i][j] = matrix[i][j] + other.matrix[i][j];
		}
	}
	return new Matrix(sumSize, sumMatrix);
}

void Matrix::print() const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j];
		}
	}
}
