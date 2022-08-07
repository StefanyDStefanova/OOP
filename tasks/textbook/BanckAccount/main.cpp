#include "BanckAccount.h"

int main()
{
	BanckAccount b;
	b.importMoney(20.99);
	b.print();
	b.withdrowMoney(5.09);
	b.print();

	return 0;
}