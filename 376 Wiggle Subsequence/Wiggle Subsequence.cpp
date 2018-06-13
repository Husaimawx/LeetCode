class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        
        vector<int> nums2 = nums;
        int j = 1;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums2[j] = nums[i];
                j++;
            }
        }
        
        if(j<=2)
            return j;
        
        int i;
        int ans = 2;
            
        for(i = 1;i<j-1;i++)
        {
            if(nums2[i-1]<nums2[i] && nums2[i+1]<nums2[i])
                ans++;
            if(nums2[i-1]>nums2[i] && nums2[i+1]>nums2[i])
                ans++;            
        }
        
        return ans;
    }
};