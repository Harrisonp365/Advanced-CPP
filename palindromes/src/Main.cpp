#include <iostream>
#include <string>

using namespace std;
//Checking for palindrome using strings
/*
bool isPalin(const string& s)
{
	int first = 0; // index of first letter
	int last = s.length() - 1; // index of last letter

	while (first < last) // we haven't reached the middle
	{
		if (s[first] != s[last]) return false;
		++first; // move forward
		--last; // move backward
	}
	return true;
}

int main()
{
	for (string s; cin >> s;)
	{
		cout << s << " is";
		if (!isPalin(s)) cout << " not";
		cout << " a palindrome\n";
	}
	return 0;
}
*/
//Checking using arrays
bool isPalin(const char s[], int n) //s is the first character of the array
{
	int first = 0;
	int last = n - 1;
	while (first < last) // we haven't reached the middle
	{
		if (s[first] != s[last]) return false;
		++first; // move forward
		--last; // move backward
	}
	return true;

}

istream& readWord(istream& is, char* buffer, int max) // read at max 'max -1' character from 'is' into buffer
{
	is.width(max); // read max -1
	is >> buffer;

	return is;
}

int main()
{
	constexpr int max = 128;
	for (char s[max]; readWord(cin, s, max);)
	{
		cout << s << " is";
		if (!isPalin(s, strlen(s))) cout << " not";
		cout << " a palindrome\n";
	}
	return 0;
}

