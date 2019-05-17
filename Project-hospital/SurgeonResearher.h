#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{

public:
	SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher);
	~SurgeonResearcher() {}

	virtual void print(ostream& os) const;
	//friend ostream& operator<<(ostream& os, const SurgeonResearcher& surgeonResearcher);
};

#endif // !__SURGEON_RESEARCHER_H

