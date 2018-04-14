#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> ans;
	if (nums.size()<4)
		return ans;
	sort(nums.begin(), nums.end());
	vector<int> slimnums;
	int dulpnum = 1;
	int lastinsert = nums[0];
	for (int i = 1; i <= nums.size(); i++)
	{
		if (i == nums.size() || nums[i] != lastinsert)
		{
			if (dulpnum >= 3)
			{
				if (dulpnum >= 4 && 4 * lastinsert == target)
				{
					vector<int> temp(4, 0);
					temp[0] = lastinsert;
					temp[1] = lastinsert;
					temp[2] = lastinsert;
					temp[3] = lastinsert;
					ans.push_back(temp);
				}
				slimnums.push_back(lastinsert);
				slimnums.push_back(lastinsert);
				slimnums.push_back(lastinsert);
			}
			else if (dulpnum == 2)
			{
				slimnums.push_back(lastinsert);
				slimnums.push_back(lastinsert);
			}
			else
			{
				slimnums.push_back(lastinsert);
			}
			dulpnum = 1;
			if(i != nums.size())
				lastinsert = nums[i];
		}
		else
			dulpnum++;
	}

	nums = slimnums;
	int lastnumi = INT_MIN;
	int lastnumj = INT_MIN;
	for (int j = 0; j<nums.size(); j++)
	{
		if (nums[j] == lastnumj)
			continue;
		else
			lastnumj = nums[j];
		for (int i = j + 1; i<nums.size(); i++)
		{
			if (nums[i] == lastnumi)
				continue;
			else
				lastnumi = nums[i];
			int from = i + 1;
			int to = nums.size() - 1;
			while (from < to)
			{
				if (nums[from] + nums[to] + nums[i] + nums[j] == target)
				{
					vector<int> temp(4, 0);
					temp[0] = nums[j];
					temp[1] = nums[i];
					temp[2] = nums[from];
					temp[3] = nums[to];
					ans.push_back(temp);

					int last = nums[from];
					while (from < to && nums[from] == last)
						from++;
					to--;
				}
				else if (nums[from] + nums[to] + nums[i] + nums[j] > target)
				{
					to--;
				}
				else
				{
					from++;
				}
			}
		}
	}

	return ans;
}

int main()
{
	vector<int> input(6, 0);
	input[0] = 1;
	input[1] = 0;
	input[2] = -1;
	input[3] = 0;
	input[4] = 2;
	input[5] = -2;
	vector<vector<int>> ans = fourSum(input,0);
	return 0;
};