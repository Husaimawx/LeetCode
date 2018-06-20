class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long long flag;
        vector<vector<int>> res;
        for(flag = pow((long long)2,nums.size())-1;flag >= 0;flag--)
        {
            vector<int> line;
            for(int j = 0;j<nums.size();j++)
            {
                if((flag >> j)&1 == 1)
                {
                    line.push_back(nums[j]);
                }
            }
            res.push_back(line);
        }
        return res;
    }
};