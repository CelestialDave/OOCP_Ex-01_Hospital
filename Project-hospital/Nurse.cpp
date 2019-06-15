#include "nurse.h"

Nurse::Nurse(const string name,int inYearExp) 
	: StaffMember(name)
{
	yearsOfExperience = inYearExp; 
}


Nurse::Nurse(ifstream& inFile) : StaffMember(inFile)
{
	inFile >> *this;
}

Nurse::~Nurse() {}


ifstream& operator >> (ifstream& inFile, Nurse& nurse) 
{
	string tempYearsOfExperience;
	getline(inFile, tempYearsOfExperience);
	nurse.yearsOfExperience=(stoi(tempYearsOfExperience));
	return inFile;
}

int Nurse::getYearsOfExp()const
{
	return yearsOfExperience;
}



void Nurse:: toOs(ostream& os) const
{
	os << yearsOfExperience << endl;
}

void Nurse::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Nurse." << "\n\tYears Of Experience: " << this->yearsOfExperience;
}


