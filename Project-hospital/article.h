#ifndef Article__H
#define Article__H

#include "Date.h"
#include "ConstantsAndGenFuncs.h"


class Article
{
private:
	char *name;
	char *nameMagazine;
	Date PublicationDate;

public:
	// C'tor:
	Article(const char* inName, char*inNameMagazine, Date inPublicitaion);
	// Copy C'tor
	Article(const Article& other);
	// D'tor:
	~Article();
};


#endif 