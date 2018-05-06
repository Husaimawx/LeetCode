class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        int res = nums[0];
        int maxsum = max(0,nums[0]);
        for(int i = 1; i < nums.size(); i++)
        {
            res = max(nums[i]+maxsum,res);
            maxsum = max(0,nums[i]+maxsum);
        }
        return res;
    }
};