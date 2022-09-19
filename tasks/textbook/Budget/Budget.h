#ifndef __BUDGET
#define __BUDGET

#include <iostream>
#include <iomanip>

class Budget
{
private:
	static double mUniBudget;
	double mFacultyBudget;

public:
	Budget();

	double getUniBudget() const;
	double getFcultyBudget() const;

	void addBudget(double money);
	void print() const;
};
#endif // !__BUDGET
