#include "ConstantsAndGenFuncs.h"
#include "researcher.h"
#include <string.h>

Researcher::Researcher(const char inName[MAX_NAME])
{
	copyName(inName, name);
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

void Researcher::addArticle(Article& art)
{
	{
		if (phySizeOfArticles == 0) //if the first researcher
		{
			articleStock = new Article*(&art);
			logSizeOfArticles++;
			phySizeOfArticles++;
		}
		else
		{
			if (logSizeOfArticles == phySizeOfArticles) //if there is no place in the array
			{
				phySizeOfArticles *= 2;
				reallocationArr();  //to reallocte the array to the new size
			}
			articleStock[logSizeOfArticles] = &art;
			logSizeOfArticles++;

		}
	}
}

void Researcher:: reallocationArr()
{
	Article** newArr = new Article*[phySizeOfArticles];
	for (int i = 0; i < logSizeOfArticles; i++)
		newArr[i] = articleStock[i];
	delete[]articleStock;
	articleStock = newArr;
}

char* Researcher::getName() const
{
	return name;
}





