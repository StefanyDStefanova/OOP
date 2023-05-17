#ifndef __JSON_ELEMENTS
#define __JSON_ELEMENTS

#include <iostream>
#include <string>
#include <vector>

class JSONElement
{
public:
	virtual ~JSONElement() = default;

	void addElement(JSONElement* newElement);
	virtual JSONElement* clone() = 0;

	virtual void writeToStream(std::ostream&) = 0;
	virtual void loadFromStream(std::istream&) = 0;

	virtual void print() = 0;

	void save(const std::string& path);
	void saveAs(const std::string& fileNme, const std::string& path);
};


class BoolData:public JSONElement
{
private:
	bool jsonBoolData;

public:
	BoolData():jsonBoolData(true) {}

	const bool getBoolData() const;
	void setBoolData(const bool newData);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};

class StringData :public JSONElement
{
private:
	std::string jsonStringData;

public:
	StringData() :jsonStringData(" ") {}

	const std::string getStringData() const;
	void setStringData(const std::string newData);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};

class DoubleData :public JSONElement
{
private:
	double jsonDoubleData;

public:
	DoubleData() :jsonDoubleData(0.0) {}

	const double getDoubleData() const;
	void setDoubleData(const double newData);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};

class NullData :public JSONElement
{
private:
	std::string jsonNullData;

public:
	NullData() :jsonNullData("null") {}

	const std::string getNullData() const;
	void setNullData(const std::string newData);

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};



class Array : public JSONElement
{
private:
	std::vector<JSONElement*> jsonArrayData;

public:
	Array() {}

	JSONElement* clone();

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};

struct Field
{
private:
	std::string name;
	JSONElement* jsonElemInField;

public:
	Field() {}
	
	//void creatField(std::string newElem);
	static void changeField(const std::string& newData);
	static Field creatField(const std::string& newElem);

};

class Object : public JSONElement
{
private:
	std::vector<Field> jsonObjectData;

public:
	Object() {}


	JSONElement* clone();

	void deleteElem(const std::string& path);

	void searchElemWithKey(const std::string& key);

	int searchElemWithPath(const std::string& path); // return postition
	void setElem(const std::string& path, const std::string& newData);
	void createNewElem(const std::string& path, const std::string& newElem);

	void moveElem(const std::string& pathFrom, const std::string& pathTo);

	void writeToStream(std::ostream& out);
	void loadFromStream(std::istream& in);

	void print();
};

#endif // !__JSON_ELEMENTS