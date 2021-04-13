#include <deque>
#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;
// check all parenthesis is string and make sure they are all valid
std::string ValidPar(std::string parStream)
{
	if (parStream.empty())
	{
		return "Valid";
	}
	std::stack<char>parStack;
	int i = 0;

	while (i < parStream.length())
	{
		switch (parStream[i])
		{
		case '(':
		case '[':
		case '{':
			parStack.push(parStream[i]);
			break;
		case ')':
			if (parStack.empty() || parStack.top() != '(')
				return "Not valid";
			parStack.pop();
			break;
		case ']':
			if (parStack.empty() || parStack.top() != '[')
				return "Not Valid";
			parStack.pop();
			break;
		case '}':
			if (parStack.empty() || parStack.top() != '{')
				return "Not valid";
			parStack.pop();
			break;
		}
		++i;
	}
	if (!parStack.empty())
		return "Not Valid"; // if the string is full it is not valid as all par need to be valid
	return "Valid";
}

void GenerateBinaryNum1toN(int n)
{
	std::queue<std::string> bin_queue;
	bin_queue.push("1");

	while (n > 0)
	{
		std::string temp = bin_queue.front();
		bin_queue.push(temp + "0");
		bin_queue.push(temp + "1");
		std::cout << temp << "  ";
		bin_queue.pop();
		n--;
	}
}


int main()
{
	//std::cout << ValidPar("(({[]}))");
	GenerateBinaryNum1toN(10);
	return 0;
}