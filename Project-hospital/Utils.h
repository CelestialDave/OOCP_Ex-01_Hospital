#ifndef __UTILS_H
#define __UTILS_H
#include <vector>
#include "hospitalException.h"

class Utils {
public:
	/*static vector<string> split(string s, string delimiter);
	static bool convertStrDateToDateObj(string strDate, Date** resDate);*/
	static bool ifIndexInRange(const int&index, const int& logSize);
	static bool isValidString(string input);
	static vector<string> Utils::split(string s, string delimiter);
	template <class ArrType, class VAL, class compareFunction>
	static ArrType binSearch(vector<ArrType> arr, VAL val, const compareFunction& f);
};

template <class ArrType, class VAL, class compareFunction>
ArrType Utils::binSearch(vector<ArrType> arr, VAL val, const compareFunction& f) throw(NotFoundException)
{
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		//int res = (stoi(inID) - stoi(allPatients[mid]->getId()));
		int res = f(arr[mid], val);
		if (res == 0) // found the value
			return arr[mid];

		if (res < 0) // go right
			left = mid + 1;

		else // (res > 0) => go left
			right = mid - 1;
	}
	
	////vector<ArrType>::iterator itrStart = arr.begin();
	////vector<ArrType>::iterator itrLeft = arr.begin();
	////vector<ArrType>::iterator itrRight = arr.end();
	////int left = 0;
	////int right = arr.size() - 1;
	//////while (itr <= itrEnd)
	////while (itrLeft <= itrRight)
	////{
	////	int mid = left + (right - left) / 2;
	////	vector<ArrType>::iterator itrMid = itrStart + mid;
	////	int res = f(itrMid, val);
	////	if (res == 0) // found the position
	////		return itrMid;

	////	if (res < 0) // go right
	////	{
	////		left = mid + 1;
	////		itrLeft = itrStart + left;
	////	}
	////	else // (res < 0) => go left
	////	{
	////		right = mid - 1;
	////		itrRight = itrStart + right;
	////	}
	////}
	// Not found:
	throw NotFoundException();
}

#endif // !__UTILS_H

