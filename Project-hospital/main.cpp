#include "Hospital.h"
#include "ConstantsAndGenFuncs.h"
#include "Ui.h"


void main()
{
	Hospital hospital;
	Ui ui(&hospital);
	ui.start();
	system("pause");
}