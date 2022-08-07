#include "BanckAccount.h"
#include <stralign.h>

BanckAccount::BanckAccount(const char* cl, const char* n, double a)
{
	strncpy(nameCustomer, cl, MAX_NAME - 1);
	nameCustomer[MAX_NAME - 1] = '\0';
	strncpy(numAccount, n, MAX_NUM - 1);
	numAccount[MAX_NUM - 1] = '\0';
	amountAvailable = a;
}

void BanckAccount::importMoney(const double amount)
{
	if (amount >= 0)
	{
		amountAvailable += amount;
	}
}

void BanckAccount::withdrowMoney(const double amount)
{
	if (amount >= 0 && amount<=amountAvailable)
	{
		amountAvailable -= amount;
	}
}

void BanckAccount::print() const
{
	std::cout << "Name: " << nameCustomer;
	std::cout << "Account: " << numAccount;
	std::cout << "Amount: " << amountAvailable;
}
