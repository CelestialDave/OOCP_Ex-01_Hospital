#ifndef __UTILS_H
#define __UTILS_H
#include <vector>
#include "hospitalException.h"
#include <string>

class Utils {
public:
	static bool ifIndexInRange(const int&index, const int& logSize);
	static bool isValidString(string input);
	static vector<string> Utils::split(string s, string delimiter);
	template <class ArrType, class VAL, class compareFunction>
	static ArrType binSearch(vector<ArrType> arr, VAL val, const compareFunction& f) throw(NotFoundException);

};

template <class ArrType, class VAL, class compareFunction>
ArrType Utils::binSearch(vector<ArrType> arr, VAL val, const compareFunction& f) throw(NotFoundException)
{
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		int res = f(*(arr[mid]), val);
		if (res == 0) // found the value
			return arr[mid];

		else if (res < 0) // go right
			left = mid + 1;

		else // (res > 0) => go left
			right = mid - 1;
	}
	// Not found:
	throw NotFoundException();
}

template <class T>
class compareByName
{
public:
	int operator()(const T& member, const string name) const
	{
		return member.getName().compare(name);
	}
};

template <class T>
class compareByEmployeeIDNumber
{
public:
	int operator()(const T& member, int empoyeeIDNumber) const
	{
		return (member.getEmployeeIDNumber() - empoyeeIDNumber);
	}
};

template <class T>
class compareByPatientID
{
public:
	int operator()(const T& member, string id) const
	{
		return (member.getId().compare(id));
	}
};

#endif // !__UTILS_H

