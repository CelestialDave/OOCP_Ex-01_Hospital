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
		int sizeOfDep,i;
		inFile >> sizeOfDep;
		for (i = 0; i < sizeOfDep; i++)
		{
			Department*dep = new Department(inFile);
			hospital->addDepartment(*dep);
		}
	}
}
void Files::writeFile()
{
	ofstream outFile("hospital.txt", ios::trunc);
	int sizeOfDep = hospital->getNumOfDepartments();
	outFile << sizeOfDep << endl;
	for (int i = 0; i < sizeOfDep; i++)
		outFile << *(hospital->getDepartmentByIndex(i)) << endl;
	outFile.close();
}