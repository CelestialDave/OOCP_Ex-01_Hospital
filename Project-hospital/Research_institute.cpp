#include "Constants.h"
#include "Research_institute.h"
#include <string.h>


ResearchInstitute::ResearchInstitute(const char inName[MAX_NAME])
{

	//to call the strcpy function
	reasearchersArr = nullptr;
	logSizeOfResearchers = 0;
	phySizeOfResearchers = 0;
}

ResearchInstitute::~ResearchInstitute()
{
	for (int i = 0; i < logSizeOfResearchers; i++)
		delete reasearchersArr[i];
	delete []reasearchersArr;
}

void ResearchInstitute::addResearcher(Researcher& researcher)
{
	if (phySizeOfResearchers == 0) //if the first researcher
	{
		reasearchersArr = new Researcher*(&researcher);
		logSizeOfResearchers++;
		phySizeOfResearchers++;
	}
	else
	{
		if (logSizeOfResearchers == phySizeOfResearchers) //if there is no place in the array
		{
			phySizeOfResearchers *= 2;
			reallocationArr();  //to reallocte the array to the new size
		}
		reasearchersArr[logSizeOfResearchers] = &researcher;
		logSizeOfResearchers++;

	}
}

void ResearchInstitute::reallocationArr()
{
	Researcher** newArr = new Researcher*[phySizeOfResearchers];
	for (int i = 0; i < logSizeOfResearchers; i++)
		newArr[i] = reasearchersArr[i];
	free(reasearchersArr);
	reasearchersArr = newArr;
}

void ResearchInstitute::showResearchers()   const
{
	char*temp;
	for (int i = 0; i < logSizeOfResearchers; i++)
	{
		temp = reasearchersArr[i]->getName;
		cout << temp << ",";
	}
	cout << endl;
}


