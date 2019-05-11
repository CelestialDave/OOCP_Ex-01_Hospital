#include "Hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"
#include "Utils.h"

// C'tor:
Hospital::Hospital()
	: allDepartments(nullptr), staffArr(nullptr), allPatients(nullptr)
//	:  allDoctors(nullptr), allNurses(nullptr), allPatients(nullptr)
{
	//logSizeOfDepartments = logSizeDoctors = logSizeNurses = 
	//logSizeOfPatients = phySizeDoctors = phySizeNurses = phySizeOfPatients = 0;
	logSizeOfDepartments = phySizeOfDepartments = logSizeOfStaff = 
		phySizeOfStaff = logSizeOfPatients = phySizeOfPatients = 0;
}


Hospital::~Hospital()
{
	//for(int i = 0; i < logSizeDoctors; i++)
	//	delete allDoctors[i];
	//delete[]allDoctors;
	//for (int i = 0; i < logSizeNurses; i++)
	//		delete allNurses[i];
	//delete[]allNurses;
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
		//find the index to push the staff member
		index = getIndexForStaffMemberInsertion(inStaffMember->getEmployeeIDNumber());

	inserStaffMemberToArrInIndex(inStaffMember, index);
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



//void Hospital::allocDocArr()
//{
//	if (phySizeDoctors == 0) // If this is the 1st Department
//	{
//		allDoctors = new Doctor*;
//		phySizeDoctors++;
//	}
//	else if (logSizeDoctors == phySizeDoctors) //if there is no place in the array
//	{
//		phySizeDoctors *= 2;
//		Doctor** newArr = new Doctor*[phySizeDoctors];
//		for (int i = 0; i < logSizeDoctors; i++)
//		{
//			newArr[i] = allDoctors[i];
//		}
//		delete[] allDoctors;
//		allDoctors = newArr;
//	}
//	else
//		return;
//}
//
//void Hospital::addDoctor(Doctor& inDoctor)
//{
//	int index;
//	allocDocArr();
//	if (logSizeDoctors == 0)
//		index = 0;
//	else
//		index = getIndexForDoctorInsertion(inDoctor.getEmployeeIDNumber());
//	//find the index to push the doctor
//
//	insertDoctorToArrInIndex(inDoctor, index);
//}
//
//int Hospital::binSearchDoctorByID(int inID) 
//{
//	int left = 0;
//	int right = logSizeDoctors - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//
//		int res = (inID - allDoctors[mid]->getEmployeeIDNumber());
//		if (res == 0) // found the index
//			return mid;
//
//		if (res > 0) // go right
//			left = mid + 1;
//
//		else // (res < 0) => go left
//			right = mid - 1;
//	}
//
//	// Not found:
//	return -1;
//}
//
//int Hospital::getIndexForDoctorInsertion(int id) //the index to insert doctor
//{
//	bool isGreater = false;
//	for (int i = 0; i < logSizeDoctors; i++)
//	{
//		isGreater = (allDoctors[i]->getEmployeeIDNumber() > id);
//		if (isGreater) // Found the member to be on the right
//		{
//			return i;
//		}
//	}
//	return logSizeDoctors; // to be inserted last
//
//}
//
//void Hospital::pushDoctorsFwdFromIndex(int index) 
////to shift 1 right all the doctor with bigger employee ID number
//{
//	for (int i = logSizeDoctors; i > index; i--) {
//		allDoctors[i] = allDoctors[i - 1];
//	}
//	allDoctors[index] = nullptr;
//}
//
//void Hospital::insertDoctorToArrInIndex(Doctor& newDoctor, int index) 
////add the doctor in the right index
//{
//	pushDoctorsFwdFromIndex(index);
//	allDoctors[index] = &newDoctor;
//	logSizeDoctors++;
//}
//
//
//void Hospital::allocNursesArr()
//{
//	if (phySizeNurses == 0) // If this is the 1st Department
//	{
//		allNurses = new Nurse*;
//		phySizeNurses++;
//	}
//	else if (logSizeNurses == phySizeNurses) //if there is no place in the array
//	{
//		phySizeNurses *= 2;
//		Nurse** newArr = new Nurse*[phySizeNurses];
//		for (int i = 0; i < logSizeNurses; i++)
//		{
//			newArr[i] = allNurses[i];
//		}
//		delete[] allNurses;
//		allNurses = newArr;
//	}
//	else
//		return;
//}
//
//void Hospital::addNurse(Nurse& inNurse)
//{
//	int index;
//	allocNursesArr();
//	if (logSizeNurses == 0)
//		index = 0;
//	else
//		index = getIndexForNurseInsertion(inNurse.getEmployeeIDNumber());
//	//find the index to insert nurse to nurse array
//
//	insertNurseToArrInIndex(inNurse, index); //insert the nurse to nurse array
//}
//
//int Hospital::binSearchNurseByID(int inID)
//{
//	int left = 0;
//	int right = logSizeNurses - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//
//		int res = (inID - allNurses[mid]->getEmployeeIDNumber());
//		if (res == 0) // found the index
//			return mid;
//
//		if (res > 0) // go right
//			left = mid + 1;
//
//		else // (res < 0) => go left
//			right = mid - 1;
//	}
//
//	// Not found:
//	return -1;
//}
//
//int Hospital::getIndexForNurseInsertion(int id) //find the index to insert nurses
//{
//	bool isGreater = false;
//	for (int i = 0; i < logSizeNurses; i++)
//	{
//		isGreater = (allNurses[i]->getEmployeeIDNumber() > id);
//		if (isGreater) // Found the member to be on the right
//		{
//			return i;
//		}
//	}
//	return logSizeNurses; // to be inserted last
//
//}
//
//void Hospital::pushNursesFwdFromIndex(int index) 
////to shift 1 right all the nurses with bigger employee ID number
//{
//	for (int i = logSizeNurses; i > index; i--)
//	{
//		allNurses[i] = allNurses[i - 1];
//	}
//	allNurses[index] = nullptr;
//}
//
//void Hospital::insertNurseToArrInIndex(Nurse& newNurse, int index)
//{
//	pushNursesFwdFromIndex(index);
//	allNurses[index] = &newNurse;
//	logSizeNurses++;
//}

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

int Hospital::binSearchDepartmentByName(const char*name)
{
	int left = 0;
	int right = logSizeOfDepartments - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int res = strcmp(name, allDepartments[mid]->getName());
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

int Hospital::getIndexForDepartmentInsertion(const char*name)
//find the index to insert the department to the right place according to alphabet
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		int res = strcmp(allDepartments[i]->getName(),name);
		if(res==1)
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

void Hospital::showStaffMembers() const
{
	if (logSizeDoctors)
	{
		cout << "The doctors " << (logSizeDoctors > 1 ? "are: " : "is: ")<<endl;
		for (int i = 0; i < logSizeDoctors; i++)
		{
			cout << i + 1 << ". " << endl;
			cout<< "Name:" << allDoctors[i]->getName() << endl;
			cout << "Employee ID number is: " << allDoctors[i]->getEmployeeIDNumber() << endl;
			cout<< "The specialty's doctor is: " << allDoctors[i]->getSpciality() << endl;
		}
	}
	else
		cout << "There is no doctor in the medical staff " << endl;
	if (logSizeNurses)
	{
		cout << "The nurses " << (logSizeNurses > 1 ? "are: " : "is: ") << endl;
		for (int i = 0; i < logSizeNurses; i++)
		{
			cout << i + 1 << ". " << endl;
			cout<< "Name:" << allNurses[i]->getName() << endl;
			cout << "Employee ID number is: " << allNurses[i]->getEmployeeIDNumber() << endl;
			cout<<"Years of exprience: "<< allNurses[i]->getYearsOfExp() << endl;
		}
	}
	else
		cout << "There is no nurses in the medical staff"<< endl;
}

void Hospital::showResearchers() const
{
	researchInst.showResearchers();
}


void Hospital::showDepartments() const
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		cout << '\t' << i + 1 << ". " << allDepartments[i]->getName() << endl;
	}
}


