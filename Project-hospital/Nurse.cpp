#include "nurse.h"

Nurse::Nurse(char*inName,const int  inEmployeeIDNumber, int inYearExp)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	yearsOfExperience = inYearExp;
	employeeIDNumber = inEmployeeIDNumber;
}

Nurse::~Nurse()
{
	delete[] name;
}
const char* Nurse::getName()const
{
	return name;
}
const int Nurse::getEmployeeIDNum()const
{
	return employeeIDNumber;
}
int Nurse::getYearsOfExp()const
{
	return yearsOfExperience;
}
