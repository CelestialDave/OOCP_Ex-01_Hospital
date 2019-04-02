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
		reallocationArr();  //to reallocte the array to the new size
	}

	if (logSizeOfResearchers < phySizeOfResearchers)
	{
		allResearchers[logSizeOfResearchers] = &researcher;
		logSizeOfResearchers++;
	}
	return true;
}

void ResearchInstitute::reallocationArr()
{
	Researcher** newArr = new Researcher*[phySizeOfResearchers];
	for (int i = 0; i < logSizeOfResearchers; i++)
		newArr[i] = allResearchers[i];
	delete[]allResearchers;
	allResearchers = newArr;
}

void ResearchInstitute::showResearchers()  const
{
	for (int i = 0; i < logSizeOfResearchers; i++)
	{
		cout << allResearchers[i]->getName() << endl;
		allResearchers[i]->showArticles();
	}
	cout <<"*******************************"<< endl;
}

bool ResearchInstitute::getResearcherByName(const char*name, Researcher*researcher)
{
	return binSearchResearcherByName(allResearchers, logSizeOfResearchers, name, researcher);
}

bool ResearchInstitute::binSearchResearcherByName(Researcher** arr,int size,const char* name,
	Researcher* researcher)
{
	Researcher* midReasercher = arr[size / 2];
	int res = strcmp(name, midReasercher->getName());
	if (size == 1)
	{
		if (res == 0) {
			researcher = midReasercher;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (res == 0)
		{
			researcher = midReasercher;
			return true;
		}
		else if (res < 0)
			return binSearchResearcherByName(arr, size / 2, name, researcher);
		else if (res > 0)
			return binSearchResearcherByName(arr+size/2, size - (size / 2), name, researcher);
	}
}

bool ResearchInstitute::addArticeToResearcher(Article& art,Researcher* researcher)
{
	return (researcher->addArticle(art));
}




