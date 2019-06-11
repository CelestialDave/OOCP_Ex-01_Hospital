#include "ConstantsAndGenFuncs.h"
#include "Research_institute.h"
#include "Utils.h"


ResearchInstitute::ResearchInstitute()
{
	/*allResearchers = nullptr;
	logSizeOfResearchers = 0;
	phySizeOfResearchers = 0;*/

}

ResearchInstitute::~ResearchInstitute()
{
	////for (int i = 0; i < logSizeOfResearchers; i++)
	////{
	////	// Vaidate current Researcher obj is purely a researcher;
	////	//	i.e. The rest will be released from Hospital::StaffMember*[] by ~Hospital()
	////	if ((typeid(allResearchers[i]).name() + 6, "Researcher") == 0)
	////		delete allResearchers[i];
	////}
	////delete[] allResearchers;

	for (auto t : allResearchers)
	{
		delete t;
	}
}

const int ResearchInstitute:: getSize() const
{
	//return logSizeOfResearchers;
	return allResearchers.size();
}

void ResearchInstitute::addResearcher(Researcher* inResearcher)
{
	//vector<Researcherr*>::iterator pos;
	allocationResearchersArr();
	/////*if (allResearchers.size() == 0)
	////	index = 0;
	////else
	////	index = getIndexForResearcherInsertion(inResearcher->getName());

	////insertResearcherToArrInIndex(inResearcher, index);*/
	allResearchers.push_back(inResearcher);
}



////int ResearchInstitute::binSearchResearcherByID(const string name)
////{
////	int left = 0;
////	int right = logSizeOfResearchers - 1;
////	while (left <= right)
////	{
////		int mid = left + (right - left) / 2;
////
////		int res = name.compare( allResearchers[mid]->getName());
////		if (res == 0) // found the index
////			return mid;
////
////		if (res > 0) // go right
////			left = mid + 1;
////
////		else // (res < 0) => go left
////			right = mid - 1;
////	}
////
////	// Not found:
////	return -1;
////}

//////int ResearchInstitute::getIndexForResearcherInsertion(const string name)
//////{
//////	for (int i = 0; i < logSizeOfResearchers; i++)
//////	{
//////		int res = allResearchers[i]->getName().compare(name);
//////		if (res == 1)
//////			return i;
//////	}
//////	return logSizeOfResearchers; // to be inserted last
//////	
//////}

////vector<Researcher*>::iterator ResearchInstitute::getIndexForResearcherInsertion(Researcher& researcher)
////{
////	vector<Researcher*>::iterator itr = allResearchers.begin();
////	vector<Researcher*>::iterator itrEnd = allResearchers.end();
////	
////	for (; itr != itrEnd; itr++)
////	{
////		if ((*itr)->getEmployeeIDNumber() >= researcher.getEmployeeIDNumber());
////			return itr;
////	}
////	return itrEnd; // to be inserted last
////}



////void ResearchInstitute::pushResearchersFwdFromIndex(int index)
////{
////	for (int i = logSizeOfResearchers; i > index; i--) {
////		allResearchers[i] = allResearchers[i - 1];
////	}
////	allResearchers[index] = nullptr;
////}

//////void ResearchInstitute::insertResearcherToArrInIndex(Researcher* newResearcher, int index)
//////{
//////	pushResearchersFwdFromIndex(index);
//////	allResearchers[index] = newResearcher;
//////	logSizeOfResearchers++;
//////}

////void ResearchInstitute::insertResearcherToArrInIndex(Researcher* newResearcher, vector<Researcher*>::iterator pos)
////{
////	allResearchers.insert(pos, newResearcher);
////}

void ResearchInstitute::allocationResearchersArr()
{	
	if ((allResearchers.capacity() >= 1) && (allResearchers.size() == allResearchers.capacity())) //if there is no place in the array
		allResearchers.reserve(allResearchers.capacity() * 2);
}

////void ResearchInstitute::showDoctorsResearchers() const throw (HospitalException)
////{
////	int j=0;
////	for (int i = 0; i < logSizeOfResearchers; i++)
////	{
////		ResearcherDoctor* researcherDoctor = dynamic_cast<ResearcherDoctor*>(allResearchers[i]);
////		SurgeonResearcher* surgeonResearcher = dynamic_cast<SurgeonResearcher*>(allResearchers[i]);
////		if (researcherDoctor) 
////		{
////			cout << "\t" <<j<< "."<<" Employee ID Number: "<<
////			researcherDoctor->getEmployeeIDNumber()<<"\n\tName: "<<
////			researcherDoctor->getName() << "\n\t";
////			researcherDoctor->showArticles();
////			j++;
////		}
////		else if(surgeonResearcher)
////		{
////			cout << "\t" <<j<< "." << " Employee ID Number: " <<
////			surgeonResearcher->getEmployeeIDNumber() <<"\n\t\t"<<"Name: "<<
////			surgeonResearcher->getName() << "\n\t";
////			surgeonResearcher->showArticles();
////			j++;
////		}
////	} 
////	if (j == 0)
////		throw ResearcherDoctorException();
////	cout << endl;
////}


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


