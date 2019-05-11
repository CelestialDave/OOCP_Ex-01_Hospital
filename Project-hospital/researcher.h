#ifndef Researcher__H
#define Researcher__H

#include "article.h"
#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"

class Researcher :virtual public StaffMember
{
private:
	Article ** articleStock;
	int logSizeOfArticles;
	int phySizeOfArticles;

public:
	// C'tor:
	Researcher(const char inName[MAX_NAME],int employeeIDNumber);
	// Disable Copy C'tor:
	Researcher(const Researcher& other);
	// D'tor:
	virtual ~Researcher();
	void addArticle(Article& art);
	//const char* getName() const;
	int getSizeOfArticles() const;
	void showArticles() const;
	void allocationArticlesArr();

	bool operator>(const Researcher& other) const;

};
#endif 