#include "json_elements.h"


void JSONElement::addElement(JSONElement* newElement)
{
	newElement->clone();
}



std::ostream& operator<<(std::ostream& out, const std::vector<JSONElement*>& data)
{
	for (JSONElement* jsonElem : data)
	{
		jsonElem->writeToStream(out);
		out << std::endl;
	}
	return out;
}

const std::string StringData::getStringData() const
{
	return jsonStringData;
}

void StringData::setStringData(const std::string newData)
{
	jsonStringData = newData;
}

void StringData::print()
{
	std::cout << ": " << "\"" << jsonStringData << "\"" << ", " << std::endl;
}

const double DoubleData::getDoubleData() const
{
	return jsonDoubleData;
}

void DoubleData::setDoubleData(const double newData)
{
	jsonDoubleData = newData;
}

void DoubleData::print()
{
	std::cout << ": " << jsonDoubleData << ", " << std::endl;

}

const std::string NullData::getNullData() const
{
	return jsonNullData;
}

void NullData::setNullData(const std::string newData)
{
	jsonNullData = "null";
}

void NullData::print()
{
	std::cout << ": " << "null" << ", " << std::endl;

}

const bool BoolData::getBoolData() const
{
	return jsonBoolData;
}

void BoolData::setBoolData(const bool newData)
{
	jsonBoolData = newData;
}

void BoolData::print()
{
	std::cout << ": " << jsonBoolData << ", " << std::endl;
}


void Array::print()
{
	std::cout << "\"" << "\" : [ ";
	// printim vytreshnostta na masiwa
	std::cout << " ]";

}



void Object::deleteElem(const std::string& path)
{
	int position = searchElemWithPath(path);
	//first delete elem
	jsonObjectData.erase(jsonObjectData.begin() + position);
}

void Object::setElem(const std::string& path, const std::string& newData)
{
	auto position = jsonObjectData.begin() + searchElemWithPath(path);

	//if(newData==null) else (everyone else strings)
	Field::changeField(newData);
}

void Object::createNewElem(const std::string& path, const std::string& newElem)
{
	auto position = jsonObjectData.begin() + searchElemWithPath(path);

	jsonObjectData.insert(position, Field::creatField(newElem));
}

void Object::print()
{

	std::cout << "\"" << "\" : {";
	//printim vytreshnistta na obekta
	std::cout << " }";

}

