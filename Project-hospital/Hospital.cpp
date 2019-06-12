#include "Hospital.h"
#include "doctor.h"
#include "nurse.h"
#include "Patient.h"
#include "Utils.h"

// C'tor:
Hospital::Hospital()
	: numOfSurgeons(0)
{
	////numOfSurgeons = 0;
}




Hospital::~Hospital()
{
	freeHospitalData();
}

void Hospital::freeHospitalData()
{
	researchInst.freeResearchInstituteData();

	for (auto t : staffArr)
		delete t;
	staffArr.clear();

	for (auto t : allDepartments)
		delete t;
	allDepartments.clear();

	for (auto t : allPatients)
		delete t;
	allPatients.clear();
}

void Hospital::allocDepartmentsArr()
{
	if ((allDepartments.capacity() >= 1) && (allDepartments.size() == allDepartments.capacity())) //if there is no place in the array
		allDepartments.reserve(allDepartments.capacity() * 2);
}


void Hospital::addResearcher(Researcher* inResearcher)
{
	researchInst.addResearcher(inResearcher);
}


void Hospital::allocStaffArr()
{
	if ((staffArr.capacity() >= 1) && (staffArr.size() == staffArr.capacity())) //if there is no place in the array
		staffArr.reserve(staffArr.capacity() * 2);
}

void Hospital::addStaffMember(StaffMember* inStaffMember)
{
	int index;
	allocStaffArr();
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
}


int Hospital::getIndexForStaffMemberInsertion(int id) //the index to insert staff member
{
	bool isGreater = false;
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

int Hospital::getSizeOfStaffArr() const
{
	return staffArr.size();
}

int Hospital::getSizeOfStaffArrInSpecificIndex(int index)
{
	return allDepartments[index]->getSizeOfStaffArr();
}

StaffMember* Hospital::getStaffmemberInSpecificIndexes(int indexDep, int indexStaffMember) const
{
	return allDepartments[indexDep]->getStaffMemberByIndex(indexStaffMember);
}

StaffMember* Hospital::binSearchStaffMemberByID(int inID) throw (StaffMemberNotFoundException)
{
	StaffMember* staffmember = nullptr;
	try {
		staffmember = Utils::binSearch<StaffMember*, int>(staffArr, inID, compareByEmployeeIDNumber<StaffMember>());
	}
	catch (NotFoundException& e)
	{
		throw StaffMemberNotFoundException();
	}
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
		if (allDepartments[i]->getName().compare(name) > 0);
			return i;
	}
	return size; // to be inserted last

}


void Hospital::insertDepartmentToArrInIndex(Department& newDepartment, int index)
{
	vector<Department*>::iterator pos = allDepartments.begin() + index;
	allDepartments.insert(pos, &newDepartment);
}


void Hospital::allocPatientsArr()
{
	if ((allPatients.capacity() >= 1) && (allPatients.size() == allPatients.capacity())) //if there is no place in the array
		allPatients.reserve(allPatients.capacity() * 2);
}

void Hospital::addPatient(Patient& inPatient) 
{
	int index;
	allocPatientsArr();
	if (allPatients.empty())
		index = 0;
	else 
		//find the index to insert patient
		index = getIndexForPatientInsertion(inPatient.getId());

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
		for (auto staffMember : staffArr)
		{
			if (strcmp(typeid(*(staffMember)).name() + 6, typeid(Researcher).name() + 6) != 0)
			{	//print if staff member is not only Researcher
				cout << "\n\t" << ++j << ". " << *(staffMember) << "\n\n";
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
		for(auto staffMember : staffArr)
		{
			Surgeon*surgeon = dynamic_cast<Surgeon*>(staffMember);
			if (surgeon)
			{
				cout << "\t" << ++j << ". " << *(staffMember) << endl;
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


void Hospital::insertPatientToArrInIndex(Patient& newPatient, int index)
{
	vector<Patient*>::iterator pos = allPatients.begin() + index;
	allPatients.insert(pos, &newPatient);
}


bool Hospital::isDepartmentsEmpty() const
{
	return (allDepartments.empty());
}

int Hospital::findTheIndexOfDepNameInDepArr(string str) const
{
	int size = allDepartments.size();
	for (int i = 0; i < size; i++)
	{
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

