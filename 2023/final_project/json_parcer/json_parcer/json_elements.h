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
	
	Value() : fValueBool(nullptr), fValueString(nullptr), fValueInteger(nullptr), fNullValue("null"), fType(Type::eNullType) {}
	Value(Value const& other);
	Value& operator=(Value const& other);
	~Value();

	const bool getValueBool() const;
	const std::string getValueString() const;
	const int getValueInteger() const;

	Type getType() const;

	void setValueBool(bool newValue);
	void setValueString(std::string newValue);
	void setValueInteger(int newValue);
	void setNull();

};

class JSONElement
{
protected:
	std::vector<JSONElement*> elements;
	std::string fName;


public:
	virtual ~JSONElement();

	void addElement(JSONElement* newElement);

	const std::string getName() const;
	void setName(const std::string newName);


	virtual void print();
};


class Field : public JSONElement
{
private:
	Value value;

public:
	Field(const std::string& name, const Value& val);

	std::string getValueAsString() const;

	void setValue(const Value& newValue);

	void print();
};

class Array : public JSONElement
{
private:
	std::string fArrayName;
	
public:
	Array(const std::string& name);
	
	void print();
};

class Object : public JSONElement
{
private:
	std::string fObjectName;

public:
	Object(const std::string& name);

	void print();
};

#endif // !__JSON_ELEMENTS
