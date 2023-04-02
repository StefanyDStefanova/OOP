#include <iostream>
#include <fstream>
#include <cstring>


/*
* Продължителност  * 

Всяка една песен има определена дължина. Създайте структура Duration,
която пази информация за продължителността на една песен 
- колко минути и колко секунди е дълга тя.

* Песен *

Време е да създадем единицата, от която ще бъдат съставени нашите 
плейлисти - песента. Създайте клас Song, представящ песен. В нашата 
програма всяка песен ще се харектеризира с име, продължителност 
и жанр. Помислете за подходящи начини, чрез които да конструирате песни. 
Реализайте гетъри и сетъри за член-данните на класа. Ще се наложи 
многократно копиране на обекти от този тип - помислете кое правило 
трябва да спазим?
*/

struct Duration
{
	size_t sec;
	size_t min;

	Duration() :sec(0), min(0) {}
};

class Song
{
private:
	char* mName = nullptr;
	Duration mDuration;
	char* mType = nullptr;

	void erse()
	{
		delete[] mName;
		mName = nullptr;

		delete[] mType;
		mType = nullptr;

		mDuration.min = 0;
		mDuration.sec = 0;
	}

public:
	Song():mName(nullptr), mType(nullptr){}
	Song(const char* name, const Duration& duration, const char* type) {}
	Song& operator=(const Song* other)
	{

	}
	~Song()
	{

	}
};

int main()
{
	return 0;
}