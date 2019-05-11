
#include "Department.h"
#include "ConstantsAndGenFuncs.h"
#include "Patient.h"

// C'tor:
//Department::Department(const char* inName)
//	: name(nullptr), docsArr(nullptr), logSizeOfDocs(0), phySizeOfDocs(0),
//	nursesArr(nullptr), logSizeOfNurses(0), phySizeOfNurses(0),
//	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
Department::Department(const char* inName)
	: name(nullptr), staffArr(nullptr), logSizeOfStaff(0), phySizeOfStaff(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0)
{
	name = new char [strlen(inName) + 1];
	strcpy(name, inName);
}

// D'tor:
Department::~Department()
{
	delete[] name;
	delete[] staffArr;
	/*delete[] docsArr;
	delete[] nursesArr;*/
	delete[] patientsArr;
}


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

void Department::addStaffMember(StaffMember* staffMember)
{
	allocStaffArr();
	staffArr[logSizeOfStaff] = staffMember;
	logSizeOfStaff++;
}

void Department::allocStaffArr()
{
	if (phySizeOfStaff == 0) // If this is the 1st Department
	{
		staffArr = new StaffMember*;
		phySizeOfStaff++;
	}
	else if (logSizeOfStaff == phySizeOfStaff) //if there is no place in the array
	{
		phySizeOfStaff *= 2;
		StaffMember** newArr = new StaffMember*[phySizeOfStaff];
		for (int i = 0; i < logSizeOfStaff; i++)
		{
			newArr[i] = staffArr[i];
		}
		delete[] staffArr;
		staffArr = newArr;
	}
	else
		return;
}


//void Department::addDoctor(Doctor& doc)
//{
//	allocDocArr();
//	docsArr[logSizeOfDocs] = &doc;
//	logSizeOfDocs++;
//	
//}
//
//void Department::allocDocArr()
//{
//	if (phySizeOfDocs == 0) // If this is the 1st Department
//	{
//		docsArr = new Doctor*;
//		phySizeOfDocs++;
//	}
//	else if (logSizeOfDocs == phySizeOfDocs) //if there is no place in the array
//	{
//		phySizeOfDocs *= 2;
//		Doctor** newArr = new Doctor*[phySizeOfDocs];
//		for (int i = 0; i < logSizeOfDocs; i++)
//		{
//			newArr[i] = docsArr[i];
//		}
//		delete[] docsArr;
//		docsArr = newArr;
//	}
//	else
//		return;
//}
//
//void Department::addNurse(Nurse& nurse)
//{
//	allocNursesArr();
//	nursesArr[logSizeOfNurses] = &nurse;
//	logSizeOfNurses++;
//}
//
//void Department::allocNursesArr()
//{
//	if (phySizeOfNurses == 0) // If this is the 1st Department
//	{
//		nursesArr = new Nurse*;
//		phySizeOfNurses++;
//	}
//	else if (logSizeOfNurses == phySizeOfNurses) //if there is no place in the array
//	{
//		phySizeOfNurses *= 2;
//		Nurse** newArr = new Nurse*[phySizeOfNurses];
//		for (int i = 0; i < logSizeOfNurses; i++)
//		{
//			newArr[i] = nursesArr[i];
//		}
//		delete[] nursesArr;
//		nursesArr = newArr;
//	}
//	else
//		return;
//}

const char* Department:: getName() const
{
	return name;
}


void Department::showPatients() const
{
	if (logSizeOfPatients > 0)
	{
		cout << "Patients visited in " << name << " are: " << endl;
		for (int i = 0; i < logSizeOfPatients; i++)
		{
			cout << "\nName: " << patientsArr[i]->getName() << "\tID: " << patientsArr[i]->getId() << "\tGender: ";
			patientsArr[i]->showGender();
			cout << "\tYear of birth: " << patientsArr[i]->getYearOfBirth() << endl;
			patientsArr[i]->showVisits();
		}
	}
	else
		cout << "\nNo Patients available in this department." << endl;
}

StaffMember** Department::operator+=(StaffMember* staffMember)
{
	addStaffMember(staffMember);
}
