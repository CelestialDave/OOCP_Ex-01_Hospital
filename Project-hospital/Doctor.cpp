#include "doctor.h"

Doctor::Doctor(const string name, const string inSpecialty)
	: StaffMember(name)
{
	////specialty = strdup(inSpecialty);
	specialty = inSpecialty;
}

Doctor::Doctor(const Doctor& other)
	: StaffMember(other)
{

	if (this!=&other)
	{
		////delete[] specialty;
		////this->specialty = strdup(other.specialty);
		this->specialty = other.specialty;
	}
}

Doctor::~Doctor()
{
	////delete[] specialty;
}


const string Doctor::getSpciality()const
{
	return specialty;
}	

void Doctor::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Doctor." << "\n\tSpecialty: " << this->specialty;
}
