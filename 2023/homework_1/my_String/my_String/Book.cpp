#include "Book.h"


void Book::copy(const Book& other)
{
    this->mISBN = other.mISBN;
    this->mTitle = other.mTitle;
    this->mAuthor = other.mAuthor;
    this->mSpace = other.mSpace;
}

void Book::clear()
{
    mISBN.remove();
    mTitle.remove();
    mAuthor.remove();
    mSpace = 0;
}

Book::Book(const char* ISBN, const char* title, const char* author, size_t space)
{
    this->mISBN = ISBN;
    this->mTitle = title;
    this->mAuthor = author;
    this->mSpace = space;
}

Book::Book(const Book& other)
{
    copy(other);
}

Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

Book::~Book()
{
    clear();
}

const char* Book::ISBN() const
{
    return mISBN.c_str();
}

const char* Book::title() const
{
    return mTitle.c_str();
}

const char* Book::author() const
{
    return mAuthor.c_str();
}

size_t Book::space() const
{
    return mSpace;
}

void Book::print() const
{
    std::cout << mISBN << std::endl;
    std::cout << mTitle << std::endl;
    std::cout << mAuthor << std::endl;
    std::cout << mSpace << std::endl;

}
