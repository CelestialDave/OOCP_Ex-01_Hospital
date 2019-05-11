#include "Visitation_Record.h"

VisitationRecord::VisitationRecord(Patient& inPatient, char* inStaffMemInChargeName,
	Date& inArrivalDate, char* inVisitPurpose)
{
	patient = &inPatient;
	staffMemInChargeName = new char[strlen(inStaffMemInChargeName) + 1];
	strcpy(staffMemInChargeName, inStaffMemInChargeName);
	arrivalDate = inArrivalDate;
	visitationPurpose = new char[strlen(inVisitPurpose) + 1];
	strcpy(visitationPurpose, inVisitPurpose);
}

VisitationRecord::VisitationRecord(const VisitationRecord& other)
{
	patient = other.patient;
	staffMemInChargeName = new char[strlen(other.staffMemInChargeName) + 1];
	strcpy(staffMemInChargeName, other.staffMemInChargeName);	
	arrivalDate = other.arrivalDate;
	visitationPurpose = new char[strlen(other.visitationPurpose) + 1];
	strcpy(visitationPurpose, other.visitationPurpose);
}

VisitationRecord::~VisitationRecord()
{
	delete[] staffMemInChargeName;
	delete[] visitationPurpose;
}

const char* VisitationRecord::getstaffMemInChargeName() const
{
	return staffMemInChargeName;
}

Date VisitationRecord::getArrivalDate() const
{
	return arrivalDate;
}

void VisitationRecord::showDate() const
{
	arrivalDate.showDate();
}

void VisitationRecord:: printVisitationPurpose() const
{
	cout << visitationPurpose;
};