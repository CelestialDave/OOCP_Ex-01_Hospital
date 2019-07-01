#include "ResearcherDoctor.h"

ResearcherDoctor::ResearcherDoctor(const Researcher & researcher, const Doctor& doctor)
	:StaffMember(researcher.getName())
	,Researcher(researcher), Doctor(doctor)
{}

ResearcherDoctor::ResearcherDoctor(ifstream& inFile) : StaffMember(inFile),
Doctor(inFile),Researcher(inFile)
{}

void ResearcherDoctor::toOs(ostream& os) const
{
	os << articleStock.getlogicSize() << endl;
	for (int i = 0; i < articleStock.getlogicSize(); i++)
		os << *(articleStock[i]);
	os << specialty << endl;
}

void ResearcherDoctor::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Doctor-Researcher." << "\n\tSpecialty: " << this->specialty
		<< "\n\tNumber of Articles published: " << this->articleStock.getlogicSize();
}
