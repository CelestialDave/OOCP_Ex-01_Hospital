#ifndef Research_Institute__H
#define Research_Institute__H

#include "researcher.h"

class ResearchInstitute
{
private:
	char*name;
	Researcher** arr;
	int numResearchers;

public:
	ResearchInstitute(char* name, Researcher**arr, int numResearchers);
	ResearchInstitute(const ResearchInstitute& other);
	~ResearchInstitute();
	void addResearcher(Researcher* researcher);
	void showResearchers()   const;
};
#endif
