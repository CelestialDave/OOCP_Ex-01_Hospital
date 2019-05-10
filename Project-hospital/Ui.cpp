#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Hospital.h"
#include "Utils.h"


Ui::Ui(Hospital *hos)
{
	hospital = hos;
}

void Ui::start()
{
	printMainMenu();
	int choise;
	bool exit = false;
	cin >> choise;
	cin.ignore();
	while (!exit)
	{
		bool askToContinue = false;
		switch (choise)
		{
		case 1:  //add a department to the hospital
		{
			char* name = getString("Department's name: ");
			Department* department = new Department(name);
			int index = hospital->binSearchDepartmentByName(department->getName()); //check if it new department
			if (index == -1) //if this is new department name
				hospital->addDepartment(*department); //add to the departments array
			else
			{
				cout << "Error: A Department by the given name already exist." << endl;
				askToContinue = true;
			}
			delete[] name;
			//printSpaceLine();
			break;
		}
		case 2:   //add a nurse
		{
			if (hospital->isDepartmentsEmpty())
			{
				cout << "Error: No Departments availble in Hospital." << endl;
				askToContinue = true;
				break;
			}
			int employeeID = getInt("Nurse's Employee ID Number: [1-9 digits]");
			bool existID = hospital->validationEmployeeId(employeeID);
			if (!existID)
			{
				int depNum;
				cout << "Please choose the Department number from the following list: " << endl;
				hospital->showDepartments();
				cin >> depNum;
				cin.ignore();
				int depInd = depNum - 1;
				bool existDep = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
				if (existDep)
				{
					Nurse*nurse = createNurse(employeeID);
					hospital->addNurse(*nurse);
					hospital->addNurseToSpecificDepartment(*nurse, depInd);
				}
				else
					cout << "Error: Department specified doesn't exist." << endl;
			}
			else
				cout << "Error: An employee of the given ID number already exists." << endl;
			break;
		}
		case 3: //add doctor to the hospital
		{
			if (hospital->isDepartmentsEmpty())
			{
				cout << "Error: No Departments availble in Hospital." << endl;
				bool askToContinue = false;
				break;
			}
			int employeeID = getInt("Doctor's Employee ID Number: [1-9 digits]");
			bool existID = hospital->validationEmployeeId(employeeID);
			if (!existID)
			{ 
				int depNum;
				cout << "Please choose the Department number from the following list: " << endl;
				hospital->showDepartments();
				cin >> depNum;
				cin.ignore();
				int depInd = depNum - 1;
				bool existDep = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
				if (existDep)
				{
					Doctor*doctor=createDoctor(employeeID);
					hospital->addDoctor(*doctor);
					hospital->addDoctorToSpecificDepartment(*doctor,depInd);


				}
				else
				{
					cout << "Error: The Department specified doesn't exist." << endl;
					bool askToContinue = false;
				}
			}
			else
			{
				cout << "Error: An employee with the given Employee ID number already exists" << endl;
				bool askToContinue = false;
			}
			break;
		}
		case 4:	// Add Visitation
		{
			
			Department* department = nullptr;
			char* inID = getString("Patient's ID number: ");
			bool isFirstTime = checkIfItFirstTimeInHospital();
			bool isExists = false;
			Patient* patient = hospital->getPatientByID(inID, &isExists);

			if (isFirstTime) //this is the first visit in the hospital
			{
				if (isExists) // 1st time = Shouldn't exist
				{ 
					cout << "Error: A Patient with the given ID number already exists." << endl;
					bool askToContinue = false;
					delete[] inID;
					break;
				}
				else {
					patient = createPatient(inID);
				}
			}
			else //it is not the first visit
			{
				if (!isExists) // Should exist
				{
					cout << "Error: A Patient with the ID number was not found." << endl;
					bool askToContinue = false;
					delete[] inID;
					break;
				}
			}

			int depNum;
			cout << "Please choose the Department number from the following list: " << endl;
			hospital->showDepartments();
			cin >> depNum;
			cin.ignore();
			int depInd = depNum - 1;
			bool exist = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
			if (!exist)
			{
				cout << "Error: The Department number chosen is invalid!" << endl;
				bool askToContinue = false;
				delete[] inID;
				if (!isExists)
					delete patient;
				break;
			}

			Department* inDep = nullptr;
			inDep = hospital->getDepartmentByIndex(depInd);

			char* inDate = getString("Patient's arrival date: [DD/MM/YYYY]");
			Date* arrivalDate = nullptr;
			bool isValidDateInput = Utils::convertStrDateToDateObj(inDate, &arrivalDate);
			if (!isValidDateInput)
			{
				cout << "Error: Input date is invalid or not according to format." << endl;
				bool askToContinue = false;
				delete[] inID;
				delete[] inDate;
				if (!isExists)
					delete patient;
				break;
			}

			char* staffMemIncharge = getString("Medical staff member in charge: ");
			char* visitPurpose = getString("Visitation purpose: ");

			VisitationRecord* newVisit = new VisitationRecord(*patient, staffMemIncharge, *arrivalDate, visitPurpose);
			patient->addVistation(*newVisit);

			// Adding Patient to relevant DB if required:
			if (!patient->hasVisitedDepartment(*inDep)) // Patient hasn't visited in this department
			{
				inDep->addPatient(*patient);
				patient->addDepatrtmentToPatient(*inDep);
			}
			if (isFirstTime)
				hospital->addPatient(*patient);

			cout << "Your visitation has been added successfully." << endl;
			break;

		}
		case 5: //add researcher to the researcher insistute
		{
			int employeeID = getInt("Researcher's Employee ID Number: [1-9 digits]");
			char*name = getString("Researcher's name: ");
			Researcher* researcher = new Researcher(name, employeeID);
			hospital->addResearcher(*researcher);
			delete[]name;
			printSpaceLine();
			break;
		}
		case 6:   //add article to specific researcher
		{
			if (hospital->getSizeOfResearchers() > 0)
			{
				char*researcherName = getString("Which researcher would you like to add an article to?");
				bool exist = false;
				Researcher*researcher = hospital->findResearcherAccordingToName(researcherName, exist);
				if (exist) //if the researcher name input is ok
				{
					char*strDate = getString("Publication Date: [DD/MM/YYYY]");
					Date* date = nullptr;
					bool okDate = Utils::convertStrDateToDateObj(strDate, &date);
					if (okDate)
					{
						Article * article = createArticle(date);
						hospital->addArticleToResearcher(*article, researcher);
					}
					else
						cout << "Error: Date is invalid." << endl;
					delete[]strDate;
				}
				else
					cout << "Error: Researcher doesn't exist in the Research Institute" << endl;
				delete[]researcherName;

			}
			else
				cout << "No Researchers available in the Research Institute." << endl;
			printSpaceLine();
			break;
		}
		case 7: //show patients in specific department
		{
			if (hospital->getNumOfDepartments() > 0)
			{
				cout << "Please choose the Department number from the following list: " << endl;
				hospital->showDepartments();
				int depNum;
				cin >> depNum;
				cin.ignore();
				int depInd = depNum - 1;
				bool ok = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
				if (ok)
					hospital->showPatientInSpecificDep(depInd);
				else
					cout << "Error: The Department number chosen is invalid!" << endl;
			}
			else
				cout << "There are no departments yet" << endl;
			break;
		}
		case 8: //show staff medical members
		{
			hospital->showStaffMembers(); 
			break;
		}
		case 9: //show the researchers in the researcher institute
		{
			hospital->showResearchers();
			break;
		}
		case 10: //search patient by ID number
		{
			char*id = getString("Patient's ID number: ");
			bool isExists = false;
			Patient* patient = hospital->getPatientByID(id, &isExists);
			if (isExists)  //the ID numebr input of patient is exist
			{
				cout << "Patient's name: " << patient->getName() << endl;
				patient->showDepatmentsVisited();
			}
			else
				cout << "Error: Patient's ID was not found." << endl;
			break;
		}
		case 11:
			exit = true;
			break;
		default:
		{
			cout << "Error: Invalid input, please try again..." << endl;
			break;
		}
		}

		printSpaceLine();
		if (askToContinue) {
			char* reply = getString("Would you like to continue? [y/n]");
			while ((strcmp(reply, "y") != 0) && (strcmp(reply, "n") != 0))
			{
				cout << "Error: invalid input. please enter 'y' for \"Yes\", 'n' for \"No\"..." << endl;
				reply = getString("Would you like to continue? [y/n]");
			}
			if (strcmp(reply, "n") == 0)
			{
				exit = true;
				printSpaceLine();
			}
			else
			{
				printMainMenu();
				cin >> choise;
				cin.ignore();
			}
		}
		else if (!exit)
		{
			printSpaceLine();
			printMainMenu();
			cin >> choise;
			cin.ignore();
		}
	}

	cout << "\n\nFarewell... \n\nAnd remember; \"Medicus curat, natura sanat\".\n" << endl;
}

