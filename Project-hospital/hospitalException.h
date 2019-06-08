#ifndef  HOSPITAL_EXCEPTION__H
#define  HOSPITAL_EXCEPTION__H

#include <iostream>
using namespace std;

class HospitalException
{
public:
	virtual void show() const {}
};

class NameException :public HospitalException
{
public:
	void show() 
	{
		cout << "Error: The name should include at least one letter." << endl;
	}
};

class DepartmentException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: No Departments availble in Hospital." << endl;
	}
};

class DepartmentExistException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: A Department by the given name already exist." << endl;
	}
};

class StaffException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: There are no Staff Members availavle in Hospital." << endl;
	}
};

class SurgeonException : public StaffException
{
public:
	virtual void show() const
	{
		cout << "Error: There are no Surgeons available in Hospital." << endl;
	}
};

class ResearcherException : public StaffException
{
public:
	virtual void show() const
	{
		cout << "Error: No Researchers available in the Research Institute." << endl;
	}
};

class ResearcherDoesntExistException :public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: Researcher doesn't exist in the Research Institute" << endl;
	}
};



class PatientExistException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: A Patient with the given ID number already exists." << endl;
	}
};

class PatientException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: Patient's ID was not found." << endl;
	}
};


class DateException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: The Date is invalid." << endl;
	}
};

class FormatException : public HospitalException
{
public:
	virtual void show() const
	{
		cout << "Error: Invalid input or not according to format." << endl;
	}
};




#endif // ! HOSPITAL_EXCEPTION__H