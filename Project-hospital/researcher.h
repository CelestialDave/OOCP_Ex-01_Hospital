#ifndef Researcher__H
#define Researcher__H

#include "article.h"

class Researcher
{
private:
	char* name;
	Article ** articleStock;
	int logSizeOfArticles;
	int phySizeOfArticles;

public:
	// C'tor:
	Researcher(const char* name, Article** arr,int sizeArticle);
	// Disable Copy C'tor:
	Researcher(const Researcher& other) = delete;
	// D'tor:
	~Researcher();
	void addArticle(Article& art);
};
#endif 