#ifndef Researcher__H
#define Researcher__H

#include "article.h"
#include "ConstantsAndGenFuncs.h"

class Researcher
{
private:
	char name[MAX_NAME];
	Article ** articleStock;
	int logSizeOfArticles;
	int phySizeOfArticles;

public:
	// C'tor:
	Researcher(const char name[MAX_NAME]);
	// Disable Copy C'tor:
	Researcher(const Researcher& other) = delete;
	// D'tor:
	~Researcher();
	void addArticle(Article& art);
	char* getName() const;
};
#endif 