class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        
        int i;
        for(i = 1;i<nums.size();i++) {
            if(nums[i] < nums[i-1])
                break;
        }
        if(i == nums.size())
            return true;
        
        if((i != 1) && (nums[i-2]>nums[i]))
            nums[i] = nums[i-1];
        for(i++;i<nums.size();i++) {
            if(nums[i] < nums[i-1])
                return false;
        }
        return true;
    }
};