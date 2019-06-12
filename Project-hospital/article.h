#ifndef Article__H
#define Article__H

#include "Date.h"
#include "ConstantsAndGenFuncs.h"
#include "hospitalException.h"


class Article
{
private:
	string name;
	string magazineName;
	Date* publicationDate;

public:
	// C'tor:
	Article(const string inName, string inMagazineName, Date&inPublicitaion) throw(HospitalException);
	Article(ifstream& inFile);
	// Copy C'tor
	Article(const Article& other);
	// D'tor:
	~Article();

	const string getName() const;
	const string getMagazineName() const;
	const Date& getPublicationDate() const;
	void print(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Article& article);
	friend ifstream& operator >>(ifstream& inFile, Article& article);

};


#endif 