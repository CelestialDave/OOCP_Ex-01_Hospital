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
	void reallocationArr();
	bool addArticeToResearcher(Article& art, Researcher* researcher);
	bool getResearcherByName(const char*name, Researcher*researcher);

	bool binSearchResearcherByName(Researcher** arr, int size, const char* name,
	Researcher* researcher);
};
#endif
