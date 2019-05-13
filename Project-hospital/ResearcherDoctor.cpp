#include "ResearcherDoctor.h"

ResearcherDoctor::ResearcherDoctor(const Researcher & researcher, const Doctor& doctor)
	:StaffMember(researcher.getName(),doctor.getEmployeeIDNumber())
	,Researcher(researcher), Doctor(doctor)
{

}

void ResearcherDoctor::print(ostream& os) const
{
	StaffMember::print(os);
	os << "\tRole: Doctor-Researcher." << "\n\tSpecialty: " << this->specialty
		<< "\n\tNumber of Articles published: " << this->logSizeOfArticles;
}

ostream& operator<<(ostream& os, const ResearcherDoctor& researcherDoc)
{
	researcherDoc.print(os);
	return os;
}