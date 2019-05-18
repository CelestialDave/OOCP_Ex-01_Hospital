#ifndef Researcher__H
#define Researcher__H

#include "article.h"
#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"

class Researcher :virtual public StaffMember
{
protected:
	Article ** articleStock;
	int logSizeOfArticles;
	int phySizeOfArticles;

public:
	// C'tor:
	Researcher(const char inName[MAX_NAME]);
	// Copy C'tor:
	Researcher(const Researcher& other);
	// D'tor:
	virtual ~Researcher();

	void addArticle(Article& art);
	void showArticles() const;
	void allocationArticlesArr();

	virtual void print(ostream& os) const;

	bool operator>(const Researcher& other) const;

};
#endif 