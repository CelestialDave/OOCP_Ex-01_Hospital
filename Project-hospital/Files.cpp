#include "File.h"


Files::Files(Hospital* hospital)
{
	this->hospital = hospital;
}

void Files::readFile()
{
	ifstream inFile("hospital.txt", ios::in);
	if (inFile.is_open())
	{
		int sizeOfDep, i, j;
		inFile >> sizeOfDep;
		inFile.ignore();

		for (i = 0; i < sizeOfDep; i++)
		{
			Department*dep = new Department(inFile);
			hospital->addDepartment(*dep);
			int sizeStaff = dep->getSizeOfStaffArr();
			for (j = 0; j < sizeStaff; j++)
			{
				StaffMember* temp = dep->getStaffMemberByIndex(j);
				hospital->addStaffMember(temp);
				SurgeonResearcher* surgeonResearcher = dynamic_cast<SurgeonResearcher*>(temp);
				if (surgeonResearcher)
					hospital->addResearcher(surgeonResearcher);
				ResearcherDoctor* researcherDoctor = dynamic_cast<ResearcherDoctor*>(temp);
				if (researcherDoctor)
					hospital->addResearcher(researcherDoctor);
			}

		}
		inFile.close();
		int num = hospital->getSizeOfStaffArr();
		int counterVal = (hospital->getStaffMemberByIndex(num - 1))->getEmployeeIDNumber();
		StaffMember::setCounter(++counterVal);
	}
}

void Files::writeFile()
{
	ofstream outFile("hospital.txt", ios::trunc);
	int sizeOfDep = hospital->getNumOfDepartments();
	outFile << sizeOfDep << endl;
	for (int i = 0; i < sizeOfDep; i++)
		outFile << *(hospital->getDepartmentByIndex(i));
	outFile.close();
}