#include "researcher.h"

Researcher::Researcher(const char inName[MAX_NAME])
{
	name = new char[strlen(inName) + 1];
	strcpy(name, inName);
	articleStock = nullptr;
	logSizeOfArticles = 0;
	phySizeOfArticles = 0;
}

Researcher::~Researcher()
{
	delete[]name;
	for (int i = 0; i < logSizeOfArticles; i++)
		delete articleStock[i];
	delete[]articleStock;
}

bool Researcher::addArticle(Article& art)
{
		if (phySizeOfArticles == 0) //if the first researcher
		{
			articleStock = new Article*;
			phySizeOfArticles++;
		}	
		else if (logSizeOfArticles == phySizeOfArticles) //if there is no place in the array
		{
			phySizeOfArticles *= 2;
			allocationArticlesArr();  //to reallocte the array to the new size
		}
		if (logSizeOfArticles < phySizeOfArticles)
		{
			articleStock[logSizeOfArticles] = &art;
			logSizeOfArticles++;
		}
		return true;
}

void Researcher:: allocationArticlesArr()
{
	if (phySizeOfArticles == 0) // If this is the 1st Department
	{
		articleStock = new Article*;
		logSizeOfArticles++;
	}
	else if (logSizeOfArticles == phySizeOfArticles) //if there is no place in the array
	{
		phySizeOfArticles *= 2;
		Article** newArr = new Article*[phySizeOfArticles];
		for (int i = 0; i < logSizeOfArticles; i++)
		{
			newArr[i] = articleStock[i];
		}
		delete[] articleStock;
		articleStock = newArr;
	}
	else
		return;
}

const char* Researcher::getName() const
{
	return name;
}

void Researcher::showArticles() const
{
	if (logSizeOfArticles)
	{
		for (int i = 0; i < logSizeOfArticles; i++)
		{
			cout << "The name of the article is: " << articleStock[i]->getName() << endl;
			cout << "The name of the magazine that include the article is: " << articleStock[i]->getMagazineName() << endl;;
			cout << "The publication date is: ";
			articleStock[i]->showDate();
		}
	}
	else
		cout << "There is no article for this researcher" << endl;
}






