class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        
        for(int i = 1; i<size; i++)
        {
            if(i == 1)
            {
                if(nums[1]<nums[0])
                    nums[1] = nums[0];
            }
            else
            {
                nums[i] = max(nums[i]+nums[i-2],nums[i-1]);
            }
        }
        return nums[size-1];
    }
};