#ifndef Doctor__H
#define Doctor__H


class Doctor
{
private:
	char*name;
	int employeeIDNumber;
	char*Specialty;

public:
	Doctor(char*name, int IDNum, char*Specialty);
	Doctor(const Doctor &) = delete;
	~Doctor();
};

#endif // !Doctor__H