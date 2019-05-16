#include "Ui.h"
#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Hospital.h"
#include "Utils.h"
#include "Visit_Surgery.h"



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
			Results res;
			res = addNewDepartment();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 2:   //add a nurse
		{
			Results res;
			res = addNewNurse();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 3: //add doctor to the hospital
		{
			Results res;
			res = addNewDoctor();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;
		}
		case 4:	// Add Visitation
		{
			Results res;
			res = addNewVisitation();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			break;

		}
		case 5: //add researcher to the researcher insistute
		{
			Results res;
			res = addNewResearcher();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			//printSpaceLine();
			break;
		}
		case 6:   //add article to specific researcher
		{
			Results res;
			res = addArticleToResearcher();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			//printSpaceLine();
			break;
		}
		case 7: //show patients in specific department
		{
			Results res;
			res = showPatientsInDepartment();
			if (res != SUCCESS)
			{
				warnings(res);
				askToContinue = true;
			}
			//if (hospital->getNumOfDepartments() > 0)
			//{
			//	cout << "Please choose the Department number from the following list: " << endl;
			//	hospital->showDepartments();
			//	int depNum;
			//	cin >> depNum;
			//	cin.ignore();
			//	int depInd = depNum - 1;
			//	bool ok = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
			//	if (ok)
			//		hospital->showPatientInSpecificDep(depInd);
			//	else
			//		// bad input1:
			//		cout << "Error: The Department number chosen is invalid!" << endl;
			//}
			//else
			//	cout << "There are no departments yet" << endl;
			break;
		}
		case 8: //show medical staff members
		{
			//***** Add to check of dynamic_cast to hospital->showMedicalStaffMembers()
			hospital->showMedicalStaffMembers(); 
			break;
		}
		case 9: // Show all researchers in Research Institute
		{
			hospital->showResearchers();
			break;
		}
		case 10: // Show all Researchers that are Doctors in the Research Institute
		{
			hospital->showDoctorResearchers();
			break;
		}
		case 11: //search patient by ID number
		{
			char*id = getString("Patient's ID number: ");
			bool isExists = false;
			Patient* patient = hospital->getPatientByID(id, &isExists);
			if (isExists)  //the ID numebr input of patient is exist
			{
				cout << "Patient's name: " << patient->getName() << endl;
				printVisitationPorpuse(patient);
				//patient->showDepatmentsVisited();
			}
			else
				cout << "Error: Patient's ID was not found." << endl;
			break;
		}
		case 12:// Which researcher has more articles
		{
			compare2Researchers();
			break;
		}
		case 13:
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


void Ui::compare2Researchers() const
{
	cout << "Choose 2 Researchers for article number comparison from the list below: " << endl;
	hospital->showResearchersName();
	int researcher1Ind, researcher2Ind;
	cin >> researcher1Ind >> researcher2Ind;
	researcher1Ind--;
	researcher2Ind--;
	bool ok1 = Utils::ifIndexInRange(researcher1Ind, hospital->getSizeOfResearchers());
	bool ok2 = Utils::ifIndexInRange(researcher2Ind, hospital->getSizeOfResearchers());
	if (ok1 && ok2)
	{
		Researcher* researcher1 = hospital->getResearcherByIndex(researcher1Ind);
		Researcher* researcher2 = hospital->getResearcherByIndex(researcher2Ind);

		if (researcher1 > researcher2)
		{
			cout << "True: " << researcher1->getName() <<
				" has more articles than " << researcher2->getName() << endl;
		}
		else
		{
			cout << "False: " << researcher1->getName() <<
				" has less or equal number of aritcles than " << researcher2->getName() << endl;
		}
	}
	else
		cout << "Error: invalid input" << endl;
}

VisitationRecord* Ui::createVisit(Patient & patient,Date* arrivalDate,int choice,bool& ok)
{
	//char* staffMemIncharge = getString("Medical staff member in charge: ");
	char* visitPurpose = getString("Visitation purpose: ");
	//VisitationRecord* visit=new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
	if (choice == CHECKUP)
	{
		char* staffMemIncharge = getString("Medical staff member in charge: ");
		VisitationRecord* visit=new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
		delete[]staffMemIncharge;
		delete[]visitPurpose;
		return visit;
	}
	else if (choice == SURGERY)
	{
		cout << "Please provide the Employee-ID number of your surgeon from the following list: "
		<< endl;
		Results res=hospital->showSurgeons();
		if (res == SUCCESS)
		{
			int employeeIDNum;
			cin >> employeeIDNum;
			int  indexSurgeon = hospital->binSearchStaffMemberByID(employeeIDNum);
			if (indexSurgeon != -1)
			{
				Surgeon*surgeon = dynamic_cast<Surgeon*>(hospital->getStaffMemberByIndex(indexSurgeon));
				surgeon->addSurgery();
				char* staffMemIncharge = strdup(surgeon->getName());
				VisitationRecord* visit = new VisitationRecord(patient, staffMemIncharge, *arrivalDate, visitPurpose);
				int surgeryRoomNum = getInt("Surgery Room Number: ");
				int fasting = getInt("Has the Patient been fasting? \n\t1.Yes\t2. No.\n");

				if (fasting == 1 || fasting == 0)
				{
					bool isFasting = (bool)fasting;
					VisitSurgery* newVisit = new VisitSurgery(*visit, surgeryRoomNum, isFasting);
					delete[]staffMemIncharge;
					delete[]visitPurpose;
					delete visit;
					return newVisit;
				}
			}
			else
			{
				delete[]visitPurpose;
				ok = false;
				return nullptr;
			}

		}
		else
		{
			delete[]visitPurpose;
			ok = false;
			return nullptr;
		}
	}
	else
	{
		delete[]visitPurpose;
		ok = false;
		return nullptr;
	}
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
	cout << "Patient's gender:  [1. Male\t2. Female]" << endl;
	cin >> gen;
	cin.ignore();
	gender = (eGender)(gen - 1);
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

void Ui::printVisitationPorpuse(Patient* patient) const
{
	int numVisits = patient->getSizeVisits();
	numVisits--;
	/*The number of visit more than one because we know the patient is exist,
	we want to get the last visitation to check if it was for Surgery or checkup */
	VisitationRecord* lastVisit = patient->getVisitByIndex(numVisits);

	VisitSurgery* temp = dynamic_cast<VisitSurgery*>(lastVisit);
	if (temp)
		cout << "The last patient visitation was for surgery" << endl;
	else
		cout << "The last patient visitation was for checkup" << endl;
}


Results Ui::addNewDepartment()
{
	Results res = SUCCESS;
	char* name = getString("Department's name: ");
	Department* department = new Department(name);
	int index = hospital->binSearchDepartmentByName(department->getName());
	if (index == -1) //if this is new department name
		hospital->addDepartment(*department); //add to the departments array
	else
		res = DEPEXIST;
	delete[] name;
	return res;
}

Results Ui::addNewNurse()
{
	Results res = SUCCESS;
	if (hospital->isDepartmentsEmpty())
	{
		res = NODEPS;
	}
	else {
		int employeeID = getInt("Nurse's Employee ID Number: [1-9 digits]");
		bool existID = hospital->verifyEmployeeIDNumber(employeeID);
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
				hospital->addStaffMember(nurse);
				hospital->addStaffMemberToDepartment(nurse, depInd);
			}
			else
				res = BADINPUT1;
		}
		else
			res = EIDEXIST;
	}
	return res;
}

