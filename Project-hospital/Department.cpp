
#include "Department.h"
#include "ConstantsAndGenFuncs.h"
#include "Patient.h"

// C'tor:
Department::Department(const char* inName)
	: name(nullptr), docArr(nullptr), logSizeOfDocs(0), phySizeOfDocs(0),
	nurseArr(nullptr), logSizeOfNurses(0), phySizeOfNurses(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
{
	name = new char [strlen(inName) + 1];
	strcpy(name, inName);
}

// D'tor:
//
//

bool Department::addPatient(Patient& patient)
{
	if (phySizeOfPatients == 0) //if the first researcher
	{
		patientsArr = new Patient*;
		phySizeOfPatients++;
	}
	else if (logSizeOfPatients == phySizeOfPatients) //if there is no place in the array
	{
		phySizeOfPatients *= 2;
		allocPatientsArr();  //to reallocte the array to the new size
	}

	if (logSizeOfPatients < phySizeOfPatients)
	{
		patientsArr[logSizeOfPatients] = &patient;
		logSizeOfPatients++;
	}
	return true;
}

bool Department::allocPatientsArr()
{
	Patient** newArr = new Patient*[phySizeOfPatients];
	for (int i = 0; i < logSizeOfPatients; i++)
		newArr[i] = patientsArr[i];
	delete[]patientsArr;
	patientsArr = newArr;
	return true;
}

bool Department::addDoctor(Doctor& doc)
{
	if (phySizeOfDocs == 0) //if the first researcher
	{
		docArr = new Doctor*;
		phySizeOfDocs++;
	}
	else if (logSizeOfDocs == phySizeOfDocs) //if there is no place in the array
	{
		phySizeOfDocs *= 2;
		allocDocArr();  //to reallocte the array to the new size
	}

	if (logSizeOfDocs< phySizeOfDocs)
	{
		docArr[logSizeOfDocs] = &doc;
		logSizeOfDocs++;
	}
	return true;
}

bool Department::allocDocArr()
{
	Doctor** newArr = new Doctor*[phySizeOfDocs];
	for (int i = 0; i < logSizeOfDocs; i++)
		newArr[i] = docArr[i];
	delete[]docArr;
	docArr = newArr;
	return true;
}

bool Department::addNurse(Nurse& nurse)
{
	if (phySizeOfNurses == 0) //if the first researcher
	{
		nurseArr = new Nurse*;
		phySizeOfNurses++;
	}
	else if (logSizeOfNurses == phySizeOfNurses) //if there is no place in the array
	{
		phySizeOfNurses *= 2;
		allocNursesArr();  //to reallocte the array to the new size
	}

	if (logSizeOfNurses < phySizeOfNurses)
	{
		nurseArr[logSizeOfNurses] = &nurse;
		logSizeOfNurses++;
	}
	return true;
}

bool Department::allocNursesArr()
{
	Nurse** newArr = new Nurse*[phySizeOfNurses];
	for (int i = 0; i < logSizeOfNurses; i++)
		newArr[i] = nurseArr[i];
	delete[]nurseArr;
	nurseArr = newArr;
	return true;
}

char* Department:: getName() const
{
	return name;
}