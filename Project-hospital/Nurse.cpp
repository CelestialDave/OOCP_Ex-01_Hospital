#include "nurse.h"

Nurse::Nurse(const string name,int inYearExp) throw(NameException)
	: StaffMember(name)
{
	if (name == "")
		throw NameException();
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
