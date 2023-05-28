#include "Utilities.h"


bool Utilities::isInteger(std::string data)
{
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return false;
	}
	return true;
}

bool Utilities::isDouble(std::string data)
{
	size_t position = data.find(",");

	for (size_t i = 0; i < position; i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return false;
	}

	for (size_t i = position + 1; i < data.length(); i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return false;
	}

	return true;
}

const std::string WHITESPACE = " \n\r\t\f\v";

std::string Utilities::ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string Utilities::rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string Utilities::trim(const std::string& s) {
	return rtrim(ltrim(s));
}


std::vector<std::string> Utilities::splitString(const std::string str, const char* delimiters)
{
	std::vector<std::string> tokensVector;
	char* buff = const_cast<char*>(str.c_str());
	char* token = std::strtok(buff, delimiters);

	while (token)
	{
		tokensVector.push_back(token);

		token = std::strtok(nullptr, delimiters);
	}

	return tokensVector;
}

std::string Utilities::getValueBetweenQuotes(std::string line)
{
	std::string data = "";
	line = Utilities::trim(line);
	size_t startPos = line.find("\"");
	if (startPos != std::string::npos)
	{
		size_t i = startPos + 1;
		while (i < line.length() && line[i] != '\"')
		{
			data += line[i];
			i++;
		}
	}

	return data;
}