Results Ui::addNewDoctor()
{
	Results res = SUCCESS;
	if (hospital->isDepartmentsEmpty())
	{
		res = NODEPS;
	}
	else {
		int docType = getInt("Please choose whether the Doctor is also:\n\t1.Researcher.\n\t2.Surgeon.\n\t3.Surgeon - Researcher.\n\t4.None.\n");
		if ((docType < 1) || (docType > 4))
		{
			res = BADINPUT1;
		}
		else {
			int employeeID = getInt("Doctor's Employee ID Number: [1-9 digits]");
			bool existID = hospital->verifyEmployeeIDNumber(employeeID);
			if (existID)
			{
				res = EIDEXIST;
			}
			else {
				int depNum;
				cout << "Please choose the Department number from the following list: " << endl;
				hospital->showDepartments();
				cin >> depNum;
				cin.ignore();
				int depInd = depNum - 1;
				bool existDep = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
				if (!existDep)
				{
					res = BADINPUT1;
				}
				else {
					Doctor* doctor = createDoctor(employeeID);
					if (docType == 4)
					{
						hospital->addStaffMember(doctor);
						hospital->addStaffMemberToDepartment(doctor, depInd);
					}
					else if ((docType == 2) || (docType == 3))
					{
						int numSurgeries = getInt("Please provide number of Surgeries perfromed: ");
						Surgeon* surgeon = new Surgeon(*doctor, numSurgeries);
						if (docType == 3)
						{
							Researcher* researcher = new Researcher(doctor->getName(), doctor->getEmployeeIDNumber());
							SurgeonResearcher* surgeonResearcher = new SurgeonResearcher(*surgeon, *researcher);
							hospital->addStaffMember(surgeonResearcher);
							hospital->addStaffMemberToDepartment(surgeonResearcher, depInd);
							delete doctor;
							delete surgeon;
							delete researcher;
						}
						else // (docType == 2)
						{
							hospital->addStaffMember(surgeon);
							hospital->addStaffMemberToDepartment(surgeon, depInd);
							delete doctor;
						}
					}
					else // (docType == 1) -> Researcher
					{
						Researcher* researcher = new Researcher(doctor->getName(), doctor->getEmployeeIDNumber());
						hospital->addStaffMember(researcher);
						hospital->addStaffMemberToDepartment(researcher, depInd);
						delete doctor;
					}
				}
			}
		}
	}
	return res;
}

