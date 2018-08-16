class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        
        int minOne = INT_MAX;
        int minTwo = INT_MAX;
        for(int i = 0;i<nums.size();i++)
        {
            if(minTwo == INT_MAX)
            {
                if(nums[i] > minOne)
                    minTwo = nums[i];
            }
            else
            {
                if(nums[i] > minTwo)
                    return true;
                else
                {
                    if(nums[i] > minOne)
                        minTwo = nums[i];
                }
            }
            if(nums[i] < minOne)
                minOne = nums[i];
        }
        return false;
    }
};