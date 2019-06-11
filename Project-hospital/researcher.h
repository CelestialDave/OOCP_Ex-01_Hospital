#ifndef Researcher__H
#define Researcher__H

#include "article.h"
//#include "ConstantsAndGenFuncs.h"
#include "StaffMember.h"
#include "Array.h"


class Researcher :virtual public StaffMember
{
protected:
	Array<Article> articleStock;
public:
	// C'tor:
	Researcher(const string inName): StaffMember(inName) 
	{

	}
	// Copy C'tor:
	Researcher(const Researcher& other) : StaffMember(other)
	{
		if (this != &other)
		{
			this->articleStock = other.articleStock;
		}
	}
	// D'tor:
	virtual ~Researcher()
	{
	}

	void addArticle(Article& art)
	{
		articleStock.addToArray(art);
	}

	void showArticles() const
	{
		int size = articleStock.getlogicSize();
		if (size)
		{
			cout << "\tArticles: ";
			for (int i = 0; i < size; i++)
			{
				cout << "\n\t" << i + 1 << ". " << *(articleStock[i]);
			}
		}
		else
			cout << "Not Available" << endl;
	}

	void allocationArticlesArr()
	{
		articleStock.alloc();
	}

	virtual void print(ostream& os) const
	{

		StaffMember::print(os);
		os << "\tRole: Researcher." << "\n\tResearchers Published: " << articleStock.getlogicSize() << endl;
	}

	bool operator>(const Researcher & other) const
	{
		return (this->articleStock.getlogicSize() > other.articleStock.getlogicSize());
	}

};
#endif 