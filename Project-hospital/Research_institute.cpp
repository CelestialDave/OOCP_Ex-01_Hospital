#include "ConstantsAndGenFuncs.h"
#include "Research_institute.h"
#include "Utils.h"


ResearchInstitute::ResearchInstitute() {}

ResearchInstitute::~ResearchInstitute()
{
	freeResearchInstituteData();
}

void ResearchInstitute::freeResearchInstituteData()
{
	for (auto t : allResearchers)
	{
		if ((typeid(t).name() + 6, "Researcher") == 0)
			delete t;
	}
	allResearchers.clear();
}

const int ResearchInstitute:: getSize() const
{
	return allResearchers.size();
}

void ResearchInstitute::addResearcher(Researcher* inResearcher)
{
	allocationResearchersArr();
	allResearchers.push_back(inResearcher);
}


void ResearchInstitute::allocationResearchersArr()
{	
	if ((allResearchers.capacity() >= 1) && (allResearchers.size() == allResearchers.capacity())) //if there is no place in the array
		allResearchers.reserve(allResearchers.capacity() * 2);
}


void ResearchInstitute::showDoctorsResearchers() const throw (HospitalException)
{
	int j = 0;
	for (auto researcher : allResearchers)
	{
		ResearcherDoctor* researcherDoctor = dynamic_cast<ResearcherDoctor*>(researcher);
		SurgeonResearcher* surgeonResearcher = dynamic_cast<SurgeonResearcher*>(researcher);
		if (researcherDoctor)
		{
			cout << "\t" << j << "." << " Employee ID Number: " <<
				researcherDoctor->getEmployeeIDNumber() << "\n\tName: " <<
				researcherDoctor->getName() << "\n\t";
			researcherDoctor->showArticles();
			j++;
		}
		else if (surgeonResearcher)
		{
			cout << "\t" << j << "." << " Employee ID Number: " <<
				surgeonResearcher->getEmployeeIDNumber() << "\n\t\t" << "Name: " <<
				surgeonResearcher->getName() << "\n\t";
			surgeonResearcher->showArticles();
			j++;
		}
	}
	if (j == 0)
		throw ResearcherDoctorException();
	cout << endl;
}


void ResearchInstitute::showResearchers()  const
{
	if (!allResearchers.empty())
	{
		cout << "\nList of Researchers: " << endl;
		int i = 0;
		for (auto researcher : allResearchers)
		{
			cout << "\n\t" << ++i << ". " << "Employee ID Number: " <<
				researcher->getEmployeeIDNumber() << "\n\tName: " <<
				researcher->getName() << endl;
			researcher->showArticles();
		}
	}
	else
		cout << "No Researchers available in Research Institute." << endl;
}

void ResearchInstitute::showResearchersName() const
{

	if (!allResearchers.empty())
	{
		cout << "\nThe researchers: " << endl;
		int i = 0;
		for (auto researcher : allResearchers)
		{
			cout << "\t" << ++i << " ." << *(researcher) << endl;
		}
	}
	else
		cout << "No Researchers available in Research Institute." << endl;
}

Researcher* ResearchInstitute::getResearcherByName(const string name) throw (ResearcherDoesntExistException)
{
	try {
		return Utils::binSearch<Researcher*>(allResearchers, name, compareByName<Researcher>());
	}
	catch (NotFoundException& e)
	{
		throw ResearcherDoesntExistException();
	}
}


void ResearchInstitute::addArticeToResearcher(Article& art,Researcher* researcher)
{
	 researcher->addArticle(art);
}

Researcher* ResearchInstitute::getResearcherByIndex(int index) const
{
	return allResearchers[index];
}
