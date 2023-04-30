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

const std::string Value::getValueNull() const
{
	return "null";
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

void Value::setValueInteger(bool newValue)
{
	fValueBool = new bool(newValue);
	fType = Type::eIntType;
}

void Value::setNull()
{
	fNullValue = "null";
	fType = Type::eNullType;
}



Field::Field(const std::string& name, const Value& val)
{
	fFieldName = name;
	value = val;
}

const std::string Field::getFieldName() const
{
	return fFieldName;
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
	else if (value.getType() == Value::Type::eNullType) {
		result = "null";
	}
	return result;
}

void Field::setFieldName(const std::string newName)
{
	fFieldName = newName;
}

void Field::setValue(const Value newValue)
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
	std::cout<< "\"" << fFieldName << "\" : " << getValueAsString();
}





Array::Array(const std::string& name)
{
	fArrayName = name;
}

const std::string Array::getArrayName() const
{
	return fArrayName;
}

void Array::setArrayName(std::string newArrayName)
{
	fArrayName = newArrayName;
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

const std::string Object::getObjectName() const
{
	return fObjectName;
}

void Object::setObjectName(std::string newObjectName)
{
	fObjectName = newObjectName;
}

void Object::print()
{
	std::cout<< "\"" << fObjectName << "\" : {" ;
	//printim vytreshnistta na obekta
	std::cout << " }";
}





void JSONElement::addElement(JSONElement* newElement)
{
	elements.push_back(newElement);
}
