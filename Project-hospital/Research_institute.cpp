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
	delete[] allResearchers;
}

const int ResearchInstitute:: getSize() const
{
	return logSizeOfResearchers;
}

void ResearchInstitute::addResearcher(Researcher* inResearcher)
{
	int index;
	allocationResearchersArr();
	if (logSizeOfResearchers == 0)
		index = 0;
	else
		index = getIndexForResearcherInsertion(inResearcher->getName());

	insertResearcherToArrInIndex(inResearcher, index);
}

int ResearchInstitute::binSearchResearcherByID(const char*name)
{
	int left = 0;
	int right = logSizeOfResearchers - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int res = strcmp(name, allResearchers[mid]->getName());
		if (res == 0) // found the index
			return mid;

		if (res > 0) // go right
			left = mid + 1;

		else // (res < 0) => go left
			right = mid - 1;
	}

	// Not found:
	return -1;
}

int ResearchInstitute::getIndexForResearcherInsertion(const char*name)
{
	for (int i = 0; i < logSizeOfResearchers; i++)
	{
		int res = strcmp(allResearchers[i]->getName(), name);
		if (res == 1)
			return i;
	}
	return logSizeOfResearchers; // to be inserted last

}

void ResearchInstitute::pushResearchersFwdFromIndex(int index)
{
	for (int i = logSizeOfResearchers; i > index; i--) {
		allResearchers[i] = allResearchers[i - 1];
	}
	allResearchers[index] = nullptr;
}

void ResearchInstitute::insertResearcherToArrInIndex(Researcher* newResearcher, int index)
{
	pushResearchersFwdFromIndex(index);
	allResearchers[index] = newResearcher;
	logSizeOfResearchers++;
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

void ResearchInstitute::showDoctorsResearchers() const
{
	int j=1;
	for (int i = 0; i < logSizeOfResearchers; i++)
	{
		ResearcherDoctor* researcherDoctor = dynamic_cast<ResearcherDoctor*>(allResearchers[i]);
		SurgeonResearcher* surgeonResearcher = dynamic_cast<SurgeonResearcher*>(allResearchers[i]);
		if (researcherDoctor) 
		{
			cout << "\t" <<j<< "."<<" employee ID number: "<<
			researcherDoctor->getEmployeeIDNumber()<<"\n\t\tName: "<<
			researcherDoctor->getName() << endl;
			researcherDoctor->showArticles();
			j++;
		}
		else if(surgeonResearcher)
		{
			cout << "\t" <<j<< "." << " employee ID number: " <<
			surgeonResearcher->getEmployeeIDNumber() <<"\n\t\t"<<"Name: "<<
			surgeonResearcher->getName() << endl;
			surgeonResearcher->showArticles();
			j++;
		}
	}
	cout << endl;
}

void ResearchInstitute::showResearchers()  const
{
	if (logSizeOfResearchers)
	{
		cout << "\nThe researchers: " << endl;
		for (int i = 0; i < logSizeOfResearchers; i++)
		{
			cout << "\t" << i + 1 << " ." <<" employee ID number: "<<
			allResearchers[i]->getEmployeeIDNumber()<< "\n\t\tName: "<<
			allResearchers[i]->getName() << endl;
			allResearchers[i]->showArticles();
		}
	}
	else
		cout << "No Researchers available in Research Institute." << endl;
}

void ResearchInstitute::showResearchersName() const
{
	if (logSizeOfResearchers)
	{
		cout << "\nThe researchers: " << endl;
		for (int i = 0; i < logSizeOfResearchers; i++)
		{
			cout << "\t" << i + 1 << " .";
			cout << allResearchers[i]->getName() << endl;
		}
	}
	else
		cout << "No Researchers available in Research Institute." << endl;
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

void ResearchInstitute::addArticeToResearcher(Article& art,Researcher* researcher)
{
	 researcher->addArticle(art);
}

Researcher* ResearchInstitute::getResearcherByIndex(int index) const
{
	return allResearchers[index];
}






