
#include "ConstantsAndGenFuncs.h"
#include "Department.h"
#include "Patient.h"
#include "Surgeon.h"
#include "ResearcherDoctor.h"
#include "SurgeonResearher.h"
#include "Utils.h"


// C'tor:
Department::Department(const string inName) throw(StringException)
	: numOfSurgeons(0)
{
	if (!Utils::isValidString(inName))
		throw StringException();
	name = inName;
}

Department::Department(ifstream& in)
{
	in >> *this;
}
// D'tor:
Department::~Department() {}


ostream& operator<<(ostream& os,Department& dep)
{
	os << dep.getName() << " " << endl;
	os << dep.staffArr.size() << endl;
	for (int i = 0; i < dep.staffArr.size(); i++)
	{
		os << *(dep.staffArr[i]);
	}
	return os;
}

ifstream& operator >> (ifstream& inFile, Department& dep)
{
	getline(inFile,dep.name);
	string tempNumStaff;
	getline(inFile, tempNumStaff);
	int numStaff = atoi(tempNumStaff.c_str());
	for (int i = 0; i <numStaff; i++)
	{
		string type;
		getline(inFile, type);
		if (type.compare(typeid(SurgeonResearcher).name()+6)==0)
		{
			SurgeonResearcher* surgeonResearcher = new SurgeonResearcher(inFile);
			dep.addStaffMember(surgeonResearcher);
		}
		else if (type.compare(typeid(Surgeon).name() + 6) == 0)
		{
			Surgeon* surgeon = new Surgeon(inFile);
			dep.addStaffMember(surgeon);
		}
		else if (type.compare(typeid(ResearcherDoctor).name() + 6) == 0)
		{
			ResearcherDoctor* researcherDoctor = new ResearcherDoctor(inFile);
			dep.addStaffMember(researcherDoctor);
		}
		else if (type.compare(typeid(Doctor).name() + 6) == 0)
		{
			Doctor* doctor = new Doctor(inFile);
			dep.addStaffMember(doctor);
		}
		else if (type.compare(typeid(Nurse).name() + 6) == 0)
		{
			Nurse* nurse = new Nurse(inFile);
			dep.addStaffMember(nurse);
		}
	}
	return inFile;
}

int Department::getSizeOfStaffArr() const
{
	return staffArr.size();
}

StaffMember* Department::getStaffMemberByIndex(int index)const
{
	return staffArr[index];
}


void Department::addPatient(Patient& patient)
{
	allocPatientsArr();//to reallocte the array to the new size
	patientsArr.push_back(&patient);
}

void Department::allocPatientsArr()
{
	if ((patientsArr.capacity() >= 1) && (patientsArr.size() == patientsArr.capacity())) //if there is no place in the array
		patientsArr.reserve(patientsArr.capacity() * 2);
}

void Department::addStaffMember(StaffMember* staffMember)
{
	allocStaffArr();
	staffArr.push_back(staffMember);
}

void Department::allocStaffArr()
{
	if ((staffArr.capacity() >= 1) && (staffArr.size() == staffArr.capacity())) //if there is no place in the array
		staffArr.reserve(staffArr.capacity() * 2);
}

const string Department:: getName() const
{
	return name;
}

int Department::getNumOfSurgeons() const
{
	return this->numOfSurgeons;
}

void Department::showPatients() const
{
	if (!patientsArr.empty())
	{
		cout << "Patients visited in " << name << " are: " << endl;
		for(auto patient : patientsArr)
		{
			cout << "\nName: " << patient->getName() << "\tID: " << patient->getId() << "\tGender: ";
			patient->showGender();
			cout << "\tYear of birth: " << patient->getYearOfBirth() << endl;
			patient->showVisits();
		}
	}
	else
		cout << "\nNo Patients available in this department." << endl;
}

vector<StaffMember*> Department::operator+=(StaffMember* staffMember)
{
	addStaffMember(staffMember);
	return staffArr;
}
