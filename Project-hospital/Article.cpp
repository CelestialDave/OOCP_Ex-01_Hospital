#include "article.h"

Article::Article(const char inName[MAX_NAME], char*inMagazineName, Date& inPublicitaion)
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	magazineName = new char[strlen(magazineName) + 1];
	strcpy(magazineName, magazineName);
	publicationDate = inPublicitaion;
}


Article::Article(const Article& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	magazineName = new char[strlen(other.magazineName) + 1];
	strcpy(magazineName, other.magazineName);
	publicationDate = other.publicationDate;
}

Article::~Article()
{
	delete[]name;
	delete[]magazineName;
}

const char* Article::getName() const
{
	return name;
}
const char* Article::getMagazineName() const
{
	return magazineName;
}
void Article::showDate() const
{
	publicationDate.showDate();
}

