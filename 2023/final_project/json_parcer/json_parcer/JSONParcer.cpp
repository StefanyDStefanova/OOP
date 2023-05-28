#include "JSONParcer.h"

void JSONParcer::readFromFile(const std::string& fileName)
{
	std::ifstream in(fileName);
	if (!in.good())
	{
		throw std::runtime_error("Failed to open file! - " + fileName);
	}

	std::string line;

	std::getline(in, line);
	if (line != "{")
	{
		in.close();
		throw std::invalid_argument("File is wrong! - " + fileName);
	}

	fCurrentOpenFileName = fileName;
	fRootElement = new Object("");
	try 
	{
		this->readRecursiveNewElements(in, fRootElement);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	in.close();

}


void JSONParcer::setValue(std::string data, Value& v)
{
	if (data == "true" || data == "false")
	{
		v.setValueBool(data == "true");
	}
	else if (Utilities::isInteger(data))
	{
		int number = std::stoi(data);
		v.setValueInteger(number);
	}
	else if (Utilities::isDouble(data))
	{
		double number = std::stod(data);
		v.setValueDouble(number);
	}
	else
	{
		v.setValueString(data);
	}
}

void JSONParcer::addMultipleFields(std::string line, JSONElement* newElement, JSONElement* currentElement)
{
	std::vector<std::string> fields = Utilities::splitString(line, ",");

	Value v;

	for (std::string field : fields) {
		std::string value = Utilities::getValueBetweenQuotes(field);

		this->setValue(value, v);
		newElement = new Field("", v);
		currentElement->addElement(newElement);
	}
}

void JSONParcer::readRecursiveNewElements(std::ifstream& in, JSONElement* currentElement)
{

	std::string line;

	while (std::getline(in, line))
	{
		line = Utilities::trim(line);
		if (line.empty())
		{
			continue;
		}

		if (line == "}," || line == "]," || line == "}" || line == "]")
		{
			return;
		}

		JSONElement* newElement = nullptr;

		if (line == "null," || line == "null")
		{
			Value v;

			newElement = new Field("", v);
			currentElement->addElement(newElement);

			line.clear();
			continue;
		}

		if (line.find(":") == std::string::npos &&
			line.find("{") == std::string::npos &&
			line.find("[") == std::string::npos)
		{
			//tuk prowerqwam dali ima fildowe koito nqmat int no imat value;
			this->addMultipleFields(line, newElement, currentElement);

			continue;
		}

		// tuk izwlichame imeto na poleto nezawisimo ot wida mu
		std::string nameElement = Utilities::getValueBetweenQuotes(line);


		// zapochwame da prowerqwame strojnostta sled : kato pyrwo namirame prawilnata oziciq
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
			
			std::vector<std::string> fields = Utilities::splitString(line, ",");

			Value v;

			for (std::string field : fields) {

				std::vector<std::string> singleValueField = Utilities::splitString(field, ": ");
				
				std::string name = Utilities::getValueBetweenQuotes(singleValueField[0]);
				this->setValue(singleValueField[1], v);
				
				newElement = new Field(name, v);

				currentElement->addElement(newElement);
			}
			continue;

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
		throw std::runtime_error("Failed to open file! - " + fileName);
	}

	out << "{\n";

	fRootElement->print(out, 0);

	out << "}";

	out.close();
	std::cout << "The operation is successful. Write in " + fileName << std::endl;

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
			!fCurrentOpenFileName.empty()	? std::cout << "The file is valid."
											: std::cout << "The file is not valid.";

			std::cout << std::endl;
		}
		
		else if (operation == "open")
		{
			std::string nameFile;
			std::cin >> nameFile;

			fCurrentOpenFileName = nameFile;

			try
			{
				this->readFromFile(nameFile);

				std::cout << "The operation is successful." << std::endl;
			}
			catch (const std::exception& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
				fCurrentOpenFileName = "";
			}
		}

		else if (operation == "close")
		{
			std::cout << "Do you want to close this file? - y/n" << std::endl;

			char option;
			std::cin >> option;
			option == 'y' ? this->save() : delete fRootElement;

			std::cout << "The operation is successful." << std::endl;
		}

		else if (operation == "help")
		{
			this->printHelpFunc();
		}

		else if (operation == "print")
		{
			fRootElement->print(std::cout, 0);
		}

		else if (operation == "search")
		{
			std::string key;
			std::cin >> key;

			try
			{
				std::cout << "[\n";
				fRootElement->searchElemWithKey(key);
				std::cout << "]\n";
			}
			catch (std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		else if (operation == "set")
		{
			std::string path;
			std::cin >> path;
			std::string newValue;
			std::cin >> newValue;

			std::vector<std::string> pathVector = Utilities::splitString(path, "/");

			try
			{
				fRootElement->setElem(pathVector, newValue);
			}
			catch (std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		else if (operation == "create")
		{
			std::string path;
			std::cin >> path;
			std::string newValue;
			std::getline(std::cin, newValue, '\n');

			std::vector<std::string> pathVector = Utilities::splitString(path, "/");

			try 
			{
				fRootElement->createNewElem(pathVector, newValue);
			}
			catch ( std::exception& e) 
			{
				std::cerr << e.what() << std::endl;
			}
		}

		else if (operation == "delete")
		{
			std::string path;
			std::cin >> path;

			std::vector<std::string> pathVector = Utilities::splitString(path, "/");

			try
			{
				fRootElement->deleteElem(pathVector);
			}
			catch (std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		else if (operation == "move")
		{
			std::string from;
			std::cin >> from;
			std::string to;
			std::cin >> to;

			std::vector<std::string> pathFrom = Utilities::splitString(from, "/");
			std::vector<std::string> pathTo = Utilities::splitString(to, "/");

			try
			{
				fRootElement->moveElem(pathFrom, pathTo);
			}
			catch (std::exception& e)
			{
				std::cerr << e.what() << std::endl;
			}
		}

		else if (operation == "save")
		{
			std::string path;
			std::cin >> path;
			this->save();
		}

		else if (operation == "saveas")
		{
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

void JSONParcer::save()
{
	writeToFile(fCurrentOpenFileName);
}

void JSONParcer::saveAs(const std::string& path)
{
	writeToFile(path);
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
