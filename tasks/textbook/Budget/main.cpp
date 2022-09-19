#include "Budget.h"

int main()
{
	const int numFaculty = 5;
	
	double budgetAmount;

	Budget fac[numFaculty];

	for (int i = 0; i < numFaculty; i++)
	{
		std::cout << "Enther the budget for " << i + 1 << " faculty.";
		std::cin >> budgetAmount;
		fac[i].addBudget(budgetAmount);
	}

	for (int i = 0; i < numFaculty; i++)
	{
		std::cout << fac[i].getFcultyBudget() << std::endl;
	}
	std::cout << fac[0].getUniBudget() << std::endl;
	

	return 0;
}
