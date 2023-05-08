#include "json_elements.h"

void Value::copy(Value const& other)
{
	if (other.fValueBool != nullptr)
	{
		fValueBool = new bool(*other.fValueBool);
	}

	if (other.fValueString != nullptr)
	{
		fValueString = new std::string(*other.fValueString);
	}

	if (other.fValueInteger != nullptr)
	{
		fValueInteger = new int(*other.fValueInteger);
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

	if (fValueString != nullptr)
	{
		delete fValueString;
		fValueString = nullptr;
	}

	if (fValueInteger != nullptr)
	{
		delete fValueInteger;
		fValueInteger = nullptr;
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

void Value::setNull()
{
	fType = Type::eNullType;
}



Field::Field(const std::string& name, const Value& val)
{
	fName = name;
	value = val;
}

std::string Field::getValueAsString() const
{
	std::string result;
	if (value.getType() == Value::Type::eBoolType) {
		if (value.getValueBool()) {
			result = "true";
		}
		else {
			result = "false";
		}
	}
	else if (value.getType() == Value::Type::eStringType) {
		result = "\"" + value.getValueString() + "\"";
	}
	else if (value.getType() == Value::Type::eIntType) {
		result = std::to_string(value.getValueInteger());
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
		value.setValueBool(newValue.getValueBool());
	}

	if (newValue.getType() == Value::Type::eIntType)
	{
		value.setValueInteger(newValue.getValueInteger());
	}

	if (newValue.getType() == Value::Type::eStringType)
	{
		value.setValueString(newValue.getValueString());
	}

	else
	{
		value.setNull();
	}
}

void Field::print()
{
	std::cout<< "\"" << fName << "\" : " << getValueAsString();
}





Array::Array(const std::string& name)
{
	fArrayName = name;
}

void Array::print()
{
	std::cout << "\"" << fArrayName << "\" : [ " ;
	// printim vytreshnostta na masiwa
	std::cout << " ]";
}





Object::Object(const std::string& name)
{
	fObjectName = name;
}

void Object::print()
{
	std::cout<< "\"" << fObjectName << "\" : {" ;
	//printim vytreshnistta na obekta
	std::cout << " }";
}





JSONElement::~JSONElement()
{
	for (JSONElement* curr : elements)
	{
		delete curr;
	}
}

void JSONElement::addElement(JSONElement* newElement)
{
	elements.push_back(newElement);
}

const std::string JSONElement::getName() const
{
	return fName;
}

void JSONElement::setName(const std::string newName)
{
	fName = newName;
}
