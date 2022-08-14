#include "Bear.h"
#include "Deer.h"
#include "Zoopark.h"

int main()
{
	Zoo zoo;

	zoo.addAnimal(new Bear("raw meat", 5, 5.5, 5));
	zoo.addAnimal(new Deer("fresh grass", 10, 2));
	zoo.addAnimal(new Bear("raw meat 2", 7, 6, 5));
	zoo.addAnimal(new Deer("fresh grass 2", 3, 4));
	zoo.addAnimal(new Bear("raw meat 3", 2, 15.5, 2));
	zoo.addAnimal(new Deer("fresh grass 3", 4, 1));
	zoo.addAnimal(new Bear("raw meat 4", 15, 25.5, 15));
	zoo.addAnimal(new Deer("fresh grass 4", 3, 20));

	zoo.printTopFive();
	
	return 0;
}