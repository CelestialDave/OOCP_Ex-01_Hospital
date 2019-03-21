#ifndef Constants__H
#define Constants__H
#include <string.h>

#include <iostream>
using namespace std;

#define MAX_NAME 100

void copyName(const char* nameFrom, char* nameTo)
{
	nameTo = new char[strlen(nameFrom) + 1];
	strcpy(nameTo, nameFrom); 
}


#endif // !Constants__H