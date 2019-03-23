#include "doctor.h"

Doctor::Doctor(const char*inName, char* inSpecialty)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	specialty = new char[strlen(inSpecialty) + 1];
	strcpy(specialty, inSpecialty);
	//ID num /***/
}

Doctor::~Doctor()
{
	delete[]name;
	delete[]specialty;
}

char* Doctor::getName()const
{
	return name;
}
int Doctor::getEmployeeIDNum()const
{
	return employeeIDNumber;
}
char* Doctor::getSpciality()const
{
	return specialty;
}
