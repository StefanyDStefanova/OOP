#include "BrowserTab.h"

void BrowserTab::del()
{
	delete[] this->URL;
	delete[] this->HTML;
}

void BrowserTab::copy(const char* URLP, const char* HTMLP)
{

	this->URL = new char[strlen(URLP) + 1];
	strcpy_s(this->URL, strlen(URLP) + 1, URLP);
	
	this->HTML = new char[strlen(HTMLP) + 1];
	strcpy_s(this->HTML, strlen(HTMLP) + 1, HTMLP);
		
}

BrowserTab::BrowserTab()
{
	std::cout << "def.\n";
	this->URL = new char[1];
	URL[0] = '\0';
	
	this->HTML = new char[1];
	HTML[0] = '\0';
}

BrowserTab::BrowserTab(const char* URL, const char* HTML)
{
	copy(URL, HTML);
}

BrowserTab::BrowserTab(const BrowserTab& other)
{
	del();
	copy(other.URL, other.HTML);
}

BrowserTab::~BrowserTab()
{
	del();
}

void BrowserTab::print() const
{
	std::cout << URL << " " << HTML << "\n";
}
