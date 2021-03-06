class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        for(int i = 1;i<nums.size();i++)
        {
            left[i] = left[i-1]*nums[i-1];
        }
        
        vector<int> right(nums.size(),1);
        for(int i = 1;i<nums.size();i++)
        {
            right[i] = right[i-1]*nums[nums.size()-i];
        }
        
        for(int i = 0;i<nums.size();i++)
        {
            left[i] *= right[nums.size()-1-i];
        }
        
        return left;
    }
};