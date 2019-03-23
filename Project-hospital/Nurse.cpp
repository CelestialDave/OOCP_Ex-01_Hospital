#include "nurse.h"

Nurse::Nurse(const char*inName, int inYearExp)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	yearsOfExperience = inYearExp;
	//iDNum /****/
}

Nurse::~Nurse()
{
	delete[]name;
}