#include "Worker.h"

int main()
{
	int n;
	std::cout << "\n n= ";
	std::cin >> n;
	std::cin.ignore();

	HourlyWorker** hourlyArr = nullptr;
	createHourlyWorkerArray(n, hourlyArr);
	printHourlyWorkerArray(n, hourlyArr);

	int m;
	std::cout << "\n m= ";
	std::cin >> m;
	std::cin.ignore();

	SalariedWorker** salariedArr = nullptr;
	createSalariedWorkerArray(m, salariedArr);
	printSalariedWorkerArray(m, salariedArr);

	sortHourlyWorkerArray(n, hourlyArr);
	printHourlyWorkerArray(n, hourlyArr);

	sortSalariedWorkerArray(m, salariedArr);
	printSalariedWorkerArray(m, salariedArr);

	deleteHourlyWorkerArray(n, hourlyArr);
	deleteSalariedWorkerArray(m, salariedArr);


	return 0;
}