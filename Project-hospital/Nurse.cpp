#include "nurse.h"

Nurse::Nurse(const char* name,int inYearExp)
	: StaffMember(name)
{
	yearsOfExperience = inYearExp; 
}

Nurse::~Nurse()
{}

int Nurse::getYearsOfExp()const
{
	return yearsOfExperience;
}

void Nurse::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Nurse." << "\n\tYears Of Experience: " << this->yearsOfExperience;
}
