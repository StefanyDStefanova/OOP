#ifndef __BANCK_ACCOUNT
#define __BANCK_ACCOUNT

#include <iostream>
#include <cstring>

const int MAX_NAME = 23;
const int MAX_NUM = 16;

class BanckAccount
{
private:
	char nameCustomer[MAX_NAME];
	char numAccount[MAX_NUM];
	double amountAvailable;

public:
	BanckAccount(const char* = " ", const char* = "0", double = 0.0);

	void importMoney(const double);
	void withdrowMoney(const double);

	void print() const;
};

#endif // !__BANCK_ACCOUNT
