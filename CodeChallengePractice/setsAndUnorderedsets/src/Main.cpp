#include <unordered_set>
#include <string>
#include <iostream>

//finding the longest string without repeated characters
int longestString(std::string str)
{
	int sLen = str.size();
	std::unordered_set<char> visitedChar;
	int windowStart = 0;
	int windowEnd = 0;
	int maxLen = 0;

	while (windowStart < sLen && windowEnd < sLen)
	{
		if (visitedChar.find(str[windowEnd]) == visitedChar.end())
		{
			visitedChar.insert(str[windowEnd]);
			maxLen = (maxLen > windowEnd - windowStart) ? maxLen : (windowEnd - windowStart + 1);
			windowEnd++;
		}
		else
		{
			visitedChar.erase(str[windowStart]);
			windowStart++;
		}
	}
	return maxLen;
}

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "abcbed";
	std::string s3 = "aaaa";

	std::cout << "S1: " << longestString(s1) << "\nS2: " << longestString(s2) << "\nS3: " << longestString(s3);
	return 0;
}