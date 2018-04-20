#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<vector<int>> tempans;
	int len = candidates.size();
	if (len == 0)
		return ans;
	if (len == 1)
	{
		if (target % candidates[0] == 0)
		{
			ans.push_back(vector<int>(target / candidates[0], candidates[0]));
		}
		return ans;
	}
	int lastnum = candidates[len - 1];
	candidates.pop_back();
	int times = 0;
	while (target > 0)
	{
		tempans = combinationSum(candidates, target);
		for (auto it = tempans.begin(); it != tempans.end(); it++)
		{
			for (int i = 0; i<times; i++)
				(*it).push_back(lastnum);
			ans.push_back(*it);
		}
		times++;
		target -= lastnum;
	}
	candidates.push_back(lastnum);

	if (target == 0)
	{
		ans.push_back(vector<int>(times, lastnum));
	}

	return ans;
}

int main()
{
	vector<int> input(3,0);
	input[0] = 2;
	input[1] = 3;
	input[2] = 5;
	vector<vector<int>> ans = combinationSum(input, 8);
	return 0;
};

// other people's code
class Solution {
public:
	std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
		std::sort(candidates.begin(), candidates.end());
		std::vector<std::vector<int> > res;
		std::vector<int> combination;
		combinationSum(candidates, target, res, combination, 0);
		return res;
	}
private:
	void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
		if (!target) {
			res.push_back(combination);
			return;
		}
		for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
			combination.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combination, i);
			combination.pop_back();
		}
	}
};