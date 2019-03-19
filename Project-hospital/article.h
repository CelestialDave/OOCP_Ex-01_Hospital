#ifndef Article__H
#define Article__H

struct Date
{
	int day;
	int month;
	int year;
};

class Article
{
private:
	char *name;
	char *nameMagazine;
	Date PublicationDate;

public:
	Article(char*name, char*nameMagazine, Date publicitaion);
	Article(const Article& other);
	~Article();
};


#endif 