#include "Book.h"


Book::Book(int serialNum):mSerialNum(serialNum)
{
}

int Book::getSerialNum() const
{
	return mSerialNum;
}

void Book::setSerialNum(int num)
{
	mSerialNum = num;
}
