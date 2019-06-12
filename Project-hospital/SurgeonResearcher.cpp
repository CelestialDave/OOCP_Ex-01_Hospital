#include "SurgeonResearher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher)
	: StaffMember(surgeon.getName()), Doctor(surgeon), Surgeon(surgeon), Researcher(researcher)
{
}

SurgeonResearcher::SurgeonResearcher(ifstream& inFile) : StaffMember(inFile),
Doctor(inFile), Surgeon(inFile), Researcher(inFile)
{

}


void SurgeonResearcher::toOs(ostream&os) const
{
	os << specialty << endl;
	os<< numSurgeries << endl;
	os << articleStock.getlogicSize() << endl;
	for (int i = 0; i < articleStock.getlogicSize(); i++)
		os << *(articleStock[i]);
}

void SurgeonResearcher::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Surgeon-Researcher" << "\n\tSpecialty: " << this->specialty
		<< "\n\tNumber of Surgeries Performed: " << this->numSurgeries << "\tArticles Published: " << this->articleStock.getlogicSize();
}

