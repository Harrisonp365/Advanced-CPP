#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
//#include <errors.h>

using namespace std;

template<typename In, typename Out>
//Input_iterator<In>() && Output_iterator<Out>()

Out copy(In first, In last, Out res)
{
	while (first != last)
	{
		*res = *first;
		++res;
		++first;
	}
	return res;
}

void f(vector<double>& vd, list<int>& li)
{
	if (vd.size() < li.size()) error("target container too small");
	copy(li.begin(), li.end(), vd.begin());
}

int main()
{
	
	return 0;
}