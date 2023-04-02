#include <iostream>
#include <cstring>
#include <fstream>
/*
* task 1 *

Да се създаде клас Baloon, съдържащ полета за цена и цвят. 
Да се реализират:

конструктор с параметри
конструктор по подразбиране
метод за отпечатване на стандартния изход
сетъри и гетъри за член-данните

*/
constexpr size_t COLOR_CAPACITY = 100;
constexpr size_t BUFFER_SIZE = 1024;
constexpr size_t CAPACITY = 1024;

class Baloon
{
private:
	double mPrice = 0.0;
	char mColor[COLOR_CAPACITY];

public:
	Baloon() {}
	Baloon(double price, const char* color) :mPrice(price)
	{
		setColor(color);
	}

	const double getPrice() const
	{
		return mPrice;
	}

	const char* getColor() const
	{
		return mColor;
	}

	void setPrice(const double newPrice)
	{
		mPrice = newPrice;
	}

	void setColor(const char* newColor)
	{
		strcpy_s(mColor,COLOR_CAPACITY, newColor);
	}

	const void print() const
	{
		std::cout << "Price: " << mPrice << std::endl;
		std::cout << "Color: " << mColor << std::endl;
	}

	void read(const char* fileName)
	{
		std::ifstream file(fileName);

		if (!file.good())
		{
			std::cerr << "Couldn't open the file!" << std::endl;
			return;
		}

		char buff[255];
		file >> buff;

		setColor(buff);

		if (!mColor)
		{
			mPrice = 0;
			return;
		}

		file >> mPrice;

		file.close();
	}

	void write(const char* fileName) const
	{
		std::ofstream file(fileName);

		if (!file.good())
		{
			std::cerr << "Couldn't open the file!" << std::endl;
			return;
		}

		file << mColor << ' ' << mPrice << std::endl;

		file.close();
	}
};


/*
* task 2 *

Да се създаде клас Shisha, съдържащ полета за цена, марка и вкус. 
Марката и вкусът трябва да бъдат символни низове, задачелени с точна големина. 
Да се реализират:

конструктор с параметри
конструктор по подразбиране
метод за отпечатване на стандартния изход
сетъри и гетъри за член-данните
деструктор, грижещ се за динамичната памет

*/

class Shisha
{
private:
	char* mBrand = nullptr;
	char* mTaste = nullptr;
	double mPrice = 0.0;

	
public:
	void erase()
	{
		delete[] mBrand;
		mBrand = nullptr;

		delete[] mTaste;
		mTaste = nullptr;

		mPrice = 0;
	}

	Shisha() {}
	Shisha(const char* brand, const char* taste, double price) :mPrice(price)
	{
		if (!brand)
		{
			erase();
			return;
		}

		size_t sizeBrand = strlen(brand);
		mBrand = new char[sizeBrand + 1];
		//strcpy_s(mBrand, sizeof(mBrand), brand);
		strcpy(mBrand, brand);
		
		if (!taste)
		{
			erase();
			return;
		}

		size_t sizeTaste = strlen(taste);
		mTaste = new char[sizeTaste + 1];
		//strcpy_s(mTaste, sizeof(mTaste), taste);
		strcpy(mTaste, taste);

		
	}
	~Shisha()
	{
		erase();
	}

	const char* getBrand() const
	{
		return mBrand;
	}

	const char* getTaste() const
	{
		return mTaste;
	}

	const double getPrice() const
	{
		return mPrice;
	}

	void setBrand(const char* newBrand)
	{
		size_t sizeBrand = strlen(newBrand);

		delete[] mBrand;
		mBrand = new char[sizeBrand + 1];
		
		if (!mBrand)
		{
			std::cerr << "Memory problem!";
			return;
		}

		//strcpy_s(mBrand, sizeBrand, newBrand);
		strcpy(mBrand, newBrand);
		mBrand[sizeBrand] = '\0';
	}

	void setTaste(const char* newTaste)
	{
		delete[]mTaste;

		size_t sizeTaste = strlen(newTaste);
		mTaste = new char[sizeTaste + 1];

		if (!mTaste)
		{
			std::cerr << "Memory problem!";
			return;
		}

		//strcpy_s(mTaste, sizeTaste, newTaste);
		strcpy(mTaste, newTaste);
		mBrand[sizeTaste] = '\0';
	}

	void setPrice(const double newPrice)
	{
		mPrice = newPrice;
	}


