#include <iostream>
#include <cstring>
#include <fstream>

/*
* task 1*

Да се реализира клас Date, който пази в себе си информация
за следните променливи:
-> Дата, Месец, Година;
Класът да има следния интерфейс:

Класът НЕ ТРЯБВА да има конструктор по подразбиране.
Date(unsigned int day, unsigned int month, unsigned int year)
- конструктор, създаващ нов обект за дата и проверяващ с assert валидността й.
unsigned int day() const
unsigned int month() const;
unsigned int year() const;
bool operator==(const Date& rhs) const;
bool operator<(const Date& rhs) const;
Предефинирайте оператора за изход <<, така че да принтира Date в следния формат: "DD.MM.YYYY"

*/

class Date
{
private:
	unsigned int mDay;
	unsigned int mMonth;
	unsigned int mYear;

public:
	Date() = delete;
	Date(unsigned int day, unsigned int month, unsigned int year)
		:mDay(day), mMonth(month), mYear(year) {}
	

	unsigned int getDay() const
	{
		return mDay;
	}
	unsigned int getMonth() const
	{
		return mMonth;
	}
	unsigned int getYear() const
	{
		return mYear;
	}

	bool operator==(const Date& rhs) const
	{
		return (mYear == rhs.mYear && mMonth == rhs.mMonth && mDay == rhs.mDay);
	}

	bool operator<(const Date& rhs) const
	{
		if (mYear < rhs.mYear)
			return true;

		if (mMonth < rhs.mMonth)
			return true;

		if (mDay < rhs.mDay)
			return true;

		return false;
	}

	friend std::ostream& operator<<(std::ofstream& out, const Date& data)
	{
		std::cout << data.mDay << "." << data.mMonth << "." << data.mYear;
	}
};


int main()
{
	Date today(3,4,2023);
	std::cout << today.getDay();

	return 0;
}