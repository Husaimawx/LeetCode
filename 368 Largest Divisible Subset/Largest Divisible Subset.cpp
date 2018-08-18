class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0)
        {
            vector<int> res;
            return res;
        }
        sort(nums.begin(),nums.end());
        vector<int> res(nums.size(),1);
        vector<int> pre(nums.size(),-1);
        int max_num = 1;
        int max_order = 0;
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = i-1;j>=0;j--)
            {
                if(nums[i] % nums[j] == 0 && res[j] >=res[i])
                {
                    res[i] = res[j]+1;
                    pre[i] = j;
                }
            }
            if(max_num < res[i])
            {
                max_num = res[i];
                max_order = i;
            }
        }
        vector<int> resList;
        while(max_order!=-1)
        {
            resList.push_back(nums[max_order]);
            max_order = pre[max_order];
        }
        vector<int> resList2;
        for(int i = resList.size()-1;i>=0;i--)
        {
            resList2.push_back(resList[i]);
        }
        return resList2;
    }
};