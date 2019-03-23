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