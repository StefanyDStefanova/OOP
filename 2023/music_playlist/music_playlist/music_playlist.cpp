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
	
	void clean()
	{
		min = 0;
		sec = 0;
	}
};

class Song
{
private:
	char* mName = nullptr;
	Duration mDuration;
	char* mType = nullptr;

	void copy(const Song& other)
	{
		size_t size = strlen(other.mName);
		char* temp = new char[size + 1];
		if ( temp )
		{
			delete[] this->mName;
			strcpy(temp, other.mName);
			this->mName = temp;
		}

		mDuration.sec = other.mDuration.sec;
		mDuration.min = other.mDuration.min;

		size_t size1 = strlen(other.mType);
		delete[] this->mType;
		this->mType = new char[size1 + 1];
		strcpy(this->mType, other.mType);

	}

	void erase()
	{
		delete[] mName;
		mName = nullptr;

		delete[] mType;
		mType = nullptr;

		mDuration.clean();
	}

public:
	Song() :mName(nullptr), mType(nullptr) {}
	Song(const char* name, const Duration& duration, const char* type)
	{
		if (!name || !type)
		{
			std::cerr << "Have a problem with data";
			return;
		}

		size_t size = strlen(name);
		delete[] this->mName;
		this->mName = new char[size + 1];
		strcpy(this->mName, name);

		mDuration.sec = duration.sec;
		mDuration.min = duration.min;

		size_t size1 = strlen(type);
		delete[] this->mType;
		this->mType = new char[size1 + 1];
		strcpy(this->mType, type);
	}
	Song(const Song& other)
	{
		copy(other);
	}
	Song& operator=(const Song& other)
	{
		if (this != &other)
		{
			erase();
			copy(other);
		}
		return *this;
	}
	~Song()
	{
		erase();
	}

	const char* getName() const
	{
		return mName;
	}
	const Duration getDuration() const
	{
		return mDuration;
	}
	const char* getType() const
	{
		return mType;
	}

	void setName(const char* newName)
	{
		size_t size = strlen(newName);
		delete[] this->mName;
		this->mName = new char[size + 1];
		strcpy(this->mName, newName);
	}
	void setDuration(const Duration& newDuration)
	{
		mDuration.sec = newDuration.sec;
		mDuration.min = newDuration.min;
	}
	void setType(const char* newType)
	{
		size_t size = strlen(newType);
		delete[] this->mType;
		this->mType = new char[size + 1];
		strcpy(this->mType, newType);
	}

	void print() const
	{
		std::cout << mName << " " << mType << " " << mDuration.min << ":" << mDuration.sec << std::endl;
	}

	void remove() { erase(); }

};

class Playlist
{
private:
	char* mNamePL = nullptr;
	Song* mSongs = nullptr;
	size_t nSize = 0;
	size_t nCapacity = 0;

	void copy(const Playlist& other)
	{
		size_t size = strlen(other.mNamePL);
		delete[] this->mNamePL;
		this->mNamePL = new char[size + 1];
		strcpy(this->mNamePL, other.mNamePL);

		this->mSongs = new Song[other.nCapacity];
		for (size_t i = 0; i < other.nSize; i++)
		{
			mSongs[i] = other.mSongs[i];
		}

	}

	void erase()
	{
		delete[] mNamePL;
		mNamePL = nullptr;

		for (size_t i = 0; i < nSize; i++)
		{
			mSongs[i].remove();
		}
	}

	void resize()
	{
		nCapacity *= 2;

		Song* tmp = new Song[nCapacity];
		for (size_t i = 0; i < nSize; i++)
		{
			tmp[i] = mSongs[i];
		}

		delete[] mSongs;

		mSongs = tmp;
	}

public:
	Playlist() = default;
	Playlist(const char* name, const Song* songs, size_t numberOfSongs )
	{
		if (songs)
		{
			setNamePlayList(name);
			nSize = numberOfSongs;
			nCapacity = numberOfSongs;

			mSongs = new Song[nCapacity];

			for (size_t i = 0; i < numberOfSongs; i++)
			{
				mSongs[i] = songs[i];
			}
		}
	}
	Playlist(const Playlist& other)
	{
		copy(other);
	}
	Playlist& operator=(const Playlist& other)
	{
		if (this != &other)
		{
			erase();
			copy(other);
		}
	}
	~Playlist()
	{
		erase();
	}

	const char* getNamePlayList() const
	{
		return mNamePL;
	}

	void setNamePlayList(const char* name)
	{
		size_t size = strlen(name);
		delete[] this->mNamePL;
		this->mNamePL = new char[size + 1];
		strcpy(this->mNamePL, name);
	}

	int getSongIndex(const char* songName)
	{
		for (int i = 0; i < nSize; i++)
		{
			if (strcmp(mSongs[i].getName(), songName) == 0)
			{
				return i;
			}
		}

		std::cerr << "This song was not found!";
		return -1;
	}

	Song& getSongByName(const char* songName)
	{
		for (size_t i = 0; i < nSize; i++)
		{
			if (strcmp(mSongs[i].getName(), songName) == 0)
			{
				return mSongs[i];
			}
		}
	}


	void addSong(const Song& songToAdd)
	{
		if (nSize == nCapacity)
		{
			resize();
		}

		mSongs[nSize] = songToAdd;
		
		nSize++;

	}

	bool removeSong(const char* songName)
	{
		for (size_t i = 0; i < nSize; i++)
		{
			if (strcmp(mSongs[i].getName(), songName) == 0)
			{
				--nSize;
				if (nSize != 0)
				{
					mSongs[i].setDuration(mSongs[nSize].getDuration());
					mSongs[i].setName(mSongs[nSize].getName());
					mSongs[i].setType(mSongs[nSize].getType());
				}
				return true;
			}
		}
		return false;

	}

	void printPlaylistInfo() const
	{
		std::cout << "Play list name: " << mNamePL << std::endl;
		std::cout << "Songs: " << std::endl;

		for (size_t i = 0; i < nSize; i++)
		{
			std::cout << i << ". ";
			mSongs[i].print();
			std::cout << std::endl;
		}
	}
};

int main()
{
	Song kalifornia;
	char name[10] = "rim";
	kalifornia.setName(name);

	Duration first;
	first.min = 5;
	first.sec = 34;
	kalifornia.setDuration(first);

	char type[10] = "chalga";
	kalifornia.setType(type);

	std::cout << kalifornia.getName() << std::endl;
	std::cout << kalifornia.getDuration().min << " " << kalifornia.getDuration().sec << std::endl;
	std::cout << kalifornia.getType() << std::endl;

	Playlist pl;

	pl.setNamePlayList(name);
	std::cout << pl.getNamePlayList() << std::endl;
	

	return 0;
}