Results Ui::addNewVisitation()
{
	Results res = SUCCESS;
	Department* department = nullptr;
	char* inID = getString("Patient's ID number: ");
	bool isFirstTime = checkIfItFirstTimeInHospital();
	bool isExists = false;
	Patient* patient = hospital->getPatientByID(inID, &isExists);

	if (isFirstTime) //this is the first visit in the hospital
	{
		if (isExists) // 1st time = Shouldn't exist
		{
			res = PIDEXIST;
			delete[] inID;
		}
		else {
			patient = createPatient(inID);
		}
	}
	else //it is not the first visit
	{
		if (!isExists) // Should exist
		{
			res = PIDNOTFOUND;
			delete[] inID;
		}
	}

	if (res == SUCCESS)
	{
		int depNum;
		cout << "Please choose the Department number from the following list: " << endl;
		hospital->showDepartments();
		cin >> depNum;
		cin.ignore();
		int depInd = depNum - 1;
		bool exist = Utils::ifIndexInRange(depInd, hospital->getNumOfDepartments());
		if (!exist)
		{
			res = BADINPUT1;
			delete[] inID;
			if (!isExists)
				delete patient;
		}
		else
		{
			Department* inDep = nullptr;
			inDep = hospital->getDepartmentByIndex(depInd);

			char* inDate = getString("Patient's arrival date: [DD/MM/YYYY]");
			Date* arrivalDate = nullptr;
			bool isValidDateInput = Utils::convertStrDateToDateObj(inDate, &arrivalDate);
			if (!isValidDateInput)
			{
				res = BADINPUT2;
				delete[] inID;
				delete[] inDate;
				if (!isExists)
					delete patient;
			}
			else
			{
				int visitChosen = getInt("Visitation purpose:\n\t1. Checkup.\n\t2. Surgery.\n");
				bool ok = true;
				VisitationRecord* newVisit = createVisit(*patient, arrivalDate, visitChosen, ok);

				if (ok)
				{
					patient->addVisitiaionRecord(newVisit);
					// Adding Patient to relevant DB if required:
					if (!patient->hasVisitedDepartment(*inDep)) // Patient hasn't visited in this department
					{
						inDep->addPatient(*patient);
						patient->addDepatrtmentToPatient(*inDep);
					}
					if (isFirstTime)
						hospital->addPatient(*patient);
					cout << "Visitation added successfully." << endl;
				}
				else
				{
					res = BADINPUT2;
					delete[] inID;
					delete[] inDate;
					if (!isExists)
						delete patient;
				}
			}
		}
	}
	return res;
}

Results Ui::addNewResearcher()
{
	Results res = SUCCESS;
	int employeeID = getInt("Researcher's Employee ID Number: [1-9 digits]");
	bool existID = hospital->verifyEmployeeIDNumber(employeeID);
	if (existID)
	{
		res = EIDEXIST;
	}
	else
	{
		char*name = getString("Researcher's name: ");
		Researcher* researcher = new Researcher(name, employeeID);
		hospital->addResearcher(researcher);
		delete[]name;
	}
	return res;
}

Results Ui::addArticleToResearcher()
{
	Results res = SUCCESS;
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
				res = BADINPUT2;
			delete[]strDate;
		}
		else
			res = RNONEXIST;
		delete[]researcherName;
	}
	else
		res = RESINSTEMPTY;
	return res;
}

Results Ui::showPatientsInDepartment()
{
	Results res = SUCCESS;
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
			// bad input1:
			res = BADINPUT1;
	}
	else
		res = NODEPS;
	return res;
}

void Ui::warnings(Results result)
{
	if (result != SUCCESS)
	{
		switch (result) {
		case NOTFOUND:
			cout << "";
			break;
		case BADINPUT1:
			cout << "Error: Invalid input." << endl;
			break;
		case BADINPUT2:
			cout << "Error: Invalid input or not according to format." << endl;
			break;
		case NODEPS:
			cout << "Error: No Departments availble in Hospital." << endl;
			break;
		case DEPEXIST:
			cout << "Error: A Department by the given name already exist." << endl;
			break;
		case NOSTAFF:
			cout << "There are no Staff Members availavle in Hospital." << endl;
			break;
		case EIDEXIST:
			cout << "Error: An Employee with the given Employee-ID Number already exists." << endl;
			break;
		case PIDEXIST:
			cout << "Error: A Patient with the given ID number already exists." << endl;
			break;
		/*case EIDNOTFOUND:
			cout << "";
			break;*/
		case PIDNOTFOUND:
			cout << "Error: Patient's ID was not found." << endl;
			break;
		case RNONEXIST:
			cout << "Error: Researcher doesn't exist in the Research Institute" << endl;
			break;
		case RESINSTEMPTY:
			cout << "No Researchers available in the Research Institute." << endl;
			break;
		default:
			break;
		}
	}

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
	cout << "\t10. Show all Researchers that are Doctors in the Research Institute." << endl;
	cout << "\t11. Get a Patient information by ID." << endl;
	cout << "\t12. Compare Researchers (>): \n\t\tShow between 2 chosen researchers if left has \n\t\tgreater number of articles then the one on the right." << endl;
	cout << "\t13. Exit Program." << endl;
}