	void print() const
	{
		std::cout << mBrand << " " << mTaste << " " << mPrice << " " << std::endl;
	}

	void read(const char* fileName)
	{
		std::ifstream file(fileName);

		if (!file.good())
		{
			std::cerr << "Couldn't  open the file!" << std::endl;
			return;
		}

		char buff[BUFFER_SIZE];
		

		file.getline(buff,BUFFER_SIZE);
		setBrand(buff);

		if (!mBrand)
		{
			std::cerr << "Memory problem!";
			return;
		}

		file.clear();

		file.getline(buff, BUFFER_SIZE);
		setTaste(buff);

		if (!mTaste)
		{
			std::cerr << "Memory problem!";
			return;
		}

		file >> mPrice;

		file.close();
	}

	void write(const char* fileName)
	{
		std::ofstream file(fileName);

		if (!file.good())
		{
			std::cerr << "Couldn't  open the file!" << std::endl;
			return;
		}

		file << mBrand << " " << mTaste << " " << mPrice << std::endl;

		file.close();
	}
};

/*
* task 3 *

Да се създаде клас Alcohol, съдържащ полета за цена и име на 
алкохола - символен низ, заделен с точна големина. 
Да се реализират следните функции:

конструктор с параметри
конструктор по подразбиране
метод за отпечатване на стандартния изход
сетъри и гетъри за член-данните
деструктор, грижещ се за динамичната памет

*/

class Alcohol
{
private:
	double mPrice = 0.0;
	char* mName = nullptr;

public:
	Alcohol() {}
	Alcohol(const char* name, double price) :mPrice(price)
	{
		size_t size = strlen(name);
		mName = new char[size + 1];
		//strcpy_s(mName, sizeof(mName), name);
		strcpy(mName, name);

		if (!name)
		{
			mPrice = 0;
			return;
		}
	}
	~Alcohol()
	{
		delete[] mName;
		mName = nullptr;
	}

	void erase()
	{
		delete[]mName;
		mName = nullptr;

		mPrice = 0;
	}

	const double getPrice() const
	{
		return mPrice;
	}

	const char* getName() const
	{
		return mName;
	}

	void setPrice(const double newPrice)
	{
		mPrice = newPrice;
	}

	void setName(const char* newName)
	{
		delete[] mName;
		size_t size = strlen(newName);
		mName = new char[size + 1];

		if (!mName)
		{
			std::cerr << "Memory probem!";
			return;
		}
		//strcpy_s(mName, size, newName);
		strcpy(mName, newName);
	}

	void print() const
	{
		std::cout << mName << " " << mPrice << std::endl;
	}

	void read(const char* fileName)
	{
		std::ifstream file(fileName);

		if (!file.good())
		{
			std::cerr << "Couldn't opent the file!";
			return;
		}

		char buff[BUFFER_SIZE];
		file.getline(buff, BUFFER_SIZE);

		setName(buff);

		if (!mName)
		{
			std::cerr << "Mmory problem!";
			delete[] mName;
			return;
		}

		file >> mPrice;
		file.close();
	}

	void write(const char* fileName)
	{
		std::ofstream file(fileName);

		if (!file.good())
		{
			std::cerr << "Couldn't opent the file!";
			return;
		}

		file << mName << " " << mPrice << std::endl;
		file.close();
	}
};

/*
* task 4 *
 

накодят един клас NightClub, който ще съдържа списък от предлагани балони, 
наргилета и алкохол (<= 1000). Да се реализират следните методи:

добавяне на балон
добавяне на наргиле
добавяне на алкохол
премахване на балон по зададен цвят
премахване на наргиле по зададена марка
премахване на алкохол по зададено име
проверка дали има балон по-евтин от N лева
проверка дали има наргиле с даден вкус
проверка дали има алкохол между A и B лева
извеждане на екрана на всичко налично в момента

*/

class NightClub
{
private:
	Baloon mBaloons[CAPACITY]{};
	Shisha mShisha[CAPACITY]{};
	Alcohol mAlcohol[CAPACITY]{};

	size_t nBaloonsSize = 0;
	size_t nShishaSize = 0;
	size_t nAlcoholSize = 0;

public:

	void addObjectBaloon(const Baloon& b) 
	{
		if (nBaloonsSize == CAPACITY)
		{
			std::cerr << "No space for more baloons" << std::endl;
			return;
		}

		mBaloons[nBaloonsSize].setColor(b.getColor());
		mBaloons[nBaloonsSize].setPrice(b.getPrice());

		++nBaloonsSize;
	}

