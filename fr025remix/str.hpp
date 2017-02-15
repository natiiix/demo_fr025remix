#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace str
{
	// Checks whether the string str begins with the string beginning
	bool beginsWith(const std::string & str, const std::string & beginning);

	// Used to split strings by a certain character
	void split(const std::string & input, std::vector<std::string> & words, const char & separator = ' ', const bool & removeEmpty = false);

	// Converts string to integer
	int toInt(const std::string & str);

	// Converts string to float
	float toFloat(const std::string & str);
}
