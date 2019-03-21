#include "ConstantsAndGenFuncs.h"
#include "Research_institute.h"


ResearchInstitute::ResearchInstitute(const char inName[MAX_NAME])
{
	copyName(inName, name); // function copy the name
	reasearchersArr = nullptr;
	logSizeOfResearchers = 0;
	phySizeOfResearchers = 0;
}

ResearchInstitute::~ResearchInstitute()
{
	delete[]name;
	for (int i = 0; i < logSizeOfResearchers; i++)
		delete reasearchersArr[i];
	delete []reasearchersArr;
}

bool ResearchInstitute::addResearcher(Researcher& researcher)
{
	if (phySizeOfResearchers == 0) //if the first researcher
	{
		reasearchersArr = new Researcher*;
		phySizeOfResearchers++;
	}
	else if (logSizeOfResearchers == phySizeOfResearchers) //if there is no place in the array
	{
		phySizeOfResearchers *= 2;
		reallocationArr();  //to reallocte the array to the new size
	}

	if (logSizeOfResearchers < phySizeOfResearchers)
	{
		reasearchersArr[logSizeOfResearchers] = &researcher;
		logSizeOfResearchers++;
	}
	return true;
}

void ResearchInstitute::reallocationArr()
{
	Researcher** newArr = new Researcher*[phySizeOfResearchers];
	for (int i = 0; i < logSizeOfResearchers; i++)
		newArr[i] = reasearchersArr[i];
	delete[]reasearchersArr;
	reasearchersArr = newArr;
}

void ResearchInstitute::showResearchers()  const
{
	for (int i = 0; i < logSizeOfResearchers; i++)
		cout << reasearchersArr[i]->getName << ",";
	cout << endl;
}



