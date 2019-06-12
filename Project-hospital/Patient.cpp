#include "Patient.h"
#include "Department.h"
#include "Utils.h"

Patient::Patient(const string inName,const string id ,enum eGender inGender, string inDateOBirth)
throw(HospitalException)
{
	if (!Utils::isValidString(inName) || !Utils::isValidString(id) || !Utils::isValidString(inDateOBirth))
		throw StringException();
	name = inName;
	ID = id;
	gender = inGender;
	yearOfBirth = inDateOBirth;
	////visits = nullptr;
	////logSizeOfVisits = 0;
	////phySizeOfVisits = 0;
	////departmentsVisited = nullptr;
	////logsizeOfDepartments = 0;
	////phySizeOfDepartments = 0;
}

Patient::~Patient()
{
	////delete[] name;
	////delete[] ID;
	//delete[] yearOfBirth;
	for (auto visit : visits)
		delete visit;
	////for (int i = 0; i < logSizeOfVisits; i++)
	////	delete visits[i];
	////delete[] visits;
	////delete[] departmentsVisited;
}

void Patient::addVisitiaionRecord(VisitationRecord* inVisitiationRecord)
{
	int index;
	allocVisitsArr();
	////if (logSizeOfVisits == 0)
	if (visits.empty())
		index = 0;
	else
		index = getIndexForVisitiationInsertion(inVisitiationRecord->getArrivalDate());
	//find the index to insert VisitiaionRecord to VisitiaionRecord array

	insertVisitToArrInIndex(inVisitiationRecord, index); //insert the VisitiaionRecord to VisitiaionRecord array
}

int Patient::getIndexForVisitiationInsertion(Date & date) //the index to insert Visitiation record
{
	int size = visits.size();
	for (int i = 0; i < size; i++)
	{
		Date curr = visits[i]->getArrivalDate();
		if (curr.getYear()>date.getYear())
		{
			return i;
		}
		else if (curr.getYear()==date.getYear())
		{
			if (curr.getMonth()>date.getMonth())
			{
				return i;
			}
			else if (curr.getMonth()== date.getMonth())
			{
				if (curr.getDay()>date.getDay())
				{
					return i;
				}

			}
		}
	}
	return size; // to be inserted last

}

void Patient::insertVisitToArrInIndex(VisitationRecord* visitiationRecord, int index)
//add the visit in the right index according to date
{
	/////*pushVisitsFwdFromIndex(index);
	////visits[index] = visitiationRecord;
	////logSizeOfVisits++;*/
	vector<VisitationRecord*>::iterator pos = visits.begin() + index;
	visits.insert(pos, visitiationRecord);
}


////void Patient::pushVisitsFwdFromIndex(int index)
//////to shift 1 right all the nurses with bigger employee ID number
////{
////	for (int i = logSizeOfVisits; i > index; i--)
////	{
////		visits[i] = visits[i - 1];
////	}
////	visits[index] = nullptr;
////}


void Patient::allocVisitsArr()
{
	if ((visits.capacity() >= 1) && (visits.size() == visits.capacity())) //if there is no place in the array
		visits.reserve(visits.capacity() * 2);
	////if (phySizeOfVisits == 0) // This is the 1st visit.
	////{
	////	visits = new VisitationRecord*;
	////	phySizeOfVisits++;

	////}
	////else if (logSizeOfVisits == phySizeOfVisits) // no room left in visits arr
	////{
	////	phySizeOfVisits *= 2;
	////	VisitationRecord** newArr = new VisitationRecord*[phySizeOfVisits];
	////	for (int i = 0; i < logSizeOfVisits; i++)
	////	{
	////		newArr[i] = visits[i];
	////	}
	////	delete[] visits;
	////	visits = newArr;
	////}
	////else
	////	return;
}

void Patient::addDepatrtmentToPatient(Department& department)
{
	allocDepartmentsVisitedArr();
	////departmentsVisited[logsizeOfDepartments] = &pDepartment;
	////logsizeOfDepartments++;
	departmentsVisited.push_back(&department);
}

void Patient::allocDepartmentsVisitedArr()
{
	if ((departmentsVisited.capacity() >= 1) && (departmentsVisited.size() == departmentsVisited.capacity())) //if there is no place in the array
		departmentsVisited.reserve(departmentsVisited.capacity() * 2);
	////if (phySizeOfDepartments == 0) // If this is the 1st Department
	////{
	////	departmentsVisited = new const Department*;
	////	phySizeOfDepartments++;
	////}
	////else if (logsizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	////{
	////	phySizeOfDepartments *= 2;
	////	const Department** newArr = new const Department*[phySizeOfDepartments];
	////	for (int i = 0; i < logsizeOfDepartments; i++)
	////	{
	////		newArr[i] = departmentsVisited[i];
	////	}
	////	delete[] departmentsVisited;
	////	departmentsVisited = newArr;
	////}
	////else
	////	return;
}

const string Patient::getName()const
{
	return name;
}

const string Patient:: getId()const
{
	return ID;
}
void Patient::showGender()const
{
	if (gender == Male)
		cout << "Male";
	else if(gender==Female)
		cout << "Female";
}
const string Patient::getYearOfBirth() const
{
	return yearOfBirth;
}
void Patient:: showVisits()const
{
	cout << "Patient's Visitations:" << endl;
	////for (int i = 0; i < logSizeOfVisits; i++)
	int i = 0;
	for (auto visit : visits)
	{ 
		VisitSurgery*temp = dynamic_cast<VisitSurgery*>(visit);
		cout << "\n\t" << ++i << ". Arrival Date: " << visit->getArrivalDate() << ": " << endl;
		cout << "\tVisitation Purpose: " << ((temp) ? "Surgery." : "Checkup.") << endl;
		cout << "\tMedical staff member in charge: " << visit->getstaffMemInChargeName() << endl;
		cout << "\tVisitation Description: " << visit->getVisitationDescription() << endl;

		if (temp)
		{
			cout << "\tSurgery Room: " << temp->getSurgeryRoomNum() << endl;
			if (temp->getFasting())
				cout << "\tPatient has been fasting." << endl;
			else
				cout << "\tPatient has not been fasting." << endl;

		}
	}
	cout << endl;
}


bool Patient::hasVisitedDepartment(Department& department) const
{
	int size = departmentsVisited.size();
	for (int i = 0; i < size; i++)
	{
		if (&department == departmentsVisited[i])
			return true;
	}
	return false;
}

int Patient::getSizeVisits() const
{
	return visits.size();
}

VisitationRecord* Patient::getVisitByIndex(int index) const
{
	return visits[index];
}
