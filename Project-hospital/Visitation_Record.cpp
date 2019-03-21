#include "Visitation_Record.h"

VisitationRecord::VisitationRecord(const char* inStaffMemInChargeName,
	const Date inArrivalDate, const char* inVisitPurpose)
{
	name = nullptr;
	id = nullptr;
	gender = N_A;
	dateOfBirth=Date(0,0,0);     /*********/
	
	/*copyName(inName, name);
	copyName(ID, id);
	gender = inGender;
	dateOfBirth = inDateOfBirth;*/
	copyName(inStaffMemInChargeName, staffMemInChargeName);
	arrivalDate = inArrivalDate;
	copyName(inVisitPurpose, visitationPurpose);
}

VisitationRecord::VisitationRecord(const VisitationRecord& other)
{
	copyName(other.name, name);
	copyName(other.id, id);
	gender = other.gender;
	dateOfBirth = other.dateOfBirth;
	copyName(other.staffMemInChargeName,staffMemInChargeName);
	arrivalDate = other.arrivalDate;
	copyName(other.visitationPurpose, visitationPurpose);
}

VisitationRecord::~VisitationRecord()
{
	delete[]staffMemInChargeName;
	delete[]visitationPurpose;
}

char* VisitationRecord::getstaffMemInChargeName() const
{
	return staffMemInChargeName;
}
void VisitationRecord::showDate() const
{
	arrivalDate.showDate();
}

void VisitationRecord:: printVisitationPurpose() const
{
	cout << visitationPurpose << endl;
};