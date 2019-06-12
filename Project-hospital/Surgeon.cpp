#include "Surgeon.h"
#include "ConstantsAndGenFuncs.h"

Surgeon::Surgeon(const Doctor& doctor, int numSurgeries) :
	StaffMember(doctor.getName()), Doctor(doctor)
{
	this->numSurgeries = numSurgeries;
}

Surgeon::Surgeon(ifstream& inFile) : StaffMember(inFile),Doctor(inFile)
{
	inFile >> *this;
}

ifstream& operator >> (ifstream& inFile, Surgeon& surgeon)
{
	string tempNumOfSurgeries;
	getline(inFile, tempNumOfSurgeries);
	surgeon.numSurgeries = stoi(tempNumOfSurgeries);
	return inFile;
}
Surgeon::~Surgeon() {}

int Surgeon:: getNumSurgeries() const
{
	return numSurgeries;
}

void Surgeon::addSurgery()
{
	numSurgeries++;
}

void Surgeon::toOs(ostream& os) const
{
	os << specialty << endl;
	os << numSurgeries << endl;
}

void Surgeon::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Surgeon." << "\n\tSpecialty: " << this->specialty
		<< "\n\tNumber of Surgeries Performed: " << this->numSurgeries;
}
