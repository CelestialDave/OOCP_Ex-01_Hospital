#include "article.h"
#include "ConstantsAndGenFuncs.h"

Article::Article(const char inName[MAX_NAME], char*inMagazineName, Date inPublicitaion)
{
	copyName(inName, name);
	copyName(inMagazineName, magazineName);
	PublicationDate = inPublicitaion;
}

Article::Article(const Article& other)
{
	copyName(other.name, name);
	copyName(other.magazineName, magazineName);
	PublicationDate = other.PublicationDate;
}

Article::~Article()
{
	delete[]name;
	delete[]magazineName;
}
