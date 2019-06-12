#include "Hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"
#include "Utils.h"

// C'tor:
Hospital::Hospital()
	////: allDepartments(nullptr), staffArr(nullptr), allPatients(nullptr)
{
	/////*logSizeOfDepartments = phySizeOfDepartments = logSizeOfStaff = 
	////	phySizeOfStaff = logSizeOfPatients = phySizeOfPatients = numOfSurgeons = 0;*/
	numOfSurgeons = 0;
}


Hospital::~Hospital()
{
	for (auto t : staffArr)
		delete t;

	for (auto t : allDepartments)
		delete t;

	for (auto t : allPatients)
		delete t;
	/////*for (int i = 0; i < logSizeOfStaff; i++)
	////	delete staffArr[i];
	////delete[] staffArr;

	////for (int i = 0; i < logSizeOfDepartments; i++)
	////	delete allDepartments[i];
	////delete[]allDepartments;
	////for (int i = 0; i<logSizeOfPatients; i++)
	////	delete allPatients[i];
	////delete[]allPatients;*/
}


void Hospital::allocDepartmentsArr()
{
	if ((allDepartments.capacity() >= 1) && (allDepartments.size() == allDepartments.capacity())) //if there is no place in the array
		allDepartments.reserve(allDepartments.capacity() * 2);
	////if (phySizeOfDepartments == 0) // If this is the 1st Department
	////{
	////	allDepartments = new Department*;
	////	phySizeOfDepartments++;
	////}
	////else if (logSizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	////{
	////	phySizeOfDepartments *= 2;
	////	Department** newArr = new Department*[phySizeOfDepartments];
	////	for (int i = 0; i < logSizeOfDepartments; i++)
	////	{
	////		newArr[i] = allDepartments[i];
	////	}
	////	delete[] allDepartments;
	////	allDepartments = newArr;
	////}
	////else
	////	return;
}


void Hospital::addResearcher(Researcher* inResearcher)
{
	researchInst.addResearcher(inResearcher);
}


void Hospital::allocStaffArr()
{
	if ((staffArr.capacity() >= 1) && (staffArr.size() == staffArr.capacity())) //if there is no place in the array
		staffArr.reserve(staffArr.capacity() * 2);
	////if (phySizeOfStaff == 0) // If this is the 1st Department
	////{
	////	staffArr = new StaffMember*;
	////	phySizeOfStaff++;
	////}
	////else if (logSizeOfStaff == phySizeOfStaff) //if there is no place in the array
	////{
	////	phySizeOfStaff *= 2;
	////	StaffMember** newArr = new StaffMember*[phySizeOfStaff];
	////	for (int i = 0; i < logSizeOfStaff; i++)
	////	{
	////		newArr[i] = staffArr[i];
	////	}
	////	delete[] staffArr;
	////	staffArr = newArr;
	////}
	////else
	////	return;
}

void Hospital::addStaffMember(StaffMember* inStaffMember)
{
	int index;
	allocStaffArr();
	////if (logSizeOfStaff == 0)
	if (staffArr.empty())
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
	vector<StaffMember*>::iterator pos = staffArr.begin() + index;
	staffArr.insert(pos, newStaffMember);
	////pushStaffMembersFwdFromIndex(index);
	////staffArr[index] = newStaffMember;
	////logSizeOfStaff++;
}

////void Hospital::pushStaffMembersFwdFromIndex(int index)
////// Shifts all the staff members with greater employee ID number 1 position to the right
////{
////	for (int i = logSizeOfStaff; i > index; i--) {
////		staffArr[i] = staffArr[i - 1];
////	}
////	staffArr[index] = nullptr;
////}

int Hospital::getIndexForStaffMemberInsertion(int id) //the index to insert staff member
{
	bool isGreater = false;
	//for (int i = 0; i < logSizeOfStaff; i++)
	int size = staffArr.size();
	for (int i = 0; i < size; i++)
	{
		isGreater = (staffArr[i]->getEmployeeIDNumber() > id);
		if (isGreater) // Found the member to be on the right
		{
			return i;
		}
	}
	return size; // to be inserted last

}

StaffMember* Hospital::binSearchStaffMemberByID(int inID) throw (StaffMemberNotFoundException)
{
	////int left = 0;
	////int right = staffArr.size() - 1;
	////while (left <= right)
	////{
	////	int mid = left + (right - left) / 2;

	////	int res = (inID - staffArr[mid]->getEmployeeIDNumber());
	////	if (res == 0) // found the index
	////		return mid;

	////	if (res > 0) // go right
	////		left = mid + 1;

	////	else // (res < 0) => go left
	////		right = mid - 1;
	////}

	////// Not found:
	////return -1;
	
	////bool res = false;
	StaffMember* staffmember = nullptr;
	try {
		staffmember = Utils::binSearch<StaffMember*, int>(staffArr, inID, compareByEmployeeIDNumber<StaffMember>());
		////res = true;
	}
	catch (NotFoundException& e)
	{
		////res = false
		throw StaffMemberNotFoundException();
	}
	////return res;
	return staffmember;
}


