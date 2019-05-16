#include "Visit_Surgery.h"
#include "ConstantsAndGenFuncs.h"

VisitSurgery::VisitSurgery(const VisitationRecord & other, int surgeryRoomNum, bool fasting) : VisitationRecord(other)
{
	this->surgeryRoomNum = surgeryRoomNum;
	this->fasting = fasting;
}
int VisitSurgery::getSurgeryRoomNum() const
{
	return surgeryRoomNum;
}
bool VisitSurgery::getFasting()const
{
	return fasting;
}