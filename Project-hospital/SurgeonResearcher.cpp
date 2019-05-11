#include "SurgeonResearher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher)
	: StaffMember(surgeon.getName(), surgeon.getEmployeeIDNumber()), Surgeon(surgeon), Researcher(researcher)
{}