////void ResearchInstitute::showResearchers()  const
////{
////	if (logSizeOfResearchers)
////	{
////		cout << "\nList of Researchers: " << endl;
////		for (int i = 0; i < logSizeOfResearchers; i++)
////		{
////			cout << "\n\t" << i + 1 << ". " << "Employee ID Number: "<<
////			allResearchers[i]->getEmployeeIDNumber()<< "\n\tName: "<<
////			allResearchers[i]->getName() << endl;
////			allResearchers[i]->showArticles();
////		}
////	}
////	else
////		cout << "No Researchers available in Research Institute." << endl;
////}

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
			////cout << "\t" << ++i << " .";
			////cout << researcher->getName() << endl;
			cout << "\t" << ++i << " ." << *(researcher) << endl;
		}
	}
	else
		cout << "No Researchers available in Research Institute." << endl;
}

////template <class ArrType, class VAL, class compareFunction>
////vector<ArrType>::iterator binSearch(ArrType arr[] ,size_t size, const VAL val, compareFunction f, bool &exist)
////{
////
////	ArrType mid = arr[size / 2];
////	compareFunction
////	//int res = name.compare(midReasercher->getName());
////	int res = f(midReasercher, val);
////	if (size == 1)
////	{
////		if (res == 0) 
////		{
////			exist = true;
////			return midReasercher;
////		}
////		else
////		{
////			throw ResearcherDoesntExistException();
////			return nullptr;
////		}
////	}
////	else 
////	{	
////		int leftSize = size / 2;
////		int secondSize = size - leftSize - 1;
////		if (res == 0)
////		{
////			exist = true;
////			return midReasercher;
////		}
////		else if (res < 0)
////			return binSearchResearcherByName(arr, leftSize, name,exist);
////		else if (res > 0)
////			return binSearchResearcherByName(arr+ leftSize+1, secondSize, name,exist);
////	}
////}


////template <class T>
////class compareNames
////{
////public:
////	bool operator()(const T& a, const T& b) const
////	{
////
////	}
////};

////int ResearchInstitute::compareResearcerNames(const Researcher* researcher, const string name) const
////{
////	//return (a.getName() < b.getName());
////	return researcher->getName().compare(name);
////}


Researcher* ResearchInstitute::getResearcherByName(const string name) throw (ResearcherDoesntExistException)
{
	//return binSearchResearcherByName(allResearchers, logSizeOfResearchers, name, exist);
	try {
		//vector<Researcher*>::iterator res = Utils::binSearch<Researcher*>(allResearchers, name, compareResearcerNames);
		//compareResearcerNames compareFunc;
		return Utils::binSearch<Researcher*>(allResearchers, name, compareResearcerNames<string>());
		//return (*res);
	}
	catch (NotFoundException& e)
	{
		throw ResearcherDoesntExistException();
	}
}

////Researcher* ResearchInstitute::getResearcherByName(const string name, bool &exist)
////{
////	//return binSearchResearcherByName(allResearchers, logSizeOfResearchers, name, exist);
////	BinarySearch
////	if (binary_search(allResearchers.begin(), allResearchers.end(), compareResearcerNames))
////		return
////	else
////
////
////}

////Researcher*  ResearchInstitute::binSearchResearcherByName(Researcher** arr,int size,const string name,
////	bool &exist) throw(ResearcherDoesntExistException)
////{
////	Researcher* midReasercher = arr[size / 2];
////	int res = name.compare(midReasercher->getName());
////	if (size == 1)
////	{
////		if (res == 0) 
////		{
////			exist = true;
////			return midReasercher;
////		}
////		else
////		{
////			throw ResearcherDoesntExistException();
////			return nullptr;
////		}
////	}
////	else 
////	{	
////		int leftSize = size / 2;
////		int secondSize = size - leftSize - 1;
////		if (res == 0)
////		{
////			exist = true;
////			return midReasercher;
////		}
////		else if (res < 0)
////			return binSearchResearcherByName(arr, leftSize, name,exist);
////		else if (res > 0)
////			return binSearchResearcherByName(arr+ leftSize+1, secondSize, name,exist);
////	}
////}


////Researcher*  ResearchInstitute::binSearchResearcherByName(Researcher** arr, int size, const string name,
////	bool &exist) throw(ResearcherDoesntExistException)
////{
////	if (binary_search(allResearchers.begin(), allResearchers.end(), compareResearcerNames))
////
////	else
////
////}

void ResearchInstitute::addArticeToResearcher(Article& art,Researcher* researcher)
{
	 researcher->addArticle(art);
}

Researcher* ResearchInstitute::getResearcherByIndex(int index) const
{
	return allResearchers[index];
}






