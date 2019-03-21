
#include <iostream>
using namespace std;
#include "Department.h"
#include "ConstantsAndGenFuncs.h"
#include "Patient.h"

// C'tor:
Department::Department(const char* inName)
	: name(nullptr), docArr(nullptr), logSizeOfDocs(0), phySizeOfDocs(0),
	nurseArr(nullptr), logSizeOfNurses(0), phySizeOfNurses(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
{
	copyName(inName, name);
}

// D'tor:
//
//

bool Department::addDoctor(Doctor* doc)
{
	
}

