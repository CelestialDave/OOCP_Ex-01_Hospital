#ifndef __UTILS_H
#define __UTILS_H
#include <vector>

class Utils {
public:
	/*static vector<string> split(string s, string delimiter);
	static bool convertStrDateToDateObj(string strDate, Date** resDate);*/
	static bool ifIndexInRange(const int&index, const int& logSize);
	static bool isValidString(string input);
	static vector<string> Utils::split(string s, string delimiter);
};

#endif // !__UTILS_H

