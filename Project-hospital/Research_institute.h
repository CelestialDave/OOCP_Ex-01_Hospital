#ifndef Research_Institute__H
#define Research_Institute__H

#include "researcher.h"

class ResearchInstitute
{
private:
	char* name;
	Researcher** reasearchersArr;
	int logSizeOfResearchers;
	int phySizeOfResearchers;

public:
	// C'tor:
	ResearchInstitute(const char* inName);
	// Copy C'tor:
	ResearchInstitute(const ResearchInstitute& other);
	// D'tor:
	~ResearchInstitute();
	void addResearcher(const Researcher& researcher);
	void showResearchers()   const;
};

#endif
