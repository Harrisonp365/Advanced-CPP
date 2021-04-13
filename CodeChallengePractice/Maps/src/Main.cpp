#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

std::pair<int, int> TwoSum(std::vector<int>& nums, int target)
{
	std::unordered_map<int, int> val_to_map;
	std::pair<int, int> result(-1, -1);
	std::vector<int>::iterator it = nums.begin();

	for (; it != nums.end(); ++it)
	{
		if (val_to_map.find(target - *it) != val_to_map.end())
		{
			result.first = val_to_map[target - *it];
			result.second = it - nums.begin();
			break;
		}
		val_to_map[*it] = it - nums.begin();
	}
	return result;
}

int main()
{
	std::vector<int> v = { 1, 4, 2, 9, 8 };
	int target = 100;
	std::pair<int, int> result = TwoSum(v, target);
	std::cout << result.first << " " << result.second;

	return 0;
}