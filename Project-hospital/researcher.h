#ifndef Researcher__H
#define Researcher__H

#include "article.h"
//#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"
#include "Array.h"


class Researcher :virtual public StaffMember
{
protected:
	Array<Article> articleStock;
public:
	// C'tor:
	Researcher(const string inName);
	Researcher(ifstream& inFile);
	// Copy C'tor:
	Researcher(const Researcher& other);

	// D'tor:
	virtual ~Researcher() {}

	void addArticle(Article& art);

	void showArticles() const;

	void allocationArticlesArr();

	virtual void print(ostream& os) const;
	//virtual void toOs(ostream& os) const;
	bool operator>(const Researcher & other) const;
	friend ifstream& operator >> (ifstream& inFile, Researcher& researcher);

};
#endif 