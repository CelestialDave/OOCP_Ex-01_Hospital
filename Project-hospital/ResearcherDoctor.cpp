#include "ResearcherDoctor.h"

ResearcherDoctor::ResearcherDoctor(const Researcher & researcher, const Doctor& doctor)
	:StaffMember(researcher.getName(),doctor.getEmployeeIDNumber())
	,Researcher(researcher), Doctor(doctor)
{

}