void Hospital::addDepartment(Department& inDepartment)
{
	int index;
	allocDepartmentsArr();
	if (allDepartments.empty())
		index = 0;
	else
		index = getIndexForDepartmentInsertion(inDepartment.getName());

	insertDepartmentToArrInIndex(inDepartment, index);
}

bool Hospital::binSearchDepartmentByName(const string name) throw(StringException)
{
	if (!Utils::isValidString(name))
		throw StringException();

	bool res = false;
	////int left = 0;
	////int right = allDepartments.size() - 1;
	////while (left <= right)
	////{
	////	int mid = left + (right - left) / 2;

	////	////int res = strcmp(name, allDepartments[mid]->getName());
	////	////if (res == 0) // found the index
	////	int compare = allDepartments[mid]->getName().compare(name);
	////	////if (name == allDepartments[mid]->getName()) // found the index
	////	if (compare == 0)	// found the index
	////		return mid;

	////	////if (res > 0) // go right
	////	////if (name > allDepartments[mid]->getName()) // go right
	////	if (compare < 0) // go right
	////		left = mid + 1;

	////	////else // (name < allDepartments[mid]->getName()) => go left
	////	else // (compare > 0) => go left
	////		right = mid - 1;
	////}

	////// Not found:
	////return -1;
	////Department* dep = nullptr;
	try {
		Utils::binSearch<Department*, string>(allDepartments, name, compareByName<Department>());
		res = true;
	}
	catch (NotFoundException& e)
	{
		res = false;
	}
	return res;
}


StaffMember* Hospital::getStaffMemberByIndex(int index) const
{
	return staffArr[index];
}

int Hospital::getIndexForDepartmentInsertion(const string name)
//find the index to insert the department to the right place according to alphabet
{
	int size = allDepartments.size();
	for (int i = 0; i < size; i++)
	{
		////int res = strcmp(allDepartments[i]->getName(),name);
		////bool res = (allDepartments[i]->getName() > name);
		////if(res)
		if (allDepartments[i]->getName().compare(name) > 0);
			return i;
	}
	return size; // to be inserted last

}

////void Hospital::pushDepartmentsFwdFromIndex(int index)
////{
////	for (int i = logSizeOfDepartments; i > index; i--) {
////		allDepartments[i] = allDepartments[i - 1];
////	}
////	allDepartments[index] = nullptr;
////}

void Hospital::insertDepartmentToArrInIndex(Department& newDepartment, int index)
{
	vector<Department*>::iterator pos = allDepartments.begin() + index;
	//pushDepartmentsFwdFromIndex(index); //make the place for insert department
	//allDepartments[index] = &newDepartment;
	//logSizeOfDepartments++;
	allDepartments.insert(pos, &newDepartment);
}


void Hospital::allocPatientsArr()
{
	if ((allPatients.capacity() >= 1) && (allPatients.size() == allPatients.capacity())) //if there is no place in the array
		allPatients.reserve(allPatients.capacity() * 2);
	////if (phySizeOfPatients == 0) // If this is the 1st Department
	////{
	////	allPatients = new Patient*;
	////	phySizeOfPatients++;
	////	return;
	////}
	////else if (logSizeOfPatients == phySizeOfPatients) //if there is no place in the array
	////{
	////	phySizeOfPatients *= 2;
	////	Patient** newArr = new Patient*[phySizeOfPatients];
	////	for (int i = 0; i < logSizeOfPatients; i++)
	////	{
	////		newArr[i] = allPatients[i];
	////	}
	////	delete[] allPatients;
	////	allPatients = newArr;
	////	return;
	////}
	////else
	////	return;
}

void Hospital::addPatient(Patient& inPatient) 
{
	int index;
	allocPatientsArr();
	////if (logSizeOfPatients == 0)
	if (allPatients.empty())
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
	if (!staffArr.empty())
	{
		cout << "Staff Members: " << endl;
		//for (int i = 0; i < logSizeOfStaff; i++)
		for (auto staffMember : staffArr)
		{
			if (strcmp(typeid(*(staffMember)).name() + 6, typeid(Researcher).name() + 6) != 0)
			{	//print if staff member is not only Researcher
				cout << "\n\t" << ++j << ". " << *(staffMember) << "\n\n";
				//j++;
			}
		}
	}
	if (j == 0)
		throw StaffException();
}

void Hospital::showSurgeons() const throw(SurgeonException)
{
	int j = 0;
	if (numOfSurgeons)
	{
		//for (int i = 0; i < logSizeOfStaff; i++)
		for(auto staffMember : staffArr)
		{
			Surgeon*surgeon = dynamic_cast<Surgeon*>(staffMember);
			if (surgeon)
			{
				cout << "\t" << ++j << ". " << *(staffMember) << endl;
				//j++;
			}
		}
	}
	if (j == 0)
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
	//for (int i = 0; i < logSizeOfDepartments; i++)
	int i = 0;
	for (auto department : allDepartments)
	{
		cout << '\t' << ++i << ". " << department->getName() << endl;
	}
}

