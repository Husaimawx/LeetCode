class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int sum = 0;
        int min = INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i];
            if(min > nums[i])
                min = nums[i];
        }
        return sum-nums.size()*min;
    }
};