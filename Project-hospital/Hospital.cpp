#include "Hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"
#include "Utils.h"

// C'tor:
Hospital::Hospital()
	: allDepartments(nullptr), staffArr(nullptr), allPatients(nullptr)
{
	logSizeOfDepartments = phySizeOfDepartments = logSizeOfStaff = 
		phySizeOfStaff = logSizeOfPatients = phySizeOfPatients = numOfSurgeons = 0;
}


Hospital::~Hospital()
{
	for (int i = 0; i < logSizeOfStaff; i++)
		delete staffArr[i];
	delete[] staffArr;

	for (int i = 0; i < logSizeOfDepartments; i++)
		delete allDepartments[i];
	delete[]allDepartments;
	for (int i = 0; i<logSizeOfPatients; i++)
		delete allPatients[i];
	delete[]allPatients;
}


void Hospital::allocDepartmentsArr()
{
	if (phySizeOfDepartments == 0) // If this is the 1st Department
	{
		allDepartments = new Department*;
		phySizeOfDepartments++;
	}
	else if (logSizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	{
		phySizeOfDepartments *= 2;
		Department** newArr = new Department*[phySizeOfDepartments];
		for (int i = 0; i < logSizeOfDepartments; i++)
		{
			newArr[i] = allDepartments[i];
		}
		delete[] allDepartments;
		allDepartments = newArr;
	}
	else
		return;
}


void Hospital::addResearcher(Researcher* inResearcher)
{
	researchInst.addResearcher(inResearcher);
}


void Hospital::allocStaffArr()
{
	if (phySizeOfStaff == 0) // If this is the 1st Department
	{
		staffArr = new StaffMember*;
		phySizeOfStaff++;
	}
	else if (logSizeOfStaff == phySizeOfStaff) //if there is no place in the array
	{
		phySizeOfStaff *= 2;
		StaffMember** newArr = new StaffMember*[phySizeOfStaff];
		for (int i = 0; i < logSizeOfStaff; i++)
		{
			newArr[i] = staffArr[i];
		}
		delete[] staffArr;
		staffArr = newArr;
	}
	else
		return;
}

void Hospital::addStaffMember(StaffMember* inStaffMember)
{
	int index;
	allocStaffArr();
	if (logSizeOfStaff == 0)
		index = 0;
	else
		// Find the index to push the staff member, maintainning asortment by EID
		index = getIndexForStaffMemberInsertion(inStaffMember->getEmployeeIDNumber());

	inserStaffMemberToArrInIndex(inStaffMember, index);
	Surgeon* tempSurgeon = dynamic_cast<Surgeon*>(inStaffMember);
	if (tempSurgeon) numOfSurgeons++;
}

void Hospital::inserStaffMemberToArrInIndex(StaffMember* newStaffMember, int index)
{
	pushStaffMembersFwdFromIndex(index);
	staffArr[index] = newStaffMember;
	logSizeOfStaff++;
}

void Hospital::pushStaffMembersFwdFromIndex(int index)
// Shifts all the staff members with greater employee ID number 1 position to the right
{
	for (int i = logSizeOfStaff; i > index; i--) {
		staffArr[i] = staffArr[i - 1];
	}
	staffArr[index] = nullptr;
}

int Hospital::getIndexForStaffMemberInsertion(int id) //the index to insert staff member
{
	bool isGreater = false;
	for (int i = 0; i < logSizeOfStaff; i++)
	{
		isGreater = (staffArr[i]->getEmployeeIDNumber() > id);
		if (isGreater) // Found the member to be on the right
		{
			return i;
		}
	}
	return logSizeOfStaff; // to be inserted last

}

int Hospital::binSearchStaffMemberByID(int inID)
{
	int left = 0;
	int right = logSizeOfStaff - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int res = (inID - staffArr[mid]->getEmployeeIDNumber());
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


void Hospital::addDepartment(Department& inDepartment)
{
	int index;
	allocDepartmentsArr();
	if (logSizeOfDepartments == 0)
		index = 0;
	else
		index = getIndexForDepartmentInsertion(inDepartment.getName());

	insertDepartmentToArrInIndex(inDepartment, index);
}

int Hospital::binSearchDepartmentByName(const string name) throw(StringException)
{
	if (!Utils::isValidString(name))
		throw StringException();
	int left = 0;
	int right = logSizeOfDepartments - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		////int res = strcmp(name, allDepartments[mid]->getName());
		////if (res == 0) // found the index
		if (name == allDepartments[mid]->getName()) // found the index
			return mid;

		////if (res > 0) // go right
		if (name > allDepartments[mid]->getName()) // go right
			left = mid + 1;

		else // (name < allDepartments[mid]->getName()) => go left
			right = mid - 1;
	}

	// Not found:
	return -1;
}
StaffMember* Hospital::getStaffMemberByIndex(int index) const
{
	return staffArr[index];
}

int Hospital::getIndexForDepartmentInsertion(const string name)
//find the index to insert the department to the right place according to alphabet
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		////int res = strcmp(allDepartments[i]->getName(),name);
		bool res = (allDepartments[i]->getName() > name);
		if(res)
			return i;
	}
	return logSizeOfDepartments; // to be inserted last

}

