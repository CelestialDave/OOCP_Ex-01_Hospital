#include "ConstantsAndGenFuncs.h"
#include "Research_institute.h"


ResearchInstitute::ResearchInstitute()
{
	allResearchers = nullptr;
	logSizeOfResearchers = 0;
	phySizeOfResearchers = 0;
}

ResearchInstitute::~ResearchInstitute()
{
	for (int i = 0; i < logSizeOfResearchers; i++)
		delete allResearchers[i];
	delete []allResearchers;
}

bool ResearchInstitute::addResearcher(Researcher& researcher)
{
	if (phySizeOfResearchers == 0) //if the first researcher
	{
		allResearchers = new Researcher*;
		phySizeOfResearchers++;
	}
	else if (logSizeOfResearchers == phySizeOfResearchers) //if there is no place in the array
	{
		phySizeOfResearchers *= 2;
		allocationResearchersArr();  //to reallocte the array to the new size
	}

	if (logSizeOfResearchers < phySizeOfResearchers)
	{
		allResearchers[logSizeOfResearchers] = &researcher;
		logSizeOfResearchers++;
	}
	return true;
}

void ResearchInstitute::allocationResearchersArr()
{
	if (phySizeOfResearchers == 0) // If this is the 1st Department
	{
		allResearchers = new Researcher*;
		phySizeOfResearchers++;
	}
	else if (logSizeOfResearchers == phySizeOfResearchers) //if there is no place in the array
	{
		phySizeOfResearchers *= 2;
		Researcher** newArr = new Researcher*[phySizeOfResearchers];
		for (int i = 0; i < logSizeOfResearchers; i++)
		{
			newArr[i] = allResearchers[i];
		}
		delete[] allResearchers;
		allResearchers = newArr;
	}
	else
		return;
}

void ResearchInstitute::showResearchers()  const
{
	for (int i = 0; i < logSizeOfResearchers; i++)
	{
		cout << allResearchers[i]->getName() << endl;
		allResearchers[i]->showArticles();
	}
}

Researcher* ResearchInstitute::getResearcherByName(const char*name, bool &exist)
{
	return binSearchResearcherByName(allResearchers, logSizeOfResearchers, name, exist);
}

Researcher*  ResearchInstitute::binSearchResearcherByName(Researcher** arr,int size,const char* name,
	bool &exist)
{
	Researcher* midReasercher = arr[size / 2];
	int res = strcmp(name, midReasercher->getName());
	if (size == 1)
	{
		if (res == 0) 
		{
			exist = true;
			return midReasercher;
		}
		else
		{
			return nullptr;
		}
	}
	else 
	{	
		int leftSize = size / 2;
		int secondSize = size - leftSize - 1;
		if (res == 0)
		{
			exist = true;
			return midReasercher;
		}
		else if (res < 0)
			return binSearchResearcherByName(arr, leftSize, name,exist);
		else if (res > 0)
			return binSearchResearcherByName(arr+ leftSize+1, secondSize, name,exist);
	}
}

bool ResearchInstitute::addArticeToResearcher(Article& art,Researcher* researcher)
{
	return (researcher->addArticle(art));
}




