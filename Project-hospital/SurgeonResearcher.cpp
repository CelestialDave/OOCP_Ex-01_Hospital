#include "SurgeonResearher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher)
	: StaffMember(surgeon.getName(), surgeon.getEmployeeIDNumber()), Doctor(surgeon), Surgeon(surgeon), Researcher(researcher)
{}


void SurgeonResearcher::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Surgeon-Researcher" << "\n\tSpecialty: " << this->specialty
		<< "\n\tNumber of Surgeries Performed: " << this->numSurgeries << "\tArticles Published: " << this->logSizeOfArticles;
}

ostream& operator<<(ostream& os, const SurgeonResearcher& surgeonResearcher)
{
	surgeonResearcher.print(os);
	return os;
}
