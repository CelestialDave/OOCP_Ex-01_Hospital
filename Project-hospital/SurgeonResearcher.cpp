#include "SurgeonResearher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher)
	: StaffMember(surgeon.getName(), surgeon.getEmployeeIDNumber()), Doctor(surgeon), Surgeon(surgeon), Researcher(researcher)
{}

ostream& operator<<(ostream& os, const SurgeonResearcher& surgeonResearcher)
{
	os << (StaffMember&)surgeonResearcher << "\tRole: Surgeon-Researcher" << "\n\tSpecialty: " << surgeonResearcher.specialty
		<< "\n\tNumber of Surgeries Performed: " << surgeonResearcher.numSurgeries << "\tArticles Published: " << surgeonResearcher.logSizeOfArticles;
	return os;
}
