#include "json_elements.h"
#include <iomanip>

void Value::copy(Value const& other)
{
	fType = other.fType;
	if (other.fValueBool != nullptr)
	{
		fValueBool = new bool(*other.fValueBool);
	}

	else if (other.fValueString != nullptr)
	{
		fValueString = new std::string(*other.fValueString);
	}

	else if (other.fValueInteger != nullptr)
	{
		fValueInteger = new int(*other.fValueInteger);
	}

	else if (other.fValueDouble != nullptr)
	{
		fValueDouble = new double(*other.fValueDouble);
	}

	else
	{
		fNullValue = "null";
	}
}

void Value::erase()
{
	if (fValueBool != nullptr)
	{
		delete fValueBool;
		fValueBool = nullptr;
	}

	else if (fValueString != nullptr)
	{
		delete fValueString;
		fValueString = nullptr;
	}

	else if (fValueInteger != nullptr)
	{
		delete fValueInteger;
		fValueInteger = nullptr;
	}

	else if (fValueDouble != nullptr)
	{
		delete fValueDouble;
		fValueDouble = nullptr;
	}
}

Value::Value(Value const& other)
{
	copy(other);
}

Value& Value::operator=(Value const& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this; 
}

Value::~Value()
{
	erase();
}

const bool Value::getValueBool() const
{
	return *fValueBool;
}

const std::string Value::getValueString() const
{
	return *fValueString;
}

const int Value::getValueInteger() const
{
	return *fValueInteger;
}

const double Value::getValueDouble() const
{
	return *fValueDouble;
}

Value::Type Value::getType() const
{
	return fType;
}

void Value::setValueBool(bool newValue)
{
	fValueBool = new bool(newValue);
	fType = Type::eBoolType;
}

void Value::setValueString(std::string newValue)
{
	fValueString = new std::string(newValue);
	fType = Type::eStringType;
}

void Value::setValueInteger(int newValue)
{
	fValueInteger = new int(newValue);
	fType = Type::eIntType;
}

void Value::setValueDouble(double newValue)
{
	fValueDouble = new double(newValue);
	fType = Type::eDoubleType;
}

void Value::setNull()
{
	fType = Type::eNullType;
}

/*---------------------------------------------------------------------------------------------------*/

Field::Field(const std::string& name, const Value& val)
{
	fName = name;
	fValue = val;
}

std::string Field::getValueAsString() const
{
	std::string result;
	if (fValue.getType() == Value::Type::eBoolType) {
		if (fValue.getValueBool()) {
			result = "true";
		}
		else {
			result = "false";
		}
	}
	else if (fValue.getType() == Value::Type::eStringType) {
		result = fValue.getValueString();
	}
	else if (fValue.getType() == Value::Type::eIntType) {
		result = std::to_string(fValue.getValueInteger());
	}
	else if (fValue.getType() == Value::Type::eDoubleType) {
		result = std::to_string(fValue.getValueDouble());
	}
	else 
	{
		result = "null";
	}
	return result;
}

void Field::setValue(const Value& newValue)
{
	if (newValue.getType() == Value::Type::eBoolType)
	{
		fValue.setValueBool(newValue.getValueBool());
	}

	if (newValue.getType() == Value::Type::eIntType)
	{
		fValue.setValueInteger(newValue.getValueInteger());
	}

	if (newValue.getType() == Value::Type::eStringType)
	{
		fValue.setValueString(newValue.getValueString());
	}

	if (newValue.getType() == Value::Type::eDoubleType)
	{
		fValue.setValueDouble(newValue.getValueDouble());
	}

	else
	{
		fValue.setNull();
	}
}

void Field::print(std::ostream& oStream, size_t numberOfTabs)
{
	oStream << std::setw(numberOfTabs * 4);
	if (fValue.getType() == Value::eNullType || fName == "")
	{
		oStream << getValueAsString() << ",\n";
	}
	else 
	{
		oStream << "\"" << fName << "\" : " << getValueAsString() << ",\n";
	}
}


/*---------------------------------------------------------------------------------------------------*/


Array::Array(const std::string& name)
{
	fName = name;
}

std::string Array::getValueAsString() const
{
	std::string returnValue;
	returnValue = "\"" + fName + "\" : [ ";

	for (JSONElement* child : fElements)
	{
		returnValue += child->getValueAsString();
	}

	returnValue += " ],\n";

	return returnValue;
}

void Array::print(std::ostream& oStream, size_t numberOfTabs)
{
	oStream << std::setw(numberOfTabs * 4) << "\"" << fName << "\" : [ \n" ;

	for (JSONElement* child : fElements) 
	{
		child->print(oStream, numberOfTabs + 1);
	}

	oStream << std::setw(numberOfTabs * 4) << " ],\n";
}


/*---------------------------------------------------------------------------------------------------*/



Object::Object(const std::string& name)
{
	fName = name;
}

std::string Object::getValueAsString() const
{
	std::string returnValue;
	returnValue = "\"" + fName + "\" : { ";

	for (JSONElement* child : fElements)
	{
		returnValue += child->getValueAsString();
	}

	returnValue += " }\n";

	return returnValue;
}

void Object::print(std::ostream& oStream, size_t numberOfTabs)
{
	if (fName.empty()) 
	{
		oStream << std::setw(numberOfTabs * 4) << "{\n";

		for (JSONElement* child : fElements)
		{
			child->print(oStream, numberOfTabs + 1);
		}

		oStream << std::setw(numberOfTabs * 4) << " }\n";
	}
	else
	{
		oStream << std::setw(numberOfTabs * 4) << "\"" << fName << "\" : {\n";

		for (JSONElement* child : fElements)
		{
			child->print(oStream, numberOfTabs + 1);
		}

		oStream << std::setw(numberOfTabs * 4) << " }\n";
	}
}


