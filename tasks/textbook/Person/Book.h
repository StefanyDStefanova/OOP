#ifndef  __BOOK
#define __BOOK

#include<iostream>
class Book
{
private:
	int mSerialNum;

public:
	Book(int serialNum);

	int getSerialNum() const;
	void setSerialNum(int num);

};
#endif // ! __BOOK