Department* Hospital::getDepartmentByIndex(int ind)
{
		return allDepartments[ind];
}

int Hospital::getNumOfDepartments()
{
	return allDepartments.size();
}

int Hospital::getNumOfSurgeons()
{
	return this->numOfSurgeons;
}


Patient* Hospital::getPatientByID(string inID, bool* isFound) throw(HospitalException)
//if patient exist return his address
{

	////int index;
	////////if (phySizeOfPatients == 0) // No patients available
	////if (allPatients.empty())// No patients available
	////{
	////	*isFound = false;
	////	return nullptr;
	////}
	////else
	////{
	////	 index = binSearchPatientByID(inID);
	////	 if (index != -1)
	////	 {
	////		 *isFound = true;
	////		 return allPatients[index];
	////	 }
	////	 else
	////	 {
	////		 *isFound = false;
	////		 return nullptr;
	////	 }
	////}

	if (allPatients.empty())
	{
		throw PatientsEmptyException();
	}

	Patient* patient = nullptr;
	try {
		 patient = Utils::binSearch<Patient*, string>(allPatients, inID, compareByPatientID<Patient>());
		 *isFound = true;
	}
	catch (NotFoundException& e)
	{
		throw PatientNotFoundException();
	}

	return patient;
}


////int Hospital::binSearchPatientByID(string inID)
//////find the index of patient according to his ID,else not found return -1
////{
////	int left = 0;
////	////int right = logSizeOfPatients - 1;
////	int right = allPatients.size() - 1;
////	while (left <= right)
////	{
////		int mid = left + (right - left) / 2;
////
////		int res = (stoi(inID) - stoi(allPatients[mid]->getId()));
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


int Hospital::getIndexForPatientInsertion(const string id) 
//find the right index to insert patient according to the ID number
{
	bool isGreater = false;
	int size = allPatients.size();
	for (int i = 0; i < size; i++)
	{
		isGreater = (stoi(allPatients[i]->getId()) > stoi(id));
		if (isGreater) // Found the member to be on the right
		{
			return i;
		}
	}
	return size; // to be inserted last
}

////void Hospital::pushPatientsFwdFromIndex(int index)
//////shift 1 right all patient that have bigger ID number
////{
////	for (int i = logSizeOfPatients; i > index; i--) {
////		allPatients[i] = allPatients[i - 1];
////	}
////	allPatients[index] = nullptr;
////}

void Hospital::insertPatientToArrInIndex(Patient& newPatient, int index)
{
	////pushPatientsFwdFromIndex(index);
	////allPatients[index] = &newPatient;
	////logSizeOfPatients++;
	vector<Patient*>::iterator pos = allPatients.begin() + index;
	allPatients.insert(pos, &newPatient);
}

////bool Hospital::verifyEmployeeIDNumber(const int& employeeID) //check if employeeID already exists
////{
////	////bool isExists = false;
////	int size = staffArr.size();
////
////	if (size > 0)
////	{
////		////isExists = verifyStaffMemberEmployeeIDBinSearch(staffArr, size, employeeID);
////		try {
////			////StaffMember* staffmember = Utils::binSearch(staffArr, employeeID, compareByEmployeeIDNumber<StaffMember>());
////			Utils::binSearch<StaffMember*, int>(staffArr, employeeID, compareByEmployeeIDNumber<StaffMember>());
////		}
////		catch (NotFoundException& e)
////		{
////			return false;
////		}
////	}
////	return true;;
////}


////bool Hospital::verifyStaffMemberEmployeeIDBinSearch(StaffMember** arr, int size, const int& employeeID) 
////{
////		StaffMember* mid = arr[size / 2];
////		if (staffArr.empty())
////			return false;
////		else if (size == 1)
////		{
////			if (mid->getEmployeeIDNumber() == employeeID) 
////				return true;
////			else 
////				return false;
////		}
////		else
////		{
////			if (mid->getEmployeeIDNumber() == employeeID)
////				return true;
////			int leftSize = size / 2;
////			int rightSize = size - leftSize-1;
////			if (mid->getEmployeeIDNumber() > employeeID)
////				return verifyStaffMemberEmployeeIDBinSearch(arr, leftSize, employeeID);
////			else if(mid->getEmployeeIDNumber() < employeeID)
////				return verifyStaffMemberEmployeeIDBinSearch(arr+ leftSize+1, rightSize, employeeID);
////		}
////	return false;
////}


bool Hospital::isDepartmentsEmpty() const
{
	return (allDepartments.empty());
}

int Hospital::findTheIndexOfDepNameInDepArr(string str) const
{
	int size = allDepartments.size();
	for (int i = 0; i < size; i++)
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

Researcher* Hospital::findResearcherAccordingToName(const string name)
{
	return researchInst.getResearcherByName(name);
}

void Hospital::addArticleToResearcher(Article & art, Researcher*researcher)
{
	researchInst.addArticeToResearcher(art, researcher);
}

const int Hospital::getSizeOfResearchers() const
{
	return  researchInst.getSize();
}

