#include "Hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"

// C'tor:
Hospital::Hospital()
	:  allDoctors(nullptr), allNurses(nullptr), allPatients(nullptr)
{
	logSizeOfDepartments = logSizeDoctors = logSizeNurses = 
	logSizeOfPatients = phySizeDoctors = phySizeNurses = phySizeOfPatients = 0;
}

// D'tor:
//
//
Hospital::~Hospital()
{
	for(int i=0;i<logSizeDoctors;i++)
		delete[]allDoctors[logSizeDoctors];
	delete[]allDoctors;
	for (int i = 0; i<logSizeNurses; i++)
			delete[]allNurses[logSizeNurses];
	delete[]allNurses;
	for (int i = 0; i<logSizeOfDepartments; i++)
		delete[]allDepartments[logSizeOfDepartments];
	delete[]allDepartments;
	for (int i = 0; i<logSizeOfPatients; i++)
		delete[]allPatients[logSizeOfPatients];
	delete[]allPatients;
}


bool Hospital::allocDepartmentsArr()
{
	Department** newArr = new Department*[phySizeOfDepartments];
	for (int i = 0; i < logSizeOfDepartments; i++)
		newArr[i] = allDepartments[i];
	delete[]allDepartments;
	allDepartments = newArr;
	return true;
}


bool Hospital::addDepartment(Department& inDep)
{
	if (phySizeOfDepartments == 0) //if the first researcher
	{
		allDepartments = new Department*;
		phySizeOfDepartments++;
	}
	else if (logSizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	{
		phySizeOfDepartments *= 2;
		allocDepartmentsArr();  //to reallocte the array to the new size
	}

	if (logSizeOfDepartments < phySizeOfDepartments)
	{
		allDepartments[logSizeOfDepartments] = &inDep;
		logSizeOfDepartments++;
	}
	return true;
}

bool Hospital::addResearcher(Researcher& inResearcher)
{
	researchInst.addResearcher(inResearcher);
	return true;
}

bool Hospital::allocDocArr()
{
	Doctor** newArr = new Doctor*[phySizeDoctors];
	for (int i = 0; i < logSizeDoctors; i++)
		newArr[i] = allDoctors[i];
	delete[]allDoctors;
	allDoctors = newArr;
	return true;
}

bool Hospital::addDoctor(Doctor& inDoc)
{
	if (phySizeDoctors == 0) //if the first researcher
	{
		allDoctors = new Doctor*;
		phySizeDoctors++;
	}
	else if (logSizeDoctors == phySizeDoctors) //if there is no place in the array
	{
		phySizeDoctors *= 2;
		allocDocArr();  //to reallocte the array to the new size
	}

	if (logSizeDoctors < phySizeDoctors)
	{
		allDoctors[logSizeDoctors] = &inDoc;
		logSizeDoctors++;
	}
	return true;
}


bool Hospital::allocNursesArr()
{
	Nurse** newArr = new Nurse*[phySizeNurses];
	for (int i = 0; i < logSizeNurses; i++)
		newArr[i] = allNurses[i];
	delete[]allNurses;
	allNurses = newArr;
	return true;
}

bool Hospital::addNurse(Nurse& inNurse)
{
	if (phySizeNurses == 0) //if the first researcher
	{
		allNurses = new Nurse*;
		phySizeNurses++;
	}
	else if (logSizeNurses == phySizeNurses) //if there is no place in the array
	{
		phySizeNurses *= 2;
		allocNursesArr();  //to reallocte the array to the new size
	}

	if (logSizeNurses < phySizeNurses)
	{
		allNurses[logSizeNurses] = &inNurse;
		logSizeNurses++;
	}
	return true;
}


bool Hospital::allocPatientsArr()
{
	Patient** newArr = new Patient*[phySizeOfPatients];
	for (int i = 0; i < logSizeOfPatients; i++)
		newArr[i] = allPatients[i];
	delete[]allPatients;
	allPatients = newArr;
	return true;
}

bool Hospital::addPatient(Patient& inPatient, const char* inDep)
{
	if (phySizeOfPatients == 0) //if the first researcher
	{
		allPatients = new Patient*;
		phySizeOfPatients++;
	}
	else if (logSizeOfPatients == phySizeOfPatients) //if there is no place in the array
	{
		phySizeOfPatients *= 2;
		allocPatientsArr();  //to reallocte the array to the new size
	}

	if (logSizeOfPatients < phySizeOfPatients)
	{
		allPatients[logSizeOfPatients] = &inPatient;
		logSizeOfPatients++;
	}
	return true;
}

void Hospital::showStaffMembers() const
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		allDepartments[logSizeOfDepartments]->showStaffMembers();
	}
}

void Hospital::showResearchers() const
{

}

void Hospital::showPatientByID(char* inID) const
{

}

int Hospital::findTheIndexOfDepNameInDepArr(char*str) const
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		if(strcmp(allDepartments[i]->getName(),str)==0)
			return i;
	}
	return -1;
}

bool Hospital:: addNurseToSpecificDepartment(Nurse & nurse, int indexToIn)
{
	allDepartments[indexToIn]->addNurse(nurse);
	return true;
}

bool Hospital::addDoctorToSpecificDepartment(Doctor & doctor, int indexToIn)
{
	allDepartments[indexToIn]->addDoctor(doctor);
	return true;

}




