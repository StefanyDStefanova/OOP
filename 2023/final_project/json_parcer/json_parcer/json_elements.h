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
	void searchElemWithKey(const std::string& key);

	int searchElemWithPath(const std::string& path); // return postition
	void setElem(const std::string& path, const std::string& newElem);
	void createNewElem(const std::string& path, const std::string& newElem);

	void deleteElem(const std::string& path);

	void moveElem(const std::string& pathFrom, const std::string& pathTo);

	void save(const std::string& path);
	void saveAs(const std::string& fileNme, const std::string& path);

	virtual JSONElement* clone() = 0;

	virtual void writeToStream(std::ostream&) = 0;
	virtual void loadFromStream(std::istream&) = 0;

	virtual void print() = 0;
};

std::istream& operator>> (std::istream& in, std::vector<JSONElement*>& data);
std::ostream& operator<< (std::ostream& out, const std::vector<JSONElement*>& data);



class Field : public JSONElement
{
private:
	Value value;

public:
	Field(const std::string& name, const Value& val);

	std::string getValueAsString() const;
	void setValue(const Value& newValue);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);


	void print();
};

class Array : public JSONElement
{
public:
	Array(const std::string& name);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	
	void print();
};

class Object : public JSONElement
{
public:
	Object(const std::string& name);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};

#endif // !__JSON_ELEMENTS