/*---------------------------------------------------------------------------------------------------*/


JSONElement::~JSONElement()
{
	for (JSONElement* curr : fElements)
	{
		delete curr;
	}
}

void JSONElement::addElement(JSONElement* newElement)
{
	if (newElement) 
	{
		fElements.push_back(newElement);
	}
	else
	{
		throw std::invalid_argument("Can not be created elements.");
	}
}

void JSONElement::searchElemWithKey(const std::string& key)
{
	for (JSONElement* child : fElements) {

		if (child->fName == key)
		{
			std::cout << child->getValueAsString() << ", \n";
		}

		child->searchElemWithKey(key);
	}
}


const std::string JSONElement::getName() const
{
	return fName;
}

void JSONElement::setName(const std::string newName)
{
	fName = newName;
}

JSONElement* JSONElement::searchElemWithPath(const std::vector<std::string>& path)
{
	return this->searchElemWithPathHelper( path, 0 );
}

JSONElement* JSONElement::searchElemWithPathHelper(const std::vector<std::string>& path, size_t index)
{
	if (index == path.size()) {
		return this;
	}

	bool foundPath = false;
	for (JSONElement* child : fElements) {

		if (index < path.size() && child->fName == path[index] )
		{
			foundPath = true;
			return child->searchElemWithPathHelper(path, index + 1);
		}
	}
	if (!foundPath) 
	{
		throw std::invalid_argument("Invalid path.");
	}

	throw std::invalid_argument("Partially invalid path.");
}

void JSONElement::setElem( std::vector<std::string>& path, const std::string& newElem)
{
	std::string endElement = path.back();

	this->deleteElem(path);

	path.pop_back();

	std::string informationForElem = "\"" + endElement + "\": \"" + newElem + "\"";

	createNewElem(path, informationForElem);

}


std::vector<std::string> splitElements(const std::string& str, char delimiter)
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

void setValue(std::string data, Value& v)
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

void JSONElement::createJSONHelper(std::vector<std::string>& newElem, JSONElement* currentElement )
{
	while (!newElem.empty())
	{
		std::string first = newElem.front();
		first = Utilities::trim(first);
		newElem.erase(newElem.begin());

		if (first.empty())
		{
			continue;
		}

		if (first == "}," || first == "]," ||
			first == "}" || first == "]")
		{
			return;
		}

		JSONElement* newElement;

		if (first == "null," || first == "null")
		{
			Value v;

			newElement = new Field("", v);
			currentElement->addElement(newElement);

			continue;
		}

		if (first.find(":") == std::string::npos &&
			first.find("{") == std::string::npos &&
			first.find("[") == std::string::npos)
		{
			//tuk prowerqwam dali ima fildowe koito nqmat int no imat value;
			std::vector<std::string> fields = Utilities::splitString(first, ",");

			Value v;

			for (std::string field : fields) {
				std::string value = Utilities::getValueBetweenQuotes(field);

				setValue(value, v);
				newElement = new Field("", v);
				currentElement->addElement(newElement);
			}

			continue;
		}

		std::string nameElement = Utilities::getValueBetweenQuotes(first);

		size_t position = first.find(":") + 1;
		char nextChar = first[position];

		if (nextChar == ' ')
		{
			nextChar = first[++position];
		}


		if (nextChar == '[')
		{
			newElement = new Array(nameElement);
			createJSONHelper(newElem, newElement);
		}
		else if (nextChar == '{')
		{
			newElement = new Object(nameElement);
			createJSONHelper(newElem, newElement);
		}
		else
		{
			std::vector<std::string> fields = Utilities::splitString(first, ",");

			Value v;

			for (std::string field : fields) {

				std::vector<std::string> singleValueField = Utilities::splitString(field, ": ");
				
				std::string name = Utilities::getValueBetweenQuotes(singleValueField[0]);				
				setValue(singleValueField[1], v);
				
				newElement = new Field(name, v);

				currentElement->addElement(newElement);
			}
			continue;

		}

		currentElement->addElement(newElement);

	}
}



void JSONElement::createNewElem(const std::vector<std::string>& path, const std::string& newElem)
{
	JSONElement* insertInThisElement = this->searchElemWithPath( path );
	std::vector<std::string> element = Utilities::splitString(newElem, ",");

	if (insertInThisElement) 
	{
		createJSONHelper(element, insertInThisElement);
	}


}

void JSONElement::deleteElem( const std::vector<std::string>& path)
{
	std::vector<std::string> parentPath = path;
	std::string nameElement = path.back();
	parentPath.pop_back();
	JSONElement* parentElement = this->searchElemWithPath(parentPath);
	if (parentElement)
	{
		JSONElement* deleteThisElement = parentElement->removeElem(std::vector<std::string>{nameElement});

		delete deleteThisElement;
		deleteThisElement = nullptr;
	}
}

JSONElement* JSONElement::removeElem(const std::vector<std::string>& path)
{
	JSONElement* removedElement = this->searchElemWithPath(path);
	size_t index = 0;
	for (JSONElement* child : fElements)
	{
		if (child == removedElement)
		{
			fElements.erase(fElements.begin() + index);
		}
		++index;
	}
	return removedElement;
}


void JSONElement::moveElem( std::vector<std::string>& pathFrom, std::vector<std::string>& pathTo)
{
	std::string elementForMove = pathFrom.back();
	pathFrom.pop_back();

	JSONElement* parentFrom = this->searchElemWithPath(pathFrom);
	JSONElement* parentTo = this->searchElemWithPath(pathTo);
	JSONElement* elementToMove = parentFrom->removeElem(std::vector<std::string>{elementForMove});
	parentTo->addElement( elementToMove );
}



