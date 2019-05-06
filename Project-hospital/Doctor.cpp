#include "doctor.h"

Doctor::Doctor(const StaffMember& staffMember, const char* inSpecialty)
	: StaffMember(staffMember)
{
	specialty = strdup(inSpecialty);
}

Doctor::Doctor(const Doctor& other)
// ???
	: StaffMember(other)
{
	if (strcmp(this->specialty, other.specialty) != 0)
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
