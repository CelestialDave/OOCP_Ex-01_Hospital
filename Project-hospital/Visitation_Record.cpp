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
	staffMemInChargeName = new char[strlen(inStaffMemInChargeName) + 1];
	strcpy(staffMemInChargeName, inStaffMemInChargeName);
	arrivalDate = inArrivalDate;
	visitationPurpose = new char[strlen(inVisitPurpose) + 1];
	strcpy(visitationPurpose, inVisitPurpose);
}

VisitationRecord::VisitationRecord(const VisitationRecord& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	id = new char[strlen(other.id) + 1];
	strcpy(id, other.id);
	gender = other.gender;
	dateOfBirth = other.dateOfBirth;
	staffMemInChargeName = new char[strlen(other.staffMemInChargeName) + 1];
	strcpy(staffMemInChargeName, other.staffMemInChargeName);	
	arrivalDate = other.arrivalDate;
	visitationPurpose = new char[strlen(other.visitationPurpose) + 1];
	strcpy(visitationPurpose, other.visitationPurpose);
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