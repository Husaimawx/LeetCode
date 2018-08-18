// Backtracking
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1)
            return false;
        int target = sum /2;
        return targetSum(nums, 0, target);
    }
    
    bool targetSum(vector<int>& nums, int from, int target)
    {
        if(from == nums.size())
            return (!target);
        for(int i = from;i<nums.size();i++)
        {
            if(targetSum(nums, i+1, target-nums[i]))
                return true;
        }
        return false;
    }
};

// DP
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1)
            return false;
        int target = sum /2;
        
        vector<bool> res(5001,0);
        res[0] = 1;
        for(auto num:nums)
        {
            for(int i = target;i>=num;i--)
            {
                if(res[i] == false)
                    res[i] = res[i-num];
            }
            if(res[target] == 1)
                return true;
        }
        return false;
    }
};