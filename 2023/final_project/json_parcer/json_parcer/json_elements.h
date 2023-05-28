#ifndef __JSON_ELEMENTS
#define __JSON_ELEMENTS

#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Utilities.h"

class Value
{
public:
	enum Type {
		eNullType = -1,
		eBoolType,
		eStringType,
		eIntType,
		eDoubleType,
	};

private:
	bool* fValueBool;
	std::string* fValueString;
	int* fValueInteger;
	double* fValueDouble;
	std::string fNullValue;

	Type fType;

	void copy(Value const& other);
	void erase();

public:
	
	Value() : fValueBool(nullptr), fValueString(nullptr), fValueInteger(nullptr), fValueDouble(nullptr), fNullValue("null"), fType(Type::eNullType) {}
	Value(Value const& other);
	Value& operator=(Value const& other);
	~Value();

	const bool getValueBool() const;
	const std::string getValueString() const;
	const int getValueInteger() const;
	const double getValueDouble() const;

	Type getType() const;

	void setValueBool(bool newValue);
	void setValueString(std::string newValue);
	void setValueInteger(int newValue);
	void setValueDouble(double newValue);
	void setNull();

};

/*---------------------------------------------------------------------------------------------------*/

class JSONElement
{
protected:
	std::vector<JSONElement*> fElements;
	std::string fName;

private: 
	void createJSONHelper(std::vector<std::string>& newElem, JSONElement* currentElement);


public:
	virtual ~JSONElement();

	const std::string getName() const;
	void setName(const std::string newName);

	void addElement(JSONElement* newElement);

	void searchElemWithKey(const std::string& key);

	JSONElement* searchElemWithPath(const std::vector<std::string>& path);
	JSONElement* searchElemWithPathHelper(const std::vector<std::string>& path, size_t index);

	void setElem( std::vector<std::string>& path, const std::string& newElem);
	void createNewElem(const std::vector<std::string>& path, const std::string& newElem);

	void deleteElem(const std::vector<std::string>& path);
	JSONElement* removeElem(const std::vector<std::string>& path);

	void moveElem(std::vector<std::string>& pathFrom, std::vector<std::string>& pathTo);


	virtual std::string getValueAsString() const = 0;

	virtual void print( std::ostream& oStream, size_t numberOfTabs ) = 0;
};

/*---------------------------------------------------------------------------------------------------*/

class Field : public JSONElement
{
private:
	Value fValue;

public:
	Field(const std::string& name, const Value& val);

	virtual std::string getValueAsString() const override;
	void setValue(const Value& newValue);

	virtual void print(std::ostream& oStream, size_t numberOfTabs) override;
};

/*---------------------------------------------------------------------------------------------------*/

class Array : public JSONElement
{
public:
	Array(const std::string& name);

	virtual std::string getValueAsString() const override;

	virtual void print(std::ostream& oStream, size_t numberOfTabs) override;
};

/*---------------------------------------------------------------------------------------------------*/

class Object : public JSONElement
{
public:
	Object(const std::string& name);

	virtual std::string getValueAsString() const override;

	virtual void print(std::ostream& oStream, size_t numberOfTabs) override;
};

#endif // !__JSON_ELEMENTS
