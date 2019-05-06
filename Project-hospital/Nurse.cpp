#include "nurse.h"

Nurse::Nurse(const StaffMember& staffMember, int inYearExp)
	: StaffMember(staffMember)
{
	yearsOfExperience = inYearExp; 
}

Nurse::Nurse(const Nurse& other)
	// ???
	: StaffMember(other)
{
	if (this->yearsOfExperience != other.yearsOfExperience)
		this->yearsOfExperience = other.yearsOfExperience;
}

Nurse::~Nurse()
{}

int Nurse::getYearsOfExp()const
{
	return yearsOfExperience;
}
