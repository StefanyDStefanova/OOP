#include "JSONParcer.h"


std::string getName(std::string line)
{
	std::string data = "";

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

void JSONParcer::readFromFile(const std::string& fileName)
{
	std::ifstream in(fileName);
	if (!in.good())
	{
		throw std::runtime_error("Failed to open file: " + fileName);
	}

	std::string line;

	std::getline(in, line);
	if (line != "{")
	{
		throw std::invalid_argument("File is wrong!" + fileName);
	}
	fCurrentOpenFileName = fileName;
	fRootElement = new Object("__rootName");
	this->readRecursiveNewElements(in, fRootElement);
	in.close();

}

bool isInteger(std::string data)
{
	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return false;
	}
	return true;
}

bool isDouble(std::string data)
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

std::string ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s) {
	return rtrim(ltrim(s));
}

void setValue(std::string data, Value v)
{
	if (data == "true" || data == "false")
	{
		v.setValueBool(data == "true");
	}
	else if (data[0] == '\"' && data[data.length() - 1] == '\"')
	{
		v.setValueString(data);
	}
	else if (isInteger(data))
	{
		int number = std::stoi(data);
		v.setValueInteger(number);
	}
	else if (isDouble(data))
	{
		double number = std::stod(data);
		v.setValueDouble(number);
	}

}

void JSONParcer::readRecursiveNewElements(std::ifstream& in, JSONElement* currentElement)
{

	std::string line;

	while (std::getline(in, line))
	{
		line = trim(line);
		if (line.empty())
		{
			continue;
		}

		if (line == "}," || line == "]," || line == "}" || line == "]")
		{
			return;
		}

		JSONElement* newElement;

		if (line == "null,")
		{
			Value v;

			newElement = new Field("", v);
			currentElement->addElement(newElement);

			line.clear();
			continue;
		}

		if (line.find("\"") && line.find(":") == std::string::npos)
		{
			//tuk prowerqwam dali ima fildowe koito nqmat int no imat value;

			std::string data = getName(line);
			Value v;

			setValue(data, v);
			continue;
		}

		std::string nameElement = getName(line);

		size_t position = line.find(":") + 1;
		char nextChar = line[position];

		if (nextChar == ' ')
		{
			nextChar = line[++position];
		}


		if (nextChar == '[')
		{
			newElement = new Array(nameElement);
			this->readRecursiveNewElements( in, newElement );
		}
		else if (nextChar == '{')
		{
			newElement = new Object(nameElement);
			this->readRecursiveNewElements( in, newElement );

		}
		else
		{
			std::vector<std::string> fields = this->splitString(line, ',');

			std::string data = line.substr(position, line.length() - position);
			Value v;

			// tuk trqbwa da wleze w wyw fora ako ima takowa splitwane koeto ne e winagi no ne znam kakwo da e usl
			//ili to dori da si e samo edin red shte zapishe neshto w tozi red?

			for (std::string field : fields) {
				std::string nameField = getName(field);

				setValue(data, v);
			}
						
			//setValue(data, v);

			newElement = new Field(nameElement, v);
		}

		currentElement->addElement(newElement);

		line.clear();
	}
}

void JSONParcer::writeToFile(const std::string& fileName)
{
	std::ofstream out(fileName);
	if (!out.good())
	{
		throw std::runtime_error("Failed to open file: " + fileName);
	}

	out << "{\n";

	fRootElement->print(out);

	out << "}";
}


void JSONParcer::performingOperations()
{
	std::cout << std::endl;
	std::cout << "**************************************************************************************" << std::endl;
	std::cout << "*                         What would you like to do:                                 *" << std::endl;
	std::cout << "**************************************************************************************" << std::endl;
	std::cout << std::endl;

	std::string operation;

	while (1)
	{
		std::cin >> operation;
		if (operation.empty())
		{
			continue;
		} 

		if (operation == "validate")
		{
			fRootElement->validate();
		}
		
		else if (operation == "open")
		{
			std::string nameFile;
			std::cin >> nameFile;

			this->readFromFile(nameFile);
		}

		else if (operation == "close")
		{
			std::cout << "Do you want to close this file? - y/n";

			char option;
			std::cin >> option;
			(option == 'y') ? this->save() : delete fRootElement;

		}

		else if (operation == "help")
		{
			this->printHelpFunc();
		}

		else if (operation == "print")
		{
			fRootElement->print(std::cout);
		}

		else if (operation == "search")
		{
			std::string key;
			std::cin >> key;

			fRootElement->searchElemWithKey(key, fRootElement);
		}

		else if (operation == "set")
		{
			std::string path;
			std::cin >> path;
			std::string newValue;
			std::cin >> newValue;

			std::vector<std::string> pathVector = this->splitString(path, '/');

			fRootElement->setElem(pathVector, newValue);
		}

		else if (operation == "create")
		{
			std::string path;
			std::cin >> path;
			std::string newValue;
			std::cin >> newValue;

			std::vector<std::string> pathVector = this->splitString(path, '/');


			fRootElement->createNewElem(pathVector, newValue);
		}

		else if (operation == "delete")
		{
			std::string path;
			std::cin >> path;

			std::vector<std::string> pathVector = this->splitString(path, '/');

			fRootElement->deleteElem(pathVector);
		}

		else if (operation == "move")
		{
			std::string from;
			std::cin >> from;
			std::string to;
			std::cin >> to;

			std::vector<std::string> pathFrom = this->splitString(from, '/');
			std::vector<std::string> pathTo = this->splitString(to, '/');

			fRootElement->moveElem(pathFrom, pathTo);
		}

		else if (operation == "save")
		{
			std::string path;
			std::cin >> path;
			this->save();
		}

		else if (operation == "saveas")
		{
			std::string file;
			std::cin >> file;
			std::string path;
			std::cin >> path;

			this->saveAs(path);
		}
		else if (operation == "exit") 
		{
			break;
		}
	}
}


std::vector<std::string> JSONParcer::splitString(const std::string& str, char delimiter)
{
	std::vector<std::string> tokensVector;
	std::string token;
	std::size_t startPos = 0;
	std::size_t endPos = str.find(delimiter);

	while (endPos != std::string::npos)
	{
		token = str.substr(startPos, endPos - startPos);
		tokensVector.push_back(token);

		startPos = endPos + 1;
		endPos = str.find(delimiter, startPos);
	}

	token = str.substr(startPos);
	tokensVector.push_back(token);

	return tokensVector;
}

void JSONParcer::save()
{
}

void JSONParcer::saveAs(const std::string& path)
{
}

void JSONParcer::printHelpFunc()
{
	std::cout << "\n The following commands are supported: \n";
	std::cout << "    <> open <file> - opens <file>\n";
	std::cout << "    <> close - closes the currently opened file\n";
	std::cout << "    <> save - saves the currently opened file\n";
	std::cout << "    <> saveas <path> - saves the currently opened file with <path>\n";
	std::cout << "    <> help - prints this information\n";
	std::cout << "    <> exit - exits the program\n";
	std::cout << "    <> print - prints all elements in json file\n";
	std::cout << "    <> create <path> <new element> - creates a new element and take in special position relative to <path>\n";
	std::cout << "    <> delete <path> - deletes an element with <path>\n";
	std::cout << "    <> move <from> <to> - moves all element from position to another position\n";
	std::cout << "    <> set <path> <string> - replace the field value with <string> relative to <path> \n";
}
