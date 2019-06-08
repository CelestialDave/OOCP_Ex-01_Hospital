
#include "Department.h"
#include "ConstantsAndGenFuncs.h"
#include "Patient.h"
#include "Surgeon.h"
#include "Utils.h"


// C'tor:
Department::Department(const string inName) throw(NameException)
	: staffArr(nullptr), logSizeOfStaff(0), phySizeOfStaff(0),
	patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0), numOfSurgeons(0)
{
	if (!Utils::isValidString(inName))
		throw NameException();
	name = inName;
}

// D'tor:
Department::~Department()
{
	////delete[] name;
	delete[] staffArr;
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
	Surgeon* tempSurgeon = dynamic_cast<Surgeon*>(staffMember);
	if (tempSurgeon) this->numOfSurgeons++;
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

const string Department:: getName() const
{
	return name;
}

int Department::getNumOfSurgeons() const
{
	return this->numOfSurgeons;
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
	return staffArr;
}
