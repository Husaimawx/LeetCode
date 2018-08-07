class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return (nums[0] > nums[1] ? nums[0] : nums[1]);
        
        // take the first
        vector<int> nums1(nums.begin()+2, nums.end()-1);
        int ans1 = nums[0] + robAux(nums1);
        
        // not take the first
        vector<int> nums2(nums.begin()+1, nums.end());
        int ans2 = robAux(nums2);
        
        return (ans1>ans2 ? ans1 : ans2);
    }
    
    int robAux(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> res(nums.size()+1,0);
        res[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--)
        {
            res[i] = nums[i] + res[i+2];
            if(res[i] < res[i+1])
                res[i] = res[i+1];
        }
        return res[0];
    }
};