void Hospital::pushDepartmentsFwdFromIndex(int index)
{
	for (int i = logSizeOfDepartments; i > index; i--) {
		allDepartments[i] = allDepartments[i - 1];
	}
	allDepartments[index] = nullptr;
}

void Hospital::insertDepartmentToArrInIndex(Department& newDepartment, int index)
{
	pushDepartmentsFwdFromIndex(index); //make the place for insert department
	allDepartments[index] = &newDepartment;
	logSizeOfDepartments++;
}


void Hospital::allocPatientsArr()
{
	if (phySizeOfPatients == 0) // If this is the 1st Department
	{
		allPatients = new Patient*;
		phySizeOfPatients++;
		return;
	}
	else if (logSizeOfPatients == phySizeOfPatients) //if there is no place in the array
	{
		phySizeOfPatients *= 2;
		Patient** newArr = new Patient*[phySizeOfPatients];
		for (int i = 0; i < logSizeOfPatients; i++)
		{
			newArr[i] = allPatients[i];
		}
		delete[] allPatients;
		allPatients = newArr;
		return;
	}
	else
		return;
}

void Hospital::addPatient(Patient& inPatient) 
{
	int index;
	allocPatientsArr();
	if (logSizeOfPatients == 0)
		index = 0;
	else 
		 index = getIndexForPatientInsertion(inPatient.getId());
	//find the index to insert patient

	insertPatientToArrInIndex(inPatient, index);
}

void Hospital::showPatientInSpecificDep(const int &index) const
{
	allDepartments[index]->showPatients();
}

void Hospital::showMedicalStaffMembers() const throw(HospitalException)
{
	int j = 0;
	if (logSizeOfStaff)
	{
		cout << "Staff Members: " << endl;
		for (int i = 0; i < logSizeOfStaff; i++)
		{
			if (strcmp(typeid(*(staffArr[i])).name() + 6, typeid(Researcher).name() + 6) != 0)
			{	//print if staff member is not only Researcher
				cout << "\n\t" << j + 1 << ". " << *(staffArr[i]) << "\n\n";
				j++;
			}
		}
	}
	if (j == 0)
		throw StaffException();
}

void Hospital::showSurgeons() const throw(SurgeonException)
{
	int j = 1;
	if (numOfSurgeons)
	{
		for (int i = 0; i < logSizeOfStaff; i++)
		{
			Surgeon*surgeon = dynamic_cast<Surgeon*>(staffArr[i]);
			if (surgeon)
			{
				cout << "\t" << j << ". " << *(staffArr[i]) << endl;
				j++;
			}
		}
	}
	if (j == 1)
	{
		throw SurgeonException();
	}
}

void Hospital::showResearchersName() const
{
	researchInst.showResearchersName();
}
void Hospital::showResearchers() const
{
	researchInst.showResearchers();
}

void Hospital::showDoctorResearchers() const
{
	researchInst.showDoctorsResearchers();
}

void Hospital::showDepartments() const
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		cout << '\t' << i + 1 << ". " << allDepartments[i]->getName() << endl;
	}
}

