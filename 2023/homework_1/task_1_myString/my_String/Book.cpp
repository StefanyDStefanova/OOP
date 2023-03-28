#include "Book.h"


void Book::erase()
{
}

const MyString& Book::ISBN() const
{
    return m_ISBN;
}

const MyString& Book::title() const
{
    return m_title;
}

const MyString& Book::author() const
{
    return m_author;
}

size_t Book::space() const
{
    return m_space;
}