bool Hospital::getDepartmentByName(char* depName, Department* resDepartment)
//find if the department is exist and return by pointer the address
{
	return binDepartmentByName(allDepartments, logSizeOfDepartments, depName, resDepartment);
}

bool Hospital::binDepartmentByName(Department** arr, int size, char* depName, Department* resDep)
//find if department exist and return by pointer the adress
{
	Department* midDep = arr[size / 2];
	int res = strcmp(depName, midDep->getName());
	if (size == 1)
	{
		if (res == 0) {
			resDep = midDep;
			return true;
		}
		else {
			return false;
		}
	}
	else 
	{
		int leftSize = size / 2;
		int rightSize = size - leftSize - 1;
		if (res == 0)
		{
			resDep = midDep;
			return true;
		}
		else if (res < 0)
			return binDepartmentByName(arr, leftSize, depName, resDep);
		else if (res > 0)
			return binDepartmentByName(arr+ leftSize+1,rightSize, depName, resDep);
	}
}


const char * Hospital::getDepartmentNameByIndex(int ind)
{
	return allDepartments[ind]->getName();
}

Department* Hospital::getDepartmentByIndex(int ind)
{
	if ((ind >= 0) && (ind < logSizeOfDepartments))
		return allDepartments[ind];
}

int Hospital::getNumOfDepartments()
{
	return logSizeOfDepartments;
}

