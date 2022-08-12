#include "Cylinder_SquarePyramide.h"

int main()
{
	Cyrlinder c(12.5, 8.0);
	SquarePyramide s(5.2, 10.5);

	if (c.isHight(s))
	{
		std::cout << "The cylinder is taller than pyramide." << std::endl;
	}

	return 0;
}