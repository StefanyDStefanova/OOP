#ifndef __JSON_PARCER
#define __JSON_PARCER

#include "json_elements.h"

#include <fstream>
#include <iostream>
#include <string>
#include "Utilities.h"


class JSONParcer
{
private:
	Object*		fRootElement;
	std::string fCurrentOpenFileName;

private:
	void readRecursiveNewElements(std::ifstream& in, JSONElement* currentElement);

	void setValue(std::string data, Value& v);

	void printHelpFunc();
	void addMultipleFields(std::string line, JSONElement* newElement, JSONElement* currentElement);

public:
	void readFromFile(const std::string& fileName);

	void writeToFile(const std::string& fileName);

	void performingOperations();

	void save();
	void saveAs(const std::string& path);



};


#endif // !__JSON_PARCER