Department* Hospital::getDepartmentByIndex(int ind)
{
		return allDepartments[ind];
}

int Hospital::getNumOfDepartments()
{
	return logSizeOfDepartments;
}

int Hospital::getNumOfSurgeons()
{
	return this->numOfSurgeons;
}

Patient* Hospital::getPatientByID(string inID, bool* isFound)
//if patient exist return his address
{
	int index;
	if (phySizeOfPatients == 0) // No patients available
	{
		*isFound = false;
		return nullptr;
	}
	else
	{
		 index = binSearchPatientByID(inID);
		 if (index != -1)
		 {
			 *isFound = true;
			 return allPatients[index];
		 }
		 else
		 {
			 *isFound = false;
			 return nullptr;
		 }
	}
}


int Hospital::binSearchPatientByID(string inID)
//find the index of patient according to his ID,else not found return -1
{
	int left = 0;
	int right = logSizeOfPatients - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int res = (stoi(inID) - stoi(allPatients[mid]->getId()));
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


int Hospital::getIndexForPatientInsertion(const string id) 
//find the right index to insert patient according to the ID number
{
	bool isGreater = false;
	for (int i = 0; i < logSizeOfPatients; i++)
	{
		isGreater = (stoi(allPatients[i]->getId()) > stoi(id));
		if (isGreater) // Found the member to be on the right
		{
			return i;
		}
	}
	return logSizeOfPatients; // to be inserted last
}

void Hospital::pushPatientsFwdFromIndex(int index)
//shift 1 right all patient that have bigger ID number
{
	for (int i = logSizeOfPatients; i > index; i--) {
		allPatients[i] = allPatients[i - 1];
	}
	allPatients[index] = nullptr;
}

void Hospital::insertPatientToArrInIndex(Patient& newPatient, int index)
{
	pushPatientsFwdFromIndex(index);
	allPatients[index] = &newPatient;
	logSizeOfPatients++;
}

bool Hospital::verifyEmployeeIDNumber(const int& employeeID) //check if employeeID dosent exist
{
	bool isExists = false;

	if (logSizeOfStaff)
		isExists = verifyStaffMemberEmployeeIDBinSearch(staffArr, logSizeOfStaff, employeeID);

	return isExists;
}


bool Hospital::verifyStaffMemberEmployeeIDBinSearch(StaffMember** arr, int size, const int& employeeID) 
{
		StaffMember* mid = arr[size / 2];
		if (logSizeOfStaff == 0)
			return false;
		else if (size == 1)
		{
			if (mid->getEmployeeIDNumber() == employeeID) 
				return true;
			else 
				return false;
		}
		else
		{
			if (mid->getEmployeeIDNumber() == employeeID)
				return true;
			int leftSize = size / 2;
			int rightSize = size - leftSize-1;
			if (mid->getEmployeeIDNumber() > employeeID)
				return verifyStaffMemberEmployeeIDBinSearch(arr, leftSize, employeeID);
			else if(mid->getEmployeeIDNumber() < employeeID)
				return verifyStaffMemberEmployeeIDBinSearch(arr+ leftSize+1, rightSize, employeeID);
		}
	return false;
}


bool Hospital::isDepartmentsEmpty() const
{
	return (logSizeOfDepartments == 0);
}

int Hospital::findTheIndexOfDepNameInDepArr(string str) const
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		////if(strcmp(allDepartments[i]->getName(),str)==0)
		if (allDepartments[i]->getName() == str)
			return i;
	}
	return -1;
}

void Hospital::addStaffMemberToDepartment(StaffMember* staffMember, int indexToIn)
{
	allDepartments[indexToIn]->addStaffMember(staffMember);
}

Researcher* Hospital::getResearcherByIndex(int index) const
{
	return researchInst.getResearcherByIndex(index);
}

Researcher* Hospital::findResearcherAccordingToName(const string name, bool&exist)
{
	return researchInst.getResearcherByName(name,exist);
}

void Hospital::addArticleToResearcher(Article & art, Researcher*researcher)
{
	researchInst.addArticeToResearcher(art, researcher);
}

const int Hospital::getSizeOfResearchers() const
{
	return  researchInst.getSize();
}

