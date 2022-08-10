#include <iostream>
#include <cstring>
#include "BrowserTab.h"

int main()
{
	BrowserTab br;
	BrowserTab b;
	BrowserTab("aaaa", "bbbbbb");
	std::cout << "HI";
	BrowserTab c = b;

	return 0;
}