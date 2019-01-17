class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int one = INT_MIN;
        int two = INT_MIN;
        int three = INT_MIN;
        vector<long> nums2;
        
        for(int i = 0;i<nums.size();i++) {
            if(nums[i] == one || nums[i] == two || nums[i] == three)
                continue;
            if(nums[i] > one) {
                three = two;
                two = one;
                one = nums[i];
            } else if(nums[i] > two) {
                three = two;
                two = nums[i];
            } else if(nums[i] > three)
                three = nums[i];
        }
        if(three != INT_MIN)
            return three;
        
        if(two == INT_MIN)
            return one;
        for(int i = 0;i<nums.size();i++)
            if(nums[i] == INT_MIN)
                return INT_MIN;
        return one;
    }
};