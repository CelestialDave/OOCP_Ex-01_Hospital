#ifndef Article__H
#define Article__H

#include "Date.h"
#include "ConstantsAndGenFuncs.h"


class Article
{
private:
	char *name;
	char *magazineName;
	Date* publicationDate;

public:
	// C'tor:
	Article(const char *inName, char*inMagazineName, Date&inPublicitaion);
	// Copy C'tor
	Article(const Article& other);
	// D'tor:
	~Article();

	const char* getName() const;
	const char* getMagazineName() const;
	const Date& getPublicationDate() const;
	void showDate() const;
};


#endif 