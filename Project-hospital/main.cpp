#include "Hospital.h"
#include "ConstantsAndGenFuncs.h"
#include "Ui.h"
#include "File.h"

void main()
{
	Hospital hospital;
	Files file(&hospital);
	file.readFile();
	Ui ui(&hospital);
	ui.start();
	file.writeFile();
	system("pause");
}