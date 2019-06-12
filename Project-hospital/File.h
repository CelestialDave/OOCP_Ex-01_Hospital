#ifndef FILE__H
#define FILE__H

#include <ostream>
#include <fstream>
#include "Hospital.h"



class Files
{
private:
	Hospital* hospital;

public:
	Files(Hospital* hospital);
	void readFile();
	void writeFile();
};




#endif
