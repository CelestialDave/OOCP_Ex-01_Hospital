#include "ConstantsAndGenFuncs.h"
#include "Date.h"
#include "Utils.h"


bool Utils:: ifIndexInRange(const int&index, const int& logSize)
{
	if (index >= 0 && index < logSize)
		return true;
	else
		return false;
}

bool Utils::isValidString(string input)
{
	return ((input.length() > 0) && (input != " "));
}

vector<string> Utils::split(string s, string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	string token;
	vector<string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}