	void addBaloon(const char* color, double price)
	{
		if (nBaloonsSize == CAPACITY)
		{
			std::cerr << "No space for more baloons" << std::endl;
			return;
		}

		mBaloons[nBaloonsSize].setColor(color);
		mBaloons[nBaloonsSize].setPrice(price);

		++nBaloonsSize;
	}
	void addShisha(const char* brand,const char* taste, double price)
	{
		if (nShishaSize == CAPACITY)
		{
			std::cerr << "No space!";
			return;
		}

		mShisha[nShishaSize].setBrand(brand);
		mShisha[nShishaSize].setTaste(taste);
		mShisha[nShishaSize].setPrice(price);

		++nShishaSize;

	}
	void addAlcohol(const char* name, double price)
	{
		if (nAlcoholSize == CAPACITY)
		{
			std::cerr << "No space!";
			return;
		}

		mAlcohol[nAlcoholSize].setName(name);
		mAlcohol[nAlcoholSize].setPrice(price);

		++nAlcoholSize;
	}

	void removeBaloon(const char* color) 
	{
		for (size_t i = 0; i < nBaloonsSize; i++)
		{
			if (strcmp(mBaloons[i].getColor(), color) == 0)
			{
				--nBaloonsSize;

				if (nBaloonsSize != 0)
				{
					mBaloons[i].setColor(mBaloons[nBaloonsSize].getColor());
					mBaloons[i].setPrice(mBaloons[nBaloonsSize].getPrice());
				}
				return;
			}
		}
	}
	void removeShisha(const char* brand) 
	{
		for (size_t i = 0; i < nShishaSize; i++)
		{
			if (strcmp(mShisha[i].getBrand(), brand) == 0)
			{
				--nShishaSize;

				if (nShishaSize != 0)
				{
					mShisha[i].setBrand(mShisha[nShishaSize].getBrand());
					mShisha[i].setTaste(mShisha[nShishaSize].getTaste());
					mShisha[i].setPrice(mShisha[nShishaSize].getPrice());
				}

				mShisha[nShishaSize].erase();

				return;
			}
		}
	}

	void removeAlcohol(const char* name)
	{
		for (size_t i = 0; i < nAlcoholSize; i++)
		{
			if (strcmp(mAlcohol[i].getName(), name) == 0)
			{
				--nAlcoholSize;

				if (nAlcoholSize != 0)
				{
					mAlcohol[i].setName(mAlcohol[nAlcoholSize].getName());
					mAlcohol[i].setPrice(mAlcohol[nAlcoholSize].getPrice());
				}

				mAlcohol[nAlcoholSize].erase();

				return;
			}
		}
	}


	

	bool checkForBaloonsCheaperThan(double price)
	{
		for (size_t i = 0; i < nBaloonsSize; i++)
		{
			if (mBaloons[i].getPrice() < price)
				return true;
		}
		return false;

	}

	bool checkForShishaWithTaste(const char* taste)
	{
		for (size_t i = 0; i < 0; i++)
		{
			if (strcmp(mShisha[i].getTaste(),taste)==0)
				return true;
		}
		return false;
	}

	bool checkForAlcoholWithPriceBetween(double lower,double upper)
	{
		for (size_t i = 0; i < nAlcoholSize; i++)
		{
			if (mAlcohol[i].getPrice() >= lower && mAlcohol[i].getPrice() <= upper)
				return true;
		}
		return false;
	}

	void print() const
	{
		for(size_t i=0;i<nBaloonsSize;i++)
		{
			mBaloons[i].print();
		}
		
		for(size_t i=0;i<nShishaSize;i++)
		{
			mShisha[i].print();
		}
		
		for(size_t i=0;i<nAlcoholSize;i++)
		{
			mAlcohol[i].print();
		}

		std::cout<<std::endl;
	}
};

int main()
{
	Baloon b;
	b.setPrice(25.50);
	char color[10] = "red";
	b.setColor(color);

	b.print();

	Shisha sh( "nqkakwo", "plod", 44.2 );
	sh.print();

	Alcohol al{ "vodka",22.34 };
	al.print();

	NightClub club;
	club.addBaloon(color, 33);
	club.addObjectBaloon(b);

	club.print();

	return 0;
}