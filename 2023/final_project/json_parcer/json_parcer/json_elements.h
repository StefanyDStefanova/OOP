#ifndef __JSON_ELEMENTS
#define __JSON_ELEMENTS

#include <iostream>
#include <string>
#include <vector>

class Value
{
public:
	enum Type {
		eNullType = -1,
		eBoolType,
		eStringType,
		eIntType,
	};

private:
	bool* fValueBool;
	std::string* fValueString;
	int* fValueInteger;
	std::string fNullValue;

	Type fType;

	void copy(Value const& other);
	void erase();

public:
	
	Value() : fValueBool(nullptr), fValueString(nullptr), fValueInteger(nullptr), fNullValue(nullptr), fType(Type::eNullType) {}
	Value(Value const& other);
	Value& operator=(Value const& other);
	~Value();

	const bool getValueBool() const;
	const std::string getValueString() const;
	const int getValueInteger() const;
	const std::string getValueNull() const;
	Type getType() const;

	void setValueBool(bool newValue);
	void setValueString(std::string newValue);
	void setValueInteger(bool newValue);
	void setNull();

};

class JSONElement
{
private:
	std::vector<JSONElement*> elements;

public:
	virtual void print();

	void addElement(JSONElement* newElement);
};


class Field : public JSONElement
{
private:
	std::string fFieldName;
	Value value;

public:
	Field(const std::string& name, const Value& val);

	const std::string getFieldName() const;
	std::string getValueAsString() const;

	void setFieldName(const std::string newName);
	void setValue(const Value newValue);

	void print();
};

class Array : public JSONElement
{
private:
	std::string fArrayName;
	
public:
	Array(const std::string& name);
	
	const std::string getArrayName() const;

	void setArrayName(std::string newArrayName);

	void print();
};

class Object : public JSONElement
{
private:
	std::string fObjectName;

public:
	Object(const std::string& name);

	const std::string getObjectName() const;

	void setObjectName(std::string newObjectName);

	void print();
};

#endif // !__JSON_ELEMENTS
