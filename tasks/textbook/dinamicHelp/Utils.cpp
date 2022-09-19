#include "Utils.h"
#include <string.h>

char* Utils::copyDynamic(const char* source)
{
	char* temp = new char[strlen(source) + 1];
	strcpy_s(temp, strlen(source) + 1, source);
	return temp;
}

char* Utils::copyDyn(char* source)
{
	return copyDynamic(static_cast<const char*>(source));
}
