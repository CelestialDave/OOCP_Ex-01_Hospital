#ifndef Research_Institute__H
#define Research_Institute__H

#include "researcher.h"
#include "Surgeon.h"
#include "SurgeonResearher.h"
#include "ResearcherDoctor.h"
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

	void showDoctorsResearchers() const;
	void showResearchers()   const;

	void addArticeToResearcher(Article& art, Researcher* researcher);
	const int getSize() const;
	Researcher* getResearcherByName(const char*name,bool&exist);
	Researcher* binSearchResearcherByName(Researcher** arr, int size, const char* name,bool&exist);
	Researcher* getResearcherByIndex(int index) const;
	void addResearcher(Researcher* inResearcher);
	int binSearchResearcherByID(const char*name);
	int getIndexForResearcherInsertion(const char*name);
	void pushResearchersFwdFromIndex(int index);
	void insertResearcherToArrInIndex(Researcher* newResearcher, int index);
	void allocationResearchersArr();

};
#endif
