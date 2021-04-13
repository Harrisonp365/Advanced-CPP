#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxSubArrSum(std::vector<int>& vec)
{
	int final_max = INT_MIN;
	int max_so_far = 0;
	int vec_size = vec.size();
	std::vector<int>::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		max_so_far += *it;
		if (final_max < max_so_far)
			final_max = max_so_far;
		if (max_so_far < 0)
			max_so_far = 0;
	}
	/*
	for (int i = 0; i < vec.size(); ++i)
	{
		max_so_far += vec[i];
		if (final_max < max_so_far)
			final_max = max_so_far;
		if (max_so_far < 0)
			max_so_far = 0;
	}
	*/
	return final_max;
}
int main()
{
	std::vector<int> v = { 5, 8, 1, -1, -2, 4 };
	cout << maxSubArrSum(v);
	return 0;
}