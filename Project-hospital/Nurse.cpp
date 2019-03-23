#include "nurse.h"

Nurse::Nurse(char*inName, int inYearExp)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	yearsOfExperience = inYearExp;
	employeeIDNumber = 0;
	//iDNum /****/
}

Nurse::~Nurse()
{
	delete[]name;
}
char* Nurse::getName()const
{
	return name;
}
int Nurse::getEmployeeIDNum()const
{
	return employeeIDNumber;
}
int Nurse::getYearsOfExp()const
{
	return yearsOfExperience;
}
