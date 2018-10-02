class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
        }
        if(sum % k != 0)
            return false;
        
        vector<bool> visited(nums.size(),true); 
        return helper(nums, k, sum/k, 0, 0, visited);
    }
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if(k == 1)
            return true;
        if(curSum == target)
            return helper(nums, k-1, target, 0, 0, visited);
        for(int i = start;i<nums.size();i++)
        {
            if(visited[i] == false)
                continue;
            visited[i] = false;
            if(helper(nums, k, target, i+1, curSum+nums[i], visited))
                return true;
            visited[i] = true;
        }
        return false;
    }
};