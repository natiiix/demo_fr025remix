#include "str.hpp"

namespace str
{
	// beginsWith
	bool beginsWith(const std::string & str, const std::string & beginning)
	{
		for (int i = 0; i < (int)beginning.size(); i++)
		{
			if (str[i] != beginning[i])
				return false;
		}

		return true;
	}

	// split
	void split(const std::string & input, std::vector<std::string> & words, const char & separator, const bool & removeEmpty)
	{
		words.clear();
		std::istringstream strstream(input);

		std::string sTemp;
		while (getline(strstream, sTemp, separator))
		{
			if (!removeEmpty || sTemp.length() > 0)
			{
				words.push_back(sTemp);
			}
		}
	}

	// toInt
	int toInt(const std::string & str)
	{
		if (str.size() > 0)
		{
			std::stringstream ss(str);
			int i;
			ss >> i;
			return i;
		}

		return 0;
	}

	// toFloat
	float toFloat(const std::string & str)
	{
		if (str.size() > 0)
		{
			std::stringstream ss(str);
			float f;
			ss >> f;
			return f;
		}

		return 0.0f;
	}
}
