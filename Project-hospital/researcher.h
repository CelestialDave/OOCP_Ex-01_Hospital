#ifndef Researcher__H
#define Researcher__H

#include "article.h"

class Researcher
{
private:
	char*name;
	Article ** stock;
	int numberOfArticles;
public:
	Researcher(char* name, Article** arr,int sizeArticle);
	Researcher(const Researcher&) = delete;
	~Researcher();
	void addArticle(Article* art);
};
#endif 