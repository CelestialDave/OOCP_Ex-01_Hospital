#include "nurse.h"

Nurse::Nurse(const string name,int inYearExp) 
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
