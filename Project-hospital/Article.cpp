#include "article.h"
#include "Utils.h"


Article::Article(const string inName, string inMagazineName, Date& inPublicitaion) throw(HospitalException)
{
	if (!Utils::isValidString(inName) || !Utils::isValidString(inMagazineName))
		throw StringException();
	name = inName;
	magazineName = inMagazineName;
	publicationDate = &inPublicitaion;
}


Article::Article(const Article& other)
{
	name = other.name;
	magazineName = other.magazineName;
	publicationDate = other.publicationDate;
}

Article::~Article()
{
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
	os << "\tArticle name: " << this->name << endl
	<< "\t\tMagazine in which was published: " << this->magazineName
	<< "\n\t\tPublication date: " << *publicationDate << endl;
}

ostream& operator<<(ostream& os, const Article& article)
{
	article.print(os);
	return os;
}


