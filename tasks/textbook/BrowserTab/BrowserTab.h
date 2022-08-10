#ifndef __BROWSER_TAB
#define __BROWSER_TAB

#include <iostream>
#include <cstring>

class BrowserTab
{
private:
	char* URL;
	char* HTML;

	void del();
	void copy(const char* URL,const char* HTML);

public:
	BrowserTab() ;
	BrowserTab(const char* URLP, const char* HTMLP);
	BrowserTab(const BrowserTab& other);

	~BrowserTab();

	void print()const;
};


#endif 