Patient* Hospital::getPatientByID(char* inID, bool* isFound)
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


int Hospital::binSearchPatientByID(char* inID)
//find the index of patient according to his ID,else not found return -1
{
	int left = 0;
	int right = logSizeOfPatients - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int res = (atoi(inID) - atoi(allPatients[mid]->getId()));
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


int Hospital::getIndexForPatientInsertion(const char* id) 
//find the right index to insert patient according to the ID number
{
	bool isGreater = false;
	for (int i = 0; i < logSizeOfPatients; i++)
	{
		isGreater = (atoi(allPatients[i]->getId()) > atoi(id));
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
	///// NEED TO BE CUSTOMIZED:
	//	Doctor* midDoc = allDoctors[size / 2];
	//	if (size == 1)
	//	{
	//		if (midDoc->getEmployeeIDNumber() == employeeID) 
	//			return true;
	//		else 
	//			return false;
	//	}
	//	else
	//	{
	//		if (midDoc->getEmployeeIDNumber() == employeeID)
	//			return true;
	//		int leftSize = size / 2;
	//		int rightSize = size - leftSize-1;
	//		if (midDoc->getEmployeeIDNumber() > employeeID)
	//			return veryfactionDoctorEmployeeIdBinSearch(arr, leftSize, employeeID);
	//		else if(midDoc->getEmployeeIDNumber() < employeeID)
	//			return veryfactionDoctorEmployeeIdBinSearch(arr+ leftSize+1, rightSize, employeeID);
	//	}
	return false;
}


//bool Hospital::veryfactionDoctorEmployeeIdBinSearch(Doctor** arr,int size,const int &employeeID)
//{
//	Doctor* midDoc = allDoctors[size / 2];
//	if (size == 1)
//	{
//		if (midDoc->getEmployeeIDNumber() == employeeID) 
//			return true;
//		else 
//			return false;
//	}
//	else
//	{
//		if (midDoc->getEmployeeIDNumber() == employeeID)
//			return true;
//		int leftSize = size / 2;
//		int rightSize = size - leftSize-1;
//		if (midDoc->getEmployeeIDNumber() > employeeID)
//			return veryfactionDoctorEmployeeIdBinSearch(arr, leftSize, employeeID);
//		else if(midDoc->getEmployeeIDNumber() < employeeID)
//			return veryfactionDoctorEmployeeIdBinSearch(arr+ leftSize+1, rightSize, employeeID);
//	}
//}
//
//bool Hospital::veryfactionNurseEmployeeIdBinSearch(Nurse** arr, int size, const int &employeeID)
//{
//	if (size == 0)
//		return false;
//	Nurse* midNurse = arr[size / 2];
//	if (size == 1)
//	{
//		if (midNurse->getEmployeeIDNumber() == employeeID)
//			return true;
//		else
//			return false;
//	}
//	else
//	{
//		if (midNurse->getEmployeeIDNumber() == employeeID)
//			return true;
//		int leftSize = size / 2;
//		int rightSize = size - leftSize -1;
//		if (midNurse->getEmployeeIDNumber() > employeeID)
//			return veryfactionNurseEmployeeIdBinSearch(arr, leftSize, employeeID);
//		else if (midNurse->getEmployeeIDNumber() < employeeID)
//			return veryfactionNurseEmployeeIdBinSearch(arr+leftSize+1, rightSize, employeeID);
//
//	}
//}

bool Hospital::isDepartmentsEmpty() const
{
	return (logSizeOfDepartments == 0);
}

int Hospital::findTheIndexOfDepNameInDepArr(char*str) const
{
	for (int i = 0; i < logSizeOfDepartments; i++)
	{
		if(strcmp(allDepartments[i]->getName(),str)==0)
			return i;
	}
	return -1;
}

//void Hospital:: addNurseToSpecificDepartment(Nurse & nurse, int indexToIn)
//{
//	allDepartments[indexToIn]->addNurse(nurse);
//}
//
//void Hospital::addDoctorToSpecificDepartment(Doctor & doctor, int indexToIn)
//{
//	allDepartments[indexToIn]->addDoctor(doctor);
//
//}
Researcher* Hospital::getResearcherByIndex(int index) const
{
	return researchInst.getResearcherByIndex(index);
}

Researcher* Hospital::findResearcherAccordingToName(const char*name, bool&exist)
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

