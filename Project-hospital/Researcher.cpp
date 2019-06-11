#include "researcher.h"

Researcher::Researcher(const Researcher& other) : StaffMember(other)
{
	if (this != &other)
	{
		this->articleStock = other.articleStock;
	}
}

void Researcher::addArticle(Article& art)
{
	articleStock.addToArray(art);
}

void Researcher::showArticles() const
{
	int size = articleStock.getlogicSize();
	if (size)
	{
		cout << "\tArticles: ";
		for (int i = 0; i < size; i++)
		{
			cout << "\n\t\t" << i + 1 << ". " << *(articleStock[i]);
		}
	}
	else
		cout << "\tArticles: No Articles Available." << endl;
}

void Researcher::allocationArticlesArr()
{
	articleStock.alloc();
}

void Researcher::print(ostream& os) const
{

	StaffMember::print(os);
	os << "\tRole: Researcher." << "\n\tArticles Published: " << articleStock.getlogicSize() << endl;
}

bool Researcher::operator>(const Researcher & other) const
{
	return (this->articleStock.getlogicSize() > other.articleStock.getlogicSize());
}