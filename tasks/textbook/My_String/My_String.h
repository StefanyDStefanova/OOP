#ifndef __MY_STRING
#define __MY_STRING

#define DEFAULT_CAPACITY 8

#include <iostream>
#include <cstring>


class String
{
private:
	char* mData; // символния низ
	size_t mCapacity; // капацитета на низа(масива)

	char* dynCopy(const char* other, size_t capacity) const;
	void resize(size_t capacity);

public:
	String();
	String(const char* other);
	String(const String& other);
	String& operator=(const String& other);

	~String();

	bool isEmpty()const;	 // проверява дали низа е празен(т.е.дали има дължина 0)

	void erase();	 // изчиства низа и задава стойност на капацитета да е тази по подразбиране(нека да е 8 символа)
	void swap(String& other); // разменя съдържанията на текущия низ и низа other

	size_t getCapacity() const;
	size_t getsize() const; //връща дължината на низа

	void setData(const char*);
	void setCapasity(const size_t);

	String& append(const String& other); // конкатенира текущия низ с низа other
	String& append(const char* other); // същото като горният метод
	void pushBack(char c); // добавя символ 'c' в края на низа

	String* substr(size_t start, size_t end) const; // връща новосъздаден обект със съдържание подниза на текущия низ, започващ от позиция start и завършващ на позиция end - 1
	
	String& operator+(const String& other)const; // -връща нов низ, който представлява конкатенация на текущия и низа other
	String& operator+=(const String& other); // -връща псевдоним към текущия низ, като преди това прави конкатенация с низа other
	char operator[](size_t index)const; // -връща копие на символът на позиция index
	char& operator[](size_t index); // -връща псевдоним към символът на позиция index
	bool operator==(const String& other)const; // -проверява лексикографски дали двата низа са еднакви
	bool operator!=(const String& other)const; // -проверява лексикографски дали двата низа са различни

	friend std::ostream& operator << (std::ostream& out, const String& str);// -приятелска функция, която записва низа в поток
	friend std::istream& operator >> (std::istream& in, const String& str);

	void print() const;

};

#endif // !__MY_STRING
