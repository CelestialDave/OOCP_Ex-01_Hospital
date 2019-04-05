#ifndef Research_Institute__H
#define Research_Institute__H

#include "researcher.h"
#include "ConstantsAndGenFuncs.h"

class ResearchInstitute
{
private:
	Researcher** allResearchers;
	int logSizeOfResearchers;
	int phySizeOfResearchers;

public:
	//ResearchInstitute() = default;
	// C'tor:
	ResearchInstitute();
	// Copy C'tor:
	ResearchInstitute(const ResearchInstitute& other)=delete;
	// D'tor:
	~ResearchInstitute();
	bool addResearcher(Researcher& researcher);
	void showResearchers()   const;
	void allocationResearchersArr();
	void addArticeToResearcher(Article& art, Researcher* researcher);
	Researcher* getResearcherByName(const char*name,bool&exist);
	Researcher* binSearchResearcherByName(Researcher** arr, int size, const char* name,bool&exist);
};
#endif
