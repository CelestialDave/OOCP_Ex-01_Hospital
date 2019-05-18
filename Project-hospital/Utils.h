#ifndef __UTILS_H
#define __UTILS_H

class Utils {
public:
	static bool convertStrDateToDateObj(char* strDate, Date** resDate);
	static bool ifIndexInRange(const int&index, const int& logSize);
};

#endif // !__UTILS_H

