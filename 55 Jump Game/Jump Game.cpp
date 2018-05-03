class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farnum = 0;
        int temp;
        for(int i = 0; i < nums.size();i++)
        {
            if(i > farnum)
                return false;
            temp = i+nums[i];
            if(temp >= nums.size()-1)
                return true;
            if(temp > farnum)
                farnum = temp;
        }
        return false;
    }
};