#include "Patient.h"

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
		delete[]departmentsVisited[i];
	delete[]departmentsVisited;
}

bool Patient::addVistation(VisitationRecord& newVisit)
{
		if (phySizeOfVisits == 0) //if the first researcher
		{
			visits = new VisitationRecord*;
			phySizeOfVisits++;
		}
		else if (logSizeOfVisits == phySizeOfVisits) //if there is no place in the array
		{
			phySizeOfVisits *= 2;
			reallocationVisitationRecordArr();  //to reallocte the array to the new size
		}
		if (logSizeOfVisits < phySizeOfVisits)
		{
			visits[logSizeOfVisits] = &newVisit;
			logSizeOfVisits++;
		}
		return true;
}

void Patient::reallocationVisitationRecordArr()
{
	VisitationRecord** newArr = new VisitationRecord*[phySizeOfVisits];
	for (int i = 0; i < logSizeOfVisits; i++)
		newArr[i] = visits[i];
	delete[]visits;
	visits = newArr;
}

bool Patient::addDepatrtmentToDepList(const char* DepartmentName)
{

	if (phySizeOfDepartments == 0) //if the first researcher
	{
		departmentsVisited = new char*;
		phySizeOfVisits++;
	}
	else if (logsizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	{
		phySizeOfDepartments *= 2;
		reallocationDepartmentsVisitedNameArr();  //to reallocte the array to the new size
	}
	if (logsizeOfDepartments < phySizeOfDepartments)
	{
		strcpy(departmentsVisited[logsizeOfDepartments], DepartmentName);
		logsizeOfDepartments++;
	}
	return true;
}

void Patient::reallocationDepartmentsVisitedNameArr()
{
	char** newArr = new char*[phySizeOfVisits];
	for (int i = 0; i < logSizeOfVisits; i++)
		newArr[i] = departmentsVisited[i];
	delete[]departmentsVisited;
	departmentsVisited = newArr;
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
	for (int i = 0; i < logSizeOfVisits; i++)
	{ 
		cout << "The staff member in charge is: " << visits[i]->getstaffMemInChargeName() << endl;
		cout << "The arrival date is: ";
		visits[i]->showDate();
		cout << endl;
		cout << "The visitiation purpose is: ";
		visits[i]->printVisitationPurpose();
		cout<<endl;
	}
}

bool Patient::hasVisitedDepartment(const char* department) const
{
	bool res = false;
	for (int i = 0; i < logsizeOfDepartments; i++)
	{
		if (strcmp(department, departmentsVisited[i]) == 0)
			res = true;
	}
	return res;
}

