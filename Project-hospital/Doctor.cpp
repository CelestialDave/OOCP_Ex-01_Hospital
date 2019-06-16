#include "doctor.h"

Doctor::Doctor(const string name, const string inSpecialty)
	: StaffMember(name)
{
	specialty = inSpecialty;
}

Doctor::Doctor(ifstream& inFile) : StaffMember(inFile)
{
	inFile >> *this;
}

Doctor::Doctor(const Doctor& other)
	: StaffMember(other)
{

	if (this!=&other)
	{
		this->specialty = other.specialty;
	}
}

Doctor::~Doctor() {}


const string Doctor::getSpciality()const
{
	return specialty;
}	

void Doctor::toOs(ostream& os) const
{
	os << specialty << endl;
}

void Doctor::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Doctor." << "\n\tSpecialty: " << this->specialty;
}

ifstream& operator >> (ifstream& inFile, Doctor& doctor)
{
	getline(inFile, doctor.specialty);
	return inFile;
}
