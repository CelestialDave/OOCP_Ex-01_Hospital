#include <iostream>
#include <string.h>

#include "Hospital.h"
#include "Department.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"

// C'tor:
Hospital::Hospital(const char* inName)
	: name(nullptr), allDoctors(nullptr), allNurses(nullptr), allPatients(nullptr)
{
	logSizeOfDepartments = logSizeDoctors = logSizeNurses = 
		logSizeOfPatients = phySizeDoctors = phySizeNurses = phySizeOfPatient = 0;
	copyName(inName, name);
}

// D'tor:
//
//

bool Hospital::addDepartment(Department& inDep)
{

}

bool Hospital::addDoctor(Doctor& inDoc)
{

}

bool Hospital::addNurse(Nurse& inNurse)
{

}

bool Hospital::addResearcher(Researcher& inResearcher)
{

}

bool Hospital::addPatient(Patient& inPatient)
{

}

void Hospital::showStaffMembers() const
{

}

void Hospital::showResearchers() const
{

}

void Hospital::showPatientByID(char* inID) const
{

}