void Ui::printSpaceLine() const
{
	cout << "\n==================================================================\n" << endl;
}

Article* Ui::createArticle(Date* date)
{
	char *name = getString("Article's name: ");
	char *magazineName = getString("The magazine in which article was published:");
	return new Article(name, magazineName,*date);
}

Nurse* Ui::createNurse(int employeeID)
{
	char*name = getString("Nurse's name: ");
	int yearsExprience = getInt("Years of Experience: ");
 	return new Nurse(name, employeeID, yearsExprience);
}


int Ui::getInt(const char* str)
{
	int num;
	cout << str << endl;
	cin >> num;
	cin.ignore();
	return num;

}
Doctor* Ui::createDoctor(int employeeID)
{
	char* name = getString("Doctor's name: ");
	char* specialty = getString("Doctor's speciality: ");
	return new Doctor(name, employeeID, specialty);
}
	
Patient* Ui::createPatient(char* id)
{
	const char* name = getString("Patient's name: ");
	eGender gen = inputGender();
	char* yearOfBirth = getString("Patient's year of birth: ");
	return (new Patient(name, id, gen, yearOfBirth));
}

char* Ui::getString(const char* prompt)

{
	if (strlen(prompt) > 0)
		cout << prompt << endl;
	
	char temp[MAX_NAME];
	cin.getline(temp, MAX_NAME);
 	char* str = new char[strlen(temp) + 1];
	strcpy(str, temp);
	return str;
}

