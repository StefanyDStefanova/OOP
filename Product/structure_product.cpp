#include <iostream>

struct Product
{
	char discription[32];	//opisanie na izdelie
	int partNum;		//nomer na izdelieto
	double cost;		//cena na izdelieto
};


int main() 
{
	Product p1 = { "screw-driver", 456, 5.50 },
		p2 = { "hammer",324,8.20 };

	std::cout << p1.discription << " " << p1.partNum << " " << p1.cost<< std::endl;
	std::cout << p2.discription << " " << p2.partNum << " " << p2.cost << std::endl;

	Product P[10];
	for (int i = 0; i < 10; i++) 
	{
		strcpy(P[i].discription, "");
		P[i].partNum = 0;
		P[i].cost = 0.0;
	}

	Product PR[5];
	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Product num:" << i+1 << " -> ";
		std::cin >> PR[i].discription;
		std::cin >> PR[i].partNum;
		std::cin >> PR[i].cost;
		std::cout<<std::endl;
	}
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Product num:" << i+1 << " -> ";
		std::cout << PR[i].discription<<" ";
		std::cout << PR[i].partNum<<" ";
		std::cout << PR[i].cost<<" ";
		std::cout << std::endl;
	}

	return 0;
}