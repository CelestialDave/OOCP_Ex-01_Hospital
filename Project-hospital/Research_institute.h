#ifndef Research_Institute__H
#define Research_Institute__H

#include "researcher.h"
#include "ConstantsAndGenFuncs.h"

class ResearchInstitute
{
private:
	char *name;
	Researcher** reasearchersArr;
	int logSizeOfResearchers;
	int phySizeOfResearchers;

public:
	// C'tor:
	ResearchInstitute(const char inName[MAX_NAME]);
	// Copy C'tor:
	ResearchInstitute(ResearchInstitute& other)=delete;
	// D'tor:
	~ResearchInstitute();
	bool addResearcher(Researcher& researcher);
	void showResearchers()   const;
	void reallocationArr();
};
#endif
