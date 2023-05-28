#include <iostream>

#include "JSONParcer.h"


int main()
{

    JSONParcer parser;
    try
    {
        parser.readFromFile("example.txt");
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }

    parser.performingOperations();
   
	return 0;
}