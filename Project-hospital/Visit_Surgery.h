#ifndef  Visit_Surgery__H
#define  Visit_Surgery__H

#include "Visitation_Record.h"

class VisitSurgery : public VisitationRecord
{
private:
	int surgeryRoomNum;
	bool fasting;
public:
	VisitSurgery(const VisitationRecord & other, int surgeryRoomNum, bool fasting);
	int getSurgeryRoomNum() const;
	bool getFasting()const;
};

#endif // ! Visit_Surgery__H