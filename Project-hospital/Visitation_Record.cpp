#include "Visitation_Record.h"

VisitationRecord::VisitationRecord(Patient& inPatient, string inStaffMemInChargeName,
	Date& inArrivalDate, string inVisitPurpose)
{
	patient = &inPatient;
	staffMemInChargeName = inStaffMemInChargeName;
	arrivalDate = inArrivalDate;
	visitationPurpose = inVisitPurpose;
}

VisitationRecord::VisitationRecord(const VisitationRecord& other)
{
	patient = other.patient;
	staffMemInChargeName = other.staffMemInChargeName;
	arrivalDate = other.arrivalDate;
	visitationPurpose = other.visitationPurpose;
}

VisitationRecord::~VisitationRecord() {}

const string VisitationRecord::getstaffMemInChargeName() const
{
	return staffMemInChargeName;
}

Date VisitationRecord::getArrivalDate() const
{
	return arrivalDate;
}

const string VisitationRecord::getVisitationDescription() const
{
	return visitationPurpose;
}
