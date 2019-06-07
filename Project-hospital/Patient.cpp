#include "Patient.h"
#include "Department.h"

Patient::Patient(const string inName,const string id ,enum eGender inGender, string inDateOBirth)
throw(NameException)
{
	////name = new char[strlen(inName) + 1];
	if (inName == "")
		throw NameException();
	name = inName;
	//strcpy(name, inName);
	////ID = new char[strlen(id) + 1];
	ID = id;
	////strcpy(ID, id);
	gender = inGender;
	////yearOfBirth = new char[strlen(inDateOBirth) + 1];
	yearOfBirth = inDateOBirth;
	////strcpy(yearOfBirth, inDateOBirth);
	visits = nullptr;
	logSizeOfVisits = 0;
	phySizeOfVisits = 0;
	departmentsVisited = nullptr;
	logsizeOfDepartments = 0;
	phySizeOfDepartments = 0;
}

Patient::~Patient()
{
	////delete[] name;
	////delete[] ID;
	//delete[] yearOfBirth;
	for (int i = 0; i < logSizeOfVisits; i++)
		delete visits[i];
	delete[] visits;
	delete[] departmentsVisited;
}

void Patient::addVisitiaionRecord(VisitationRecord* inVisitiationRecord)
{
	int index;
	allocVisitsArr();
	if (logSizeOfVisits == 0)
		index = 0;
	else
		index = getIndexForVisitiationInsertion(inVisitiationRecord->getArrivalDate());
	//find the index to insert VisitiaionRecord to VisitiaionRecord array

	insertVisitToArrInIndex(inVisitiationRecord, index); //insert the VisitiaionRecord to VisitiaionRecord array
}

int Patient::getIndexForVisitiationInsertion(Date & date) //the index to insert Visitiation record
{
	for (int i = 0; i < logSizeOfVisits; i++)
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
	return logSizeOfVisits; // to be inserted last

}

void Patient::insertVisitToArrInIndex(VisitationRecord* visitiationRecord, int index)
//add the visit in the right index according to date
{
	pushVisitsFwdFromIndex(index);
	visits[index] = visitiationRecord;
	logSizeOfVisits++;
}


void Patient::pushVisitsFwdFromIndex(int index)
//to shift 1 right all the nurses with bigger employee ID number
{
	for (int i = logSizeOfVisits; i > index; i--)
	{
		visits[i] = visits[i - 1];
	}
	visits[index] = nullptr;
}


void Patient::allocVisitsArr()
{
	if (phySizeOfVisits == 0) // This is the 1st visit.
	{
		visits = new VisitationRecord*;
		phySizeOfVisits++;

	}
	else if (logSizeOfVisits == phySizeOfVisits) // no room left in visits arr
	{
		phySizeOfVisits *= 2;
		VisitationRecord** newArr = new VisitationRecord*[phySizeOfVisits];
		for (int i = 0; i < logSizeOfVisits; i++)
		{
			newArr[i] = visits[i];
		}
		delete[] visits;
		visits = newArr;
	}
	else
		return;
}

void Patient::addDepatrtmentToPatient(const Department& pDepartment)
{
	allocDepartmentsVisitedArr();
	departmentsVisited[logsizeOfDepartments] = &pDepartment;
	logsizeOfDepartments++;
}

void Patient::allocDepartmentsVisitedArr()
{
	if (phySizeOfDepartments == 0) // If this is the 1st Department
	{
		departmentsVisited = new const Department*;
		phySizeOfDepartments++;
	}
	else if (logsizeOfDepartments == phySizeOfDepartments) //if there is no place in the array
	{
		phySizeOfDepartments *= 2;
		const Department** newArr = new const Department*[phySizeOfDepartments];
		for (int i = 0; i < logsizeOfDepartments; i++)
		{
			newArr[i] = departmentsVisited[i];
		}
		delete[] departmentsVisited;
		departmentsVisited = newArr;
	}
	else
		return;
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
	for (int i = 0; i < logSizeOfVisits; i++)
	{ 
		VisitSurgery*temp = dynamic_cast<VisitSurgery*>(visits[i]);
		cout << "\n\t" << i + 1 << ". Arrival Date: " << visits[i]->getArrivalDate() << ": " << endl;
		cout << "\tVisitation Purpose: " << ((temp) ? "Surgery." : "Checkup.") << endl;
		cout << "\tMedical staff member in charge: " << visits[i]->getstaffMemInChargeName() << endl;
		cout << "\tVisitation Description: " << visits[i]->getVisitationDescription() << endl;

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


bool Patient::hasVisitedDepartment(Department& pDepartment) const
{
	for (int i = 0; i < logsizeOfDepartments; i++)
	{
		if (&pDepartment == departmentsVisited[i])
			return true;
	}
	return false;
}

int Patient::getSizeVisits() const
{
	return logSizeOfVisits;
}

VisitationRecord* Patient::getVisitByIndex(int index) const
{
	return visits[index];
}
