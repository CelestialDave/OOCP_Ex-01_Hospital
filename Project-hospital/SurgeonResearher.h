#ifndef __SURGEON_RESEARCHER_H
#define __SURGEON_RESEARCHER_H

#include "Surgeon.h"
#include "researcher.h"

class SurgeonResearcher : public Surgeon, public Researcher
{

public:
	SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher);
	SurgeonResearcher(ifstream& inFile);
	~SurgeonResearcher() {};

	virtual void toOs(ostream&os) const;

	virtual void print(ostream& os) const;
};

#endif // !__SURGEON_RESEARCHER_H

