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
	vector<Researcher*> allResearchers;

public:
	// C'tor:
	ResearchInstitute();
	// Copy C'tor:
	ResearchInstitute(const ResearchInstitute& other)=delete;
	// D'tor:
	~ResearchInstitute();

	void freeResearchInstituteData();

	void showDoctorsResearchers() const throw(HospitalException);
	void showResearchers()   const;
	void showResearchersName() const;


	void addArticeToResearcher(Article& art, Researcher* researcher);
	const int getSize() const;

	Researcher* getResearcherByName(const string name) throw (ResearcherDoesntExistException);
	Researcher* getResearcherByIndex(int index) const;
	void addResearcher(Researcher* inResearcher);
	void allocationResearchersArr();

};
#endif
