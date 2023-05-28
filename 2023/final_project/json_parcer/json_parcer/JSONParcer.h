#ifndef __JSON_PARCER
#define __JSON_PARCER

#include "json_elements.h"

#include <fstream>
#include <iostream>
#include <string>


class JSONParcer
{
private:
	Object*		fRootElement;
	std::string fCurrentOpenFileName;
public:
	void readFromFile(const std::string& fileName);
	void readRecursiveNewElements(std::ifstream& in, JSONElement* currentElement);

	void writeToFile(const std::string& fileName);

	void performingOperations();

	std::vector<std::string> splitString(const std::string& str, char delimiter);

	void save();
	void saveAs(const std::string& path);

	void printHelpFunc();
};


#endif // __JSON_PARCER


