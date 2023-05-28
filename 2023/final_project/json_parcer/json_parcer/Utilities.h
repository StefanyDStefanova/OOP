#ifndef __UTILITIES
#define __UTILITIES

#include <string>
#include <iostream>
#include <vector>


class Utilities
{
public:
	static bool isInteger(std::string data);
	static bool isDouble(std::string data);

	static std::string ltrim(const std::string& s);
	static std::string rtrim(const std::string& s);
	static std::string trim(const std::string& s);

	static std::vector<std::string> splitString(const std::string str, const char* delimiters);

	static std::string getValueBetweenQuotes(std::string line);

};

#endif // !__UTILITIES
