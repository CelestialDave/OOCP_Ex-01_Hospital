
#include <iostream>
using namespace std;
#include "Department.h"

Department::Department(const char* inName)
	: docArr(nullptr), logSizeOfDocs(0), phySizeOfDocs(0),
	nurseArr(nullptr), logSizeOfNurses(0), phySizeOfNurses(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
{

}

