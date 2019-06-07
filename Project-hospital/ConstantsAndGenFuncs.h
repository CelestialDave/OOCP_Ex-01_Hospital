#pragma warning(disable: 4996)

#ifndef Constants__H
#define Constants__H
#include <string>
//#include <string.h>
#include <iostream>
using namespace std;

enum Results {SUCCESS, NOTFOUND, BADINPUT, BADFORMAT, NODEPS, DEPEXIST, NOSTAFF, NOSURGINHOS, 
	NOSURGINDEP, EIDEXIST, PIDEXIST, EIDNOTFOUND, PIDNOTFOUND, RNONEXIST, RESINSTEMPTY};

//#define MAX_MENU_OPTIONS 11
#define MAX_NAME 100
// Date MAX values:
#define MAX_DAY 31
#define MAX_MONTH 12
#define MIN_YEAR 2000
#define MAX_YEAR 2050
#define CHECKUP 1
#define SURGERY 2


#endif // !Constants__H