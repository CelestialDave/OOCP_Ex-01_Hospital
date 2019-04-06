#include "doctor.h"

Doctor::Doctor(const char*inName,int inEmployeeIDNumber, const char* inSpecialty)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	specialty = new char[strlen(inSpecialty) + 1];
	strcpy(specialty, inSpecialty);
	employeeIDNumber = inEmployeeIDNumber;
}

Doctor::~Doctor()
{
	delete name;
	delete specialty;
}

const char* Doctor::getName()const
{
	return name;
}
const int Doctor::getEmployeeIDNum()const
{
	return employeeIDNumber;
}
const char* Doctor::getSpciality()const
{
	return specialty;
}
