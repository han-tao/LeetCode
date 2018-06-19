#include <iostream> 
#include <algorithm>
#include <vector> 
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> res;
	int remainder;
	int index;
	for ( index = 0; index < nums.size(); ++index)
	{
		remainder = target - nums[index];
		if (nums[index] < remainder)
		{
			for (int iindex = index+1; iindex < nums.size(); iindex++)
			{
				if (remainder == nums[iindex])
				{
					res.push_back(index+1);
					res.push_back(iindex+1);
					break;
				}
			}
		}
	}
	return res;
}
int main(int argc, char** argv) {
	std::vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	std::vector<int> res = twoSum(nums, target);
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
	{
		std::cout << *iter << '\t';
	}
	std::cin.get();
	return 1;
}