enum eGender Ui::inputGender()
{
	int gen;
	enum eGender gender;
	cout << "Patient's gender:  [0: Male, 1: Female]" << endl;
	cin >> gen;
	cin.ignore();
	gender = (eGender)gen;
	return gender;
}

bool Ui::checkIfItFirstTimeInHospital() const
{
	bool res;
	cout << "Is this the Patient's first visit?  [0: No, 1: Yes]" << endl;
	cin >> res;
	cin.ignore();
	return res;
}


int Ui::inputYearsOfExprience()const
{
	int yearsExp;
	cout << "Years of experience: " << endl;
	cin >> yearsExp;
	cin.ignore();
	return yearsExp;
}

void Ui::printMainMenu() const
{
	cout << "\t\t::Hospital Management System::" << endl;
	cout << "\nPlease choose an option from the following list:\n" << endl;
	cout << "\t1. Add a Department to the Hospital." << endl;
	cout << "\t2. Add a Nurse to the Hospital." << endl;
	cout << "\t3. Add a Doctor to the Hospital." << endl;
	cout << "\t4. Add a Patient's Visitation." << endl;
	cout << "\t5. Add a Researcher to The Hospital's Research Institute." << endl;
	cout << "\t6. Add a Researcher's Article." << endl;
	cout << "\t7. Show all Patients by Department." << endl;
	cout << "\t8. Show all the Hospital's Medical Staff Members." << endl;
	cout << "\t9. Show all Researchers in the Research Institute." << endl;
	cout << "\t10. Get a Patient information by ID." << endl;
	cout << "\t11. Exit Program." << endl;
}


