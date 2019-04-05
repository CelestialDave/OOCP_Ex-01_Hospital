
#include "Department.h"
#include "ConstantsAndGenFuncs.h"
#include "Patient.h"

// C'tor:
Department::Department(const char* inName)
	: name(nullptr), docsArr(nullptr), logSizeOfDocs(0), phySizeOfDocs(0),
	nursesArr(nullptr), logSizeOfNurses(0), phySizeOfNurses(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
{
	name = new char [strlen(inName) + 1];
	strcpy(name, inName);
}

// D'tor:
Department::~Department()
{
	delete[]name;
}

//

void Department::addPatient(Patient& patient)
{
	allocPatientsArr();//to reallocte the array to the new size
	patientsArr[logSizeOfPatients] = &patient;
	logSizeOfPatients++;
}

void Department::allocPatientsArr()
{
	if (phySizeOfPatients == 0) // If this is the 1st Patient
	{
		patientsArr = new Patient*;
		phySizeOfPatients++;
	}
	else if (logSizeOfPatients == phySizeOfPatients) //if there is no more room in the array
	{
		phySizeOfPatients *= 2;
		Patient** newArr = new Patient*[phySizeOfPatients];
		for (int i = 0; i < logSizeOfPatients; i++)
		{
			newArr[i] = patientsArr[i];
		}
		delete[] patientsArr;
		patientsArr = newArr;
	}
	else
		return;
}

void Department::addDoctor(Doctor& doc)
{
	allocDocArr();
	docsArr[logSizeOfDocs] = &doc;
	logSizeOfDocs++;
	
}

void Department::allocDocArr()
{
	if (phySizeOfDocs == 0) // If this is the 1st Department
	{
		docsArr = new Doctor*;
		phySizeOfDocs++;
	}
	else if (logSizeOfDocs == phySizeOfDocs) //if there is no place in the array
	{
		phySizeOfDocs *= 2;
		Doctor** newArr = new Doctor*[phySizeOfDocs];
		for (int i = 0; i < logSizeOfDocs; i++)
		{
			newArr[i] = docsArr[i];
		}
		delete[] docsArr;
		docsArr = newArr;
	}
	else
		return;
}

void Department::addNurse(Nurse& nurse)
{
	allocNursesArr();
	nursesArr[logSizeOfNurses] = &nurse;
	logSizeOfNurses++;
}

void Department::allocNursesArr()
{
	if (phySizeOfNurses == 0) // If this is the 1st Department
	{
		nursesArr = new Nurse*;
		phySizeOfNurses++;
	}
	else if (logSizeOfNurses == phySizeOfNurses) //if there is no place in the array
	{
		phySizeOfNurses *= 2;
		Nurse** newArr = new Nurse*[phySizeOfNurses];
		for (int i = 0; i < logSizeOfNurses; i++)
		{
			newArr[i] = nursesArr[i];
		}
		delete[] nursesArr;
		nursesArr = newArr;
	}
	else
		return;
}

const char* Department:: getName() const
{
	return name;
}


void Department::showPatients() const
{
	if (logSizeOfPatients > 0)
	{
		cout << "The patients in " << name << (logSizeOfPatients > 1 ? " are" : " is") << endl;
		for (int i = 0; i < logSizeOfPatients; i++)
		{
			cout << "name: " << patientsArr[i]->getName() << endl;
			cout << "ID: " << patientsArr[i]->getId() << endl;
			cout << "Gender: ";
			patientsArr[i]->showGender();
			cout << "Year of birth: " << patientsArr[i]->getYearOfBirth() << endl;
			patientsArr[i]->showVisits();
		}
	}
	else
		cout << "There is no patients in this department" << endl;
}
