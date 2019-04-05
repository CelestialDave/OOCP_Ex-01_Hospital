#include "Patient.h"

#include "Department.h"

Patient::Patient(const char* inName,const char* id ,enum eGender inGender, char* inDateOBirth)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	ID = new char[strlen(id) + 1];
	strcpy(ID, id);
	gender = inGender;
	yearOfBirth = new char[strlen(inDateOBirth) + 1];
	strcpy(yearOfBirth, inDateOBirth);
	visits = nullptr;
	logSizeOfVisits = 0;
	phySizeOfVisits = 0;
	departmentsVisited = nullptr;
	logsizeOfDepartments = 0;
	phySizeOfDepartments = 0;
}

Patient::~Patient()
{
	delete[]name;
	delete[]ID;
	delete[]yearOfBirth;
	int i;
	for (i = 0; i < logSizeOfVisits; i++)
		delete[]visits[i];
	delete[]visits;
	for (i = 0; i < logsizeOfDepartments; i++)
		delete departmentsVisited[i];
	delete[]departmentsVisited;
}

void Patient::addVistation(VisitationRecord& newVisit)
{
	allocVisitsArr();
	visits[logSizeOfVisits] = &newVisit;
	logSizeOfVisits++;
}

void Patient::allocVisitsArr()
{
	if (phySizeOfVisits == 0) // This is the 1st visit.
	{
		visits = new VisitationRecord*;
		phySizeOfVisits++;

	}
	else if (logSizeOfVisits == phySizeOfVisits) // no room left in visits arr
	{
		phySizeOfVisits *= 2;
		VisitationRecord** newArr = new VisitationRecord*[phySizeOfVisits];
		for (int i = 0; i < logSizeOfVisits; i++)
		{
			newArr[i] = visits[i];
		}
		delete[] visits;
		visits = newArr;
	}
	else
		return;
}

void Patient::addDepatrtmentToPatient(const Department& pDepartment)
{
	allocDepartmentsVisitedArr();
	departmentsVisited[logsizeOfDepartments] = &pDepartment;
	logsizeOfDepartments++;
}

void Patient::allocDepartmentsVisitedArr()
{
	if (phySizeOfDepartments == 0) // If this is the 1st Department
	{
		departmentsVisited = new const Department*;
		phySizeOfDepartments++;
	}
	else if (logsizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	{
		phySizeOfDepartments *= 2;
		const Department** newArr = new const Department*[phySizeOfDepartments];
		for (int i = 0; i < logsizeOfDepartments; i++)
		{
			newArr[i] = departmentsVisited[i];
		}
		delete[] departmentsVisited;
		departmentsVisited = newArr;
	}
	else
		return;
}

const char* Patient::getName()const
{
	return name;
}

const char*Patient:: getId()const
{
	return ID;
}
void Patient::showGender()const
{
	if (gender == Male)
		cout << "Male" << endl;
	else if(gender==Female)
		cout << "Female" << endl;
}
const char* Patient::getYearOfBirth() const
{
	return yearOfBirth;
}
void Patient:: showVisits()const
{
	cout << "visitaion:" << endl;
	for (int i = 0; i < logSizeOfVisits; i++)
	{ 
		cout << i + 1 << "." << endl;
		cout << "The staff member in charge is: " << visits[i]->getstaffMemInChargeName() << endl;
		cout << "The arrival date is: ";
		visits[i]->showDate();
		cout << "The visitiation purpose is: ";
		visits[i]->printVisitationPurpose();
		cout<<endl;
	}
}

void Patient::showDepatmentsVisited() const
{
		cout<<(logsizeOfDepartments > 1 ? "The departments which visited are" : "The department the patient visited is") << endl;
		for (int i = 0; i < logsizeOfDepartments; i++)
			cout << departmentsVisited[i]->getName() << endl;
}


bool Patient::hasVisitedDepartment(Department& pDepartment) const
{
	for (int i = 0; i < logsizeOfDepartments; i++)
	{
		if (&pDepartment == departmentsVisited[i])
			return true;
	}
	return false;
}

