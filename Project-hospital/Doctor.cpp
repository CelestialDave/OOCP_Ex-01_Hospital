#include "doctor.h"

Doctor::Doctor(const char* name, int employeeIDNumber, const char* inSpecialty)
	: StaffMember(name, employeeIDNumber)
{
	specialty = strdup(inSpecialty);
}

Doctor::Doctor(const Doctor& other)
// ???
	: StaffMember(other)
{

	if (this!=&other)
	{
		delete[] specialty;
		this->specialty = strdup(other.specialty);
	}
}

Doctor::~Doctor()
{
	delete[] specialty;
}


const char* Doctor::getSpciality()const
{
	return specialty;
}
