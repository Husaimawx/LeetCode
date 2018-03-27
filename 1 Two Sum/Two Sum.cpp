#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		vector<int> result;
		int N = numbers.size();
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (numbers[i] + numbers[j] == target)
				{
					result.push_back(i);
					result.push_back(j);
					return result;
				}
			}
		}
		return result;
	}
};