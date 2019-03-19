#ifndef Doctor__H
#define Doctor__H


class Doctor
{
private:
	char* name;
	int employeeIDNumber;
	char* specialty;

public:
	// C'tor:
	Doctor(const char* inName, int inIDNum, char* inSpecialty);
	// Copy C'tor:
	Doctor(const Doctor &) = delete;
	// D'tor:
	~Doctor();
};

#endif // !Doctor__H