
#include "ConstantsAndGenFuncs.h"
#include "Department.h"
#include "Patient.h"
#include "Surgeon.h"
#include "ResearcherDoctor.h"
#include "SurgeonResearher.h"
#include "Utils.h"


// C'tor:
Department::Department(const string inName) throw(StringException)
	////: staffArr(nullptr), logSizeOfStaff(0), phySizeOfStaff(0),
	////patientsArr(nullptr), logSizeOfPatients(0), phySizeOfPatients(0), 
	: numOfSurgeons(0)
{
	if (!Utils::isValidString(inName))
		throw StringException();
	name = inName;
}

Department::Department(ifstream& in) :patientsArr(nullptr), staffArr(nullptr)
{
	logSizeOfPatients = 0;
	phySizeOfPatients = 0;
	in >> *this;
}
// D'tor:
Department::~Department()
{
	////delete[] name;
	////delete[] staffArr;
	////delete[] patientsArr;
}


void Department::setlogSizeOfStaff(int size)
{
	this->logSizeOfStaff = size;
}

ostream& operator<<(ostream& os,Department& dep)
{
	os << dep.getName() << " " << endl;
	os << dep.logSizeOfStaff << endl;
	for (int i = 0; i < dep.logSizeOfStaff; i++)
	{
		os << *(dep.staffArr[i]) << endl;
	}
	return os;
}

ifstream& operator >> (ifstream& inFile, Department& dep)
{
	getline(inFile,dep.name);
	string numStaff;
	getline(inFile, numStaff);
	dep.setlogSizeOfStaff(stoi(numStaff));
	dep.phySizeOfStaff = dep.logSizeOfStaff;
	dep.staffArr = new StaffMember*[dep.logSizeOfStaff];
	for (int i = 0; i < dep.logSizeOfStaff; i++)
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


void Department::addPatient(Patient& patient)
{
	allocPatientsArr();//to reallocte the array to the new size
	/////*patientsArr[logSizeOfPatients] = &patient;
	////logSizeOfPatients++;*/
	patientsArr.push_back(&patient);
}

void Department::allocPatientsArr()
{
	if ((patientsArr.capacity() >= 1) && (patientsArr.size() == patientsArr.capacity())) //if there is no place in the array
		patientsArr.reserve(patientsArr.capacity() * 2);
	////if (phySizeOfPatients == 0) // If this is the 1st Patient
	////{
	////	patientsArr = new Patient*;
	////	phySizeOfPatients++;
	////}
	////else if (logSizeOfPatients == phySizeOfPatients) //if there is no more room in the array
	////{
	////	phySizeOfPatients *= 2;
	////	Patient** newArr = new Patient*[phySizeOfPatients];
	////	for (int i = 0; i < logSizeOfPatients; i++)
	////	{
	////		newArr[i] = patientsArr[i];
	////	}
	////	delete[] patientsArr;
	////	patientsArr = newArr;
	////}
	////else
	////	return;
}

void Department::addStaffMember(StaffMember* staffMember)
{
	allocStaffArr();
	/////*staffArr[logSizeOfStaff] = staffMember;
	////logSizeOfStaff++;
	////Surgeon* tempSurgeon = dynamic_cast<Surgeon*>(staffMember);
	////if (tempSurgeon) this->numOfSurgeons++;*/
	staffArr.push_back(staffMember);
}

void Department::allocStaffArr()
{
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
		////for (int i = 0; i < logSizeOfPatients; i++)
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

	////if (logSizeOfPatients > 0)
	////{
	////	cout << "Patients visited in " << name << " are: " << endl;
	////	for (int i = 0; i < logSizeOfPatients; i++)
	////	{
	////		cout << "\nName: " << patientsArr[i]->getName() << "\tID: " << patientsArr[i]->getId() << "\tGender: ";
	////		patientsArr[i]->showGender();
	////		cout << "\tYear of birth: " << patientsArr[i]->getYearOfBirth() << endl;
	////		patientsArr[i]->showVisits();
	////	}
	////}
	////else
	////	cout << "\nNo Patients available in this department." << endl;
}

vector<StaffMember*> Department::operator+=(StaffMember* staffMember)
{
	addStaffMember(staffMember);
	return staffArr;
}
