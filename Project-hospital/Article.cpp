#include "article.h"

Article::Article(const string inName, string inMagazineName, Date& inPublicitaion) throw(NameException)
{
	////name = new char[strlen(inName) + 1];
	if (inName == "" || inMagazineName== "")
		throw NameException();
	name = inName;
	////strcpy(name, inName);
	////magazineName = new char[strlen(inMagazineName) + 1];
	magazineName = inMagazineName;
	////strcpy(magazineName, inMagazineName);
	publicationDate = &inPublicitaion;
}


Article::Article(const Article& other)
{
	////name = new char[strlen(other.name) + 1];
	name = other.name;
	////strcpy(name, other.name);
	////magazineName = new char[strlen(other.magazineName) + 1];
	magazineName = other.magazineName;
	////strcpy(magazineName, other.magazineName);
	publicationDate = other.publicationDate;
}

Article::~Article()
{
	////delete[] name;
	////delete[] magazineName;
	delete publicationDate;

}

const string Article::getName() const
{
	return name;
}
const string Article::getMagazineName() const
{
	return magazineName;
}

const Date& Article::getPublicationDate() const
{
	return *(this->publicationDate);
}

void Article::print(ostream& os) const
{
	os << "Article name: " << this->name << endl
	<< "\t\tMagazine in which was published: " << this->magazineName
	<< "\n\t\tPublication date: " << *publicationDate << endl;
}

ostream& operator<<(ostream& os, const Article& article)
{
	article.print(os);
	return os;
}


